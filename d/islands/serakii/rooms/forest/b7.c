#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"south" : FOR"b2",
"north" : FOR"b8",
"east" : FOR"b6",

]));

}
