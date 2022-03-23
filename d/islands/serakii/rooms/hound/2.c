#include <std.h>
#include "../../serakii.h"

inherit STORAGE"hound_camp.c";



void create(){
   ::create();


set_exits(([
"south" : HOUND"1",
"north" : HOUND"4",
"tent" : HOUND"tent1",

]));

}
