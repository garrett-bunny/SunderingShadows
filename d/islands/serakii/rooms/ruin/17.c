#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


          "north" : RUINS"19",
          "south" : RUINS"15",
          "west" : RUINS"27",

   ]));

}
