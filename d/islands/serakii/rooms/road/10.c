#include <std.h>
#include "../../serakii.h"

inherit STORAGE"trade_road.c";



void create(){
   ::create();


set_exits(([

"east" : ROAD"9",
"southwest" : ROAD"11",
]));

}

