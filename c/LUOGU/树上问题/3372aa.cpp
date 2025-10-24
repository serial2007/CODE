#include <iostream>
#include <stdio.h>
using namespace std;
#define N (100001*4)
#define ll long long
ll a[N], sum[N], tag[N];
int n,m;
ll gens(int tree, int l, int r) {
	if (l>r) while(true);
	if (l==r) {sum[tree]=a[l];return a[l];}
	sum[tree] = 0;
	ll mid = (l+r)/2;
	sum[tree] += gens(tree*2,l,mid);
	sum[tree] += gens(tree*2+1,mid+1,r);
	return sum[tree];
}
ll set(int tree, int l, int r, int k, int tagw, int al, int ar, bool force=false) {
	if (l>r) while(true);
	if (l<al&&r<al || l>ar&&r>ar) {
		sum[tree]+=tagw * (r-l+1);
		tag[tree]+=tagw;
	}
	else if (l>=al&&r<=ar && !force) {
		sum[tree]+=(tagw+k) * (r-l+1);
		tag[tree]+=(tagw+k);
	}
	else {
		if (l==r) {
			sum[tree] += (tagw+k);
			tag[tree] = 0;
		}
		else {
			ll mid = (l+r)/2;
			sum[tree] = set(tree*2,l,mid,k,tag[tree]+tagw,al,ar) +
						set(tree*2+1,mid+1,r,k,tag[tree]+tagw,al,ar);
			tag[tree] = 0;
		}
	}
	return sum[tree];
} 

ll get(int tree, int l, int r, int al, int ar) {
	if (l>r) while(true);
	if (l<al&&r<al || l>ar&&r>ar) return 0;
	if (l==r) return sum[tree];
	if (al<=l && r<=ar) return sum[tree];
	ll mid = (l+r)/2;
	return get(tree*2,l,mid,al,ar) +
		   get(tree*2+1,mid+1,r,al,ar);
}


int main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	gens(1,1,n);
	int l, r, k;
	while (m--) {
		int op; cin>>op;
		if (op==1) {
			cin>>l>>r>>k;
			set(1,1,n,k,0,l,r,false);
		} else {
			cin>>l>>r;
			set(1,1,n,0,0,l,r,false);
			cout<<get(1,1,n,l,r)<<endl;
		}
	}
}

/*
5 5
1 1 1 1 1
1 1 5 4
2 1 5
2 1 3
2 2 5
*/