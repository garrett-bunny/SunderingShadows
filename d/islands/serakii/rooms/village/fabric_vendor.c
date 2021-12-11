#include <std.h>
#include "../../serakii.h"

inherit STORAGE"construction.c";

void create(){
   ::create();
   set_exits(([

          "north" : TOWN"tailors_shop",
          "south" : TOWN"leatherwork",
          "northwest" : TOWN"foyer",
          "southwest" : TOWN"metals_vendor",
          "west" : TOWN"garden",
          
   ]));

}
