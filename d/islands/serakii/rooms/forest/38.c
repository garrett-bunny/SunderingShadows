
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "west" : FOR"39",
    "north" : FOR"37",

]));

}

