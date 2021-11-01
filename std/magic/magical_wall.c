//
// magical_wall.c
//
// A standardized inherit file for any and all magical
// walls. Any future magical walls should inherit this file
// in the name of standardization.
//
// For BEST utilization, simple use this file and set its
// parameters from the spell itself.
//
// -- Tlaloc -- 11.1.21
//

#include <std.h>
#include <dameons.h>

#define MAX_DUR    10000
#define DEF_DUR      100

inherit OBJECT;

int DC, blocking, health;
object owner;
string type, exit;

//Variable Functions
int set_difficulty(int x)   { DC = x; return DC;             }
int set_durability(int x)   { durability = x; return health; }
object set_owner(object ob) { owner = ob; return owner;      }
string set_type(string str) { type = str; return type;       }
string set_exit(string str) { exit = str; return exit;       }

int query_difficulty() { return DC;         }
int query_durability() { return durability; }
object query_owner()   { return owner;      }
string query_type()    { return type;       }
string query_exit()    { return exit;       }

int add_durability(int x)
{
    durability = min( ({ MAX_DUR, durability + x }) );
    return durability;
}
//End Variable Functions

void create()
{
    ::create();
    set_name("wall");
    set_id( ({ "wall", "magical wall" }) );
    set_weight(10000);
    set_value(0);
    set_durability(DEF_DUR);
}

void init()
{
    ::init();
    add_action("end_walls", "remove");
}

int is_invincible() { return 1; }

int block(string exitn)
{
    string wallname;
    object room;
    
    if(!strlen(exitn))
        return 0;
    
    if(!objectp(owner))
        return 0;
    
    room = environment(this_object());
    
    if(!object(room))
        return 0;
    
    set_exit(exitn);
    wallname = owner->query_name() + exitn + type + "wall";
    
    if(present(wallname, room))
        return 0;
    
    add_id("wallname");
    
    return room->set_blocked(exitn, this_object());
}   