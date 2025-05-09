#include <bits/stdc++.h>
using namespace std;

int upperbound(vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += upperbound(matrix[i], x);
    }
    return cnt;
}

int MatrixMedian(vector<vector<int>> &matrix, int n, int m) {
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, n, m, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 5, 10},
        {9, 10, 12, 14, 16}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    int result = MatrixMedian(matrix, n, m);
    cout << result << endl;

    return 0;
}