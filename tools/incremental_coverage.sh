#!/bin/bash

# 增量覆盖率检查脚本
# 用法: ./incremental_coverage.sh <覆盖率报告文件> <基础分支> <覆盖率阈值>

set -e

COVERAGE_FILE=${1:-"bazel-out/_coverage/_coverage_report.dat"}
BASE_REF=${2:-"HEAD~1"}
THRESHOLD=${3:-85}

echo "🎯 执行增量覆盖率检查..."
echo "覆盖率文件: $COVERAGE_FILE"
echo "基础分支: $BASE_REF"
echo "覆盖率阈值: $THRESHOLD%"

# 检查覆盖率文件是否存在
if [ ! -f "$COVERAGE_FILE" ]; then
    echo "❌ 覆盖率文件不存在: $COVERAGE_FILE"
    exit 1
fi

# 获取修改的文件列表（仅C++文件）
CHANGED_FILES=$(git diff --name-only $BASE_REF...HEAD | grep -E '\.(cc|cpp|cxx)$' | grep '^app/' || true)

if [ -z "$CHANGED_FILES" ]; then
    echo "✅ 没有修改的C++源代码文件，跳过增量覆盖率检查"
    exit 0
fi

echo "修改的文件："
echo "$CHANGED_FILES"

# 将文件路径转换为绝对路径
ABSOLUTE_FILES=""
for file in $CHANGED_FILES; do
    if [ -f "$file" ]; then
        ABSOLUTE_FILES="$ABSOLUTE_FILES $(pwd)/$file"
    fi
done

if [ -z "$ABSOLUTE_FILES" ]; then
    echo "⚠️  修改的文件都不存在，跳过增量覆盖率检查"
    exit 0
fi

# 提取修改文件的覆盖率信息
echo "提取增量覆盖率数据..."
if lcov --extract "$COVERAGE_FILE" $ABSOLUTE_FILES -o incremental_coverage.info 2>/dev/null; then
    # 生成增量覆盖率HTML报告
    genhtml incremental_coverage.info -o incremental_coverage_html --title "增量覆盖率报告" 2>/dev/null || true
    
    # 计算增量覆盖率
    INCREMENTAL_COVERAGE=$(lcov --summary incremental_coverage.info 2>&1 | grep "lines......" | awk '{print $2}' | sed 's/%//' || echo "0")
    
    echo "增量代码覆盖率: ${INCREMENTAL_COVERAGE}%"
    
    # 检查增量覆盖率是否达到阈值
    if awk "BEGIN {if($INCREMENTAL_COVERAGE >= $THRESHOLD) exit 0; else exit 1}"; then
        echo "✅ 增量覆盖率测试通过: ${INCREMENTAL_COVERAGE}% >= ${THRESHOLD}%"
        exit 0
    else
        echo "❌ 增量覆盖率测试失败: ${INCREMENTAL_COVERAGE}% < ${THRESHOLD}%"
        echo "💡 请为新增和修改的代码添加足够的测试用例"
        echo ""
        echo "修改的文件及其覆盖率详情："
        lcov --list incremental_coverage.info 2>/dev/null || true
        exit 1
    fi
else
    echo "⚠️  无法生成增量覆盖率报告，可能修改的文件没有覆盖率数据"
    echo "请确保修改的代码有对应的测试用例"
    exit 1
fi 
