#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"south" : FOR"b15",

]));

}

void reset(){
   ::reset();
   if(!present("archway")){
      new(OBJ"archway.c")->move(TO);
   }
}

