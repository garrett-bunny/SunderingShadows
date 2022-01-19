#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([

"south" : HOUND"27",
"east" : HOUND"21",

]));

}

void reset(){
   ::reset();
   if(!present("catapult")){
      new(OBJ"catapult.c")->move(TO);
   }
}
