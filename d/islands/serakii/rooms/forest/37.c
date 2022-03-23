
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "west" : FOR"36",
    "north" : FOR"40",
    "south" : FOR"38",

]));

}

