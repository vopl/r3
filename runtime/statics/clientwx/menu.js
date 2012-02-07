let make=function(frame)
{
	let menuBar = new wx.MenuBar();
	
	
	let file = new wx.Menu();
	
	let item = file.append(wx.Id.ANY, "&Quit");
	file.actions[item.id] = function()
	{
		frame.close();
	}
	
	item = file.append(wx.Id.ANY, "&Network");
	file.actions[item.id] = function()
	{
		frame.close();
	}
	
	menuBar.append(file, "&File");
	frame.menuBar = menuBar;
}