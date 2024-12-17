#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'



int main() {
    ll n;
    cin>>n;
    ll c;
    cin>>c;
    vector<ll>start(n),end(n),cost(n);
    for(ll i=0;i<n;i++){//n
        cin>>start[i]>>end[i]>>cost[i];
    }
    set<int>st;
    for(int i=0;i<n;i++){//nlog
        st.insert(start[i]);
        st.insert(end[i]+1);
    }
    int idx=0;
    map<int,int>mp;
    for(auto it:st){//nlogn
        mp[it]=idx;
        idx++;
    }
    vector<ll>diff(idx+1,0);
    for(int i=0;i<n;i++){//nlogn
        int idx1=mp[start[i]];
        int idx2=mp[end[i]+1];
        diff[idx1]+=cost[i];
        diff[idx2]-=cost[i];
    }
    for(int i=1;i<=idx;i++){
        diff[i]+=diff[i-1];
    }
    vector<int>a(st.begin(),st.end());//n
    // vector<int>a;
    // for(auto it:st){
    //     a.push_back(it);
    // }
    ll ans=0;
    for(int i=1;i<a.size();i++){//n
        ll span=a[i]-a[i-1];
        ans+=min(diff[i-1],c)*span;
    }
    cout<<ans<<endl;
    // T.C:- O(nlogn)
}