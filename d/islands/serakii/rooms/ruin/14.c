#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([

         "east" : RUINS"24",
          "north" : RUINS"16",
          "southwest" : RUINS"12",

   ]));

}
