#include <std.h>
#include "../../serakii.h"

inherit STORAGE"bone_tower.c";

void create(){
   ::create();

set_exits(([
"northwest" : BONE"13",
"up" : BONE"15",

]));

}

