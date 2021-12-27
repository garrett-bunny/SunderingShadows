#include <std.h>
#include "../../serakii.h"

inherit STORAGE"tree_lined.c";

void create(){
   ::create();


   set_long(::query_long()+"\n%^C253%^To the south is a massive white stone tower.%^CRST%^\n");


   set_exits(([

          "north" : RUINS"2",
          "south" : WHITE"5",
          "east" : RUINS"12",
         "west" : RUINS"11",
   ]));

}
