#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"north" : HOUND"21",
"west" : HOUND"27",
"east" : HOUND"22",
"south" : HOUND"25",

]));

}

void reset(){
   ::reset();
   if(!present("arbalest")){
      new(OBJ"arbalest.c")->move(TO);
   }
}
