
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"dock.c";

void create(){
   ::create();
   set_exits(([

          "northeast" : DOCK"2",
         "west" : "/d/shadow/virtual/sea/serakii.dock",


   ]));

}
