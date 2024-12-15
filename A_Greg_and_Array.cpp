#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> l(m + 1), r(m + 1);
    vector<long long> d(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }

   
    vector<long long> op_count(m + 2, 0);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        op_count[x]++;
        op_count[y + 1]--;
    }

    // Calculate cumulative op_count to know how many times each operation is applied
    for (int i = 1; i <= m; i++) {
        op_count[i] += op_count[i - 1];
    }

    // Apply operations to a difference array for `a`
    vector<long long> diff(n + 2, 0);
    for (int i = 1; i <= m; i++) {
        diff[l[i]] += op_count[i] * d[i];
        diff[r[i] + 1] -= op_count[i] * d[i];
    }

    // Calculate the final array using the difference array
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1]; // Cumulative sum
        a[i] += diff[i];
    }

    // Output the final array
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}