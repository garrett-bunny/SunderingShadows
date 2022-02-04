
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"dock.c";

void create(){
   ::create();
   set_exits(([

	  "north" : DOCK"5",
      "southwest" : DOCK"7",

   ]));

}
