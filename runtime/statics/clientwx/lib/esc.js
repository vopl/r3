var xml = function(str)
{
        str = ""+str;
        str = str.replace(/\&/gm,'&amp;');
        str = str.replace(/"/gm,'&quot;');
        str = str.replace(/'/gm,'&apos;');
        str = str.replace(/\</gm,'&lt;');
        str = str.replace(/\>/gm,'&gt;');
        return str;
}

var str = function(str)
{
        str = ""+str;
        str = str.replace(/\\/gm,'\\\\');
        str = str.replace(/'/gm,'\\\'');
        str = str.replace(/"/gm,'\\\"');
        str = str.replace(/[\b]/gm,'\\b');
        str = str.replace(/\f/gm,'\\f');
        str = str.replace(/\n/gm,'\\n');
        str = str.replace(/\r/gm,'\\r');
        str = str.replace(/\t/gm,'\\t');
        return str;
}


var isIdent = function(name)
{
        return (""+name).match(/^([\$a-zA-Zа-яёА-ЯЁ_])([\$a-zA-Zа-яёА-ЯЁ0-9_])*$/);
}

var ident = function(name)
{
        if(!isIdent(name))
                return '"'+str(name)+'"';
        return name;
}
