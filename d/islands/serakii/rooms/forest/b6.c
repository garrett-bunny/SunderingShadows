#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"west" : FOR"b7",
"northeast" : FOR"b23",
"southeast" : FOR"b5",

]));

}
