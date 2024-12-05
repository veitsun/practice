#include "Matrix.h"
#include <ctime>
#include <iostream>

using namespace std;

// 构造函数

Matrix::Matrix(int n) {
  this->m_n = n;

  // 初始化数组，赋值为0
  this->m_ptr = new int[m_n * m_n];

  for (int i = 0; i < n * n; i++) {
    m_ptr[i] = 0;
  }
}

// 重写构造拷贝构造函数,因为有属性在堆区开辟
Matrix::Matrix(const Matrix &p) {
  this->m_n = p.m_n;
  // 重新在堆区开辟内存
  this->m_ptr = new int[p.m_n * p.m_n];

  for (int i = 0; i < m_n * m_n; i += m_n) {
    for (int j = 0; j < m_n; j++) {
      m_ptr[i + j] = p.m_ptr[i + j];
    }
  }
}

// 初始化矩阵
void Matrix::InitMatrix() {

  srand((unsigned)time(NULL));
  for (int i = 0; i < m_n * m_n; i += m_n) {
    for (int j = 0; j < m_n; j++) {
      m_ptr[i + j] = rand() % (10);
    }
  }
  cout << "初始化矩阵完成" << endl;
}

// 显示矩阵
void Matrix::show() {
  cout << "该矩阵为：" << endl;
  for (int i = 0; i < m_n * m_n; i += m_n) {
    for (int j = 0; j < m_n; j++) {
      cout << m_ptr[i + j] << " ";
    }
    cout << endl;
  }
}

// 析构函数
Matrix::~Matrix() {
  if (this->m_ptr != nullptr) {
    delete m_ptr;
    m_ptr = nullptr;
  }
}
