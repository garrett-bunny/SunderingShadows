#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("DivineSpellcraft");
    feat_name("apotheosis");
    feat_prereq("Cleric L31");
    feat_desc("The cleric has become the chosen servant of their deity in the world. The cleric becomes a conduit of her deity and thus can cast domain spells at will, without memorization or using spell slots. In addition, the gains +1 caster level on spells of their chosen domain. Finally, the cleric becomes with infused divine energy and so becomes 20% resistant to divine damage.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }

   if((int)ob->query_class_level("cleric") < 31) 
   {
      dest_effect();
      return 0;
   }
   return ::prerequisites(ob);
}

void execute_feat() 
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob) {
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob) {
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}

