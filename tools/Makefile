.PHONY: build test coverage clean format lint help install-deps

# 默认目标
all: build test

# 构建项目
build:
	@echo "🔨 构建项目..."
	cd .. && bazel build //app:main

# 运行主程序
run:
	@echo "🚀 运行程序..."
	cd .. && bazel run //app:main

# 运行所有测试
test:
	@echo "🧪 运行测试..."
	cd .. && bazel test //app/... --test_output=all

# 生成代码覆盖率报告
coverage:
	@echo "📊 生成覆盖率报告..."
	cd .. && bazel coverage //app/... --combined_report=lcov
	@if command -v genhtml >/dev/null 2>&1; then \
		echo "📈 生成HTML覆盖率报告..."; \
		cd .. && genhtml bazel-out/_coverage/_coverage_report.dat -o coverage_html; \
		echo "覆盖率报告已生成: ../coverage_html/index.html"; \
	else \
		echo "⚠️  genhtml未安装，跳过HTML报告生成"; \
	fi

# 检查代码覆盖率是否达标
coverage-check: coverage
	@echo "🎯 检查覆盖率是否达到85%..."
	@if [ -f ../bazel-out/_coverage/_coverage_report.dat ]; then \
		total_lines=$$(grep "^LF:" ../bazel-out/_coverage/_coverage_report.dat | awk -F: '{sum+=$$2} END {print sum+0}'); \
		covered_lines=$$(grep "^LH:" ../bazel-out/_coverage/_coverage_report.dat | awk -F: '{sum+=$$2} END {print sum+0}'); \
		echo "总行数: $$total_lines"; \
		echo "覆盖行数: $$covered_lines"; \
		if [ "$$total_lines" -gt 0 ]; then \
			coverage=$$(echo "scale=2; $$covered_lines * 100 / $$total_lines" | bc); \
			echo "当前覆盖率: $${coverage}%"; \
			if [ "$$(echo "$$coverage >= 85" | bc)" -eq 1 ]; then \
				echo "✅ 覆盖率测试通过: $${coverage}% >= 85%"; \
			else \
				echo "❌ 覆盖率测试失败: $${coverage}% < 85%"; \
				exit 1; \
			fi \
		else \
			echo "⚠️  没有找到可测试的代码行"; \
		fi \
	else \
		echo "❌ 覆盖率报告文件未找到"; \
		exit 1; \
	fi

# 格式化代码
format:
	@echo "🎨 格式化代码..."
	@if command -v clang-format >/dev/null 2>&1; then \
		cd .. && find app -name "*.cc" -o -name "*.cpp" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" -o -name "*.hxx" | xargs clang-format -i; \
		echo "✅ 代码格式化完成"; \
	else \
		echo "❌ clang-format未安装，请先安装: sudo apt-get install clang-format"; \
		exit 1; \
	fi

# 检查代码格式
format-check:
	@echo "🔍 检查代码格式..."
	@if command -v clang-format >/dev/null 2>&1; then \
		cd .. && find app -name "*.cc" -o -name "*.cpp" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" -o -name "*.hxx" | xargs clang-format --dry-run --Werror; \
	else \
		echo "❌ clang-format未安装，请先安装: sudo apt-get install clang-format"; \
		exit 1; \
	fi

# 运行静态分析
lint:
	@echo "🔍 运行静态分析..."
	@if command -v clang-tidy >/dev/null 2>&1; then \
		echo "📝 刷新编译数据库..."; \
		cd .. && bazel run @hedron_compile_commands//:refresh_all; \
		echo "🔍 运行clang-tidy分析..."; \
		cd .. && find app -name "*.cc" -o -name "*.cpp" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" -o -name "*.hxx" | xargs clang-tidy -p . --quiet; \
		echo "✅ 静态分析完成"; \
	else \
		echo "❌ clang-tidy未安装，请先安装: sudo apt-get install clang-tidy"; \
		exit 1; \
	fi

# 清理构建文件
clean:
	@echo "🧹 清理构建文件..."
	cd .. && bazel clean
	cd .. && rm -rf coverage_html/
	cd .. && rm -rf bazel-*


# 完整的CI检查流程 (跳过format-check和lint如果工具未安装)
ci-check: test coverage-check
	@echo "🔧 运行可用的代码质量检查..."
	@if command -v clang-format >/dev/null 2>&1; then \
		$(MAKE) format-check; \
	else \
		echo "⚠️  跳过格式检查 (clang-format未安装)"; \
	fi
	@if command -v clang-tidy >/dev/null 2>&1; then \
		$(MAKE) lint; \
	else \
		echo "⚠️  跳过静态分析 (clang-tidy未安装)"; \
	fi
	@echo "✅ 所有可用的CI检查完成"

# 帮助信息
help:
	@echo "可用的make目标:"
	@echo "  build         - 构建项目"
	@echo "  run           - 运行主程序"
	@echo "  test          - 运行所有测试"
	@echo "  coverage      - 生成代码覆盖率报告"
	@echo "  coverage-check- 检查覆盖率是否达到85%"
	@echo "  format        - 格式化代码"
	@echo "  format-check  - 检查代码格式"
	@echo "  lint          - 运行静态分析"
	@echo "  clean         - 清理构建文件"
	@echo "  ci-check      - 运行完整的CI检查流程"
	@echo "  help          - 显示此帮助信息" 
