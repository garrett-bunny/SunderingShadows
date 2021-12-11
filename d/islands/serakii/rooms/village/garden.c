#include <std.h>
#include "../../serakii.h"

inherit STORAGE"construction.c";

void create(){
   ::create();
   set_exits(([

          "south" : TOWN"metals_vendor",
          "north" : TOWN"foyer",
          "east" : TOWN"fabric_vendor",
          "west" : TOWN"herb_vendor",
          
   ]));

}
