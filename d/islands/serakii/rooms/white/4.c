#include <std.h>
#include "../../serakii.h"

inherit STORAGE"white_hall.c";



void create(){
   ::create();



set_exits(([
"northwest" : WHITE"5",
"south" : WHITE"2",

]));


}
