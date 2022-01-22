
#include <std.h>
#include "../../graez.h"

inherit STORAGE"ruins.c";


void create(){
   ::create();

   set_long(::query_long()+"%^C058%^\nIn the middle of the room lays the ruins of a giant forge. The obscene heat of the fire, coupled with what looks like a coordinated physical attack has destroyed the forge and eliminated its use for the city.%^CRST%^\n");

   set_exits(([
        "north":TOWN"weapons",
        "south":TOWN"smith"

    ]));

}
