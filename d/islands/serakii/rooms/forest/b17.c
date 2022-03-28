#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"north" : FOR"b18",
"west" : FOR"b16",

]));

}
