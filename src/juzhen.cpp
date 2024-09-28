#include<iostream>
#include<cstdlib>
#include<ctime>
#include "../include/juzhen.h"

using namespace std;

Juzhen::Juzhen(int n)
{
    this->n=n;
}

void Juzhen::Initjuzhen()
{
    a = new int[n*n];

    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           
           a[i+j]= rand()%(101);

           //产生0~n之间的随机数（包括n和0），
        // double base=((double)rand())/RAND_MAX;//产生0~1之间的随机实数;
        // long long res=((double)100*base+0.5);//再把上面的实数扩大n倍并四舍五入
        // a[i+j] = res;
        }
        cout<<endl;
    }
    cout<<"初始化矩阵完成"<<endl;
}

void Juzhen::show()
{
    cout<<"该矩阵为："<<endl;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cout<<a[i+j]<<" ";
        }
        cout<<endl;
    }
}

Juzhen::~Juzhen() {}