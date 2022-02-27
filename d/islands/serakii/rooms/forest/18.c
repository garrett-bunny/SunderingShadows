
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
    "west" : FOR"19",
    "south" : FOR"17",

]));

}

