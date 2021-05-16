#include <stdio.h>
int min(int m, int n)
{
   if(m<n) return m;
   else return n;
}
int main()
{
   int N, M, i, j, x, y, p, q, t;
   t=64;
   char a[50][50];
   scanf("%d %d", &N, &M);
   for(i=0; i<N; i++){
	for(j=0; j<M; j++){
		 scanf("%c", &a[i][j]);
	}
	scanf("%c");
}
         
         
/*	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%c",a[i][j]);
		}
		puts("");
	}*/
   for(i=0; i<=N-8; i++)
   {
      for(j=0; j<=M-8; j++)
      {
         p=0;
         q=0;
         for(x=i; x<i+8; x++)
         {
            for(y=j; y<j+8; y++)
            {
            	//printf("(%d,%d) : %d %c\n",x,y,(x+y)%2,a[x][y]);
               if(((x+y)%2==0&&a[x][y]=='W')||((x+y)%2!=0&&a[x][y]=='B'))
                  p+=1;
               else q+=1;
            }
         }
         t=min(t, min(p, q));
         printf("%d\n", t);
      }
   }
   printf("%d", t);
   return 0;
}
