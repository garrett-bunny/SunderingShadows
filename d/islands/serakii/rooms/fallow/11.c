
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"north" : FALLOW"4",
"west" : FALLOW"10",
"east" : FALLOW"12",
"south" : FALLOW"15",
"southwest" : FALLOW"14",


]));

}

