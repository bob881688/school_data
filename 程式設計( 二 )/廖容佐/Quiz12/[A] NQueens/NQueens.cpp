#include "NQueens.h"
#include <cmath>

// 默认构造函数
NQueens::NQueens() : numQueens(8), numAttacks(0), permutation(numQueens, 0) {
    for (unsigned int i = 0; i < numQueens; ++i) {
        permutation[i] = i;
    }
    calculateAttacks();
}

// 带参数的构造函数
NQueens::NQueens(unsigned int n) : numQueens(n), numAttacks(0), permutation(numQueens, 0) {
    for (unsigned int i = 0; i < numQueens; ++i) {
        permutation[i] = i;
    }
    calculateAttacks();
}

// 复制构造函数
NQueens::NQueens(const NQueens& other) {
    copyFrom(other);
}

// 赋值操作符
NQueens& NQueens::operator=(const NQueens& other) {
    if (this != &other) {
        copyFrom(other);
    }
    return *this;
}

// 计算攻击次数
NQueens& NQueens::calculateAttacks() {
    numAttacks = 0;
    for (unsigned int i = 0; i < numQueens; ++i) {
        for (unsigned int j = i + 1; j < numQueens; ++j) {
            if (permutation[i] == permutation[j] || 
                std::abs(static_cast<int>(permutation[i] - permutation[j])) == static_cast<int>(j - i)) {
                numAttacks++;
            }
        }
    }
    return *this; // 返回当前对象的引用
}

// 获取皇后数量
unsigned int NQueens::getNumQueens() const {
    return numQueens;
}

// 获取攻击次数
unsigned int NQueens::getNumAttacks() const {
    return numAttacks;
}

// 复制数据的辅助方法
void NQueens::copyFrom(const NQueens& other) {
    numQueens = other.numQueens;
    numAttacks = other.numAttacks;
    permutation = other.permutation;
}

// 流插入操作符
std::ostream& operator<<(std::ostream& os, const NQueens& nq) {
    for (unsigned int i = 0; i < nq.numQueens; ++i) {
        os << nq.permutation[i] << " ";
    }
    os << ": " << nq.numAttacks << " Attacks";
    return os;
}

// 流提取操作符
std::istream& operator>>(std::istream& is, NQueens& nq) {
    is >> nq.numQueens;
    if (nq.numQueens == 0) return is; // Stop reading if numQueens is 0

    nq.permutation.resize(nq.numQueens);
    
    for (unsigned int i = 0; i < nq.numQueens; ++i) {
        for (unsigned int j = 0; j < nq.numQueens; ++j) {
            int value;
            is >> value;
            if (value == 1) {
                nq.permutation[i] = j;
            }
        }
    }

    nq.calculateAttacks();
    return is;
}

// 转换操作符
NQueens::operator unsigned int*() {
    return permutation.data();
}