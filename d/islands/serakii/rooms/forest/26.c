
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
    "north" : FOR"23",
    "west" : FOR"25",
    "south" : FOR"27",

]));

}

