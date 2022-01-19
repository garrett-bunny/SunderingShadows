#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"east" : HOUND"10",
"west" : HOUND"15",
"south" : HOUND"5",
"north" : HOUND"14",

]));

}
