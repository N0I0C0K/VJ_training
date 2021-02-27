//
// Created by ncsji on 2021/2/26.
//
#include <cstdio>
#include <queue>
#include <string.h>

const int N = 35;
int l,r,c;
char maps[N][N][N];
bool visited[N][N][N];
int direct[6][3] = {{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

struct pos{
    int x,y,z,step;
};
pos start;

int bfs(pos st){
    std::queue<pos> q;
    q.push(st);
    while (!q.empty()){
        pos temp = q.front();
        q.pop();
        for (int i = 0; i < 6; ++i) {
            pos new_pos;
            new_pos.x = temp.x + direct[i][0];
            new_pos.y = temp.y + direct[i][1];
            new_pos.z = temp.z + direct[i][2];
            new_pos.step = temp.step + 1;
            if (!visited[new_pos.x][new_pos.y][new_pos.z] && new_pos.x >= 1 && new_pos.x <= l && new_pos.y >= 1 && new_pos.y <= r && new_pos.z >= 1 && new_pos.z <= c && maps[new_pos.x][new_pos.y][new_pos.z] != '#'){
                visited[new_pos.x][new_pos.y][new_pos.z] = true;
                if (maps[new_pos.x][new_pos.y][new_pos.z] == 'E'){
                    return  new_pos.step;
                }
                q.push(new_pos);
            }
        }
    }
    return -1;
}

int main(){
    while (~scanf("%d%d%d", &l, &r, &c)){
        if (c == 0 && r == 0 && l == 0){
            break;
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= l; ++i) {
            for (int j = 1; j <= r; ++j) {
                for (int k = 1; k <= c; ++k) {
                    scanf("%c",&maps[i][j][k]);
                    if (maps[i][j][k] == 'S'){
                        start.x = i;
                        start.y = j;
                        start.z = k;
                        start.step = 0;
                    }
                }
            }
        }
        int t = bfs(start);
        if (t != -1){
            printf("Escaped in %d minute(s).\n", t);
        }
        else
            printf("Trapped!\n");

    }
    return 0;
}