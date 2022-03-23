
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([

    "east" : FOR"31",
    "west" : FOR"29",

]));

}

void reset(){
   ::reset();
   if(!present("chunk")){
      new(OBJ"druid_chunk.c")->move(TO);
   }
}

