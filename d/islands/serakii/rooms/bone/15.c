#include <std.h>
#include "../../serakii.h"

inherit STORAGE"bone_atrium.c";

void create(){
   ::create();

set_exits(([
"northwest" : BONE"16",
"northeast" : BONE"17",
"down" : BONE"14",

]));

}

