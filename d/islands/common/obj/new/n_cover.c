//Cleaned up code - and updated it a bit to help thieves - especially SC thieves more
// Cythera 5/06
// updated dex bonus from the new system. Nienne, 09/07.
#include <std.h>

inherit "/d/common/obj/armour/studded.c";


void create()
{
    ::create();
    set_name("shadow");
    set_id(({ "armor", "shadow", "mass of shadows", "night's cover", "shadows", "shadow shirt", "mass" }));
    
    set_short("%^BOLD%^%^BLACK%^N%^RESET%^%^BLUE%^i%^BOLD%^"+
        "%^BLACK%^ght%^RESET%^%^BLUE%^'%^BOLD%^%^BLACK%^s "+
        "Co%^RESET%^%^BLUE%^v%^BOLD%^%^BLACK%^er%^RESET%^");
    
    set_obvious_short("%^BOLD%^%^BLACK%^A mass of shadows%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^This dark mass bears a faint "+
        "resemblance to something akin to a short sleeved shirt.  "+
        "The mass is always %^RESET%^%^BLUE%^moving%^BOLD%^%^BLACK%^"+
        " and withering about, making it difficult to determine the exact "+
        "shape.  Woven from the substances of "+
        "%^RESET%^s%^BOLD%^%^BLACK%^h%^RESET%^a%^BOLD%^%^BLACK%^d"+
        "%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^w%^RESET%^%^BLUE%^s%^BOLD%^"+
        "%^BLACK%^, that ethereal substance which lingers between "+
        "%^BOLD%^%^WHITE%^light%^BLACK%^ and %^BOLD%^%^BLUE%^darkness"+
        "%^BOLD%^%^BLACK%^, shades of %^RESET%^gray %^BOLD%^%^BLACK%^and"+
        " lighter shades of black ripple through the body of this mass.  "+
        "Though light in weight, there seems to be more to this mass of"+
        " shadows than meets the eye.%^RESET%^");
        
    set_value(20000);
    set_size(-1);
    
    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("athletics",6);
    set_item_bonus("stealth",6);
    set_item_bonus("thievery",6);

    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
   
    set_lore("Manufactured only for the highest members of the Shadow-Thief's faith,"+
        " the Night's Cover was a rare prize given to those who had best demonstrated"+
        " the tenants of the Lord of Shadows. From what rare records that can be found"+
        " on the Night's Cover, since Mask's faith is rather secretive, it seems that "+
        "the mass of shadows is more akin to a suit of armor than clothing, as once "+
        "thought.  The mass is said to mold itself to the wearer's body, helping to "+
        "further the art of deception that those loyal to The King of Thieves live in."+
        "  Though the Night's Cover was jealously covered by some followers of the "+
        "Nightsinger, who felt that those of Mask had gone too far, stealing upon the "+
        "power of the night.  Even with rumors of an alliance between the two faiths, "+
        "there are those Sharrans who would slay or torture any they see with such armor on.");
  
    set_property("lore difficulty",32);
    
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func()
{
    if(ETO->is_class("thief")) 
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows pull you into their protective"+
            " embrace as you slip on the mass of shadows.");
        tell_room(EETO,"%^BOLD%^%^BLACK%^Writhing blithely the mass "+
            "of shadows forms itself to "+ETO->QCN+"'s body.",ETO);
        return 1;
    }

    tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows pull around you, offering their protection!");
    tell_room(EETO,"%^BOLD%^%^BLACK%^A mass of shadows pulls around "+ETO->QCN+"'s body.",ETO);
    return 1;
}


int remove_func()
{
    if(!ETO->is_class("thief"))
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows pull away from you, pooling into a mass.");
        tell_room(EETO,"%^BOLD%^%^BLACK%^A mass of shadows pulls away from"+
        " "+ETO->QCN+"'s body.",ETO);
        return 1;
    }
    
    tell_object(ETO,"%^BOLD%^%^BLACK%^The shadows loosen their protective"+
        " embrace as you slip out of the mass of shadows.");
    tell_room(EETO,"%^BOLD%^%^BLACK%^Writhing in annoyance the mass "+
        "of shadows pulls itself away from "+ETO->QCN+"'s body.",ETO);
    return 1;
}