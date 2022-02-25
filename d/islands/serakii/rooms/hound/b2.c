#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"northwest" : HOUND"b3",
"east" : HOUND"b1",

]));

}

