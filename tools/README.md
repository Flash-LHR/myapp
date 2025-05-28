# 开发工具

这个目录包含了用于本地开发的便捷工具和脚本。

## Makefile

`Makefile` 提供了一系列便捷的开发命令，简化常见的开发任务。

### 使用方法

```bash
cd tools
make <目标>
```

### 可用目标

| 命令 | 描述 |
|------|------|
| `make help` | 显示所有可用命令 |
| `make build` | 构建项目 |
| `make run` | 运行主程序 |
| `make test` | 运行所有测试 |
| `make coverage` | 生成代码覆盖率报告 |
| `make coverage-check` | 检查覆盖率是否达到85% |
| `make format` | 格式化代码 |
| `make format-check` | 检查代码格式 |
| `make lint` | 运行静态分析 |
| `make clean` | 清理构建文件 |
| `make ci-check` | 运行完整的CI检查流程 |

### 重要说明

⚠️ **CI流水线独立性**: GitHub Actions CI流水线不依赖这些工具，而是直接使用Bazel命令。这确保了CI环境的简洁性和可重现性。

🛠️ **本地开发便利**: 这些工具仅为本地开发提供便利，让开发者能够快速执行常见任务而无需记住复杂的Bazel命令。

### 前置要求

使用这些工具需要安装：
- Bazel
- clang-format (用于代码格式化)
- clang-tidy (用于静态分析)
- lcov (用于覆盖率报告)
- bc (用于数学计算)

可以使用以下命令安装依赖：
```bash
sudo apt-get update
sudo apt-get install -y clang-format clang-tidy lcov bc
``` 
