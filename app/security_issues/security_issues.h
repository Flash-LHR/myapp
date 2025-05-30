#ifndef APP_SECURITY_ISSUES_SECURITY_ISSUES_H
#define APP_SECURITY_ISSUES_SECURITY_ISSUES_H

#include <string>

// 缓冲区溢出相关函数
void buffer_overflow_example(const char* input);
std::string unsafe_string_copy(const char* source);

// 空指针解引用
int null_pointer_dereference(int* ptr);

// 未初始化变量使用
int use_uninitialized_variable();

// 内存泄漏
char* memory_leak_example();

// 格式字符串漏洞
void format_string_vulnerability(const char* user_input);

// 整数溢出
int integer_overflow_example(int a, int b);

// 数组越界访问
int array_bounds_violation(int index);

// 不安全的字符串操作
void unsafe_strcpy(const char* source);

#endif  // APP_SECURITY_ISSUES_SECURITY_ISSUES_H
