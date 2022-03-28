#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"northeast" : FOR"b11",
"southeast" : FOR"b8",

]));

}
