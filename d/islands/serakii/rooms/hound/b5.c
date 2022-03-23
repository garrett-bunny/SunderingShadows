#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();


set_exits(([
"west" : HOUND"b4",
"north" : HOUND"b6",

]));

}

