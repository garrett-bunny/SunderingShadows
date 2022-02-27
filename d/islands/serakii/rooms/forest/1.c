

#include <std.h>
#include "../../serakii.h"

inherit STORAGE"mist_forest.c";



void create(){
   ::create();


set_exits(([
"west" : FOR"2",
"south" : FOR"9",

]));

}
void reset(){
   ::reset();
   if(!present("archway")){
      new(OBJ"archway.c")->move(TO);
   }
}


void init() {
    ::init();
    add_action("power_fun", "power");

}

int power_fun(string str,object who){

object ob;

    if(!str) {
       tell_object(TP,"%^BLACK%^%^BOLD%^Power what? the archway?\n%^RESET%^");
       return 1;
    }

    if(str == "archway"){
        ob=present("shard of soul",TP);
        if(!ob) return notify_fail("\nYou have nothing you could use to power the archway.\n");
        //ob->remove();
       tell_object(TP,"%^YELLOW%^%^BOLD%^The archway powers up and a portal appears\n%^RESET%^");
	   add_exit( HOUND"b12", "portal" );
        return 1;
    }
	
       tell_object(TP,"%^BLACK%^%^BOLD%^Power what? the archway?\n%^RESET%^");
    return 1;
}

