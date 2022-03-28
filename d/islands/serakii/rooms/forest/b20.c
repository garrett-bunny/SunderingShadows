#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"west" : FOR"b19",
"northwest" : FOR"b21",


]));

}
