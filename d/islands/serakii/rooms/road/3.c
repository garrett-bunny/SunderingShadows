#include <std.h>
#include "../../serakii.h"

inherit STORAGE"trade_road.c";



void create(){
   ::create();


set_exits(([

"northeast" : ROAD"1",
"west" : ROAD"8",
]));

}
