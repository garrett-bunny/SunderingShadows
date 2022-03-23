#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"southwest" : HOUND"b3",
"east" : HOUND"b5",

]));

}

