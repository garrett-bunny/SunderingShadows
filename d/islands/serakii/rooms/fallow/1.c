#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"north" : ROAD"4",
"east" : FALLOW"2",
]));

}
