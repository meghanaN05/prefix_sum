
#include <bits/stdc++.h>
using namespace std;

const int MAX_TEMP = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    // Difference array for tracking the range updates
    vector<int> diff(MAX_TEMP + 2, 0);

    // Reading recipes and updating the difference array
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    // Calculate the prefix sum to get the temperature frequencies
    vector<int> freq(MAX_TEMP + 1, 0);
    for (int i = 1; i <= MAX_TEMP; ++i) {
        freq[i] = freq[i - 1] + diff[i];
    }

    // Determine admissible temperatures by checking if freq[i] >= k
    vector<int> admissible(MAX_TEMP + 1, 0);
    for (int i = 1; i <= MAX_TEMP; ++i) {
        admissible[i] = (freq[i] >= k) ? 1 : 0;
    }

    // Calculate the prefix sum of admissible temperatures
    vector<int> admissible_prefix(MAX_TEMP + 1, 0);
    for (int i = 1; i <= MAX_TEMP; ++i) {
        admissible_prefix[i] = admissible_prefix[i - 1] + admissible[i];
    }

    // Answer the queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << admissible_prefix[b] - admissible_prefix[a - 1] << '\n';
    }

    return 0;
}
