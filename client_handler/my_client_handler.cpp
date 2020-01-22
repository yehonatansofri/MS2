//
// Created by yehonatan on 19/01/2020.
//

#include "my_client_handler.h"

using namespace std;

void MyClientHandler::handleClient(int & client_socket) {
    list<string> lines_list;
    string str;

    do {
        char buffer[BUFFER_SIZE] = {0};
        int valread = read(client_socket , buffer, BUFFER_SIZE);

        list<string> tmp_list = Stringer::stringListFromCharArray(buffer);

        //add tmp_list to lines_list
        lines_list.insert(lines_list.end(), tmp_list.begin(), tmp_list.end());

    } while (endNotEntered(lines_list));

    str = setAndSolveMatrix(lines_list);

    //send solution to client
    send(client_socket , str.c_str() , strlen(str.c_str()) , 0 );

    close(client_socket);
}

bool MyClientHandler::endNotEntered(list<string> lines_list) {
  string last_line;
  bool endIn = false;

    if(lines_list.size() > 0) {
       last_line = lines_list.back();
    }

  if (last_line != "" && last_line.length() <= 5) {
    endIn = (last_line.length() == strspn(last_line.c_str(), END));
  }

  return !endIn;
}

string MyClientHandler::setAndSolveMatrix(list<string> lines_list) {
    auto searchable = makeSearchable(lines_list);
    string solution;
    MatrixAdapter matrix_adapter;

    if (file_cache_manager.exist(&searchable)) {
        solution =  file_cache_manager.get(&searchable);
    } else {
    solution = matrix_adapter.solve(searchable);
    file_cache_manager.insert(&searchable, solution);
  }

  return solution;
}

MatrixSearchable MyClientHandler::makeSearchable(list<string> lines_list) {
  MatrixBuilder matrix_builder;
  Matrix<int> matrix;
  list<string>::iterator iter;

  //make list to hold one line in each node
  lines_list = Stringer::listOfLines(lines_list);

  matrix_builder.buildNXNMatrix(lines_list);

  matrix = matrix_builder.getMatrix();

  iter = lines_list.end();
  --iter;//go to last string - "end\n"
  Point end = Stringer::pointFromString(*(--iter));
  Point start = Stringer::pointFromString(*(--iter));

  return MatrixSearchable(matrix, start, end);
}
