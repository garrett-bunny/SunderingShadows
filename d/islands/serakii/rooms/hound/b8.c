#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"south" : HOUND"b7",
"northwest" : HOUND"b9",

]));

}

