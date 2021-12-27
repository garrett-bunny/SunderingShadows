#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


          "east" : RUINS"15",
          "north" : RUINS"27",
          "south" : RUINS"25",

   ]));

}
