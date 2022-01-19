
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"east" : FALLOW"4",
"south" : FALLOW"10",
"southwest" : FALLOW"9",


]));

}

