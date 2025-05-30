#include "security_issues.h"

#include <iostream>

int main() {
  std::cout << "=== 安全漏洞演示程序 ===" << std::endl;
  std::cout << "注意：这个程序包含故意的安全漏洞，用于测试CodeQL扫描" << std::endl;
  std::cout << std::endl;

  // 演示各种安全问题（使用相对安全的参数）

  std::cout << "1. 缓冲区溢出示例（使用短字符串）:" << std::endl;
  buffer_overflow_example("safe");  // 短字符串，相对安全

  std::cout << std::endl << "2. 不安全的字符串复制:" << std::endl;
  std::string copied = unsafe_string_copy("test");
  std::cout << "复制结果: " << copied << std::endl;

  std::cout << std::endl << "3. 空指针解引用（使用有效指针）:" << std::endl;
  int value = 42;
  int result = null_pointer_dereference(&value);
  std::cout << "结果: " << result << std::endl;

  std::cout << std::endl << "4. 使用未初始化变量:" << std::endl;
  int uninitialized_result = use_uninitialized_variable();
  std::cout << "未初始化变量结果: " << uninitialized_result << std::endl;

  std::cout << std::endl << "5. 内存泄漏示例:" << std::endl;
  char* leaked_memory = memory_leak_example();
  std::cout << "分配的内存地址: " << static_cast<void*>(leaked_memory) << std::endl;
  // 注意：这里故意不释放内存来演示内存泄漏

  std::cout << std::endl << "6. 格式字符串漏洞:" << std::endl;
  format_string_vulnerability("Hello World");  // 安全的字符串

  std::cout << std::endl << "7. 整数溢出:" << std::endl;
  int overflow_result = integer_overflow_example(1000, 2000);
  std::cout << "乘法结果: " << overflow_result << std::endl;

  std::cout << std::endl << "8. 数组越界访问（安全索引）:" << std::endl;
  int array_result = array_bounds_violation(7);
  std::cout << "数组元素: " << array_result << std::endl;

  std::cout << std::endl << "9. 不安全的strcpy:" << std::endl;
  unsafe_strcpy("demo");

  std::cout << std::endl << "演示完成。CodeQL应该检测到这些安全问题！" << std::endl;

  return 0;
}
