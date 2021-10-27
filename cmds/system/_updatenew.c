/*
  _update.c
  
  Tlaloc's attempt at rewriting the update command with
  new functionality.
  
  FLAGS as FOLLOWS
  -r - ignore inherited files
  -R - update all inherited files
  -z - update only inherited files "older" than the target
  
  -- Tlaloc --
*/

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_updatenew(string str)
{
    string file, *files, tmp, *flags, *input;
    int deep, dirupdate;
    object ob, *obs;
    
    input = explode(str, " ");
    
    if(str == "*")
    {
        file = resolv_path(this_player()->get_path(), str);
        files = get_dir(file + "/*.c");
        
        foreach(string temp in files)
            do_update(file + "/" + temp, 0);
        
        return 1;
    }
                
    file = resolv_path(this_player()->get_path(), input[0]);
    tell_object(this_player(), "file = " + file);
    
    if(sizeof(input) > 1)
        input = input[1..];
    else
        input = ({  });
    
    if(sizeof(input))
    {
        if(member_array("-r", input) >= 0)
            deep = 1;
        if(member_array("-R", input) >= 0)
            deep = 2;
        if(member_array("-z", input) >= 0)
            deep = 3;
        if(member_array("*", input) >= 0)
            dirupdate = 1;           
    }
    
    if(!file || file == "here")
        file = "/" + file_name(environment(this_player()));
    
    if(file_size(file) == -2 && file_size(file + ".c") < 0)
    {
        write("Update : file is a directory.\n");
        return 1;
    }
    
    if(file[<2..<1] != ".c")
        file += ".c";
    
    seteuid(getuid(previous_object()));
    
    if(do_update(file, deep) < time())
        write(file + " : No update necessary.");
    
    seteuid(UID_SYSTEM);
        
    return 1;
}

int do_update(string file, int deep)
{
    mixed *info;
    object ob, *obs;
    int tmp, last_inherit;
    
    last_inherit = 0;

    if(ob = find_object(file))
    {
        obs = filter_array(all_inventory(ob), (: objectp($1) :));
        foreach(object obj in obs)
            obj->move("/d/shadowgate/void");
    }
    
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
    
    if(!catch(load_object(file)))
        write(file + " : updated and loaded.");
    else
        write(file + " : ERROR in loading file.");
        
    if(file[0] != '/')
        file = "/" + file;
    
    foreach(object obj in obs)
        obj->move(ob);
    
    return time();
}

   