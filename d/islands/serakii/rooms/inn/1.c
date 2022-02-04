#include <std.h>
#include "../../serakii.h"

inherit STORAGE"outside_inn.c";



void create(){
   ::create();
   set_long(::query_long()+"\n%^C094%^The door to the inn stands before you.%^CRST%^\n");


set_exits(([
"inn" : INN"inn",
"northeast" : INN"2",
"southwest" : ROAD"1",

]));

    set_door("door",INN"inn","inn",0);

}
