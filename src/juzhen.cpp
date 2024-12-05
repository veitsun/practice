#include "juzhen.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Juzhen::Juzhen(int n) { this->n = n; }

void Juzhen::Initjuzhen() {
  a = new int[n * n];

  srand((unsigned)time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i + j] = rand() % (10);
    }
    cout << endl;
  }
  cout << "初始化矩阵完成" << endl;
}

void Juzhen::show() {
  cout << "该矩阵为：" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i + j] << " ";
    }
    cout << endl;
  }
}

Juzhen::~Juzhen() {}