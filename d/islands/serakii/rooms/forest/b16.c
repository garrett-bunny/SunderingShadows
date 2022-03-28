#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"southwest" : FOR"b10",
"east" : FOR"b17",

]));

}
