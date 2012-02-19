
function UiLoader(parent)
{
    QUiLoader.call(this, parent);

    var uiStack = [];
    //////////////////////////////////////////////////////////////////////////
    this.load = function(device, parentWidget)
    {
        uiStack.unshift({});
        var res = this.__proto__.load.call(this, device, parentWidget);
        if(res instanceof Object)
        {
            res.ui = uiStack[0];
        }
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

    this.createLayout = function(className, parent, name)
    {
        var res = this.__proto__.createLayout(className, parent, name)
        if(name && uiStack[0] && res)
        {
            uiStack[0][name] = res;
        }
        return res;
    }

    this.createWidget = function(className, parent, name)
    {
        var res = this.__proto__.createWidget(className, parent, name)
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