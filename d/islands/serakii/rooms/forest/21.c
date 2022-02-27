
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
    "east" : FOR"22",
    "north" : FOR"11",
    "west" : FOR"20",

]));

}

