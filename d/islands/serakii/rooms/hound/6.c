#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"east" : HOUND"4",
"west" : HOUND"19",
"north" : HOUND"16",

]));

}
