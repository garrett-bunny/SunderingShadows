#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"southeast" : HOUND"b2",
"northeast" : HOUND"b4",

]));

}

