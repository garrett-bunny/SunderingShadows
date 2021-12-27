
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"dock.c";

void create(){
   ::create();
   set_exits(([

	  "northeast" : DOCK"7",
	  
   ]));

}
    void reset(){
   ::reset();
   if(!present("incense")){
      new(OBJ"dock_burner.c")->move(TO);
   }
}

