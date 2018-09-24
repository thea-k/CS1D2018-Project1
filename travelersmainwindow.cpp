#include "travelersmainwindow.h"
#include "ui_travelersmainwindow.h"

TravelersMainWindow::TravelersMainWindow(QWidget* parent)
		: QMainWindow(parent), ui(new Ui::TravelersMainWindow) {
	ui->setupUi(this);
	DbManager controller;
	controller.initDataBase();
	//    controller.readInTxtFile();
}

TravelersMainWindow::~TravelersMainWindow() { delete ui; }
