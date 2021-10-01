#include <std.h>
#include <spell.h>
#include <magic.h>
#include <priest.h>
#include <daemons.h>

inherit SPELL;

string *types = ({ "plant", "animal", "human" });

object cocoon, cocoon_inside;

void create()
{
    ::create();
    set_spell_name("cocoon");
    set_spell_level(([ "innate" : 9 ]));
    set_mystery("nature");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS cocoon on RACE");
    set_damage_desc("Envelop yourself in a cocoon and become another race");
    set_description(".");
    set_arg_needed();
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string()
{
    return "%^CYAN%^"+caster->QCN+" lifts "+caster->QP+" head and lets out a call to the wilds.";
}

int color(string str)
{
    return CRAYON_D->color_string(str, "dark green");
}

void spell_effect(int prof)
{
    
    if(!objectp(caster))
        return;
    
    if(!arg))
    {
        tell_object(caster, "You need to choose a race to change into.");
        dest_effect(target);
        return;
    }
    if(member_array(arg, RACE_D->query_races()) < 0)
    {
        tell_object(caster, capitalize(arg) + " is not a valid race.");
        dest_effect();
        return;
    }
    if(!USER_D->is_valid_terrain(environment(this_object())->query_terrain(), "forest"))
    {
        tell_object(caster, "You need to be in the forest to use this ability.");
        dest_effect();
        return;
    }
    
    if(catch(cocoon = new("/d/magic/room/cocoon.c")) ||
    catch(cocoon_inside = new("/d/magic/room/cocoon_inside.c")))
    {
        tell_object(caster, "Something went wrong. Contact a creator.");
        dest_effect();
        return;
    }
    
    tell_object(caster, "%^GREEN%^You begin to spin a cocoon of silky threads around yourself.%^RESET%^");
    tell_room(place, "%^GREEN%^" + caster->query_cap_name() + " begins to spin silky threads around " + caster->query_objective() + ".", caster);
       
    spell_successful();
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
    
    caster->move_player(cocoon_inside);
    cocoon->move(environment(caster));
    
    tell_object(caster, "%^GREEN%^BOLD%^You spin the silky threads around you and finish your cocoon.");
    tell_room(place, "%^GREEN%^BOLD%^" + caster->query_cap_name() + " finishes spinning the threads into a complete cocoon!");
    call_out("dest_effect", 8 * ROUND_LENGTH);
}
    
void dest_effect()
{
    tell_object(caster, "%^GREEN%^You wriggle and push your way out. You burst into open, fresh air, a brand new %^YELLOW%^" + arg + ".");
    tell_room(place, "%^GREEN%^The cocoon begins to wriggle then bursts open, revealing a " + arg + ".", caster);
    caster->move_player(place);
    cocoon_inside->dest_effect();
    cocoon->dest_effect();
    
    ::dest_effect();
}
