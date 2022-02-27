#include <std.h>
#include "../../serakii.h"

inherit STORAGE"beach.c";
object ob;


void create(){
   ::create();
   set_long(::query_long()+"\n%^C247%^Dominating the whole section of beach is a giant archway made of some %^C093%^unknown metal%^C247%^.%^CRST%^\n");




set_exits(([
"west" : HOUND"b11",

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
	   add_exit( FOR"1", "portal" );
        return 1;
    }
	
       tell_object(TP,"%^BLACK%^%^BOLD%^Power what? the archway?\n%^RESET%^");
    return 1;
}