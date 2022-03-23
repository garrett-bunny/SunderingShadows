
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "east" : FOR"34",
    "north" : FOR"26",
    "south" : FOR"28",

]));

}

