#include <QApplication>
#include "travelersmainwindow.h"

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	TravelersMainWindow w;
	w.show();

	return a.exec();
}
