#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct query{
    ll sparse[101];
} dot[200001];
int main() {
    ll m, q, i, j, n, x, point;
    
    cin>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%lld", &dot[i].sparse[1]);
    }
    for(i=1;i<=m;i++)
    {
        for(j=2;j<=100;j++)
        {
            dot[i].sparse[j]=dot[dot[i].sparse[j-1]].sparse[j-1];
        }
    }
    cin>>q;
    for(i=1;i<=q;i++)
    {
        scanf("%lld %lld", &n, &x);
        point=x;
        ll imsi=1;
        while(n!=0)
        {
            if(n%2)
            point=dot[point].sparse[imsi];
            imsi++;
            n/=2;
        }
        printf("%lld\n", point);
    }
    return 0;
}
