#include <iostream>
using namespace std;
const int N = 1e6 + 10;  // 定义一个常量 N，表示数组的最大长度
int arr[N];              // 定义一个全局数组 arr，长度为 N
int n, m;

int main() {
    // 数的范围 ：　　整数二分查找
    cin >> n >> m;  // 输入数组的长度和查询个数
    for (int i = 0; i < n; i++)
        cin >> arr[i];  // 输入数组的元素
    while (m--) {
        int x;
        cin >> x;  // 输入要查询的数

        int l = 0, r = n - 1;  // 初始化二分查找的左右边界
        while (l < r) {
            int mid = (l + r) / 2;  // 计算中间位置
            if (arr[mid] >= x)      // 如果中间位置的元素大于等于 x
                r = mid;            // 将右边界移动到中间位置
            else
                l = mid + 1;  // 将左边界移动到中间位置的下一个位置
        }
        if (arr[l] != x)
            cout << "-1 -1" << endl;
        else {
            cout << l << " ";      // 输出第一个等于 x 的位置
            int l = 0, r = n - 1;  // 初始化第二次二分查找的左右边界
            while (l < r) {
                int mid = (l + r + 1) / 2;  // 计算中间位置
                if (arr[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;  // 如果中间位置的元素大于
                                  // x，将右边界移动到中间位置的前一个位置
            }
            cout << l << endl;  // 输出最后一个等于 x 的位置
        }
    }
    return 0;
}