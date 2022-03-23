


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([

          "north" : TOWN"6",
          "east" : TOWN"8",

   ]));

}


