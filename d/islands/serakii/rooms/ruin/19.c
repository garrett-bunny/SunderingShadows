#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


          "east" : RUINS"5",
          "south" : RUINS"17",
          "west" : RUINS"28",

   ]));

}
