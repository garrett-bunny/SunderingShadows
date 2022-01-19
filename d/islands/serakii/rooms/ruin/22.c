#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([

          "south" : RUINS"23",
          "west" : RUINS"18",
          "north" : RUINS"21",

   ]));

}
