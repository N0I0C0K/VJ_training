//
// Created by ncsji on 2021/2/27.
//

#include <iostream>
#include <queue>
#include <string.h>
#include <cstdio>

int map[5][5];
int direct[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool vis[5][5];
int step[5][5];
int pre[5][5];

struct pos{
    int x,y,step;
};

int bfs(pos start){
    std::queue<pos> q;
    q.push(start);
    while(!q.empty()){
        pos temp = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            pos n;
            n.x = temp.x+direct[i][0];
            n.y = temp.y+direct[i][1];
            n.step = temp.step+1;
            if (!vis[n.x][n.y] && n.x>=0 && n.x<5 &&n.y>=0 &&n.y<5 && map[n.x][n.y] != 1){
                vis[n.x][n.y] = true;
                if (n.step < step[n.x][n.y]){
                    step[n.x][n.y] = n.step;
                    pre[n.x][n.y] = temp.x*5+temp.y;
                }
                else{
                    continue;
                }
                if (n.x == 4 && n.y == 4){

                }
                else{
                    q.push(n);
                }
            }
        }
    }
    return step[4][4];
};

void dfs(int idx){
    int x = idx/5,y = idx%5;
    if (x == 0 && y == 0){
        printf("(%d, %d)\n",x,y);
        return;
    }
    dfs(pre[x][y]);
    printf("(%d, %d)\n",x,y);
}

int main(){
    memset(step, 100, sizeof step);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin>>map[i][j];
        }
    }
    pos s;
    s.x = 0;
    s.y = 0;
    s.step = 0;
    int re = bfs(s);
    dfs(24);
    return re;
}