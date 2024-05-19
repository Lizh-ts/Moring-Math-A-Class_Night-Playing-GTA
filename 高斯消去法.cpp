#include<iostream>
using namespace std;
//Lizh-ts
int x,y;
float a[10][10];
int chk(int r){
	int zero=0;
		for(int k=0;k<x;k++){
			if(a[r][k]==0){
				zero+=1;
			}
		}
		if(zero==x){
			r-=1;
		}
		return r;
	}
void Ans(){
	int b[x];
	int h=x-1;
	for(int i=y-1;i>=0;i--){
		while(a[i][h]==0){
			i=chk(i);
			if(a[i][0]!=0){
				break;
			}
		}
		if(a[i][h]==0 and a[i][x]!=0){
			cout<<i<<"無解"<<endl;
			break;
		}
		if(a[i][x]==0 and a[i][h]==0){
			cout<<i<<"有無限解"<<endl;
			break;
		}
		if(a[i][h]!=0){
			b[h]=a[i][x]/a[i][h];
			for(int j=i;j>0;j--){
				a[j-1][h]*=b[h];
				a[j-1][x]-=a[j-1][h];
				a[j-1][h]=0;
			}
			h--;
		}
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
	int d=0;
	for(int c=0;c<y;c++){
		for(int i=c+1;i<y;i++){
			if(d>=x){
				break;
			}
			if(a[c][d]==0){
				d++;
			}
			float k=a[i][d]/a[c][d];
			for(int j=0;j<x+2;j++){
				a[i][j]-=a[c][j]*k;
			}
		}
		d++;
	}
	Ans();
	
	return 0;
}
