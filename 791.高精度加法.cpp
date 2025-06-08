// vector用法总结（2025年6月8日）
// 1. 声明和初始化
//    vector<int> v;           // 声明一个空的int类型vector
//    vector<int> v2(5, 0);    // 长度为5，每个元素初始为0
// 2. 添加元素
//    v.push_back(3);          // 在末尾添加元素3
// 3. 访问元素
//    int x = v[0];            // 访问第一个元素
//    int y = v.at(1);         // 安全访问第二个元素
// 4. 遍历
//    for (int i = 0; i < v.size(); i++) cout << v[i];
//    for (auto x : v) cout << x;
// 5. 删除元素
//    v.pop_back();            // 删除最后一个元素
//    v.clear();               // 清空所有元素
// 6. 其他常用操作
//    v.size();                // 返回元素个数
//    v.empty();               // 判断是否为空
//
// 在本代码中，vector用于存储高精度加法的每一位数字，方便按位操作和动态扩容。

#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 10;

// 高精度加法函数，输入两个倒序存储的数字A、B，返回它们的和（倒序存储）
vector<int> add(vector<int>& A, vector<int>& B) {
    vector<int> C;  // 存储结果
    int t = 0;      // 进位
    // 遍历A和B的每一位
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size())
            t += A[i];  // 加A的当前位
        if (i < B.size())
            t += B[i];        // 加B的当前位
        C.push_back(t % 10);  // 当前位结果
        t /= 10;              // 更新进位
    }
    if (t)
        C.push_back(1);  // 最高位有进位时补1
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;  // 输入两个大整数
    // 将字符串a倒序存入A
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    // 将字符串b倒序存入B
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    auto C = add(A, B);  // 计算高精度加法
    // 倒序输出结果
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    return 0;
}