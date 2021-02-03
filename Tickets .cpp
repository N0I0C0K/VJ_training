#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 2010;

int dp[maxn];
int a[maxn];
int b[maxn];

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n;
    while(n--){
        cin>>k;
        for(int i = 1;i <= k;i++){
            cin>>a[i];
        }
        for(int i = 2;i <= k;i++){
            cin>>b[i];
        }
        dp[1] = a[1];
        dp[2] = min(dp[1]+a[2], b[2]);
        for(int i = 3;i <= k;i++){
            dp[i] = min(dp[i-1]+a[i],dp[i-2]+b[i]);
        }
        int h=dp[k]/3600+8;
        int m=dp[k]%3600/60;
        int s=dp[k]%60;
        if(h>12)
            printf("%02d:%02d:%02d pm\n", h-12, m, s);
        else
            printf("%02d:%02d:%02d am\n", h, m, s);
    }
    return 0;
}
