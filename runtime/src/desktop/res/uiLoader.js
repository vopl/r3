
var uiLoader = new QUiLoader;
uiLoader.creator = new QUiLoader;


uiLoader.createAction = function(parent, name)
{
    var res = this.creator.createAction(parent, name);
    if(name && this.ui && res)
    {
        this.ui[name] = res;
    }
    return res;
}

uiLoader.createActionGroup = function(parent, name)
{
    var res = this.creator.createActionGroup(parent, name);
    if(name && this.ui && res)
    {
        this.ui[name] = res;
    }
    return res;
}

uiLoader.createLayout = function(className, parent, name)
{
    var res = this.creator.createLayout(className, parent, name)
    if(name && this.ui && res)
    {
        this.ui[name] = res;
    }
    return res;
}

uiLoader.createWidget = function(className, parent, name)
{
    var res = this.creator.createWidget(className, parent, name)
    if(name && this.ui && res)
    {
        this.ui[name] = res;
    }
    return res;
}

uiLoader.create = function(device, parentWidget)
{
    this.ui = {};
    
    var res = this.load(device, parentWidget);
    if(res instanceof Object)
    {
        res.ui = this.ui;
    }
    delete this.ui;

    return res;
}

uiLoader;