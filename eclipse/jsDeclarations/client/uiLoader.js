
function UiLoader(parent)
{
    QUiLoader.call(this, parent);

    var uiStack = [];
    //////////////////////////////////////////////////////////////////////////
    this.load = function(src, parentWidget)
    {
        uiStack.unshift({});

        if(!(src instanceof QIODevice))
        {
        	src = new QFile(src);
        }

        var res = this.__proto__.load.call(this, src, parentWidget);
        res.ui = uiStack[0];
        
        uiStack.shift();
		
        return res;
    }

    //////////////////////////////////////////////////////////////////////////
    this.createAction = function(parent, name)
    {
        var res = this.__proto__.createAction(parent, name);
        if(name && uiStack[0] && res)
        {
            uiStack[0][name] = res;
        }
        return res;
    }

    this.createActionGroup = function(parent, name)
    {
        var res = this.__proto__.createActionGroup(parent, name);
        if(name && uiStack[0] && res)
        {
            uiStack[0][name] = res;
        }
        return res;
    }

    var createAsClass = function(className, parent, name)
    {
    	var ProtoCtor = global[className];
    	if(ProtoCtor)
    	{
    		var Ctor = function(parent)
    		{
    			ProtoCtor.call(this, parent);
    		}
    		Ctor.prototype = new ProtoCtor();

    		var res = new Ctor(parent);
    		res.objectName = name;

    		return res;
    	}
    	return null;
    }

    this.createLayout = function(className, parent, name)
    {
    	var res = createAsClass(className, parent, name);

    	if(!res)
        {
        	res = this.__proto__.createLayout(className, parent, name)
        }
        if(name && uiStack[0] && res)
        {
            uiStack[0][name] = res;
        }
        return res;
    }

    this.createWidget = function(className, parent, name)
    {
    	var res = createAsClass(className, parent, name);

    	if(!res)
    	{
		res = this.__proto__.createWidget(className, parent, name)
    	}

        if(name && uiStack[0] && res)
        {
            uiStack[0][name] = res;
        }

	return res;
    }
    
}

UiLoader.prototype = new QUiLoader();


var uiLoader = new UiLoader();

uiLoader;