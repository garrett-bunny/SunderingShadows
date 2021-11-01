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

int DC,            //Difficulty in getting past the wall (or damaging it)
    blocking,      //Is it currently blocking?
    damage,        //Spell strength of wall
    durability;    //The health of the wall

object owner;      //The original caster

string type,       //Which type/element is the wall?
       exit,       //Which exit is it blocking
       stat;       //What stat is used to determine if we make it past?

//Variable Functions
int set_difficulty(int x)   { DC = x; return DC;             }
int set_durability(int x)   { durability = x; return health; }
int set_clevel(int x)       { clevel = x; return clevel;     }
object set_owner(object ob) { owner = ob; return owner;      }
string set_type(string str) { type = str; return type;       }
string set_exit(string str) { exit = str; return exit;       }
string set_stat(string str) { stat = str; return stat;       }

int query_difficulty() { return DC;         }
int query_durability() { return durability; }
int query_clevel()     { return clevel;     }
object query_owner()   { return owner;      }
string query_type()    { return type;       }
string query_exit()    { return exit;       }
string query_stat()    { return stat;       }

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
    
    if(room->set_blocked(exitn, this_object()))
    {
        blocking = 1;
        return 1;
    }
    
    return 0;
}

int try_to_pass(object who)
{
    int roll1;
    string stat;
    
    if(!objectp(who))
        return 0;
    
    if(!strlen(type))
        return 1;
    
    if(!difficulty)
        return 1;
    
    roll1 = roll_dice(1, 20);
    
    if(!strlen(stat))
        stat = "strength";
    
    roll1 += BONUS_D->stat_bonus(who, stat);
    
    switch(type)
    {
        case "fire":
        
    
    
    
    