#include <std.h>

inherit LRWEAPON;

int martialtrack, exotictrack;

void create(){
    ::create();
    set_id(({"shuriken"}));
    set_name("shuriken");
    set_short("A shuriken");
    set_long(
        "This a sharp shuriken."
        );
    set_prof_type("staff");
    set_weight(1);
    set_type("piercing");
    set_decay_rate(100);
    set_range(2,4,8);
    set_ammo("shurikens");
    set_lr_prof_type("sling");
    set_weapon_prof("exotic");
    set_lr_type("piercing");
    set_size(1);
    set_wc(1,4);
    set_large_wc(1,4);
    set_value(3);
    set_rate_of_fire(2);
    set_weapon_speed(2);
    set_property("repairtype",({"woodwork", "weaponsmith"}));
	set_wield((:TO,"wield_fun":));
    set_unwield((:TO,"remove_fun":));
}

int wield_fun() {
   if(member_array("martial weapon proficiency",(string*)ETO->query_temporary_feats()) == -1)&&!ob->is_class("monk")) {
     ETO->add_temporary_feat("martial weapon proficiency");
     martialtrack = 1;
   }
   if(member_array("exotic weapon proficiency",(string*)ETO->query_temporary_feats()) == -1) {
     ETO->add_temporary_feat("exotic weapon proficiency");
     exotictrack = 1;
   }
   tell_object(ETO,"%^RESET%^%^CYAN%^You slip the ring over a finger, and you feel a sudden battle readiness fill you.%^RESET%^");
   return 1;
}

int remove_fun() {
   tell_room(EETO,"%^RESET%^%^CYAN%^The battle readiness fades, and you feel normal again.%^RESET%^");
   if(exotictrack) {
     ETO->remove_temporary_feat("exotic weapon proficiency");
     exotictrack = 0;
   }
   if(martialtrack) {
     ETO->remove_temporary_feat("martial weapon proficiency");
     martialtrack = 0;
   }
   return 1;
}