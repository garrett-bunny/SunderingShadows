
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"southeast" : FALLOW"31",
"north" : FALLOW"20",


]));

}

