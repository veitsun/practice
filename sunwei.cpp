#include "include/Harem.h"
#include <cstdio>
#include <cstring>
#include <iostream>
#include "include/employee.h"
#include "include/worker.h"
#include "include/manager.h"
#include "include/boss.h"
using namespace std;

int main() {
  worker *emp = new employee(1,"岁盼盼",1); 
  emp->showInfo();

  worker *emp1 = new manager(2,"濛濛濛",2); 
  emp1->showInfo();

  worker *emp2 = new boss(3,"岁盼盼",3); 
  emp2->showInfo();

  return 0;
}
