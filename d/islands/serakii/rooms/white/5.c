#include <std.h>
#include "../../serakii.h"

inherit STORAGE"white_hall.c";



void create(){
   ::create();

set_long(::query_long()+"\n%^C247%^You can see a room to the south that has stairs. There is also a giant gate to the north, but it has been sealed shut%^CRST%^\n");

set_exits(([
"southeast" : WHITE"4",
"southwest" : WHITE"6",
"south" : WHITE"7",

]));


}
