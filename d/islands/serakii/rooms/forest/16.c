
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
    "north" : FOR"15",
    "east" : FOR"20",

]));

}

