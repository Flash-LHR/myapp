#include "security_issues.h"

#include <cassert>
#include <iostream>

// 简单的测试函数，不使用GoogleTest宏
void test_functions_exist() {
  std::cout << "测试函数是否存在..." << std::endl;

  // 测试安全的用例
  std::string result = unsafe_string_copy("test");
  assert(result == "test");

  // 测试有效的数组索引
  int value = array_bounds_violation(5);
  assert(value == 5);

  // 测试非零值
  int non_null_value = 42;
  int result2 = null_pointer_dereference(&non_null_value);
  assert(result2 == 52);

  std::cout << "基本测试通过" << std::endl;
}

int main() {
  test_functions_exist();
  std::cout << "所有测试完成" << std::endl;
  return 0;
}
