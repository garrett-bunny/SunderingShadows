


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
set_long(::query_long()+"%^C059%^\nTo the south is a cozy little church.%^CRST%^\n");
   set_exits(([

		  "west" : TOWN"8",
		  "south" : TOWN"church",

   ]));

}


