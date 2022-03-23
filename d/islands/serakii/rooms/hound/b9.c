#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"southeast" : HOUND"b8",
"north" : HOUND"b10",

]));

}

