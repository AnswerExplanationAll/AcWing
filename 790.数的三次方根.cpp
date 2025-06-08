#include <iostream>
using namespace std;

// 输入的数
double n;

int main() {
    cin >> n;  // 读入待求三次方根的数
    double l, r;
    // 区间初始化：正数时从0到n或1，负数时从n或-1到0
    if (n >= 0) {
        l = 0, r = max(1.0, n);  // 兼容n在[0,1)的情况
    } else {
        l = min(n, -1.0), r = 0;  // 兼容n在(-1,0)的情况
    }
    // 二分法求三次方根，精度1e-7
    while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        if (mid * mid * mid < n)
            l = mid;  // mid立方小于n，根在右侧
        else
            r = mid;  // mid立方大于等于n，根在左侧
    }
    cout << fixed;      // 固定小数位输出
    cout.precision(6);  // 保留6位小数
    cout << l << endl;  // 输出三次方根
    return 0;
}