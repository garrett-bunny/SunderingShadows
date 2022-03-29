#include <std.h>
#include "../../serakii.h"

inherit STORAGE"bone_tower.c";

void create(){
   ::create();

set_exits(([
"northeast" : BONE"12",
"southeast" : BONE"14",

]));

}

