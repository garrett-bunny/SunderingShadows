// Library Instructor - LoKi - 2022

#include <std.h>
#include <daemons.h>
inherit NPC;

int x,y,w,q;    
string prof_name, prof_outfit, prof_type;


void create() {
   object ob;
   ::create();
   set_name("professor"); 
   set_short("professor"); 
   set_id(({ "professor"})); 
   set_long("professor"); 
   set_race("human");
   set_stats("intelligence",14);
   set_stats("wisdom",18);
   set_stats("strength",20);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);

   set_class("mage");   
   set_mlevel("mage",30);
   set_guild_level("mage",30);
   
   set_alignment(2); 
   set_gender("male"); 
   set_size(3);
   set_exp(0); 
   set_overall_ac(-10); 
   set_hd(30,10);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0); 

   set_property("no bows",1); 
   set_spoken("wizish"); 
   make_me();

}



void make_me(){
	
    string* prof_names = ({ "%^C068%^Byron Harstrem%^CRST%^", "%^C139%^Thomas Kilgrav%^CRST%^", "%^C206%^Percival Nell%^CRST%^","%^C037%^Jacob Ascelin%^CRST%^"});
    string* prof_outfits = ({ "%^C240%^dark gray robe%^CRST%^", "%^C055%^formal attire%^CRST%^", "%^C251%^chalk covered cassock%^CRST%^","%^C060%^adventurer's gear%^CRST%^"});
    string* prof_types = ({ "dragons", "souls", "history","gods"});	

    prof_name = prof_names[random(sizeof(prof_names))];    
	prof_outfit = prof_outfits[random(sizeof(prof_outfits))];    
	prof_type = prof_types[random(sizeof(prof_types))];

   set_short("Professor " +prof_name+ " "); 
   set_id(({ "professor",prof_name,})); 
   set_long("Professor " +prof_name+ " is dressed in " +prof_outfit+ ". He is young, perhaps in his early thirties and stands ready to teach lessons at the library. When not teaching he stands near the lectern, shuffling through his papers."); 

}

void go_home(object to)
{
    if (!objectp(to)) {
        return;
    }
    tell_room(environment(to), "The professor leaves the classroom");
    to->move("/d/shadowgate/void");
    to->remove();
}

void heart_beat(){
    ::heart_beat();
    x = random(5);
        y++;
    if(x == 1){
        if(y > 10){ //one lesson every 10 minutes if people are here
            teach_a_lesson();
                return;
        }
    }

}

int teach_a_lesson(){
y = 0;
teach_the_lesson(0);
return 1;
}

void teach_the_lesson(){
	
	
	switch(prof_type){
		case "dragons": 
    		    dragon2_lesson_1(TP,0);
		break;
		
		case "souls": 
		    souls_lesson_1(TP,0);
		break;
		
		case "history": 
		    history_lesson_1(TP,0);
		break;
		
		case "gods": 
		    gods_lesson_1(TP,0);
		break;

		default:
			force_me("say I have nothing to teach!");
		break;
    }
}

void catch_say(string message){
    if(strsrch(message,"24601") != -1) {
      call_out("reply_24601",1,TP,message);
    }
}

void reply_24601(string msg, object who){
    tell_room(ETO,"x = "+x+" and y = "+y+" \n");
}

void souls_lesson_1(object tp,int num){
            switch(num){
                case(0):
                    tell_room(ETP,"%^C152%^The professor steps up to the %^C059%^lectern%^C152%^.%^CRST%^\n");
					force_me("pose %^C097%^standing at the lectern teaching%^CRST%^");
                break;
                case(1):
		            force_me("say Settle down everyone, please take your seats.");
                    tell_room(ETP,"%^C144%^The professor shuffles his %^C193%^parchments %^C144%^around and waits.%^CRST%^\n");                    
                break;
                case(2):
                    tell_room(ETP,"%^C075%^students slowly sit on %^C094%^benches %^C075%^and hush.%^CRST%^\n");
		            force_me("say I am professor "+prof_name+" and we are learning about "+prof_type+ " today.");
                break;
                case(3):
		            force_me("say Specifically we are learning about the Lysaran shrine in the ruins. The shrine was installed through the activism of Warden Malcolm and Captain Sophia in Growingdays of 760.");
                    tell_room(ETP,"\n");
                break;
                case(4):
		            force_me("say The shrine releases a soul that has been trapped through arcane or fell means. This has been important for corpses trapped in the ruins of Karon'dale as the attack has indeed trapped them.");
                    tell_room(ETP,"\n");
                break;
                case(5):
		            force_me("say The act also releases a small amount of energy, and I surmise that if enough souls are released a great amount of energy could be released. This is not possible though with corpses as the process takes time.");
                    tell_room(ETP,"\n");
                break;
                case(6):
				    force_me("say thank you, no questions today, meet me for office hours later.");
                    tell_room(ETP,"%^C152%^The professor gathers up his papers and steps away from the lectern.%^CRST%^\n");
					force_me("pose clear");
                    go_home(TO);
                break;
            return;
                }
    num++;
    call_out("souls_lesson_1",5,tp,num);
    return;
}

