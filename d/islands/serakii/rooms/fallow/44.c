
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"north" : FALLOW"41",





]));

}

void reset(){
   ::reset();
   if(!present("scarecrow")){
      new(MOBS"scarecrow.c")->move(TO);
   }
}
