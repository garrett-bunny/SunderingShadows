#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"north" : HOUND"22",
"west" : HOUND"25",


]));

}

void reset(){
   ::reset();
   if(!present("arbalest")){
      new(OBJ"arbalest.c")->move(TO);
   }
}
