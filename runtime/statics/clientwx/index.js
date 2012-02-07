//global wx
glue.wx = require("wx");
wx.initAllImageHandlers();

//global dump, dumps
let dumper = include('lib/dumper.js');
glue.dump = dumper.dump;
glue.dumps = dumper.dumps;

glue.menu = include('menu.js');

//initialize application
wx.theApp.onInit = function()
{
	let frame = new wx.Frame(null, wx.Id.ANY, "An App example");
	frame.icon = new wx.Icon("web.xpm", wx.BitmapType.XPM);
	
	//network dialog
	

	//menu
	menu.make(frame);

	frame.createStatusBar(2);

	frame.setStatusWidths(new Array(100, -1, -1));

	let auin = wx.AuiNotebook(frame);

	for(let i=0; i<10; i++)
	{
		let p = wx.Panel(auin);

		let bs = wx.BoxSizer(wx.Orientation.VERTICAL);
		for(let j=0; j<10; j++)
		{
			let b = wx.Button(p, -1, "кнопка "+i+", "+j);
			bs.add(b);
		}
		p.sizer = bs;

		auin.addPage(p, "закладка "+i);
	}

	// Don't forget to show the frame by setting the visible property to true!
	frame.visible = true;

	topWindow = frame;

	return true;
}
