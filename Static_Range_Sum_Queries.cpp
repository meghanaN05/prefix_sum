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
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int>prev(n+1,0);
    for(int i= 1;i<=n;i++){
        prev[i]=prev[i-1]+v[i-1];
    }
    
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<prev[b]-prev[a-1]<<endl;
    }

    return 0;

}