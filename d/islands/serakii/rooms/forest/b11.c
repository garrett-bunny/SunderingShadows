#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";

void create(){
   ::create();

set_exits(([
"north" : FOR"b13",
"southwest" : FOR"b9",
"southeast" : FOR"b10",

]));

}
