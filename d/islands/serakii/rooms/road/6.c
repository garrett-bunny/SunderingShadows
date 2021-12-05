#include <std.h>
#include "../../serakii.h"

inherit STORAGE"trade_road.c";



void create(){
   ::create();
   set_long(::query_long()+"\n%^C252%^To the north you can see a massive fortress%^CRST%^\n");


set_exits(([

"south" : ROAD"2",
"north" : ROAD"7",
]));

}
