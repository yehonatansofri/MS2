//
// Created by yehonatan on 14/01/2020.
//

#ifndef MS2_OBJECTS_POINT_H_
#define MS2_OBJECTS_POINT_H_

class Point {
 public:
  Point(unsigned int x, unsigned int y) : x_(x), y_(y) {}
  unsigned int getX();
  unsigned int getY();
 private:
  unsigned int x_;
  unsigned int y_;
};

#endif //MS2_OBJECTS_POINT_H_
