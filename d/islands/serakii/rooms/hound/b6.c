#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"south" : HOUND"b5",
"north" : HOUND"b7",

]));

}

