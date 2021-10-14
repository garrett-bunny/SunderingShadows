#include <std.h>
#include <spell.h>
#include <magic.h>
#include <priest.h>
#include <daemons.h>

//#define BAN ({ "soulforged", "deva", "shade", "alaghi", "ghost", "nightwing", "barrus", "illithid", "unborn", "dragon" })

inherit SPELL;

void second_hit();
void last_hit();

object* victims;

//string *types = ({ "plant", "animal", "human" });
//string *valid_races;
//int cocooned = 0;

//object cocoon, cocoon_inside;

void create()
{
    ::create();
    set_spell_name("holy phoenix");
    set_spell_level(([ "cleric" : 9 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS holy phoenix");
    set_description("With this ability, the cleric sends a fervent prayer to their deity "
					"sacrificing themselves for the lives of their friends and to the bane of "
					"there enemies. Such a sacrifice always looks favorable by the gods.");
    set_arg_needed();
	set_damage_desc("divine");
    set_verbal_comp();
    set_somatic_comp();
	splash_spell(3);
	set_save("reflex");
}

string query_cast_string()
{
    return "%^C154%^"+caster->QCN+" clenches "+caster->QP+" fists and chants a fervent prayer to their deity!";
}

//int preSpell()
//{
//    int size;
    
 //   if(caster->cooldown("phoenix"))
 //   {
 //       tell_object(caster, "You can't use holy phoenix yet. Type <cooldowns> to see your wait time.");
 //       return 0;
  //  }

//}

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

        tell_object(peep, "%^C195%^Another surge of light bursts from" +caster->QCN+ "%^C195%^striking you with greater intensity!%^RESET%^");
        tell_object(environment(peep), "%^C195%^" + peep->QCN + " trembles as the light continues to blast into " + peep->QP + " frame.", peep);
        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage, "divine");
        } else {
            tell_object(peep, "%%^C195%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_target_limb(), sdamage, "divine");
        }
    }

    if (!sizeof(victims)) {
        dest_effect();
    }

    call_out("last_hit", ROUND_LENGTH);
}

void last_hit()
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
        tell_object(peep, "%^C195%^" +caster->QCN+ "%^C195%^explodes in a massive burst of divine energy!%^RESET%^");
        tell_object(environment(peep), "%^C195%^^" + peep->QCN + " shudders violently as the explosion blasts into them");
        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage * 2, "divine");
        } else {
            tell_object(peep, "%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_target_limb(), sdamage, "divine");
        }
    }
	caster->add_cooldown("cocoon", 86400);
    dest_effect();
}
	
void dest_effect()
{
    if (find_call_out("second_hit") != -1) {
        remove_call_out("second_hit");
    }
    if (find_call_out("last_hit") != -1) {
        remove_call_out("last_hit");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
	
	
	
	
	
	