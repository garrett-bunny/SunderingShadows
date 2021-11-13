#include <std.h>
#include <magic.h>

inherit SPELL;

#define SCRY_D "/daemon/ic_scry_locate_d"

int bonus;
object blocker, temp, temp2;

void create()
{
    ::create();
    set_spell_name("impenetrable veil");
    set_spell_level(([ "mage" : 9, "bard" : 6 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS impenetrable veil on TARGET");
    set_damage_desc("half of clevel to stealth checks on sneaking, untrackable, protection from scrying");
    set_description("You raise a veil of impenetrable magic around the target, causing them to move silently, leaving no tracks. They also become extremely difficult to detect with scrying magic.");
    set_arg_needed();
	set_helpful_spell(1);
}

int preSpell()
{
    if (!target) target = caster;

    if(temp = target->query_property("block scrying"))
    {
        if(!objectp(temp))
        {
            target->remove_property("block scrying");
        }
        else
        {
            tell_object(caster,"%^BOLD%^%^MAGENTA%^You are already "
                "protected by blocking magic!%^RESET%^");
        }
        return 0;
    }

    if(target->query_property("chameleoned"))
    {
        tell_object(caster,"The target is already under the influence of similar effect");
    }
    return 1;
}

spell_effect()
{   
    if(!target)
        target = caster;

    if(!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

    spell_successful();

    tell_room(place,"%^MAGENTA%^"+caster->QCN+"  raises an impenetrable veil of magic around "+target->QCN+".%^RESET%^");

    blocker = SCRY_D->add_block_scrying(target);
    blocker->set_block_power(query_spell_DC(target, 0));
    
    target->set_property("spelled", ({TO}) );
    target->set_property("block scrying", 1);
    target->set_property("chameleoned",clevel / 2);
    target->set_property("untrackable", 1);
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(target))
    {
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target,"%^MAGENTA%^The magical veil fades.%^RESET%^");
        target->remove_property("chameleoned");
        target->remove_property("untrackable");
        target->remove_property("block scrying");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
