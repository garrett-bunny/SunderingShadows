#include <std.h>
#include "../../serakii.h"

inherit STORAGE"construction.c";

void create(){
   ::create();
   set_exits(([

          "south" : TOWN"fight_ring",
          "down" : TOWN"meditation",
          "east" : TOWN"4"
          
   ]));

}
