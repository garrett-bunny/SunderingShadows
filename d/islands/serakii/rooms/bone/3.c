#include <std.h>
#include "../../serakii.h"

inherit STORAGE"bone_tower.c";

void create(){
   ::create();

set_exits(([
"southeast" : BONE"2",
"northeast" : BONE"4",

]));

}
