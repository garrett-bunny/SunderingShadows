//
// _whoip.c
//
// Similar to who but displays ip numbers.
//
// USAGE : whoip
//         whoip <player name>
//         whoip <ip number>
//
// Only available to admins.
//
// -- Tlaloc -- 10/28/21
//

#include <std.h>
#include <security.h>
#include <daemons.h>

#define DIVIDER "=======================================================================\n"

int cmd_whoip(string str)
{
    object user;
    string name;
    int x;
    
    if(!str)
    {
        printf("%s:  Local Time is: %s)\n%s", mud_name(), ctime(time()), DIVIDER);
        printf("Name              IP number          IP name\n" + DIVIDER);
        
        foreach(user in users())
        {
            name = user->query_name();
            
            if(!strlen(name))
                name = "(login)";
            else
                name = capitalize(name);
            
            printf("%-17s %-18s %-25s\n", name, query_ip_number(user), query_ip_name(user));
        }
        
        x = sizeof(users());
        printf("%sCurrently there %s %d player%s.\n", DIVIDER, x > 1 ? "are" : "is", x, x > 1 ? "s" : "");
        
        return 1;
    }

    return 1;
}    
        