#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"south" : HOUND"b6",
"north" : HOUND"b8",

]));

}

