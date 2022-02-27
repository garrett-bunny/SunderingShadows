
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "west" : FOR"42",
    "south" : FOR"40",
    "north" : FOR"44",

]));

}

