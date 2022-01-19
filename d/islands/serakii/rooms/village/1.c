
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([

	  "southwest" : DOCK"9",
          "northeast" : TOWN"2",
	  
   ]));

}
