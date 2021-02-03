#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs()
{
    
}

int main(int argc, char const *argv[])
{
    int citys;
    cin>>citys;
    while(citys--)
    {
        vector<vector<int>> maps(1000);
        int n,m;
        cin>>n>>m;
        while (m--)
        {
            int x,y,wight;
            cin>>x>>y>>wight;
            maps[x].push_back(y);
        }
        
    }
    
    return 0;
}
