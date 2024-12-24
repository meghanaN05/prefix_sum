#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    int votes[n+1];
    for(int i=0;i<=n;i++){
        votes[i]=0;
    }
    vector<int>candidates;
    for(int i=0;i<n;i++){
        int left,right;
        cin>>left>>right;
        left--;right--;
        votes[left]++;
        votes[right+1]--;
        if(i<left || i>right){
            candidates.push_back(i+1);

        }}
        for(int i=1;i<=n;i++){
            votes[i]=votes[i]+votes[i-1];
        }
        vector<int>ans;
        for(auto candidate:candidates){
            if(votes[candidate-1]==n-1){
                ans.push_back(candidate);
            }
        }
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it<<endl;
        }
    }


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    while (k--) {
        solve();
    }

    return 0;

}