#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";



void create(){
   ::create();
   set_long(::query_long()+"\n%^C247%^Dominating the whole section of beach is a giant archway made of some %^C093%^unknown metal%^C247%^.%^CRST%^\n");




set_exits(([
"west" : HOUND"b11",

]));

}


void reset(){
   ::reset();
   if(!present("archway")){
      new(OBJ"archway.c")->move(TO);
   }
}

