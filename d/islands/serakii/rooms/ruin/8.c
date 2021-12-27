#include <std.h>
#include "../../serakii.h"

inherit STORAGE"tree_lined.c";

void create(){
   ::create();


   set_exits(([

          // "west" : RED"1",
         "east" : RUINS"7",

   ]));

}
