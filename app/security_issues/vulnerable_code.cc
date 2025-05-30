#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

// 1. 缓冲区溢出漏洞 - CodeQL应该检测CWE-120
void buffer_overflow_demo() {
  char buffer[10];
  char* dangerous_input = "This is a very long string that will overflow the buffer";
  strcpy(buffer, dangerous_input);  // 危险！缓冲区溢出
  printf("Buffer: %s\n", buffer);
}

// 2. 格式字符串漏洞 - CodeQL应该检测CWE-134
void format_string_vulnerability(const char* user_input) {
  printf(user_input);  // 危险！用户输入直接作为格式字符串
}

// 3. 使用危险函数 - CodeQL应该检测CWE-676
void dangerous_functions() {
  char buffer[100];
  char large_input[1000];
  // 模拟危险的输入读取
  scanf("%s", buffer);          // 危险！scanf没有边界检查
  strcpy(buffer, large_input);  // 危险！可能的缓冲区溢出
  printf("Input: %s\n", buffer);
}

// 4. 未检查返回值的内存分配
void unchecked_malloc() {
  char* ptr = (char*)malloc(1000);
  strcpy(ptr, "test");  // 危险！没有检查malloc是否成功
  printf("Data: %s\n", ptr);
  // 内存泄漏：没有free
}

// 5. 空指针解引用
int null_pointer_access(int* ptr) {
  return *ptr + 1;  // 危险！没有检查ptr是否为null
}

// 6. 数组越界访问
void array_bounds_error() {
  int arr[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i <= 10; i++) {  // 危险！i会超出数组边界
    printf("arr[%d] = %d\n", i, arr[i]);
  }
}

// 7. 使用未初始化的变量
int use_uninitialized() {
  int uninitialized_var;
  return uninitialized_var * 2;  // 危险！使用未初始化的变量
}

// 8. 整数溢出
int integer_overflow(int a, int b) {
  return a * b;  // 危险！可能溢出，没有检查
}

int main() {
  printf("=== 安全漏洞演示 ===\n");

  // 调用各种有漏洞的函数（注释掉以避免实际运行时崩溃）
  // buffer_overflow_demo();
  // format_string_vulnerability("Hello %s %d");
  // dangerous_functions();
  // unchecked_malloc();

  int value = 42;
  printf("Null pointer test: %d\n", null_pointer_access(&value));

  // array_bounds_error();  // 注释掉以避免崩溃

  printf("Uninitialized: %d\n", use_uninitialized());
  printf("Overflow: %d\n", integer_overflow(1000000, 1000000));

  return 0;
}
