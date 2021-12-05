
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"dock.c";

void create(){
   ::create();
   set_exits(([

	  "northwest" : DOCK"4",
      "southeast" : DOCK"3",
	  "southwest" : DOCK"1",

   ]));

}
