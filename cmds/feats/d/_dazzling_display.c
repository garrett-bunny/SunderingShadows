//Created by: Klieth
#include <std.h>
#include <daemons.h>
inherit FEAT;

object feat;

void create() 
{
    ::create();
    feat_type("instant");
    feat_category("WeaponMastery");
    feat_name("dazzling display");
    feat_prereq("Weapon Focus");
	feat_syntax("dazzling_display");
    feat_desc("While wielding the weapon in which you have Weapon Focus, you can perform a bewildering show of prowess as a full-round action. Make an Intimidate check to demoralize all foes within 30 feet who can see your display.");
}

int prerequisites(object ob)
{
	if(!FEATS_D->has_feat(ob, "weapon focus")) 
	{
		dest_effect();
		return 0; 
	}
    return ::prerequisites(ob); 
}
	
int cmd_dazzling_display(string str) 
{
    if(!this_player())
		return 0;
    feat = new(base_name(this_object()));
    feat->setup_feat(this_player(), str);
	return 1;
}

void execute_feat() 
{
	mapping tempmap;
	::execute_feat();
	
	if(caster->cooldown("dazzling display"))
	{
		tell_object(caster, "You are not ready to perform your dazzling display yet!");
		return 1; 
	}
	
	if((int)caster->query_property("using instant feat")) 
	{
		tell_object(caster, "You are already in the middle of using a feat!");
		dest_effect();
		return 1; 
	}
	
	if(!sizeof(caster->query_wielded()) && !caster->query_property("shapeshifted") && !caster->is_class("monk") && !FEATS_D->usable_feat(caster, "unarmed combat")) 
	{
        tell_object(caster,"How can you rush at anyone without a weapon?");
        dest_effect();
        return; 
	} 
        
	tell_object(target,"%^C107%^" + caster->query_cap_name() + " begins to dance and twirl as they show an awesome display of control. With an abrupt stop they end in an intimidating stance, facing you with a small smile.",({target}));
	tell_object(caster,"%^C107%^You begin your dance, ensuring every moment is visible to your enemies to ensure that they fully appreciate the skill you hold.");
	tell_room(place,"%^C107%^You see "+caster->QCN+" begin a dazzling display with his weapons.",caster);
	caster->use_stamina(roll_dice(2,6));
	caster->set_property("using instant feat", 1);
	//caster->set_property("dazzling_display", 1);
	//Will add in later when other feats use it.
    caster->add_cooldown("dazzling display", 60); 

}
	
void execute_attack() 
{
	int i;
    object* targets;

    if (!objectp(caster)) 
	{
		dest_effect();
		return; 
	}

    caster->remove_property("using instant feat");
    ::execute_attack();

    if (caster->query_unconscious()) 
	{
		dest_effect();
		return; 
	}

    targets = caster->query_attackers();

    if (!sizeof(targets))
    {
		tell_object(caster, "You are not under attack!");
		dest_effect();
		return;
    }
		
    targets += ({ caster });
    targets -= ({ caster });
    targets = shuffle(targets);

    for (i = 0; i < sizeof(targets) && i < 8; i++) 
	{
        if (targets[i] == caster) 
		{
            continue; 
		}

        if (!objectp(targets[i])) 
		{
            continue; 
		}

        if(!BONUS_D->intimidate_check(targets[i], caster) || PLAYER_D->immunity_check(targets[i], "fear")) 
		{
			tell_object(caster,"%^C107%^You finish your dance - but don't think it worked.");
			tell_object(targets[i],"%^C107%^You watch the weapons display with keen interest, however, it %^C160%^fails %^C107%^to inspire much %^C194%^fear at all in you.%^C107%^"); 
            tell_room(place,"%^C107%^You see "+targets[i]->query_cap_name() + " resist the display.",caster);
		    continue; 
		}

		else 
		{
			tell_object(caster,"%^C054%^You finish your dance and can tell by the look on your targets face... they are %^C160%^scared.");
			tell_object(targets[i],"%^C119%^The dazzling display makes you realize, just maybe you're not %^C107%^good %^C119%^enough.");
            tell_room(place,"%^C107%^You see "+targets[i]->query_cap_name()+" is clearly %^C160%^intimidated %^C107%^by the display.",caster);
			"/std/effect/status/shaken"->apply_effect(targets[i],roll_dice(1, 4));
        }

	    caster->add_attacker(targets[i]);
	    targets[i]->add_attacker(caster);
    }
    dest_effect();
    return;
}
	
void dest_effect() 
{
    ::dest_effect();
    remove_feat(caster);
    return;
}