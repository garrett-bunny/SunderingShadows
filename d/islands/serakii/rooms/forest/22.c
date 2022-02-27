
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
    "east" : FOR"23",
    "north" : FOR"10",
    "west" : FOR"21",

]));

}

