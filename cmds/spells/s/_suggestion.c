#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("suggestion");
    set_spell_level(([ "psion" : 1,  ]));
    set_spell_sphere("telepathy");
    set_discipline("telepath");
    set_syntax("cast CLASS suggestion on TAGET to COMMAND");
    set_description("You manifest a suggestion that the target has no choice but to obey. If the target succeeds the save or is immune, they will attack the caster.");
    set_save("will");
    mental_spell(1);
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string targ, command;

    if(sscanf(arg,"%s to %s",targ,command)!=2)
    {
        tell_object(caster,"<"+syntax+">");
        dest_effect();
        return;
    }

    if(!objectp(target = present(targ,place)))
    {
        tell_object(caster,"That is not here!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^MAGENTA%^You enter a suggestion into "+target->QCN+"'s mind to:%^RESET%^ "+command+"!");
    tell_object(target, "%^BOLD%^MAGENTA%^You feel a hypnotic suggestion entering your mind, causing you to " + command + "!%^RESET%^");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" focuses on "+target->QCN+"'s mind%^RESET%^!", ({ caster, target }));

    if(do_save(target,0)||
       target->query_property("no dominate",1)||
       mind_immunity_damage(target, "default"))
    {
        tell_room(environment(target),"Outraged at "+caster->QCN+" for "+caster->QP+" attempt at mind control, "+target->QCN+" attacks "+caster->QO+"!", ({target, caster}) );
        tell_object(target,"Outraged at "+caster->QCN+" for "+caster->QP+" attempt at mind control, you attack "+caster->QO+"!");
        tell_object(caster,""+target->QCN+" attacks you, outraged at you for your attempt at mind control!" );
        spell_kill(target, caster);
        return;
    }

    target->set_property("dominated",1);
    target->force_me(command);
    target->remove_property("dominated");
    spell_successful();
    dest_effect();
    return;
}
