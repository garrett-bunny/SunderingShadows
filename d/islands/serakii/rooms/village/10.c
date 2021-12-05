


#include <std.h>
#include "../../serakii.h"

inherit STORAGE"village.c";

void create(){
   ::create();
   set_exits(([


		  "north" : TOWN"11",
		  "west" : TOWN"13",


   ]));

}

void reset(){
   ::reset();
   if(!present("statue")){
      new(OBJ"town_statue.c")->move(TO);
   }
}


