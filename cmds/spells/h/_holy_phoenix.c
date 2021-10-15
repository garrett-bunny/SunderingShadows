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

object oldenv, web, mass;
int waittime;

void dest_effect();
void waiter(int num);

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

string query_cast_string(){
   tell_object(caster,"%^BOLD%^Grabbing your holy symbol tightly "+
      "in your hand, shouting out a desperate please to your deity. "+
      "in the air with your right forefinger.%^RESET%^");
   tell_room(place,"%^BOLD%^"+caster->QCN+" holds a holy symbol "+
      "tightly in "+caster->QP+" left hand as "+caster->QS+" they "+
      "shout out a desperate prayer to their deity.%^RESET%^",caster);
   return "display";
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
        tell_room(place, "%^C195%^" + peep->QCN + "'s eyes flinches as " + peep->QS + " bright light begins to cover them!%^RESET%^", peep);

        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage, "divine");
        } else {
            tell_object(peep, "%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_peep_limb(), sdamage / 2, "divine");
        }

    }
    spell_successful();
	caster->set_paralyzed(30, "%^C195%^You feel overwhelmed by divine power, you are losing control and unable to think or act!");
    call_out("second_hit", 15);
}

void second_hit()
{
    object peep;
    define_base_damage(0);

    foreach(peep in victims)
    {
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
    caster->set_paralyzed(30, "%^C195%^Your body feels burning hot as if the energy is trying to escape! You are about to explode!");
    call_out("last_hit", 15);
}

void last_hit()
{
    object peep;

    define_base_damage(0);

    foreach(peep in victims)
    {
        tell_object(peep, "%^C195%^" +caster->QCN+ "%^C195%^explodes in a massive burst of divine energy!%^RESET%^");
        tell_object(environment(peep), "%^C195%^" + peep->QCN + " shudders violently as the explosion blasts into them!");
		tell_room(place,"%^C195%^" +caster->QCN+ "explodes in a burst of light, energy ripping through the room.%^RESET%^",caster);
        if (!do_save(peep)) {
            damage_targ(peep, peep->return_peep_limb(), sdamage * 2, "divine");
        } else {
            tell_object(peep, "%^C195%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
            damage_targ(peep, peep->return_target_limb(), sdamage, "divine");
        }
    }
	waittime= 5;
	oldenv=environment(caster);
	caster->add_cooldown("holy phoenix", 50);
	web=new("/d/magic/room/judgement.c");
    caster->move(web);
    addSpellToCaster();
    call_out("waiter",ROUND_LENGTH,1);
}

void waiter(int num) {
    object *tempinv;
    if(!caster || !objectp(web)){
        dest_effect();
        return;
    }
    if (!present(caster,web)) {
        mass->remove();
        web->move("/d/shadowgate/void.c");
        while ( tempinv=(object *)web->all_inventory() ) {
            tempinv[0]->move(oldenv);
            return;
        }
    }
    if (num < waittime)
        call_out("waiter",ROUND_LENGTH,num+1);
    else
        dest_effect();
    return;
}
void dest_effect() {
    int i;
    object *tempinv;

    if (objectp(caster) && objectp(web))
        if (present(caster,web)) {
            tell_object(caster,"%^BOLD%^%^YELLOW%^You feel warmth throughout your body as you step out of a ball of light!%^RESET%^");
            tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" suddenly steps out of the glowing orb.%^RESET%^",caster );
            caster->move(oldenv);
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
        }
	if (find_call_out("second_hit") != -1) {
        remove_call_out("second_hit");
    }
    if (find_call_out("last_hit") != -1) {
        remove_call_out("last_hit");
    }
    if (objectp(caster) && objectp(web)) {
        if (!present(caster,web)) {
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
            TO->remove();
        }
    } else if(objectp(web)) {
        tempinv=all_inventory(web);
        for (i=0;i++;i<sizeof(tempinv)) {
            if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
        }
        TO->remove();
        web->remove();
    } else {
        TO->remove();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}


	
	
	
	