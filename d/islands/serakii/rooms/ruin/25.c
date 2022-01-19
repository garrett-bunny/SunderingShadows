#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


          "east" : RUINS"13",
          "north" : RUINS"26"

   ]));

}
