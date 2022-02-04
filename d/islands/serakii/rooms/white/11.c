#include <std.h>
#include "../../serakii.h"

inherit STORAGE"white_hall.c";



void create(){
   ::create();


set_exits(([
"north" : WHITE"10",
"southeast" : WHITE"12",


]));


}
