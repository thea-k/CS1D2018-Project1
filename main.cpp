#include "travelersmainwindow.h"
#include "dbmanager.h"
#include <QApplication>
#include "city.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TravelersMainWindow w;
    w.show();

    return a.exec();
}
