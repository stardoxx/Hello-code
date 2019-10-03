#include<iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		int k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int r1 = -1;
		int r2 = -1;
		int countr1 = 0;
		int countr2 = 0;
		bool flag = true;
		for(int i=0;i<n;i++)
		{
			int rem = arr[i] % (k+1);
			if(r1 == -1)
			{
				r1 = rem;
				++countr1;
			}
			else if(r1 == rem)
			{
				++countr1;
			}
			else if(r2 == -1)
			{
				r2 = rem;
				++countr2;
			}
			else if(r2 == rem)
			{
				++countr2;
			}
			else{
				flag = false;
				break;
			}
		}
		if(flag == false){
			cout<<"NO"<<endl;
		}else if(countr1 >= n-1 || countr2 >= n-1)
		{
			// cout<<r1<<"  "<<r2<<endl;
			// cout<<countr1<<endl;
			// cout<<countr2<<endl;
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}