#ifndef NQUEENS_H
#define NQUEENS_H

#include <iostream>
#include <vector>

class NQueens {
public:
    // 默认构造函数
    NQueens();

    // 带参数的构造函数
    NQueens(unsigned int n);

    // 复制构造函数
    NQueens(const NQueens& other);

    // 赋值操作符
    NQueens& operator=(const NQueens& other);

    // 计算攻击次数
    NQueens& calculateAttacks(); // 返回引用以支持链式调用

    // 获取皇后数量
    unsigned int getNumQueens() const;

    // 获取攻击次数
    unsigned int getNumAttacks() const;

    // 重载流插入操作符
    friend std::ostream& operator<<(std::ostream& os, const NQueens& nq);

    // 重载流提取操作符
    friend std::istream& operator>>(std::istream& is, NQueens& nq);

    // 转换操作符，将类对象转换为无符号整数指针
    operator unsigned int*();

private:
    unsigned int numQueens; // 皇后数量
    unsigned int numAttacks; // 攻击次数
    std::vector<unsigned int> permutation; // 排列表示

    // 从另一个对象复制数据的辅助方法
    void copyFrom(const NQueens& other);
};

#endif // NQUEENS_H