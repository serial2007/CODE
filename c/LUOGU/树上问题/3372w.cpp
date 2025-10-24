#include<iostream>
#include<cstdio>
#define MAXN 1000001
#define ll long long
using namespace std;
unsigned ll n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];

void build(ll p,ll l,ll r)
{
	tag[p] =0 ;
	if(l==r) {
		ans[p] = a[l];return;
	}
	ll mid=(l+r)/2;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
} 
inline void f(ll p, ll l, ll r, ll k) {
    tag[p] = tag[p] + k;
    ans[p] = ans[p] + k * (r - l + 1);
}
void push_down(ll p, ll l, ll r) {
	ll mid = (l+r)/2;
	f(p*2, l, mid, tag[p]);
    f(p*2+1, mid + 1, r, tag[p]);
    tag[p] = 0;
}
void push_up(ll p) {
    ans[p] = ans[p*2] + ans[p*2+1];
}
inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k)
{
	if(nl<=l && r<=nr) {
		ans[p] += k*(r-l+1);
		tag[p] += k;
		return;
	}
	push_down(p, l, r);
	ll mid = (l+r)/2;
	if (nl<=mid) update(nl,nr,l,mid,p*2,k);
	if (nr>mid)  update(nl,nr,mid+1,r,p*2+1,k);
	push_up(p);
}
ll query(ll q_x,ll q_y,ll l,ll r,ll p)
{
	ll res = 0;
	if (q_x<=l && r<=q_y) return ans[p];
	ll mid = (l+r)/2;
	push_down(p, l, r);
    if (q_x <= mid) res += query(q_x, q_y, l, mid, p*2);
    if (q_y > mid) res += query(q_x, q_y, mid + 1, r, p*2+1);
    return res;
}
int main()
{
    ll a1,b,c,d,e,f;
    cin>>n>>m;
    for(unsigned ll i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--)
    {
        scanf("%lld",&a1);
        switch(a1)
        {
            case 1:{
                scanf("%lld%lld%lld",&b,&c,&d);
                update(b,c,1,n,1,d);
                break;
            }
            case 2:{
                scanf("%lld%lld",&e,&f);
                printf("%lld\n",query(e,f,1,n,1));
                break;
            }
        }
    }
    return 0;
}