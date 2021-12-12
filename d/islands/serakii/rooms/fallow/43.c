
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"north" : FALLOW"40",
"southeast" : FALLOW"45",




]));

}

