//
// _destall.c
//
// Finds all instances of file_name given and destructs them.
//
// -- Tlaloc -- 10/28/21
//

#include <std.h>
#include <security.h>

inherit DAEMON;

mapping envs = ([  ]);

int cmd_destall(string str)
{
    object *obs;
    
    obs = objects( (: base_name($1) == $(str) :) );
    map_array(obs, (: envs[$1] = environment($1) :));
    
    seteuid(getuid(this_player()));
    
    foreach(object ob in obs)
    {
        if(!catch(destruct(ob, 1)))
        {
            write("You dest "+ob->query_short()+".");
        }
    }
    
    seteuid(UID_SYSTEM);
    
    //printf("%O\n", envs);
    
    return 1;
}   