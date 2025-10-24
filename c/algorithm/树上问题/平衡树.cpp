#include <bits/stdc++.h>
using namespace std;
/*
https://www.cnblogs.com/ac-evil/p/11755354.html
平衡树是一种十分有用的数据结构，它能支持以下操作：
1、插入一个数x
2、删除一个数x
3、查询一个数x（其排名，其前驱后继）
4、查询排名为k的数x
5、快速合并与分裂
6、维护区间修改、查询、翻转
7、维护其它信息
*/

struct Node {
	Node *ch[2]; // 结点的左右孩子。为什么不分开写成lc,rc呢？往后就知道了
	int v, s, c; // v表示该结点的值，s表示以该结点为根的子树大小，
	// c表示权值v的结点数量（合并了相同权值的结点），即v的副本数量
	int r; // Treap专有的随机数，是大根堆的关键字
	void maintain() { // 维护当前结点的信息
		s = ch[0]->s + ch[1]->s + c;
	}
	Node(int v) : v(v), c(1), s(1), r(rand()) { ch[0] = ch[1] = nil; } // 新建结点
} *root;
struct Node *nil;

void init() {
	srand(0);
	nil = new Node(0);
	root = nil->ch[0] = nil->ch[1] = nil;
	nil->s = nil->c = 0;
}

// d=0代表左旋，d=1代表右旋
void rotate(Node* &o, int d) {
	Node *k = o->ch[!d];
	o->ch[!d] = k->ch[d];
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;
}

void insert(Node* &o, int v) {
	if (o==nil) {o=new Node(v); return;}
	if (o->v == v) {o->c++; o->s++; return;}
	int d = (v < o->v) ? 0 : 1;
	insert(o->ch[d], v);

	if(o->r < o->ch[d]->r) rotate(o, !d);
	o->maintain();
}

int remove(Node* &o, int v) {
	if (o==nil) return -1;
	if (o->v == v) {
		if (! --o->c) // 如果只有一个副本
		{
			if (o->ch[0]==nil || o->ch[1]==nil) {
				Node * p = o;
				o = o->ch[o->ch[1]==nil ? 0 : 1];
				delete p;
			} else{
				int d = o->ch[0]->r  >  o->ch[1]->r  ? 0:1;
				rotate(o, !d);
				remove(o->ch[!d], v);
			}
		}
	}
	else remove(o->ch[v < o->v ? 0 : 1], v);
	if (o != nil) o->maintain();
}
