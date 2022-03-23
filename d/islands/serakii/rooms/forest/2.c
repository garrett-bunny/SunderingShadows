
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
"north" : FOR"3",
"east" : FOR"1",
"west" : FOR"12",

]));

}

