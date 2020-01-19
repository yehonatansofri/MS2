//
// Created by yehonatan on 14/01/2020.
//

#ifndef MS2_OBJECTS_POINT_H_
#define MS2_OBJECTS_POINT_H_

#include "string"


#define NO_POINT Point(-1, -1)
#include <string>


class Point {
 public:
  Point(int x, int y) : x_(x), y_(y) {}
  unsigned int getX();
  unsigned int getY();
  bool operator==(Point);
  bool operator!=(Point);
  std::string toString();
 private:
  unsigned int x_;
  unsigned int y_;
};

#endif //MS2_OBJECTS_POINT_H_