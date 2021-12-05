


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_long(::query_long()+"%^C058%^\nTo the south stands a small ruined church.%^CRST%^\n");
   set_exits(([

		  "west" : TOWN"8",
		  "south" : TOWN"church",

   ]));

}


