#include <bits/stdc++.h>
 
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const int N = 22;
int dp[N][1<<N], dis[N][N];
 
 
signed main(){
    fastio
    int n;
    cin >> n;
 
    vector<array<int,3>> v;
    for(int i = 0;i < n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        v.push_back({x,y,z});
    }
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            dis[i][j] = abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1])+max((int)0, v[j][2]-v[i][2]);
            dis[j][i] = abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1])+max((int)0, v[i][2]-v[j][2]);
        }
    }

    memset(dp,0x3f3f3f3f,sizeof dp);

    dp[0][1] = 0;
 
    for(int mask = 0;mask < (1<<n);mask++){
        for(int u = 0;u < n;u++){
            if(mask&(1<<u)){
                for(int v = 0;v < n;v++){
                    if(mask&(1<<v)) continue;
                    dp[v][mask^(1<<v)] = min(dp[v][mask^(1<<v)], dp[u][mask] + dis[u][v]);
                }
            }
        }
    }
 
    int ans = 1e18;
    for(int i = 1;i < n;i++){
        ans = min(ans,dp[i][(1<<n)-1] + dis[i][0]);
    }

    cout << ans << "\n";
}