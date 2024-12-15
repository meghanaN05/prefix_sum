#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

void solve() {
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    int sum=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans+=mp[sum-x];
        if(sum==x) ans++;
        mp[sum]++;
    }
    cout<<ans<<endl;

    return 0;

}