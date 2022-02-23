// Lysara's Font - Serakii - Commissioned by Malcolm and Sophia - LoKi 2022

#include <std.h>
#include "../serakii.h"
inherit OBJECT;

void create(){
    ::create();
    set_name("Lysara's Font");
    set_id(({"font","lysara's font","fountain"
,"altar","stone font","stone shrine"}));
    set_short("Stone Shrine");
    set_long("This shrine consists of a small stome bowl of water sitting to the side of a slab of rock the size of a small bed. The stone has been smoothed to an almost glass like texture and stands in contrast to the ruins around it. Along the slab is writing that you could >read<. The stone bowl seems to be constantly filled with water though you are unsure how. The whole shrine seems to radiate calm and peace.%^RESET%^");
    set_weight(10000);
    set_value(5000);
    set_property("no animate",1);
}

void init() {
    ::init();
    add_action("read_fun", "read");
    add_action("sanctify_fun","sanctify")
}

int read_fun(string str,object who){

    if(!str) {
       tell_object(TP,"%^BLACK%^%^BOLD%^Read what?\n%^RESET%^");
    return 1;
}

    if((str == "writing") || (str == "shrine")){
        tell_object(TP,"%^RED%^you read..%^RESET%^");
        return 1;
    }
    return 0;
}