/*
  _update.c
  
  Tlaloc's attempt at rewriting the update command with
  new functionality.
  
  -- Tlaloc --
*/

#include <std.h>

inherit DAEMON;

int do_update(string file, int deep)
{
    mixed *info;
    object ob;
    int tmp, last_inherit;
    
    last_inherit = 0;
    
    if(deep == 3)
    {
        info = stat(file);
        ob = load_object(file);
    
        foreach(string fn in inherit_list(ob))
        {
            tmp = do_update(fn, deep > 1 ? deep : 0);
            last_inherit = tmp > last_inherit ? tmp : last_inherit;
        }
    
        if(sizeof(info))
        {
            last_inherit = info[1] > last_inherit ? info[1] : last_inherit;
            //If object is not out of date
            if(info[2] > last_inherit)
                return info[2];
        }
        
        destruct(ob, 1);
    }
    
    else
    {
        ob = find_object(file);
        
        if(ob)
        {
            foreach(string fn in inherit_list(ob))
                do_update(fn, deep > 1 ? deep : 0);
                
            destruct(ob, 1);
        }
    }
    
    load_object(file);
    if(file[0] != '/')
        file = "/" + file;
    
    write(file + " : updated and loaded.\n");
    
    return time();
}   