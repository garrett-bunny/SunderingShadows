
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
"east" : FOR"9",
"south" : FOR"22",
"west" : FOR"11",

]));

}

