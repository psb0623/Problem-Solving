#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char s[50],t;
		scanf("%s",s);
		int n = strlen(s);
		if(!strcmp(s+n-2,"ne")){
			s[n-2]='\0';
			printf("%sanes\n",s);
			continue;
		}
		t=s[n-1];
		s[n-1]='\0';
		switch(t){
			case 'a':
				printf("%sas",s);
				break;
			case 'i':
				printf("%sios",s);
				break;
			case 'y':
				printf("%sios",s);
				break;
			case 'l':
				printf("%sles",s);
				break;
			case 'n':
				printf("%sanes",s);
				break;
			case 'o':
				printf("%sos",s);
				break;
			case 'r':
				printf("%sres",s);
				break;
			case 't':
				printf("%stas",s);
				break;
			case 'u':
				printf("%sus",s);
				break;
			case 'v':
				printf("%sves",s);
				break;
			case 'w':
				printf("%swas",s);
				break;
			default:
				printf("%s%cus",s,t);
				break;
		}
		printf("\n");
	}
}
