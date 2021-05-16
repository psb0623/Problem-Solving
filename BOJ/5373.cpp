#include<bits/stdc++.h>
using namespace std;
char oU[3][4] = {"www","www","www"};
char oD[3][4] = {"yyy","yyy","yyy"};
char oF[3][4] = {"rrr","rrr","rrr"};
char oB[3][4] = {"ooo","ooo","ooo"};
char oL[3][4] = {"ggg","ggg","ggg"};
char oR[3][4] = {"bbb","bbb","bbb"};
char U[3][4],D[3][4],F[3][4],B[3][4],L[3][4],R[3][4];

void init(){
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
		U[i][j] = oU[i][j];
		D[i][j] = oD[i][j];
		F[i][j] = oF[i][j];
		B[i][j] = oB[i][j];
		L[i][j] = oL[i][j];
		R[i][j] = oR[i][j];
	}
}

void Up(){
	char tmp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tmp[i][j] = U[2-j][i];
		}
	}
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) U[i][j] = tmp[i][j];
	
	for(int i=0;i<3;i++){
		int t = F[0][i];
		F[0][i] = R[0][i];
		R[0][i] = B[0][i];
		B[0][i] = L[0][i];
		L[0][i] = t;
	}
}

void Dp(){
	char tmp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tmp[i][j] = D[2-j][i];
		}
	}
	
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) D[i][j] = tmp[i][j];
	
	for(int i=0;i<3;i++){
		int t = F[2][i];
		F[2][i] = L[2][i];
		L[2][i] = B[2][i];
		B[2][i] = R[2][i];
		R[2][i] = t;
	}
}

void Lp(){
	char tmp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tmp[i][j] = L[2-j][i];
		}
	}
	
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) L[i][j] = tmp[i][j];
	
	for(int i=0;i<3;i++){
		int t = U[i][0];
		U[i][0] = B[2-i][2];
		B[2-i][2] = D[i][0];
		D[i][0] = F[i][0];
		F[i][0] = t;
	}
}

void Rp(){
	char tmp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tmp[i][j] = R[2-j][i];
		}
	}
	
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) R[i][j] = tmp[i][j];
	
	for(int i=0;i<3;i++){
		int t = U[i][2];
		U[i][2] = F[i][2];
		F[i][2] = D[i][2];
		D[i][2] = B[2-i][0];
		B[2-i][0] = t;
	}
}

void Fp(){
	char tmp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tmp[i][j] = F[2-j][i];
		}
	}
	
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) F[i][j] = tmp[i][j];
	
	for(int i=0;i<3;i++){
		int t = R[i][0];
		R[i][0] = U[2][i];
		U[2][i] = L[2-i][2];
		L[2-i][2] = D[0][2-i];
		D[0][2-i] = t;
	}
}

void Bp(){
	char tmp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tmp[i][j] = B[2-j][i];
		}
	}
	
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) B[i][j] = tmp[i][j];
	
	for(int i=0;i<3;i++){
		int t = R[i][2];
		R[i][2] = D[2][2-i];
		D[2][2-i] = L[2-i][0];
		L[2-i][0] = U[0][i];
		U[0][i] = t;
	}
}


int main(){
	
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			if(s == "L+") Lp();
			if(s == "L-") for(int j=0;j<3;j++) Lp();
			if(s == "R+") Rp();
			if(s == "R-") for(int j=0;j<3;j++) Rp();
			if(s == "U+") Up();
			if(s == "U-") for(int j=0;j<3;j++) Up();
			if(s == "D+") Dp();
			if(s == "D-") for(int j=0;j<3;j++) Dp();
			if(s == "F+") Fp();
			if(s == "F-") for(int j=0;j<3;j++) Fp();
			if(s == "B+") Bp();
			if(s == "B-") for(int j=0;j<3;j++) Bp();
		}
	
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++) printf("%c",U[i][j]);
			printf("\n");
		}
	}
}
