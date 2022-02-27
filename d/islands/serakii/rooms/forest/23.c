
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
    "north" : FOR"9",
    "west" : FOR"22",
    "south" : FOR"26",

]));

}

