#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
public:
    Matrix(int n);
    void assignMatrix();
    void show();
    void InitMatrix();
    ~Matrix();
private:
    int _n; //阶数
    int  **m_ptr; //二重指针实现动态矩阵
    
};
#endif