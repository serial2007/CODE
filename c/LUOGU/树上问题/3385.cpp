#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int to, w;
};
vector<Edge> edge[4004];
int c[4004];
int l[4004];
queue<int> q;

bool loop() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) edge[i].clear();
	int x,y,z;
	for(int i=1; i<=m; i++) {
		cin>>x>>y>>z;
		edge[x].push_back(Edge{y,z});
		if(z>=0) edge[y].push_back(Edge{x,z});
	}
	memset(c, 0, sizeof(c));
	memset(l, 0x7f,sizeof(l));
	l[1]=0;
	q.push(1); 
	while(!q.empty())
	{
		int k=q.front(); q.pop();
		for (auto& i : edge[k]) {
			if(i.w + l[k] < l[i.to]) {
				l[i.to] = i.w + l[k];
				q.push(i.to);
				if (++c[i.to] >= n) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int it; cin>>it;
	while(it--) {
		if(loop())
		cout<<"YES\n";
		else cout<<"NO\n";
	}
}