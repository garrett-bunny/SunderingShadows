#include <std.h>
#include "../../serakii.h"

inherit STORAGE"construction.c";

void create(){
   ::create();
   set_exits(([

         "out" : TOWN"3",
          "east" : TOWN"wood_vendor",
          "west" : TOWN"wood_shop",
          "south" : TOWN"garden",
          "southeast" : TOWN"fabric_vendor",
          "southwest" : TOWN"herb_vendor",

          
   ]));

}
