#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int n,q;
  cin>>n>>q;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  vector<int>freq(n+1,0);
  while(q--){
    int l,r;
    cin>>l>>r;
    freq[l-1]++;
    freq[r]--;

  }
  for(int i=1;i<n;i++){
    freq[i] +=freq[i-1];
  }
  freq.pop_back();
  sort(v.rbegin(),v.rend());
  sort(freq.rbegin(),freq.rend());
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=v[i]*freq[i];
  }
  cout<<sum<<endl;

    return 0;

}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     // Input the size of the array and the number of queries
//     int n, q;
//     cin >> n >> q;

//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     // To calculate frequency of each index
//     vector<int> freq(n + 1, 0);

//     // Process each query
//     while (q--) {
//         int l, r;
//         cin >> l >> r;
//         freq[l - 1]++;       // Start of range
//         freq[r]--;           // End of range + 1
//     }

//     // Convert frequency to prefix sum to get the actual frequency for each index
//     for (int i = 1; i < n; ++i) {
//         freq[i] += freq[i - 1];
//     }

//     // Remove the extra element we used for range adjustment
//     freq.pop_back();

//     // Sort the array and frequency in descending order
//     sort(a.begin(), a.end(), greater<int>());
//     sort(freq.begin(), freq.end(), greater<int>());

//     // Calculate the maximum sum
//     long long maxSum = 0;
//     for (int i = 0; i < n; ++i) {
//         maxSum += (long long)a[i] * freq[i];
//     }

//     // Output the result
//     cout << maxSum << endl;

//     return 0;
// }