void dragons_lesson_1(object tp,int num){
            switch(num){
                case(0):
                    tell_room(ETP,"%^C152%^The professor steps up to the %^C059%^lectern%^C152%^.%^CRST%^\n");
					force_me("pose %^C097%^standing at the lectern teaching%^CRST%^");
                break;
                case(1):
		            force_me("say Settle down everyone, please take your seats.");
                    tell_room(ETP,"%^C144%^The professor shuffles his %^C193%^parchments %^C144%^around and waits.%^CRST%^\n");                    
                break;
                case(2):
                    tell_room(ETP,"%^C075%^students slowly sit on %^C094%^benches %^C075%^and hush.%^CRST%^\n");
		            force_me("say I am professor "+prof_name+" and we are learning about "+prof_type+ " today.");
                break;
                case(3):
		            force_me("say Specifically we are learning about the blue dragon Tepphaal.");
                    tell_room(ETP,"\n");
                break;
                case(4):
		            force_me("say Tepphaal is originally not from Serakii though after the silence has made its lair deep in the mountains to the west.");
                    tell_room(ETP,"\n");
                break;
                case(5):
		            force_me("say It is said that she has convinced the kobolds there that she is the reincarnation of Kurtulmak. She was wounded gravely by Vasha years ago and the cult has been tending to her while she rests. The library feels that she is still asleep, and is not a danger to the Black Keep.");
                    tell_room(ETP,"\n");
                break;
                case(6):
				    force_me("say thank you, no questions today, meet me for office hours later.");
                    tell_room(ETP,"%^C152%^The professor gathers up his papers and steps away from the lectern.%^CRST%^\n");
					force_me("pose clear");
                    go_home(TO);
                break;
            return;
                }
    num++;
    call_out("dragons_lesson_1",5,tp,num);
    return;
}

void history_lesson_1(object tp,int num){
            switch(num){
                case(0):
                    tell_room(ETP,"%^C152%^The professor steps up to the %^C059%^lectern%^C152%^.%^CRST%^\n");
					force_me("pose %^C097%^standing at the lectern teaching%^CRST%^");
                break;
                case(1):
		            force_me("say Settle down everyone, please take your seats.");
                    tell_room(ETP,"%^C144%^The professor shuffles his %^C193%^parchments %^C144%^around and waits.%^CRST%^\n");                    
                break;
                case(2):
                    tell_room(ETP,"%^C075%^students slowly sit on %^C094%^benches %^C075%^and hush.%^CRST%^\n");
		            force_me("say I am professor "+prof_name+" and we are learning about "+prof_type+ " today.");
                break;
                case(3):
		            force_me("say Specifically we are learning about the construction of the three keeps.");
                    tell_room(ETP,"\n");
                break;
                case(4):
		            force_me("say The Voice in 622, back when there was a full Voice, ordered the construction of the three keeps and sourced stone from across the realm. The designs for the three keeps and the stones were specifically chosen from some ancient manuscript that was found in the library,");
                    tell_room(ETP,"\n");
                break;
                case(5):
		            force_me("say The three standards were consecrated and placed at the top of each tower, providing thier protective measures. Those standards of course are lost now but there is hope they can be found and replaced on the tower tops.");
                    tell_room(ETP,"\n");
                break;
                case(6):
				    force_me("say thank you, no questions today, meet me for office hours later.");
                    tell_room(ETP,"%^C152%^The professor gathers up his papers and steps away from the lectern.%^CRST%^\n");
					force_me("pose clear");
                    go_home(TO);
                break;
            return;
                }
    num++;
    call_out("history_lesson_1",5,tp,num);
    return;
}

void gods_lesson_1(object tp,int num){
            switch(num){
                case(0):
                    tell_room(ETP,"%^C152%^The professor steps up to the %^C059%^lectern%^C152%^.%^CRST%^\n");
					force_me("pose %^C097%^standing at the lectern teaching%^CRST%^");
                break;
                case(1):
		            force_me("say Settle down everyone, please take your seats.");
                    tell_room(ETP,"%^C144%^The professor shuffles his %^C193%^parchments %^C144%^around and waits.%^CRST%^\n");                    
                break;
                case(2):
                    tell_room(ETP,"%^C075%^students slowly sit on %^C094%^benches %^C075%^and hush.%^CRST%^\n");
		            force_me("say I am professor "+prof_name+" and we are learning about "+prof_type+ " today.");
                break;
                case(3):
		            force_me("say Specifically we are learning about the rise of Velik.");
                    tell_room(ETP,"\n");
                break;
                case(4):
		            force_me("say Velik was originally an elven slave named Minienal in the slave city of Tonovi. There was a violent revolt in 752 that resulted in a siege on the city. ");
                    tell_room(ETP,"\n");
                break;
                case(5):
		            force_me("say Minienal faced down a great undead beast called the Nightwalker and when it was felled Minienal took on the divine essence and became a demi god of freedom and revolution.");
                    tell_room(ETP,"\n");
                break;
                case(6):
				    force_me("say thank you, no questions today, meet me for office hours later.");
                    tell_room(ETP,"%^C152%^The professor gathers up his papers and steps away from the lectern.%^CRST%^\n");
					force_me("pose clear");
                    go_home(TO);
                break;
            return;
                }
    num++;
    call_out("gods_lesson_1",5,tp,num);
    return;
}
