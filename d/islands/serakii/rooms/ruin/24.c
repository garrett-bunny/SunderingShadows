#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([

          "west" : RUINS"14",
          "north" : RUINS"23",

   ]));

}
