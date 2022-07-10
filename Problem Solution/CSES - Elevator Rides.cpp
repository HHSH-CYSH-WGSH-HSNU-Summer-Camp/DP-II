#include <bits/stdc++.h>
 
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const int N = 22;
pair<int,int> arr[1<<N];
int w[N];
 
signed main(){
    fastio
    int n, x;
    cin >> n >> x;
    for(int i = 0;i < n;i++)
        cin >> w[i];
 
    for(int i = 0;i < (1<<n);i++) arr[i] = {n+1,0};
    arr[0] = {1,0};
 
    for(int mask = 0;mask < (1<<n);mask++) {
        for(int i = 0;i < n;i++){
            if(mask&(1<<i)){
                auto tmp = arr[mask^(1<<i)];
                if(tmp.second+w[i] > x){
                    tmp = {tmp.first+1,w[i]};
                }else{
                    tmp.second += w[i];
                }
                arr[mask] = min(arr[mask],tmp);
            }
        }
    }
 
    cout << arr[(1<<n)-1].first << "\n";
}