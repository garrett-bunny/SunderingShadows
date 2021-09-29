/*
  _lure_of_the_cosmos.c
  
  Heavens mystery innate power.
  
  -- Tlaloc --
*/

#include <spell.h>
#include <daemons.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("lure of the cosmos");
    set_spell_level(([ "innate" : 5 ]));
    set_spell_sphere("alteration");
    set_mystery("heavens");
    set_syntax("cast CLASS lure of the cosmos");
    set_damage_desc("flight ability");
    set_description("You feel the pull of the cosmos, so strongly that you literally lift yourself off the ground, reaching for the heavens above.");
    //set_verbal_comp();
    //set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->query_cap_name() + " begins to beckon to the heavens.%^RESET%^";
}

void spell_effect(int prof)
{   
    if(!objectp(caster))
        return;
    
    if(caster->query_property("flying"))
    {
        tell_object(caster,"You're already under a similar effect!");
        this_object()->remove();
        return;
    }
    
    spell_successful();
     
    caster->set_property("flying", 1);
    
    tell_object(caster, CRAYON_D->color_string("You reach for the stars, and will yourself towards them, lifting off of the ground.", "very black"));
    tell_room(place, CRAYON_D->color_string(caster->query_cap_name() + " reaches for the stars above " + caster->query_objective() + " and lifts off the ground.", "very black"), caster);
    
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster, "%^BLACK%^BOLD%^The wings of darkness fade.%^RESET%^");
        caster->remove_property("flying");
    }
    
    ::dest_effect();
}    