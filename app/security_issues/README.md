# 安全漏洞演示模块

⚠️ **警告：此模块包含故意的安全漏洞，仅用于测试CodeQL扫描功能**

## 目的

这个模块包含了常见的C++安全漏洞示例，用于验证GitHub CodeQL安全扫描是否正常工作。这些漏洞是故意构造的，用于测试自动化安全分析工具的检测能力。

## 包含的安全漏洞

### 1. 缓冲区溢出 (Buffer Overflow)
- **函数**: `buffer_overflow_example()`, `unsafe_string_copy()`, `unsafe_strcpy()`
- **问题**: 使用`strcpy()`而不检查目标缓冲区大小
- **CodeQL应检测**: CWE-120, CWE-121

### 2. 空指针解引用 (Null Pointer Dereference)
- **函数**: `null_pointer_dereference()`
- **问题**: 解引用指针而不检查是否为null
- **CodeQL应检测**: CWE-476

### 3. 使用未初始化变量 (Use of Uninitialized Variable)
- **函数**: `use_uninitialized_variable()`
- **问题**: 使用未初始化的局部变量
- **CodeQL应检测**: CWE-457

### 4. 内存泄漏 (Memory Leak)
- **函数**: `memory_leak_example()`
- **问题**: 分配内存但不释放
- **CodeQL应检测**: CWE-401

### 5. 格式字符串漏洞 (Format String Vulnerability)
- **函数**: `format_string_vulnerability()`
- **问题**: 将用户输入直接用作printf格式字符串
- **CodeQL应检测**: CWE-134

### 6. 整数溢出 (Integer Overflow)
- **函数**: `integer_overflow_example()`
- **问题**: 乘法运算可能导致整数溢出
- **CodeQL应检测**: CWE-190

### 7. 数组越界访问 (Array Bounds Violation)
- **函数**: `array_bounds_violation()`
- **问题**: 访问数组元素而不检查索引边界
- **CodeQL应检测**: CWE-125

## 验证方法

1. 运行CodeQL扫描后，检查安全报告
2. 确认上述每种漏洞类型都被检测到
3. 查看CodeQL提供的详细分析和修复建议

## 运行演示

```bash
# 构建演示程序
bazel build //app/security_issues:vulnerable_demo

# 运行演示（注意：包含安全漏洞，仅用于测试）
bazel run //app/security_issues:vulnerable_demo

# 运行基本测试
bazel run //app/security_issues:security_issues_test
```

## 重要说明

- 这些代码**绝不应该**在生产环境中使用
- 仅用于安全工具测试和教育目的
- 运行这些程序可能存在安全风险
- CodeQL扫描应该在CI流水线中检测到所有这些问题

## 期望的CodeQL检测结果

当CodeQL扫描运行时，应该生成包含以下类型问题的安全报告：

- Buffer overflow vulnerabilities
- Null pointer dereference
- Use of uninitialized variable
- Memory leak
- Format string vulnerability
- Integer overflow
- Array bounds violation

如果CodeQL没有检测到这些问题，则表明扫描配置可能需要调整。 
