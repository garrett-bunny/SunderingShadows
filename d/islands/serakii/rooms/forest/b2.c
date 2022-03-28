#include <std.h>
#include "../../serakii.h"

inherit STORAGE"corrupted_forest.c";



void create(){
   ::create();


set_exits(([
"north" : FOR"b7",
"southwest" : FOR"b1",
"east" : FOR"b3",

]));

}
