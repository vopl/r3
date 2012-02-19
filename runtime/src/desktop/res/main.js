
// var res = include("P:/projects/r3/repo/runtime/Debug/client/test.js");
// print("from main2: ", script.filePath, ", ", res);


importExtension('qt');
importExtension('qt.core');
importExtension('qt.gui');
importExtension('qt.uitools');
importExtension('qt.sql');



global.uiLoader = include('uiLoader.js');














global.mainWindow = uiLoader.create(new QFile(':/mainWindow.ui'));
mainWindow.windowIcon = new QIcon(":/mainWindowIcon.png");

mainWindow.ui.networkDialog = uiLoader.create(new QFile(':/networkDialog.ui'));

mainWindow.ui.actionNetwork.activated.connect(function()
{
    mainWindow.ui.networkDialog.visible = !mainWindow.ui.networkDialog.visible;
});

mainWindow.show();
QCoreApplication.exec();
