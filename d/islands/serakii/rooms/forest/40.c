
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "west" : FOR"41",
    "north" : FOR"43",
    "south" : FOR"37",

]));

}

