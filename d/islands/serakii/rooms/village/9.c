


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([

		  "west" : TOWN"6",
		  "south" : TOWN"8",

   ]));

}


