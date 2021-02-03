/*  不要62 HDU - 2089 
    https://vjudge.net/problem/HDU-2089
    暴力预处理
    32ms 5.3MB
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 1000010;

int f[maxn];

bool check(int x){
    while (x)
    {
        if(x %10 == 4 || x%100 == 62){
            return false;
        }
        x /= 10;
    }
    return true;
}

void init(){
    f[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if(check(i)){
            f[i] = f[i-1]+1;
        }
        else{
            f[i] = f[i-1];
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int n,m;
    init();
    while (scanf("%d%d", &n, &m) != EOF && n &&m)
    {
        printf("%d\n", f[m] - f[n - 1]);
    }
    
    return 0;
}
