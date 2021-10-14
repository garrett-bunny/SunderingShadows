#include <std.h>
#include <spell.h>
#include <magic.h>
#include <priest.h>
#include <daemons.h>

#define BAN ({ "soulforged", "deva", "shade", "alaghi", "ghost", "nightwing", "barrus", "illithid", "unborn", "dragon" })

inherit SPELL;

string *types = ({ "plant", "animal", "human" });
string *valid_races;
int cocooned = 0;

object cocoon, cocoon_inside;

void create()
{
    ::create();
    set_spell_name("holy phoenix");
    set_spell_level(([ "cleric" : 9 ]));
    set_spell_sphere("evocation");
    set_syntax("cast CLASS holy phoenix");
    set_description("With this ability, the cleric sends a fervent prayer to their deity "
					"sacrificing themselves for the lives of their friends and to the bane of "
					"there enemies. Such a sacrifice always looks favorable by the gods.");
    set_arg_needed();
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^C154%^"+caster->QCN+" clenches "+caster->QP+" fists and chants a fervent prayer to their deity!";
}

int preSpell()
{
    int size;
    
    if(caster->cooldown("phoenix"))
    {
        tell_object(caster, "You can't use holy phoenix yet. Type <cooldowns> to see your wait time.");
        return 0;
    }

}

void spell_effect(int prof)
{
    object peep;
    victims = target_selector();

    if (!sizeof(victims)) {
        tell_object(caster,"%^BOLD%^%^GREEN%^Your spell fails to connect to anyone.");
        dest_effect();
    }

    foreach(peep in victims)
    {
        tell_object(peep, "%^C195%^Bright light hits you, starting to burn your skin!%^RESET%^");
        tell_room(place, "%^C195%^" + peep->QCN + "'s eyes flinch as " + peep->QS + " bright light begins to cover them!%^RESET%^", peep);

        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage, "divine");
        } else {
            tell_object(peep, "%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_peep_limb(), sdamage / 2, "divine");
        }

    }
    spell_successful();
    call_out("second_hit", ROUND_LENGTH);
}

void second_hit()
{
    object peep;
    define_base_damage(0);

    foreach(peep in victims)
    {
        if (!objectp(peep)) {
            victims -= ({ peep });
            continue;
        }
        if (peep->query_hp() < 0) {
            victims -= ({ peep });
            continue;
        }

        tell_object(peep, "%^C195%^Another surge of light bursts from" +caster->QCN+ "%^C195%^striking you with greater intensity!");
        tell_object(environment(peep), "%^C195%^" + peep->QCN + " trembles as the light continues to blast into " + peep->QP + " frame.", peep);
        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage / 2, "acid");
        } else {
            tell_object(peep, "%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_target_limb(), sdamage / 4, "acid");
        }
    }

    if (!sizeof(victims)) {
        dest_effect();
    }

    call_out("last_hit", ROUND_LENGTH);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
void spell_effect(int prof)
{
    
    if(!objectp(caster))
        return;
 
    
    tell_object(caster, color("You begin to spin a cocoon of silky threads around yourself."));
    tell_room(place, "%^GREEN%^" + caster->query_cap_name() + " begins to spin silky threads around " + caster->query_objective() + ".", caster);
       
    spell_successful();
    caster->add_cooldown("cocoon", 86400);
    call_out("finish_cocoon", ROUND_LENGTH);
}





void finish_cocoon()
{
    if(!objectp(caster))
        return;
    
    if(caster->query_current_attacker())
    {
        tell_object(caster, "Your cocoon spinning was interrupted!");
        dest_effect();
        return;
    }
    
    if(!cocoon_inside->setup_cocoon(types[random(sizeof(types))]))
    {
        tell_object(caster, "Something went wrong with the cocoon.");
        dest_effect();
        return;
    }

    cocoon->move(place);    
    caster->move_player(cocoon_inside);
    
    tell_object(caster, color("You spin the silky threads around you and finish your cocoon."));
    tell_room(place, "%^GREEN%^BOLD%^" + caster->query_cap_name() + " finishes spinning the threads into a complete cocoon!", caster);
    cocooned = 1;
    call_out("dest_effect", 15 * ROUND_LENGTH);
}
    
void dest_effect()
{
    if(objectp(caster) && cocooned)
    {
        tell_object(caster, color("You wriggle and push your way out. You burst into open, fresh air, a brand new " + arg + "."));
        tell_room(place, "%^GREEN%^The cocoon begins to wriggle then bursts open, revealing a " + arg + ".", caster);
        caster->move_player(place);
        caster->set_race(arg);
    }
    cocoon_inside->remove();
    cocoon->remove();
    
    ::dest_effect();
}
