#include "include/Harem.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void *print_a(void *a) { // 线程a
  for (int i = 0; i < 10; i++) {
    sleep(1);
    std::cout << "aa" << std::endl;
  }
  return NULL;
}

void *print_b(void *b) { // 线程b
  for (int i = 0; i < 20; i++) {
    sleep(1);
    std::cout << "bbb" << std::endl;
  }
  return NULL;
}

int main() {
  pthread_t t0;
  pthread_t t1;

  // 创建线程a
  if (pthread_create(&t0, NULL, print_a, NULL) == -1) {
    std::cout << "创建线程t0失败" << std::endl;
    exit(0);
  }

  // 创建线程b
  if (pthread_create(&t1, NULL, print_b, NULL) == -1) {
    std::cout << "创建线程b失败" << std::endl;
    exit(1);
  }

  // 等待线程结束
  void *result;
  if (pthread_join(t0, &result) == -1) {
    std::cout << "回收t0线程失败" << std::endl;
    exit(1);
  }
  if (pthread_join(t1, &result) == -1) {
    std::cout << "回收t1线程失败" << std::endl;
    exit(1);
  }

  return 0;
}
