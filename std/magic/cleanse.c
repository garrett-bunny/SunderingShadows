/**
 * @file
 * @brief common cleansing used in heal and mass heal
 */

#include <std.h>
#include <daemons.h>

void cleanse(object target)
{
    object * effects;

    if(target->query_paralyzed())
        target->remove_paralyzed();

    effects = target->query_property("status_effects");

    if(sizeof(effects))
    {
        object effect;
        foreach(effect in effects)
        {
            if(!objectp(effect))
                continue;
            if(effect->query_name() == "effect_fatigued" ||
               effect->query_name() == "effect_exhausted" ||
               effect->query_name() == "effect_dazzled" ||
               effect->query_name() == "effect_confused" ||
               effect->query_name() == "effect_negative_level" ||
               effect->query_name() == "effect_sickened"
                )
                effect->dest_effect(target);
        }
    }

    target->set_blind(0);
    target->set_temporary_blinded(0);
    target->set_poisoning(-target->query_poisoning());
}


void restore(object target)
{
    object * effects;

    if(target->query_paralyzed())
        target->remove_paralyzed();

    effects = target->query_property("status_effects");

    if(sizeof(effects))
    {
        object effect;
        foreach(effect in effects)
        {
            if(!objectp(effect))
                continue;
            if(effect->query_name() == "effect_fatigued" ||
               effect->query_name() == "effect_exhausted" ||
               effect->query_name() == "effect_negative_level" ||
               effect->query_name() == "effect_confused"
                )
                effect->dest_effect(target);
        }
    }

    target->set_blind(0);
    target->set_temporary_blinded(0);
    target->set_poisoning(-target->query_poisoning());
}

void lesser_restore(object target)
{
    object * effects;

    effects = target->query_property("status_effects");

    if(sizeof(effects))
    {
        object effect = effects[random(sizeof(effects))];

        if(objectp(effect))
            effect->dest_effect(target);
    }
}


void regenerate(object target)
{
    object * effects;

    if(target->query_paralyzed())
        target->remove_paralyzed();

    effects = target->query_property("status_effects");

    if(sizeof(effects))
    {
        object effect;
        foreach(effect in effects)
        {
            if(!objectp(effect))
                continue;
            if(effect->query_name() == "effect_fatigued" ||
               effect->query_name() == "effect_exhausted")
                effect->dest_effect(target);
        }
    }

    target->set_blind(0);
    target->set_temporary_blinded(0);
    target->set_poisoning(-target->query_poisoning());
}
