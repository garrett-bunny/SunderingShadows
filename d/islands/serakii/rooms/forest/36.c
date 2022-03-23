
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "east" : FOR"37",
    "west" : FOR"35",
    "north" : FOR"41",
    "south" : FOR"39",

]));

}

