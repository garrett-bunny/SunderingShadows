#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"southeast" : HOUND"19",
"west" : HOUND"b2",

]));

}

