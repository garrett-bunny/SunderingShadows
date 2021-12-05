#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();
   ::create();
   set_long(::query_long()+"%^C058%^\nTo the southwest "+
   "you see a yard of siege engines!%^CRST%^\n");

set_exits(([
"east" : HOUND"6",
"southwest" : HOUND"21",
"south" : HOUND"20",

]));

}
