var esc_str = function(str)
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
};

var esc_isIdent = function(name)
{
	return (""+name).match(/^([\$a-zA-Zа-яёА-ЯЁ_])([\$a-zA-Zа-яёА-ЯЁ0-9_])*$/);
};

var esc_ident = function(name)
{
	if(!esc_isIdent(name))
		return '"'+esc_str(name)+'"';
	return name;
};

/////////////////////////////////////////////////
global.dumpw = function(val, deep, indent, writer)
{
	if(!indent) indent = '  ';
	var spacer = function(num, swriter)
	{
		if(swriter)
		{
			for(var k=0; k<num; k++)
				writer(indent);
			return "";
		}
		return new Array(num+1).join(indent);
	};

	if(undefined == deep) deep=10;
	if(0 > deep) deep=0;
	var recognizeXetters = false;
	var replaceFunctionBody = function(name){return "function "+name+"(){/*body dropped*/}";};
	var level=0;
	var storage = {};
	var path='VAR';
	writer('VAR=');

	var impl = function(val, deep, level, path, innl, writer)
	{

		switch(typeof(val))
		{
		case "undefined":
			writer("undefined");
			return;
		case "boolean":
		case "number":
			writer(val.toString());
			return;
		case "string":
			writer('"');
			writer(esc_str(val));
			writer('"');
			return;
		//case "xml":
			//writer(esc.xml(val.toXMLString()));
			//var str = val.toXMLString();
			//if(str) writer(str);
			//else writer('<></>');
			//return;
		case "function":
			if(val instanceof Function)
			{
				var functionName = val.name;
				for(var p in storage)
				{
					if(storage[p] === val)
					{
						writer(p);
						return;
					}
				}
				storage[path] = val;
				if(undefined != replaceFunctionBody)
				{
					writer(replaceFunctionBody(functionName));
					return;
				}
				var strVal;
				if(val.toString)
				{
					strVal = val.toString(2);
				}
				else
				{
					try
					{
						strVal = ""+val;
					}
					catch(e)
					{
						strVal = ""+e;
					}
				}
				
	/*			if(strVal.match(/\s*function\s+\w+\(\)/))
				{
					var params=[];
					for(var i=0; i<val.length; i++) params.push('_'+i);
					strVal = 'native_function('+params.join(', ')+'){}';
				}
				else
	*/			{
					strVal = strVal.replace(/^/gm, spacer(level+1));
					strVal = strVal.replace(/\s*(.*)/, '$1');
				}
				writer(strVal);
				return;
			}
			else//if(val instanceof Function)
			{
			}
		case "object":
			if(val == null)
			{
				writer("null");
				return;
			}

			for(var p in storage)
			{
				if(storage[p] === val)
				{
					writer(p);
					return;
				}
			}

			storage[path] = val;

			if(val instanceof Date)
			{
				writer("new Date('");
				writer(val.toString());
				writer("')");
				return;
			}

			if(val instanceof Array)
			{
				if(!val.length)
				{
					writer("[]");
					return;
				}
				if(level >= deep)
				{
					writer("[...]");
					return;
				}

				if(!innl)
				{
					writer("\n");
					spacer(level, writer);
				}
				writer("[\n");
				for(var i in val)
				{
					spacer(level+1, writer);
					impl(val[i], deep, level+1, path+"["+i+"]", true, writer);
					writer(",\n");
				}
				spacer(level, writer);
				writer("]");
				return;
			}

			var empty=true;
			for(var i in val)
			{
				empty = false;
				break;
			}
			
			if(empty && 'length' in val && 'callee' in val)
			{
				if(!val.length)
				{
					writer("[/*arguments*/]");
					return;
				}
				if(level >= deep)
				{
					writer("[/*arguments*/...]");
					return;
				}

				if(!innl)
				{
					writer("\n");
					spacer(level, writer);
				}
				writer("[//arguments\n");
				for(var i=0; i<val.length; i++)
				{
					spacer(level+1, writer);
					impl(val[i], deep, level+1, path+"["+i+"]", true, writer);
					writer(",\n");
				}
				spacer(level, writer);
				writer("]");
				return;
			}
			
			/*
			var strVal;
			if(val instanceof CppObject)
			{
				strVal = "CppObject of "+val.cppClass;
			}
			else
			*/
			{
				if(val.toString)
				{
					strVal = val.toString();
				}
				else
				{
					try
					{
						strVal = ""+val;
					}
					catch(e)
					{
						strVal = ""+e;
					}
				}
				strVal = strVal.replace(/\[object (\w+)\]/, '$1');
			}
			if('Object' == strVal)
			{
				strVal = '';
			}
			if(empty)
			{
				if(strVal)
				{
					writer("{/*");
					writer(strVal);
					writer("*/}");
				}
				else
				{
					writer("{}");
				}

				return;
			}
			if(level >= deep)
			{
				if(strVal)
				{
					writer("{/*");
					writer(strVal);
					writer("...*/}");
				}
				else
				{
					writer("{...}");
				}
				return;
			}                               

			if(!innl)
			{
				writer("\n");
				spacer(level, writer);
			}

			if(strVal)
			{
				writer("{//");
				writer(strVal);
				writer("\n");
			}
			else
			{
				writer("{\n");
			}

			for(var i in val)
			{
				spacer(level+1, writer);
				
				var doDefault = true;
				if(recognizeXetters)
				{
					var getter = val.__lookupGetter__(i);
					var setter = val.__lookupSetter__(i);
					if(getter || setter)
					{
						doDefault = false;
						if(getter)
						{
							writer("get ");
							writer(esc_ident(i));
							
							var strVal = getter.toString(2);
							
							{
								strVal = strVal.replace(/^/gm, spacer(level+1));
								strVal = strVal.replace(/\s*function (.*)/, '$1');
							}
							
							writer(strVal);
						}
						if(setter)
						{
							if(getter)
							{
								writer(",\n");
								spacer(level+1, writer);
							}
							writer("set ");
							writer(esc_ident(i));
							
							var strVal = setter.toString(2);
							
							{
								strVal = strVal.replace(/^/gm, spacer(level+1));
								strVal = strVal.replace(/\s*function (.*)/, '$1');
							}
							
							writer(strVal);
						}
					}
				}
				if(doDefault)
				{
					writer(esc_ident(i));
					writer(": ");
					impl(val[i], deep, level+1, path+'['+esc_ident(i)+']', false, writer);
				}
				writer(",\n");

			}
			spacer(level, writer);
			writer("}");
			return;
		}
	}

	impl(val, deep, level, path, false, writer);
	writer(';\n');
	storage = {};
}


/////////////////////////////////////////////////
global.dumps = function(val, deep, indent)
{
	var res="";
	dumpw(val, deep, indent, function(v){res += v});
	return res;
};

/////////////////////////////////////////////////
global.dump = function(val, deep, indent)
{
	var res="";
	dumpw(val, deep, indent, function(v){res += v});
	log(res);
}

