//
// _ud.c
//
// Passes through to _update.c
//
// -- Tlaloc --
//

#include <std.h>

inherit DAEMON;

int cmd_ud(string str)
{
    object cmd;
    
    if(catch(cmd = find_object("/cmds/system/_update.c")))
    {
        write("Failure to load update command.");
        return 1;
    }
    
    cmd->cmd_update(str);
    
    return 1;
}