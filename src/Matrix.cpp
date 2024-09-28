#include "../include/Matrix.h"
#include <iostream>

Matrix::Matrix(int n)
{
    this->_n = n;
}

//初始化
void Matrix::InitMatrix()
{
     m_ptr = new int*[_n];
    for(int i=0;i<_n;i++)
        m_ptr[i] = new int[_n];

}

//为矩阵赋值
void Matrix::assignMatrix()
{
    int num;
    for (int i = 0; i < _n; i++)
    {
        std::cout<<"请在第"<<i<<"列，输入"<< _n <<"个数据"<<std::endl;
        for(int j = 0; j < _n; j++)
        {
            
            std::cin >> num;
            m_ptr[j][i] = num;
        }
    }
    
}

//显示矩阵
void Matrix::show()
{
    std::cout<<"该矩阵为："<<std::endl;
    for (int i = 0; i < _n; i++)
    {
        for(int j = 0; j < _n; j++)
        {
            
            std::cout<<m_ptr[i][j]<<" ";
        }
        std::cout<<std::endl;    
    }
}

//析构函数
Matrix::~Matrix() {
 for (int i = 0; i < _n; ++i) {
			delete[] m_ptr[i];
		}
		delete[] m_ptr;
}