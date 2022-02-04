
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"dock.c";

void create(){
   ::create();
   set_exits(([

	  "northeast" : DOCK"6",
      "southwest" : DOCK"8",

   ]));

}
