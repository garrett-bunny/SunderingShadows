#include <std.h>
#include <spell.h>
#include <magic.h>
#include <priest.h>
inherit SPELL;

string *types = ({ "plant", "animal", "human" });

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
    
    if(!USER_D->is_valid_terrain(environment(this_object())->query_terrain(), "forest"))
    {
        tell_object(caster, "You need to be in the forest to use this ability.");
        dest_effect();
        return;
    }
    
    spell_successful();
}


void dest_effect()
{
    
    tell_room(place, "%^GREEN%^The centipedes fall to the ground, dead.");
    
    ::dest_effect();
}
