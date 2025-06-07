#include <iostream>
using namespace std;

const int N = 1e6 + 10;  // 定义一个常量 N，表示数组的最大长度
int arr[N];              // 定义一个全局数组 arr，长度为 N
int n;  // 定义一个全局变量 n，表示数组的实际长度

void quick_sort(int arr[], int l, int r) {
    if (l >= r)
        return;  // 如果左边界大于右边界，直接返回
    int x = arr[l], i = l - 1, j = r + 1;  // 选择基准值 x 为左边界的元素，i
                                           // 初始化为 l - 1，j 初始化为 r + 1
    while (i < j) {
        do
            i++;
        while (arr[i] < x);  // 从左向右找到第一个大于等于 x 的元素
        do
            j--;
        while (arr[j] > x);  // 从右向左找到第一个小于等于 x 的元素
        if (i < j)
            swap(arr[i], arr[j]);  // 如果 i 小于 j，交换这两个元素
    }
    quick_sort(arr, l, j);      // 递归对左半部分进行快速排序
    quick_sort(arr, j + 1, r);  // 递归对右半部分进行快速排序
}

int main() {
    // quick_sort 快速排序
    scanf("%d", &n);  // 输入数组的长度
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);   // 输入数组的元素
    quick_sort(arr, 0, n - 1);  // 调用快速排序函数
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);  // 输出排序后的数组
    return 0;
}