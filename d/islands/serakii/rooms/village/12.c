


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([


		  "south" : TOWN"13",
		  "east" : TOWN"11",


   ]));

}

void reset(){
   ::reset();
   if(!present("statue")){
      new(OBJ"town_statue.c")->move(TO);
   }
}


