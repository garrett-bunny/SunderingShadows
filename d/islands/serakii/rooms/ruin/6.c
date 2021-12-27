#include <std.h>
#include "../../serakii.h"

inherit STORAGE"tree_lined.c";

void create(){
   ::create();

   set_long(::query_long()+"\n%^C241%^To the north is a massive closed and barred gate%^CRST%^\n");


   set_exits(([

         // "north" : CAER"1",
        "south" : RUINS"5",
         "east" : RUINS"9",
          "west" : RUINS"7",

   ]));

}
