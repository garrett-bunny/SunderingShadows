
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
"west" : FOR"5",
"south" : FOR"8",

]));

}

