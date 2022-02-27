
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "east" : FOR"36",
    "west" : FOR"9",

]));

}

