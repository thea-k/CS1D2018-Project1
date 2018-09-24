#ifndef TRAVELERSMAINWINDOW_H
#define TRAVELERSMAINWINDOW_H

#include <QMainWindow>

#include "dbmanager.h"

namespace Ui {
class TravelersMainWindow;
}

class TravelersMainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit TravelersMainWindow(QWidget* parent = nullptr);
  ~TravelersMainWindow();

 private:
  Ui::TravelersMainWindow* ui;
};

#endif  // TRAVELERSMAINWINDOW_H
