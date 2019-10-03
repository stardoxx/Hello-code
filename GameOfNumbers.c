#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k,l,c,b,max =0,m=0;
	int flagi=0,flagj=0;
	for(i=0;i<n;i++)
	{
		b = a[i];

		flagi=0;
		for(j =i+1;j<n;j++){
			if(flagi == 0){
						if(a[j]>b){
							++flagi;
							flagj =0;
							for(k=j+1;k<n;k++){
								if(flagj==0){
													if(a[k]<a[j]){
														printf("%d ",a[k]);
														++flagj;
													}
												}
							}
							if(flagj==0){
								printf("%d ",-1);
							}

						}
			}
		}
		
			if(flagi==0){
								printf("%d ",-1);
							}			
		
	}
}
