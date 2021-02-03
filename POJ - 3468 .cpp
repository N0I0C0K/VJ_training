#include<iostream>

using namespace std;

const int maxnum = 1000000001;
const int maxn = 100010;
long long int input[maxn],tree[maxn<<2],lazy[maxn<<2];

void pushup(int k){
    tree[k] = tree[k<<1]+tree[k<<1|1];
}

void pushdown(int k){
    if(lazy[k]){
        lazy[k<<1] += lazy[k];
        lazy[k<<1|1] += lazy[k];
        int mid = (k<<1+k<<1+1)>>1;        
        tree[k<<1] += lazy[k]*(mid-k<<2+1);
        tree[k<<1|1] += lazy[k]*(k<<2+3-mid);
        lazy[k] = 0;
    }
}

void build(int k, int l, int r){
    if(l == r){
        tree[k] = input[l];
    }
    else{
        int m = (l+r)>>1;
        build(k<<1, l, m);
        build(k<<1|1, m+1, r);
        pushup(k);
    }
}

long long int query(int L, int R, int l, int r, int k){
    if(L<=l && R>=r){
        return tree[k];
    }
    pushdown(k);
    long long int res = 0;
    int mid = (l+r)>>1;
    if(L <= mid){
        res += query(L, R, l, mid, k<<1);
    }
    if( R > mid){
        res += query(L, R, mid+1, r, k<<1|1);
    }
    return res;
}

void update(int p, int v, int l, int r, int k){
    if(l == r){
        input[p] += v;
        tree[k] += v;
    }
    else{
        int m = (l+r)>>1;
        if(p <= m){
            update(p, v, l, m, k<<1);
        }
        else{
            update(p, v, m+1, r, k<<1|1);
        }
        pushup(k);
    }
}

void update(int L, int R, int v, int l, int r, int k){
    if(L <= l && R >= r){
        lazy[k] += v;
        tree[k] += v*2;
    }
    else{
        pushdown(k);
        int m = (l+r)>>1;
        if(L<=m){
            update(L,R,v,l,m,k<<1);
        }
        if(R>m){
            update(L,R,v,m+1,r,k<<1|1);
        }
        pushup(k);
    }
}

int main(int argc, char const *argv[])
{
    int n,q;
    cin>>n>>q;
    for(int i = 1;i <= n; i++){
        cin>>input[i];
    }
    build(1, 1, n);
    while (q--)
    {
        char a[2];
        cin>>a;
        int a1,a2;
        long long a3;
        if(a[0] == 'Q'){
            cin>>a1>>a2;
            cout<<query(a1,a2,1, n, 1)<<endl;
        }
        else{
            cin>>a1>>a2>>a3;
            update(a1,a2, a3, 1, n, 1);
        }
    }
    return 0;
}
