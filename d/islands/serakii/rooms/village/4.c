


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([

          "south" : TOWN"2",
          "east" : TOWN"5",
   ]));

}


