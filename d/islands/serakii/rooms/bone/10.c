#include <std.h>
#include "../../serakii.h"

inherit STORAGE"bone_tower.c";

void create(){
   ::create();
   has_a_clue=3;

set_exits(([
"northeast" : BONE"11",
"down" : BONE"9",

]));

}
