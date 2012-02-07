/////////////////////////////////////////////////
let dumpw = function(val, deep, indent, writer)
{
	let esc = dumpw.esc;
	if(!esc)
	{
		dumpw.esc = include('esc.js');
		esc = dumpw.esc;
	}

	if(!indent) indent = '  ';
	let spacer = function(num, swriter)
	{
		if(swriter)
		{
			for(let k=0; k<num; k++)
			{
				writer(indent);
			}
			return "";
		}
		return new Array(num+1).join(indent);
	}

	if(undefined == deep) deep=10;
	if(0 > deep) deep=0;
	let recognizeXetters = true;
	let replaceFunctionBody = function(name){return "function "+name+"(){/*body dropped*/}"};
	let level=0;
	let storage = {};
	let path='VAR';
	writer('VAR=');

	let impl = function(val, deep, level, path, innl, writer)
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
			writer(esc.str(val));
			writer('"');
			return;
		case "xml":
			//writer(esc.xml(val.toXMLString()));
			let str = val.toXMLString();
			if(str) writer(str);
			else writer('<></>');
			return;
		case "function":
			if(val instanceof Function)
			{
				let functionName = val.name;
				for(let p in storage)
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
				let strVal;
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
				
/*				if(strVal.match(/\s*function\s+\w+\(\)/))
				{
					let params=[];
					for(let i=0; i<val.length; i++) params.push('_'+i);
					strVal = 'native_function('+params.join(', ')+'){}';
				}
				else
*/				{
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

			for(let p in storage)
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
			
			if(val instanceof RegExp)
			{
				writer(val.toString());
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
				for(let i in val)
				{
					spacer(level+1, writer);
					impl(val[i], deep, level+1, path+"['"+esc.str(i)+"']", true, writer);
					writer(",\n");
				}
				spacer(level, writer);
				writer("]");
				return;
			}

			let empty=true;
			for(let i in val)
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
				for(let i=0; i<val.length; i++)
				{
					spacer(level+1, writer);
					impl(val[i], deep, level+1, path+"['"+esc.str(i)+"']", true, writer);
					writer(",\n");
				}
				spacer(level, writer);
				writer("]");
				return;
			}
			
			
			let strVal;
			// if(val instanceof CppObject)
			// {
				// strVal = "CppObject of "+val.cppClass;
			// }
			// else
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
						//strVal = ""+e;
						strVal = "UNKNOWN ("+e+")";
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

			for(let i in val)
			{
				spacer(level+1, writer);
				
				let doDefault = true;
				if(recognizeXetters)
				{
					let getter = val.__lookupGetter__(i);
					let setter = val.__lookupSetter__(i);
					if(getter || setter)
					{
						doDefault = false;
						if(getter)
						{
							writer("get ");
							writer(esc.ident(i));
							
							let strVal = getter.toString(2);
							
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
							writer(esc.ident(i));
							
							let strVal = setter.toString(2);
							
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
					writer(esc.ident(i));
					writer(": ");
					impl(val[i], deep, level+1, path+"['"+esc.str(i)+"']", false, writer);
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
let dump = function(val, deep, indent)
{
	dumpw(val, deep, indent, print);
}

/////////////////////////////////////////////////
//let dumpe = function(val, deep, indent)
//{
//	dumpw(val, deep, indent, warn_noln);
//	warn();
//}

/////////////////////////////////////////////////
let dumps = function(val, deep, indent)
{
	let res=[];
	dumpw(val, deep, indent, function(v){res.push(v)});
	return res.join('');
}
