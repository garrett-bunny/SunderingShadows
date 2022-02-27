
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
"north" : FOR"6",
"east" : FOR"7",
"west" : FOR"4",

]));

}

