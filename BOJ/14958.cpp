#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

typedef complex<double> base;
  
void fft(vector <base> &a, bool invert)
{
    int n = sz(a);
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*acos(-1)/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
  
void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
}
 
int n,m;
map<char, int> mp;
char A[100010], B[100010];
 
int main(){
    mp['R'] = 0;
	mp['P'] = 1;
	mp['S'] = 2;
    scanf("%d %d",&n, &m);
    scanf("%s %s",A,B);
    
    vector<int> res(n+m,0); 
    for(int i=0;i<n;i++) A[i] = (mp[A[i]]+1)%3;
    for(int i=0;i<m;i++) B[i] = mp[B[i]];
    for(int i=0;i<3;i++){
        vector<int> a(n+m,0),b(m,0),tmp;
        for(int j=0;j<n;j++) a[j] = (A[j]==i)?1:0;
        for(int j=0;j<m;j++) b[j] = (B[m-j-1]==i)?1:0;
        multiply(a,b,tmp);
        for (int j=0;j<n+m;j++) res[j] += tmp[j];
    }
    
    int ans=0;
    
    for(int i=m-1;i<n+m;i++) ans = max(ans, res[i]);
    printf("%d", ans);
}
