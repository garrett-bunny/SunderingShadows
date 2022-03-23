#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"south" : HOUND"b9",
"northeast" : HOUND"b11",

]));

}

