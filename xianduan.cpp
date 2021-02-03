#include<iostream>
#include<cstdio>
#define lint long long int
using namespace std;

const lint maxn = 100010;
const lint maxnum = 1000000010;

lint input[maxn];

struct node
{
    lint l,r;
    lint sum;
    lint lazy_tag;
}tree[maxn<<2];

void pushup(lint k){
    tree[k].sum = tree[k<<1].sum + tree[k<<1|1].sum;
}

void pushdown(lint k){
    if(tree[k].lazy_tag!=0){
        lint laz = tree[k].lazy_tag;
        tree[k<<1].lazy_tag += laz;
        tree[k<<1|1].lazy_tag += laz;
        lint mid = (tree[k].l+tree[k].r)>>1;
        tree[k<<1].sum += laz*(mid-tree[k<<1].l+1);
        tree[k<<1|1].sum += laz*(tree[k<<1|1].r - mid);
        tree[k].lazy_tag = 0;
    }
}

void build(lint k, lint l ,lint r){
    tree[k].l = l;
    tree[k].r = r;
    tree[k].lazy_tag = 0;
    if(l == r){
        tree[k].sum = input[l];
    }
    else{
        lint m = (l+r)>>1;
        build(k<<1, l, m);
        build(k<<1|1, m+1, r);
        pushup(k);
    }
}

lint query(lint l, lint r, lint k){
    if(l <= tree[k].l && r >= tree[k].r){
        return tree[k].sum;
    }
    if(tree[k].r < l || tree[k].l > r){
        return 0;
    }
    pushdown(k);
    lint res = 0;
    if(l <= tree[k<<1].r){
        res += query(l, r, k<<1);
    }
    if(r >= tree[k<<1|1].l){
        res += query(l, r, k<<1|1);
    }
    return res;
}

void updata(lint l, lint r, lint v, lint k){
    if(l <= tree[k].l && r>= tree[k].r){
        tree[k].sum += v*(tree[k].r-tree[k].l+1);
        tree[k].lazy_tag+=v;
        return;
    }
    pushdown(k);
    if(l <= tree[k<<1].r){
        updata(l, r, v, k<<1);
    }
    if(r >= tree[k<<1|1].l){
        updata(l,r, v, k<<1|1);
    }
    pushup(k);
}

int main(int argc, char const *argv[])
{
    lint n,q;
    scanf("%d%d", &n, &q);
    for(lint i = 1;i <= n; i++){
        scanf("%lld", &input[i]);
    }
    build(1, 1, n);
    while (q--)
    {
        char a[2];
        scanf("%s", a);
        lint a1,a2;
        long long a3;
        if(a[0] == 'Q'){
            scanf("%lld%lld",&a1,&a2);
            printf("%lld\n",query(a1,a2, 1));
        }
        else{
            scanf("%lld%lld%lld",&a1,&a2,&a3);
            updata(a1,a2, a3, 1);
        }
    }
    return 0;
}
