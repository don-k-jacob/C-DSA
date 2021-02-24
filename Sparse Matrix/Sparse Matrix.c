#include<stdio.h>

#define MAX 40

int sparseIn(int [][3],int,int);
int sparseAdd(int [][3],int [][3],int [][3]);
void sumDisp(int [][3]);
void sparseDisp(int [][3]);

int main(){
	int sp1[MAX][3],sp2[MAX][3],sp3[MAX][3],m,n,p,q,r;
	printf("\nEnter Dimensions of Matrix : ");
	scanf("%d%d",&m,&n);
	printf("\nEnter Matrix 1 : \n");
	p = sparseIn(sp1,m,n);
	printf("\nEnter Matrix 2 : \n");
	q = sparseIn(sp2,m,n);
	printf("\nMatrix 1 in Sparse Form \n");
	sparseDisp(sp1);
	printf("\nMatrix 2 in Sparse Form \n");
	sparseDisp(sp2);
	r = sparseAdd(sp1,sp2,sp3);
	printf("\nResultant Matrix \n");
	sumDisp(sp3);
	printf("\nResultant Matrix in Sparse Form \n");
	sparseDisp(sp3);
	return 0;
}

int sparseIn(int sp[][3],int m,int n){
	int i,j,r=1,t;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&t);
			if(t!=0){
				sp[r][0] = i;
				sp[r][1] = j;
				sp[r++][2] = t;
			}
		}
	}
	sp[0][0] = m;
	sp[0][1] = n;
	sp[0][2] = --r;
	return r;
}

int sparseAdd(int sp1[][3], int sp2[][3],int sp3[][3]){
	int i,j,r=1;
	for(i=1,j=1; i<=sp1[0][0] && j<=sp1[0][0];){
		if(sp1[i][0]==sp2[j][0]&&sp1[i][1]==sp2[j][1]){
			sp3[r][0] = sp1[i][0];
			sp3[r][1] = sp1[i][1];
			sp3[r++][2] = sp1[i++][2]+sp2[j++][2];
		}else if((sp1[i][0]<sp2[j][0])||((sp1[i][0]==sp2[j][0])&&(sp1[i][1]<sp2[j][1]))){
			sp3[r][0] = sp1[i][0];
			sp3[r][1] = sp1[i][1];
			sp3[r++][2] = sp1[i++][2];
		}else{
			sp3[r][0] = sp2[j][0];
			sp3[r][1] = sp2[j][1];
			sp3[r++][2] = sp2[j++][2];
		}
	}

	while(i<=sp1[0][0]){
		sp3[r][0] = sp1[i][0];
		sp3[r][1] = sp1[i][1];
		sp3[r++][2] = sp1[i++][2];
	}

	while(j<=sp1[0][1]){
		sp3[r][0] = sp2[j][0];
		sp3[r][1] = sp2[j][1];
		sp3[r++][2] = sp2[j++][2];
	}
	sp3[0][0] = sp1[0][0];
	sp3[0][1] = sp1[0][1];
	sp3[0][2] = --r;
	return r;
}

void sumDisp(int sp[][3]){
	int i,j,k=1;
	for(i=0; i<sp[0][0] ;i++){
		for(j=0;j<sp[0][1];j++){
			if(k<=sp[0][2]&&sp[k][0]==i&&sp[k][1]==j)
				printf("%d\t",sp[k++][2]);
			else
				printf("0\t");
		}
		printf("\n");
	}
}

void sparseDisp(int sp[][3]){
	int i,j,k=1;
	printf("%d\t%d\t%d\n",sp[0][0],sp[0][1],sp[0][2]);
	for(i=0 ;i<sp[0][0]+1;i++){
		for(j=0;j<sp[0][1]+1;j++){
			if(k<=sp[0][2]  &&  sp[k][0]==i  &&  sp[k][1]==j)
				printf("%d\t%d\t%d\n",i,j,sp[k++][2]);
		}
	}
}