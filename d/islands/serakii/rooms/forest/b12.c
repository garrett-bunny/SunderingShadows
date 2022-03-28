#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"east" : FOR"b13",

]));


}
void reset(){
   ::reset();
   if(!present("construct")){
      new(OBJ"hconstruct.c")->move(TO);
   }
}
