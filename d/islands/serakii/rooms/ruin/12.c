#include <std.h>
#include "../../serakii.h"

inherit STORAGE"ruins.c";

void create(){
   ::create();


   set_exits(([


         "west" : RUINS"1",
          "northeast" : RUINS"14",

   ]));

}
