
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"west" : FALLOW"4",
"northeast" : FALLOW"6",
"south" : FALLOW"12",


]));

}

