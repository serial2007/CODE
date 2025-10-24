#include <vector>
#include <iostream>
using namespace std;
const int N = 110000;
vector<int> h[N];
int n,ans = N;
bool f[N];
int dfs(int u){
   
    f[u] = true;
    int sum = 1,res = 0;
    for(int i=0;i<h[u].size();i++){
   
        if(!f[h[u][i]]){
   
            int s = dfs(h[u][i]);
            res = max(res,s); 
            sum += s;
        }
    }
    res = max(res,n - sum);
    ans = min(res,ans);
    return sum;
}
int main(){
   
    cin >> n;
    for(int i=1;i<=n;i++){
   
        int a,b;
        cin >> a >>b;
        h[a].push_back(b);
        h[b].push_back(a);
    }
    dfs(1);
    cout << ans << endl;
}
