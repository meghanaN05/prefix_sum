#include <bits/stdc++.h>
using namespace std;

const int maxi = 100010;

int n, m;
long long y[maxi], z[maxi];

int main() {
    cin >> n;
    for (int i= 1; i<= n; i++) {
        int v;
        cin >> v;
        y[i] = z[i] = v;
    }

    sort(y + 1, y + n + 1);

    for (int i = 1; i <= n; i++) {
        z[i] += z[i - 1];
        y[i] += y[i - 1];
    }

    cin >> m;
    for (int i = 1; i<= m; i++) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) 
            cout << z[r] - z[l - 1] << "\n";
        else 
            cout << y[r] - y[l - 1] << "\n";
    }

    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// #define int long long
// #define endl '\n'



// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;
//     int arr[n];
//      int a[10001],b[10001];
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//     }
//     for(int i=1;i<=n;i++){
//         arr[i]=a[i]=b[i];
//     }
//     sort(a+1,a+n+1);
//     for(int i=1;i<=n;i++){
//         a[i]+=a[i-1];
//         b[i]+=b[i-1];
//     }
//     int m;
//     cin>>m;
//     for(int i=1;i<=m;i++){
//         int ans,l,r;
//         cin>>ans>>l>>r;
//         if(ans==1)
//         cout<<b[r]-b[l-1]<<endl;
//          else{
//             cout<<a[r]-a[l-1]<<endl;
//          }
//     }
   


//     return 0;

// }
