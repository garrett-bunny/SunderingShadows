#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


          "east" : RUINS"13",
          "north" : RUINS"26"

   ]));

}

void reset(){
   ::reset();
   if(!present("font")){
      new(OBJ"font.c")->move(TO);
   }
   if(!present("spirit_of_the_shrine")){
      new(MOBS"shrine_spirit.c")->move(TO);
   }
}