#include <iostream>
#include<cstring>
#include "../include/Matrix.h"

using namespace std;

int main()
{   
  Matrix ma = Matrix(4);
  ma.InitMatrix();
  ma.show();
  
  Matrix mb =  Matrix(4); 
  mb.InitMatrix();
  mb.show();

  Matrix mc = ma.operator*(mb);
  mc.show();

  return 0;
}
