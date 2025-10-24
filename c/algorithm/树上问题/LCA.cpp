// P3384
#include <iostream>
#include <stdio.h>

const int N = 1e5 + 5;
using namespace std;

int n,m,root,p,a[N];
struct Edge{
	int to,next;
}edge[N<<2];
int head[N], depth[N];
int parents[N][20]; // 倍增

void get_parent(int k, int pa, int d=1) {
	if(!k) return;
	int p=pa;
	for(int i=0; i<20; i++) {
		if(p == 0) break;
		parents[k][i] = p;
		p = parents[p][i];
	}
	depth[k] = d;
	for(int u=head[k]; u; u=edge[u].next) {
		if(edge[u].to == pa) continue;
		get_parent(edge[u].to, k, d+1);
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	for(int i=19; i>=0; i--){
		if(depth[parents[u][i]] < depth[v]) continue;
		u=parents[u][i];
	}
	if(u==v) return u;
	for(int i=19; i>=0; i--){
		if(parents[u][i] == parents[v][i]) continue;
		u=parents[u][i], v=parents[v][i];
	}
	return parents[u][0];
}
int main() {
	cin>>n;
	int it=0;
	for(int i=1; i<n; i++) {
		int x,y; 
		cin>>x>>y;
		edge[++it] = Edge{y,head[x]};
		head[x] = it;
		edge[++it] = Edge{x,head[y]};
		head[y] = it;
	}
	get_parent(root=1, 0, 1);
	int x,y;
	while(cin>>x>>y){
		cout<<lca(x,y)<<endl;
	}
}


// int main() {
// 	cin>>n>>m>>root>>p;
// 	for(int i=1; i<=n; i++) cin>>a[i];
// 	int it=0;
// 	for(int i=1; i<n; i++) {
// 		int x,y; 
// 		cin>>x>>y;
// 		edge[++it] = Edge{y,head[x]};
// 		head[x] = it;
// 		edge[++it] = Edge{x,head[y]};
// 		head[y] = it;
// 	}
// 	while(m--){

// 	}
// }