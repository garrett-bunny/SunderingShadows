#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([

"north" : HOUND"28",
   "south" : HOUND"26",
"east" : HOUND"24",

]));

}

void reset(){
   ::reset();
   if(!present("catapult")){
      new(OBJ"catapult.c")->move(TO);
   }
}
