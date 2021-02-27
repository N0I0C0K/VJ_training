//
// Created by ncsji on 2021/2/27.
//
#include <cstdio>
#include <string.h>
const int maxn = 26;
bool map[maxn][maxn];
bool vis[maxn];
int path[maxn];

int m,n;

void dfs(int from, int count){
    path[count] = from;
    if (count == 20){
        if (map[from][m]){
            printf("%d: ",n++);
            for (int i = 1; i <= 20 ; ++i) {
                 printf(" %d",path[i]);
            }
            printf(" %d\n", m);
        }
        return;
    }
    for (int i = 1; i <= 20; ++i) {
        if (map[from][i] && !vis[i]){
            vis[i] = true;
            dfs(i, count+1);
            vis[i] = false;
        }
    }
}

int main(){
    int i1,i2,i3;
    for (int i = 1; i <= 20 ; ++i) {
        scanf("%d%d%d",&i1,&i2,&i3);
        map[i][i1] = true;
        map[i][i2] = true;
        map[i][i3] = true;
    }
    while (scanf("%d",&m) != EOF && m){
        memset(vis, false, sizeof vis);
        memset(path, 0, sizeof path);
        n = 1;vis[m] = true;
        dfs(m,1);
    }
    return 0;
}
