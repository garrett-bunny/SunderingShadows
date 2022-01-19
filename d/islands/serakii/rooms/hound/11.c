#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";

void create(){
   ::create();

set_exits(([
"north" : HOUND"12",
"west" : HOUND"10",
"south" : HOUND"9",

]));

}
