#include <cstring>
#include <iostream>
#include <memory>

#include "app/hello/hello.h"
#include "app/world/world.h"

void safe_operations() {
  // 修复1: 使用智能指针和安全的字符串操作
  std::unique_ptr<char[]> buffer(new char[100]);
  strncpy(buffer.get(), "Hello", 99);
  buffer[99] = '\0';  // 确保字符串结尾

  // 修复2: 移除未使用的变量，如果需要类型转换可以这样做：
  // auto* int_ptr = reinterpret_cast<int*>(buffer.get());

  // 修复3: 智能指针自动管理内存，不需要手动delete
}

int main() {
  std::cout << hello(1) + world() << std::endl;
  return 0;
}
