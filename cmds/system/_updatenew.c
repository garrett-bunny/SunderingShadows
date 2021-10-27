/*
  _update.c
  
  Tlaloc's attempt at rewriting the update command with
  new functionality.
  
  -- Tlaloc --
*/

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_updatenew(string str)
{
    string file, tmp, *flags;
    int deep;
    object ob, *obs;
    
    sscanf(str, "%s %s", file, tmp);
    
    tell_object(this_player(), "file = " + file);
    
    if(strlen(tmp))
        flags = explode(tmp, " ");
    
    if(sizeof(flags))
    {
        if(member_array("r", flags) >= 0)
            deep = 1;
        if(member_array("R", flags) >= 0)
            deep = 2;
        if(member_array("z", flags) >= 0)
            deep = 3;
    }
    
    if(!file || file == "here")
        file = "/" + file_name(environment(this_player()));
    
    if(file_size(file) == -2 && file_size(file + ".c") < 0)
    {
        write("Update : file is a directory.\n");
        return 1;
    }
    
    obs = ({  });
    
    if(ob = find_object(file))
    {
        obs = filter_array(all_inventory(ob), (: objectp($1) :));
        foreach(object obj in obs)
            obj->move("/d/shadowgate/void");
    }
    
    if(file[<2..<1] != ".c")
        file += ".c";
    
    seteuid(getuid(previous_object()));
    
    if(do_update(file, deep) < time())
        write(file + " : No update necessary.");
    
    seteuid(UID_SYSTEM);
    
    foreach(object obj in obs)
        obj->move(ob);
}

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
            if(deep)
            {
                foreach(string fn in inherit_list(ob))
                    do_update(fn, deep > 1 ? deep : 0);
            }
                
            destruct(ob, 1);
        }
    }
    
    load_object(file);
    if(file[0] != '/')
        file = "/" + file;
    
    write(file + " : updated and loaded.");
    
    return time();
}

   