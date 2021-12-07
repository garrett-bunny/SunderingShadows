#include <std.h>


/*
  Feyborn Acquired Template
*/

string *races_allowed()
{
    return ({"human", "elf", "half-elf", "half-orc", "beastkin", "dwarf", "half-dwarf"});
}

int is_rollable() { return 0; } // not rollable in creation

mapping innate_spells()
{
    return ([ "darkvision"     : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
              "thorn body"     : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),            
           ]);
}

int query_unbound_age()
{
    return 1;
}

int sight_bonus()
{
    return 2;
}

int apply_template(object ob)
{
    ob->set_acquired_template("feyborn");
    return 1;
}

int remove_template(object ob)
{
    ob->set_acquired_template(0);
    return 1;
}
