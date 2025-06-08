#include <iostream>
using namespace std;
const int N = 1e6 + 10;
long long arr[N];
int n;
long sum = 0;

void merge_sort(long long arr[], int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    static long long temp[N];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            sum += mid - i + 1;  // 统计逆序对
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (int t = 0; t < k; t++)
        arr[l + t] = temp[t];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    cout << sum;
    return 0;
}