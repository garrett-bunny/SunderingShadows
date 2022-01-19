#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"northeast" : HOUND"19",
"west" : HOUND"27",
"east" : HOUND"20",
"south" : HOUND"24",
"west" : HOUND"28",

]));

}

void reset(){
   ::reset();
   if(!present("arbalest")){
      new(OBJ"arbalest.c")->move(TO);
   }
}
