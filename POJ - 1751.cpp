#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 760
#define M 1010
using namespace std;

int x[N], y[N], f[N];
int n,m,u,v,w;
struct Node
{
    int v,u,w;
}node[N];

bool cmp(Node a, Node b)
{
    return a.w<b.w;
}

int find_parent(int a)
{
    if(f[a] == a){
        return a;
    }
    return find_parent(f[a]);
}

int main(int argc, char const *argv[])
{

    scanf("%d", &n);
    //cin>>n;
    int k = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&x[i],&y[i]);
        //cin>>x[i]>>y[i];
        f[i] = i;
    }
    scanf("%d",&m);
    //cin>>m;
    int total = 1;
    for(int i = 1;i <= m; i++){
        scanf("%d%d",&u,&v);
        //cin>>u>>v;
        u = find_parent(u), v = find_parent(v);
        if(u!=v){
            f[u] = v;
            ++total;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            u = find_parent(i),v = find_parent(j);
            if(u == v) continue;
            w = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            node[++k].u=i,node[k].v=j,node[k].w=w;
        }
    }
    sort(node+1, node+1+k, cmp);
    for(int i = 1;i<=k;i++){
        u = find_parent(node[i].u), v = find_parent(node[i].v);
        if(u==v) continue;
        f[u] = v;
        total++;
        cout<<node[i].u<<" "<<node[i].v<<endl;
        if(total == n) break;
    }
    return 0;
}
