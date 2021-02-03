#include<iostream>
#include<queue>
using namespace std;

bool b[100001] = {false};
int a[100001];

int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    
    queue<int> qu;
    qu.push(n);
    int nums = 1;
    b[n] = true;
    while(qu.size() > 0){
        int temp = qu.front();
        qu.pop();
        b[temp] = true;
        if(temp == k){
            cout<<a[temp]<<endl;
            return 0;
        }
        if(temp+1<100001&&b[temp+1] == false){
            qu.push(temp+1);
            a[temp+1] = a[temp]+1;
            b[temp+1] = true;
        }
        if(temp-1>=0&&b[temp-1] == false){
            qu.push(temp-1);
            a[temp-1] = a[temp]+1;
            b[temp-1] = true;
        }
        if(temp*2<=100001 && b[temp*2] ==false){
            qu.push(temp*2);
            a[temp*2] = a[temp]+1;
            b[temp*2] = true;
        }
    }
    return 0;
}
