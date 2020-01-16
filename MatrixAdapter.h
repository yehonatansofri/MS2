//
// Created by yehonatan on 14/01/2020.
//

#ifndef MATRIXADAPTER_H_
#define MATRIXADAPTER_H_


#include "objects/matrix.h"
#include "string"
#include "util/stringer.h"


#define REGEX "[-]{0,1}[\\d]+[.]{0,1}[\\d]{0,}"

//Matrix Adapter can make matrix object from string
//each time you enter a string that represents a row
//string contains int seperated by commas
//e.g. "1, -2, 3, 4, 5"
//when you finished adding all rows, call getMatrix()
class MatrixAdapter {
 public:
  void addRow(string);
  Matrix<int> getMatrix();
 private:
  void setValuesInVector(vector<string> &);
  Matrix<int> int_matrix_;
};

#endif //MS2__MATRIXADAPTER_H_
