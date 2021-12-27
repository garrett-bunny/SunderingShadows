#include <std.h>
#include "../../serakii.h"

inherit STORAGE"tree_lined.c";

void create(){
   ::create();


   set_exits(([

         // "north" : CAER"1",
        "south" : RUINS"5",
         "east" : RUINS"9",
          "west" : RUINS"7",

   ]));

}
