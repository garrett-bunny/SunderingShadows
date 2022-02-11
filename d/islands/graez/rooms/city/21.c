


#include <std.h>
#include "../../graez.h"

inherit STORAGE"outerstreet.c";



void create(){
   ::create();
      set_long(::query_long()+"\nTo the north lays the %^C231%^sprawling cathedral complex%^CRST%^ of the %^C231%^Castle de Boquillas%^CRST%^ Its %^C042%^stained glass%^CRST%^ windows gleaming at all hours. The %^C059%^road%^CRST%^ continues to the south and west.\n");


set_exits(([
"east" : BATTLE"3",
"west" : TOWN"17",
"south" : BATTLE"2",

]));

}

