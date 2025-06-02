#include <cstring>
#include <iostream>

#include "app/hello/hello.h"
#include "app/world/world.h"

void unsafe_operations() {
  // 问题1: 原始指针操作
  char* buffer = new char[100];
  strcpy(buffer, "Hello");

  // 问题2: C风格类型转换
  int* int_ptr = (int*)buffer;

  // 问题3: 手动内存管理
  if (true) {
    delete[] buffer;  // 可能的内存泄漏风险
  }
}

int main() {
  std::cout << hello(1) + world() << std::endl;
  return 0;
}
