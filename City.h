#pragma once
#ifndef H_City
#define H_City

#include <QTextCodec>

using namespace std;

class City {
 public:
  City();
  City(QString, int);
  int getDistance() const;
  QString getName() const;
  void setDistance(int);
  void setName(QString);

 private:
  QString cityName;
  int distanceFromPreviousCity;
};

#endif  // !"City.h"
