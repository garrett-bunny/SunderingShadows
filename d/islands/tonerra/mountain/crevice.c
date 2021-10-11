#include <std.h>

#include "/d/islands/tonerra/areadefs.h"
inherit ROOM;

void create(){
   ::create();

  set_no_clean(1);
   set_name("dragon's home");
   set_short("Dragon' Home");
   set_long("This is the inside of the dormant volcano. The emerald dragon resides here.");
   set_smell("default","Fumes from the still raging fires below singe your nose");
   set_exits((["up":MOUNTAIN+"mount63"]));
}

void init(){
   ::init();

   add_action("search_fun", "search");
}

void search_fun(string str){
    if((str == "walls") {
		tell_object(TP, "There appears to be something behind the barrels. You could try to push one out of the way.");
	}
}}

int GoThroughDoor(){
	if(TP->query_size() > 1 {
	write("That is much to steep for you.");
	 return 0;}
    else{
     return 1;
	}}
