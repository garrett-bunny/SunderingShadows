#include <std.h>
#include "../../serakii.h"

inherit STORAGE"bone_tower.c";

void create(){
   ::create();

set_exits(([
"northeast" : BONE"7",
"southeast" : BONE"9",

]));

}
