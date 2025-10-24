#include<cstdio>
using namespace std;
struct node
{int x;
 int value;
 int next;
};
node e[60000];
int visited[1505],dis[1505],st[1505],queue[1000];
int main()
{
  int n,m,u,v,w,start,h,r,cur;
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    for(int i=1;i<=1500;i++)
      {visited[i]=0;
       dis[i]=-1;
       st[i]=-1;  //这个初始化给下边那个while循环带来影响
      }
 
   for(int i=1;i<=m;i++)
      {
       scanf("%d%d%d\n",&u,&v,&w);    
       e[i].x=v;            //记录后继节点    相当于链表中的创建一个节点，并使得数据域先记录
       e[i].value=w;
       e[i].next=st[u];     //记录顶点节点的某一个边表节点的下标，相当于在链表中吧该边表节点的next指针先指向他的后继边表节点
       st[u]=i;                //把该顶点的指针指向边表节点，相当于链表中的插入中，头结点的指针改变
      }
    start=1;
    visited[start]=1;
    dis[start]=0;
    h=0;
    r=1;
    queue[r]=start;
    while(h!=r)
     {

      h=(h+1)%1000;
      cur=queue[h];
      int tmp=st[cur];
      visited[cur]=0;
    

     while(tmp!=-1)
        {
            if (dis[e[tmp].x]<dis[cur]+e[tmp].value)            //改成大于号才对
            {
                   dis[e[tmp].x]=dis[cur]+e[tmp].value;
                    if(visited[e[tmp].x]==0)
                      {

                           visited[e[tmp].x]=1;
                           r=(r+1)%1000;
                            queue[r]=e[tmp].x;
                       }
            }
         tmp=e[tmp].next;     
        }
     }
    printf("%d\n",dis[n]);
  }
  return 0;  
}


