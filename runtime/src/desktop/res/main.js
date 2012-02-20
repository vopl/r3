
// var res = include("P:/projects/r3/repo/runtime/Debug/client/test.js");
// print("from main2: ", script.filePath, ", ", res);


importExtension('qt');
importExtension('qt.core');
importExtension('qt.gui');
importExtension('qt.uitools');
importExtension('qt.sql');



global.uiLoader = include(':/uiLoader.js');

//include(':/client.js');
var network = include(':/network.js');
print(network);

network.onStateChanged.connect(function(ec,numChannels){
	print('s1', ec, numChannels);
})

function f22(ec,numChannels){
	print('s2', ec, numChannels);
}
network.onStateChanged.connect(f22);
//network.onStateChanged.disconnect(f22)

print(network.onStateChanged);
network.onStateChanged('_myec__', 221);


QCoreApplication.exec();
