#include "include/Harem.h"
#include "include/Matrix.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  // Harem *girl = new Harem(18, 165, 105);
  // bool check = girl->check_beauty();
  // if (check)
  //   cout << "nice girl" << endl;
  // else
  //   cout << "sad girl" << endl;
  // girl->show();

  Matrix *matrix = new Matrix(4);
  matrix->InitMatrix();
  matrix->assignMatrix();
  matrix->show();
  return 0;
}