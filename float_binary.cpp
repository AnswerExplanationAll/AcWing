#include <iostream>
using namespace std;

int main() {
    // 浮点数二分查找
    int x;
    cin >> x;                      // 输入一个整数 x
    double l = 0, r = x;           // 定义二分查找的左右边界
    while (r - l > 1e-6) {         // 当左右边界的差小于 1e-6 时停止
        double mid = (l + r) / 2;  // 计算中间位置
        if (mid * mid >= x) {      // 如果中间位置的平方大于等于 x
            r = mid;               // 将右边界移动到中间位置
        } else {
            l = mid;  // 将左边界移动到中间位置
        }
    }
    cout << l << endl;  // 输出结果
    return 0;
}