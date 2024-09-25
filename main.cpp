#include "include/Harem.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  Harem *girl = new Harem(18, 165, 105);
  bool check = girl->check_beauty();
  if (check)
    cout << "nice" << endl;
  else
    cout << "sad" << endl;
  girl->show();
  return 0;
}
