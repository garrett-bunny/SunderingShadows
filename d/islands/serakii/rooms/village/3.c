


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([

          "north" : TOWN"5",
          "west" : TOWN"2",
          "southeast" : TOWN"6",
         "south" : TOWN"foyer",
   ]));

}


