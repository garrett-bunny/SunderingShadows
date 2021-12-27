
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"north" : FALLOW"23",
"south" : FALLOW"33",
"southwest" : FALLOW"32",



]));

}

