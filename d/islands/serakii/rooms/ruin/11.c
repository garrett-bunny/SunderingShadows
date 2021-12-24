#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


         "east" : RUINS"1",
          "northwest" : RUINS"13",

   ]));

}
