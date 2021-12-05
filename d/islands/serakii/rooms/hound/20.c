#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"west" : HOUND"21",
"south" : HOUND"22",

]));

}

void reset(){
   ::reset();
   if(!present("catapult")){
      new(OBJ"catapult.c")->move(TO);
   }
}
