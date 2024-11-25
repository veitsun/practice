#include "include/Harem.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <random>
#include <iostream>
#include <pthread.h>
#include <ctime>
#include <unistd.h>

using namespace std;
int n,k,len;

// 生成[a,b]之间的整数
int myRandom(int x, int y)
{
    return x + (rand() % (y - x + 1));
}

void mySwap(int &a,int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int randomPartition(int *a,int p,int r)
{
  int temp = myRandom(p,r);
  mySwap(a[p],a[temp]);
  
  int x = a[p], i = p, j = r+1 ;
  while (true)
  {
    while (a[++i] < x && i < r) ;  //找到比a[p]大的数

    while (a[--j] > x ) ;  //找到比a[p]小的数
    
    if(i>=j) break;
    mySwap(a[i],a[j]);    
  }
    a[p] = a[j];
    a[j] = x;

  return j ;

}

//递归函数
int randomSelect(int *a,int p,int r,int k)
{

  if(p == r)    
    return a[p]; //递归出口
  
  //随机选取一个数，把数组划分成大于和小于该数的两部分,并返回该数的下标
  int i = randomPartition(a,p,r); 

  // 求小于该数的一部分数组长度
   len = i - p + 1;

  // 该长度大于K,说明在前一部分的数组内
  if(len >= k)                            // 0  1  2  3  4  5  6  7
    return randomSelect(a,p,i,k);                // 23 45 12 18 35 67 13 77
  else
    return randomSelect(a, i+1 , r , k-len);
  
}


int main()
{
  
    //输入数组长度n
    cout<<"输入数组的长度： "<<endl;
    cin>>n;
   
    int *a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    //输入第k小
    cout<<"输入K"<<endl;
    cin>>k;


  // for (int i = 0; i < n; i++)
  // {
  //   cout<<a[i]<<" ";
  // }

  //使用线性随机算法查找第K小的值
  int result =randomSelect(a, 0, n-1, k);

  // for (int i = 0; i < n; i++)
  // {
  //   cout<<a[i]<<" ";
  // }

  cout<<endl;
  cout<<"第"<<k<<"个数为："<<result<<endl;

  return 0;
}



