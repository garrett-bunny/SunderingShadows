#include <std.h>

inherit "/std/monster.c";

void create() 
{
    ::create();
    set_name("Test Dummy");
    set_id(({"dummy", "test dummy", "testdummy", "practice dummy"}));
    set_race("test dummy");
    set_skill("perception",10000);
    set_body_type("human");
    set_short("OOC undead test dummy");
    set_long("This is a rugged practice dummy shaped in the rough dimensions of a man and covered with an old red shirt and black pants.  It seems to be stuffed with leather and looks to have seen a great deal of use. There is a large white skull painted on the front of this dummy.");
    set_hd(1,1);
    set_level(1);
    set_class("fighter");
    set_mlevel("fighter", 1);
    set_hp(10000000);
    set_exp(1);
    set_overall_ac(9);
    set_property("undead",1);
    set_property("no death", 1);
}

int do_typed_damage_effects(victim, limb, damage, damage_type){
    tell_room(ETO, "%^MAGENTA%^Dummy says%^RESET%^: I got hit to "+limb+" for "+damage+" "+damage_type+" damage!");
    return damage;
}

