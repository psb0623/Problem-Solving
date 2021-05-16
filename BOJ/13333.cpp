#include <bits/stdc++.h>
using namespace std;
int n,a[1010];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=n;i>0;i--) if(a[n-i]>=i) return !printf("%d",i);
    printf("0");
}
