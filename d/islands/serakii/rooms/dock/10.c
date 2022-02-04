
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"dock.c";

void create(){
   ::create();
   set_exits(([

	  "east" : DOCK"9",
	  
   ]));

}
