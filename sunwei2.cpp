#include "include/Harem.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <unistd.h>

using namespace std;

void func() { std::cout << "hello worrld" << std::endl; }

int main() {
  // 创建一个线程
  std::thread tt(func);
  // 等待线程结束
  // tt.join();
  std::cout << "end" << std::endl;
  return 0;
}
