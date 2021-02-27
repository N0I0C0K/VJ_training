#include <iostream>
using namespace std;

int n,k;
char maps[10][10];
bool r[10],c[10];

int dfs(int idx, int sum){
    if (idx > n*n){
        if (sum == k)   return 1;
        else    return 0;
    }
    int ans = dfs(idx+1, sum),x = idx/n, y = idx%n;
    if (maps[x][y] == '#' && !r[x] && !c[y]){
        r[x] = c[y] = true;
        ans += dfs(idx+1,sum+1);
        r[x] = c[y] = false;
    }
    return ans;
}

int main() {
    int  i,j,a[][3]={1,2,3,4,5,6,7,8,9};

    for(i=0;i<3;i++)

        for(j=i+1;j<3;j++)    a[j][i]=0;

    for(i=0;i<3;i++)

    {  for(j=0;j<3;j++)    printf("%d  ", a[i][j]);

        printf("\n");

    }
    return 0;
}
