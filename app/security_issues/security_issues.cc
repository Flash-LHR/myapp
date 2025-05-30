#include "security_issues.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

// 缓冲区溢出示例 - CodeQL应该检测到
void buffer_overflow_example(const char* input) {
  char buffer[10];
  // 危险：没有检查输入长度，可能导致缓冲区溢出
  strcpy(buffer, input);
  std::cout << "Buffer content: " << buffer << std::endl;
}

// 不安全的字符串复制 - CodeQL应该检测到
std::string unsafe_string_copy(const char* source) {
  char buffer[100];
  // 危险：strcpy不检查边界
  strcpy(buffer, source);
  return std::string(buffer);
}

// 空指针解引用 - CodeQL应该检测到
int null_pointer_dereference(int* ptr) {
  // 危险：没有检查ptr是否为nullptr
  return *ptr + 10;
}

// 使用未初始化的变量 - CodeQL应该检测到
int use_uninitialized_variable() {
  int uninitialized_var;
  // 危险：使用未初始化的变量
  return uninitialized_var * 2;
}

// 内存泄漏示例 - CodeQL应该检测到
char* memory_leak_example() {
  char* buffer = static_cast<char*>(malloc(256));
  if (buffer != nullptr) {
    strcpy(buffer, "Some data");
  }
  // 危险：分配的内存没有被释放
  return buffer;  // 调用者可能忘记free
}

// 格式字符串漏洞 - CodeQL应该检测到
void format_string_vulnerability(const char* user_input) {
  // 危险：直接使用用户输入作为格式字符串
  printf(user_input);
  printf("\n");
}

// 整数溢出示例 - CodeQL应该检测到
int integer_overflow_example(int a, int b) {
  // 危险：没有检查溢出
  return a * b;
}

// 数组越界访问 - CodeQL应该检测到
int array_bounds_violation(int index) {
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // 危险：没有检查数组边界
  return array[index];
}

// 不安全的strcpy使用 - CodeQL应该检测到
void unsafe_strcpy(const char* source) {
  char destination[50];
  // 危险：strcpy不检查目标缓冲区大小
  strcpy(destination, source);
  std::cout << "Copied: " << destination << std::endl;
}
