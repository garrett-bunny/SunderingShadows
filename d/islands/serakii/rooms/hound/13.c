
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"east" : HOUND"12",
"west" : HOUND"13",
"south" : HOUND"10",

]));

}
