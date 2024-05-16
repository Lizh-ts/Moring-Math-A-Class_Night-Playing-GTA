#include<iostream>
using namespace std;
int x,y;
float a[10][10];
void Ans(){
	int b[x];
	b[x-1]=a[y-1][x]/a[y-1][x-1];
	for(int i=y-1;i>0;i--){
		for(int j=i;j>0;j--){
			a[j-1][i]*=b[i];
			a[j-1][x]-=a[j-1][i];
			a[j-1][i]=0;
		}
		b[i-1]=a[i-1][x]/a[i-1][i-1];
	}
	cout<<"ANS=";
	for(int i=0;i<x;i++){
		cout<<b[i]<<" ";
	}
}
int main(){
	cin>>x>>y;
	for(int i=0;i<y;i++){
		for (int j=0;j<x+1;j++){
			cin>>a[i][j];
		}
	}
	for(int c=0;c<y;c++){
		for(int i=c+1;i<y;i++){
			float k=a[i][c]/a[c][c];
			for(int j=c+1;j<x+1;j++){
				a[i][j]-=a[c][j]*k;
			}
		}
	}
	Ans();
	
	return 0;
}
