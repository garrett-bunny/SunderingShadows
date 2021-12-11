#include <std.h>
#include "../../serakii.h"

inherit STORAGE"construction.c";

void create(){
   ::create();
   set_exits(([

          "north" : TOWN"brewery",
          "south" : TOWN"lab",
          "northeast" : TOWN"foyer",
          "southeast" : TOWN"metals_vendor",
          "east" : TOWN"garden",
          
   ]));

}
