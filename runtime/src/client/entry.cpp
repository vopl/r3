#include "pchqt.h"
//#include "client.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	int res;
	{
// 		Client w;
// 		w.show();
		res = a.exec();
	}
	return res;
}
