#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SHAPESHIFT;
    

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "right arm","left arm" }) );
    set_new_damage_type("bludgeoning");
    set_limbs( ({ "head","torso","right arm", "left arm" }) );
//    set_attack_functions(([ "right arm" : (:TO,"arm_attack":), "left arm" : (:TO,"arm_attack":) ])); // moving this to an on-demand command
    set_attack_functions(([ "right arm" : (:TO,"shape_attack":), "left arm" : (:TO,"shape_attack":) ]));
    set_ac_bonus(0); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(0);
    set_castable(1);
    set_can_talk(1);
    set_shape_race("elemental");
    set_shape_language("celestial");
    set_shape_profile("life_elemental_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in
    set_shape_bonus("perception",4);
    set_shape_bonus("spellcraft",4);
    set_shape_bonus("sight bonus",3);
    set_shape_bonus("empowered",2);
    set_shape_bonus("damage resistance",10);
    set_shape_bonus("spell damage resistance",10);
    set_shape_height(200+random(40));
    set_shape_weight(5000+random(2000));
}

string * query_subraces() {
    return ({ "elemental","life elemental" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("rises before you, a creature of pure elemental force. Vaguely humanoid, it "
        "has a head with depthless orbs for eyes, descending to the outline of a body with arms at "
        "either side. The torso trails down to a formless mass that moves over the ground somehow. "
        "The being is unsettling at best, its intimidating bulk being something not of this plane.");

    obj->setDescriptivePhrase("shifting $R");

    obj->set("speech string","voice");
    obj->set("describe string","eerily");

    obj->force_me("message in moves in");
    obj->force_me("message out moves off to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^YELLOW%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^BLUE%^You reach out to the planes beyond the material, harnessing the very essence of "
        "life Your bond with positive energy grows stronger, attuned as you are now with the magical energies of the "
        "world around you.  You are ELEMENTAL!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands an ELEMENTAL!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the nature of life.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel a tinge of remose as you feel your elemental form slipping away.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s motions slow and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and gaining definition!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}

// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    object place, *attackers, *allies, *targets;
    int dam;
    
    if(!tp || !targ)
        return 0;
    
    place = environment(tp);
    
    if(place != environment(targ))
        return 0;
    
    //30% chance of firing
    if(random(3))
        return 0;
    
    attackers = tp->query_attackers();
    allies = PARTY_D->query_party_members(tp->query_party());
    
    if(!sizeof(attackers) && !sizeof(allies))
        return 0;
    
    //Elemental does positive energy to friendly living and enemy undead
    attackers = filter_array(attackers, (: $1->is_undead() :));
    allies = filter_array(allies, (: !($1->is_undead()) :));
    
    if(!sizeof(attackers) && !sizeof(allies))
        return 0;
    
    targets = attackers + allies;
    
    tell_room(place, "%^WHITE%^Whisps of healing energy emanate from " + tp->query_cap_name() + ", caressing everyone with healing energy!", ({ tp }));
    tell_object(tp, "%^WHITE%^Whispes of healing energy emanate from your form, caressing everyone with healing energies!");
    
    foreach(object ob in targets)
        ob->cause_typed_damage(ob, "torso", roll_dice(1, 6) + tp->query_class_level("oracle"), "positive energy");
    
    return roll_dice(1, 6);  
}
