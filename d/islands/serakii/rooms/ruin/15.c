#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


          "north" : RUINS"17",
          "south" : RUINS"13",
          "west" : RUINS"26",
          "east" : RUINS"3",

   ]));

}
