#include <std.h>
#include <daemons.h>
#include <dirs.h>

#define VALID ({ "black", "blue", "brass", "bronze", "copper", "gold", "green", "red", "silver", "white" }) 

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("SavageCombat");
    feat_name("dragon affinity");
    feat_syntax("dragon_affinity");
    feat_desc("This feat allows an oracle with the dragon mystery to choose their chosen dragon affinity. This will determine things like resistance granted and damage types for breath weapons.
    
%^CYAN%^BOLD%^The choices for dragon affinity are as follows: \n\%^RED%^" + implode(VALID,"\n") + "%^RESET%^");
    permanent(1);
    allow_tripped(1);
}

int allow_shifted()
{
    return 1;
}

int cmd_dragon_affinity(string args)
{
    if(this_player()->query("dragon_affinity"))
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^You already have your dragon affinity set.");
        return 1;
    }

    tell_object(TP,"%^BOLD%^%^WHITE%^Select your dragon affinity:\n");
    tell_object(TP,"%^BOLD%^%^MAGENTA%^" + implode(map_array(VALID, (:"  " + $1:)), "\n"));
    tell_object(TP,"%^BOLD%^%^WHITE%^\nEnter anything else to abort.");
    input_to("select_affinity", 0);
    return 1;
}

void select_affinity(string args)
{
    if(member_array(args, VALID) == -1)
    {
        tell_object(TP,"%^BOLD%^%^WHITE%^Aborting...");
        return;
    }

    tell_object(TP,"%^BOLD%^%^WHITE%^You have selected %^CYAN%^" + args + "%^WHITE%^ as your dragon affinity.");
    tell_object(TP,"%^BOLD%^%^WHITE%^Is this a correct choice? Type %^GREEN%^yes%^WHITE%^ to confirm, anything else to abort.");
    input_to("confirm_selection", 0);
    return;
}

void confirm_selection(string args)
{
    if (args != "yes") {
        tell_object(this_player(), "%^BOLD%^%^WHITE%^Aborting...");
        return;
    }

    this_player()->set("dragon_affinity", args);
    tell_object(TP,"%^BOLD%^%^WHITE%^Your dragon affinity has been set.");
    return;
}

int prerequisites(object ob)
{
    if (!objectp(ob))
        return 0;
        
    if (!ob->is_class("oracle"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void execute_attack()
{
    object attacker, *attackers;
    string my_name, att_name, my_poss, att_poss;
    int level;
    
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (caster->query_ghost() || caster->query_unconscious())
        return;

    if(caster->query_bound() || caster->query_paralyzed())
        return;
    
    attacker = caster->query_current_attacker();
    
    if(!attacker)
        return;
    
    my_name = caster->query_cap_name();
    att_name = attacker->query_cap_name();
    my_poss = caster->query_possessive();
    att_poss = attacker->query_possessive();
    level = caster->query_class_level("oracle");
    
    
    
    attackers = caster->query_attackers();
}


void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
