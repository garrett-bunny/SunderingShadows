#include <std.h>
#include "../../serakii.h"

inherit STORAGE"construction.c";

void create(){
   ::create();
   set_exits(([

          "north" : TOWN"garden",
          "northeast" : TOWN"fabric_vendor",
          "northwest" : TOWN"herb_vendor",
          "east" : TOWN"goldsmith_shop",
          "west" : TOWN"forge",
          
   ]));

}
