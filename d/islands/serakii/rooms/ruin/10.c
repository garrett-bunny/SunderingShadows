#include <std.h>
#include "../../serakii.h"

inherit STORAGE"tree_lined.c";

void create(){
   ::create();


   set_exits(([

          // "east" : BLACK"1",
         "west" : RUINS"9",

   ]));

}
