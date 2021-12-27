#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([

          "south" : RUINS"9",

   ]));

}

void reset(){
   ::reset();
   if(!present("construct")){
      new(OBJ"construct.c")->move(TO);
   }
}
