#include <std.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("nightmare");
    set_spell_level(([ "mage" : 5, "bard":5, "innate" : 5 ]));
    set_domains("nightmare");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS nightmare on TARGET");
    set_damage_desc("mental, fatigue for clevel / 4 + 1  rounds");
    set_description("The nightmare prevents restful sleep and causes target to become fatigued for a very long period of time. Nightmare clerics casting this spell as an innate spell must expend one Divine grace point.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^BLUE%^" + caster->QCN + " makes a few passes in the air, whispering in dread undertones.%^RESET%^";
}

int preSpell() {
    
    if(caster->is_class("cleric") && spell_type == "innate")
    {
        if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
        {
            tell_object(caster, "You don't have the Divine Grace to cast Nightmare!");
            return 0;
        }
    }
    
    return 1;
}

spell_effect()
{

    if (!do_save(target, 0)) {
        if (mind_immunity_damage(target, "default")) {
            spell_successful();
            dest_effect();
            return;
        }
        "/std/effect/status/fatigued"->apply_effect(target, clevel / 4 + 1);
    }

    damage_targ(target, target->return_target_limb(), sdamage, "mental");

    tell_object(target, "%^BLUE%^A heavy nightmarish vision descends upon you as " + caster->QCN + " completes the spell.");
    tell_room(ENV(target), "%^BLUE%^" + target->QCN + " shudders and staggers as feeling of dread swipes by the area.", target);

}
