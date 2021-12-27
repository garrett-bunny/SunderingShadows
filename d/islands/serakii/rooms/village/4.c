


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([

         "west" : TOWN"dojo",
          "south" : TOWN"2",
          "east" : TOWN"5",
   ]));

}


