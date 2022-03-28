#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"south" : FOR"b7",
"northwest" : FOR"b9",
"northeast" : FOR"b10",

]));

}
