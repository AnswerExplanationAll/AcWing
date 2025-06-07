#include <iostream>
using namespace std;

const int N = 1e6 + 10;  // 定义一个常量 N，表示数组的最大长度
int arr[N];              // 定义一个全局数组 arr，长度为 N
int temp[N];  // 定义一个临时数组用于存储合并后的结果
int n;        // 定义一个全局变量 n，表示数组的实际长度

void merge_sort(int arr[], int l, int r) {
    if (l >= r)
        return;  // 如果左边界大于等于右边界，直接返回
    int mid = (l + r) / 2;          // 计算中间位置
    merge_sort(arr, l, mid);        // 递归对左半部分进行归并排序
    merge_sort(arr, mid + 1, r);    // 递归对右半部分进行归并排序
    int i = l, j = mid + 1, k = 0;  // 初始化指针 i、j 和 k

    while (i <= mid && j <= r) {  // 当左半部分和右半部分都有元素时
        if (arr[i] <= arr[j]) {  // 如果左半部分的元素小于等于右半部分的元素
            temp[k++] = arr[i++];  // 将左半部分的元素放入临时数组
        } else {
            temp[k++] = arr[j++];  // 将右半部分的元素放入临时数组
        }
    }
    while (i <= mid) {         // 如果左半部分还有元素
        temp[k++] = arr[i++];  // 将左半部分的元素放入临时数组
    }
    while (j <= r) {           // 如果右半部分还有元素
        temp[k++] = arr[j++];  // 将右半部分的元素放入临时数组
    }
    for (int i = 0; i < k; i++) {  // 将临时数组中的元素复制回原数组
        arr[l + i] = temp[i];
    }
}

int main() {
    // merge_sort 归并排序
    cin >> n;  // 输入数组的长度
    for (int i = 0; i < n; i++)
        cin >> arr[i];          // 输入数组的元素
    merge_sort(arr, 0, n - 1);  // 调用归并排序函数
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";  // 输出排序后的数组
    return 0;
}