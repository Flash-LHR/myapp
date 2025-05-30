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
| `make coverage-check` | 检查总体覆盖率是否达到85% |
| `make incremental-coverage` | 检查增量覆盖率是否达到85% |
| `make format` | 格式化代码 |
| `make format-check` | 检查代码格式 |
| `make lint` | 运行静态分析 |
| `make clean` | 清理构建文件 |
| `make ci-check` | 运行完整的CI检查流程（包含增量覆盖率） |

## 增量覆盖率检查

### 什么是增量覆盖率？

增量覆盖率是指**仅对新增和修改的代码**进行覆盖率检查，而不是整个代码库。这样可以：

- 🎯 **专注新代码质量**：确保新增代码有足够的测试
- ⚡ **快速反馈**：无需等待整个项目的覆盖率计算
- 📈 **渐进改进**：逐步提升代码库的整体测试覆盖率

### 如何使用

```bash
# 本地检查（与上一个提交对比）
make incremental-coverage

# 手动运行脚本
./incremental_coverage.sh <覆盖率文件> <基础分支> <阈值>

# 示例：与master分支对比，要求90%覆盖率
./incremental_coverage.sh bazel-out/_coverage/_coverage_report.dat origin/master 90
```

### CI中的增量覆盖率

- **Pull Request**：自动与目标分支（如master）对比
- **Push到主分支**：与前一个提交对比
- **阈值要求**：>=85%
- **失败处理**：如果增量覆盖率不足，CI会失败并提供详细报告

### 覆盖率报告

增量覆盖率检查会生成：

1. **控制台输出**：显示覆盖率百分比和详细信息
2. **HTML报告**：`incremental_coverage_html/index.html`
3. **CI构件**：在GitHub Actions中可下载报告

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

## 脚本说明

### `incremental_coverage.sh`

增量覆盖率检查的核心脚本，功能包括：

- 自动检测修改的C++源文件
- 提取这些文件的覆盖率数据
- 生成增量覆盖率报告
- 验证是否达到指定阈值
- 提供详细的失败信息和修复建议

**用法**：
```bash
./incremental_coverage.sh [覆盖率文件] [基础分支] [阈值]
```

**参数**：
- `覆盖率文件`：lcov格式的覆盖率数据文件（默认：`bazel-out/_coverage/_coverage_report.dat`）
- `基础分支`：用于对比的基础分支或提交（默认：`HEAD~1`）
- `阈值`：要求的最低覆盖率百分比（默认：85） 
