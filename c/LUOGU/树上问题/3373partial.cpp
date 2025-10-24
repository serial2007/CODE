#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 400005
struct seg {
	ll sum, add, mul;
	int l, r;
} s[N];

ll a[N], mod;
ll build_tree(int loc, int l,int r) {
	if(l==r) {
		s[loc].sum = a[l];
		s[loc].l = l;
		s[loc].r = r;
		return s[loc].sum;
	} else {
		ll mid = (l+r)/2;
		s[loc].sum = 
			build_tree(loc*2,l,mid) +
			build_tree(loc*2+1,mid+1,r);
		s[loc].l = l;
		s[loc].r = r;
		return s[loc].sum;
	}
}
void pushdown(int pos) { //pushdown的维护
	s[pos << 1].sum = (s[pos << 1].sum * s[pos].mul + s[pos].add * (s[pos << 1].r - s[pos << 1].l + 1)) % mod;
	s[pos << 1 | 1].sum = (s[pos << 1 | 1].sum * s[pos].mul + s[pos].add * (s[pos << 1 | 1].r - s[pos << 1 | 1].l + 1)) % mod;
	
	s[pos << 1].mul = (s[pos << 1].mul * s[pos].mul) % mod;
	s[pos << 1 | 1].mul = (s[pos << 1 | 1].mul * s[pos].mul) % mod;
	
	s[pos << 1].add = (s[pos << 1].add * s[pos].mul + s[pos].add) % mod;
	s[pos << 1 | 1].add = (s[pos << 1 | 1].add * s[pos].mul + s[pos].add) % mod;
		
	s[pos].add = 0;
	s[pos].mul = 1;
	return; 
}


int main() {
	int n,m,op,x,y,k;
	cin>>n>>m>>mod;
	for(int i=0; i<=n;i++)
		cin>>a[i];
	build_tree(1,1,n);
	while(m--) {
		cin>>op;

	}
}