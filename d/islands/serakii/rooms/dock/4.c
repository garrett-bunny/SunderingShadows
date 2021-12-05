
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"dock.c";

void create(){
   ::create();
   set_exits(([

	  "northwest" : DOCK"9",
	  "southeast" : DOCK"2",
	  
   ]));

}
