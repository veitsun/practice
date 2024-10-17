#ifndef MATRIX_H
#define MATRIX_H
#include<stdlib.h>
#include<iostream>

using namespace std;


class Matrix
{
public:
    //构造函数
    Matrix(int n);

    // 重写构造拷贝构造函数,因为有属性在堆区开辟
    Matrix(const Matrix& p);

    //初始化矩阵
    void InitMatrix();
    //显示矩阵
    void show();

    //矩阵相乘
    Matrix  operator* (const Matrix& p)
    {
        if(this->m_n != p.m_n)
        {
            std::cout<< "矩阵阶数不一样，无法计算"<<std::endl;
            exit(0);
        }
        else
        {
            Matrix temp(p.m_n);

            cout<<"测试该矩阵为："<<endl;
     

            // (row*m_n + col) 表示遍历一维数组下标
            // (row*m_n + k ) row*m_n表示第几行，K是循环列数
            // (k*m_n + col) 表示第几列，k*m_n表示前面有多个
            for (int row = 0; row < m_n; row++)
            {   
                for (int col = 0; col < m_n; col++)
                {
                    for (int k = 0; k < m_n; k++)
                        {
                            // cout<<(row*m_n + col)<< "     "<<(row*m_n + k) <<"     "<<(k*m_n + col)<<endl;

                            // cout<<temp.m_ptr[row*m_n + col]<<"      "<<m_ptr[row*m_n + k]<<"    "<<p.m_ptr[k*m_n + col] <<endl;
                            
                            temp.m_ptr[row*m_n + col] += (m_ptr[row*m_n + k]*p.m_ptr[k*m_n + col]) ;
                        }
                
                }
            
            }

            return temp;
        }
       
        
    }
    
    
    //析构函数
    ~Matrix();
private:
    int m_n;  //阶数

    int  *m_ptr; // 指针
    
};
#endif