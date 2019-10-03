#include<iostream>
using namespace std;

void Buildtree(int * tree,int start,int end,int index)
{
	if(start == end)
	{
		tree[index] = 0;
		return;  
	}
	int mid = (start + end)/2;
	Buildtree(tree,start,mid,2*index+1);
	Buildtree(tree,mid+1,end,2*index+2);
	tree[index] = tree[2*index+1] + tree[2*index+2];
	return;
}
void Toggle(int *tree,int *lazy,int startIndex,int endIndex,int rangeStart,int rangeEnd,int index)
{
	if(lazy[index]!=0)
	{
		if(startIndex == endIndex)
		{
			
		}
	}
	if((startIndex == endIndex) && rangeStart<=startIndex && startIndex<=rangeEnd)
	{
		if(tree[index] == 0)
		{
			tree[index] = 1;
		}
		else{
			tree[index] = 0;
		}
		return;
	}
	if((rangeStart < startIndex && rangeEnd<startIndex) || (rangeStart > endIndex && rangeEnd > endIndex))
	{
		return;
	}
	else{
		int mid = (startIndex + endIndex)/2;
		Toggle(tree,startIndex,mid,rangeStart,rangeEnd,2 *index+1);
		Toggle(tree,mid+1,endIndex,rangeStart,rangeEnd,2 *index+2);
		tree[index] = tree[2*index+1] + tree[2*index+2];
		return;		
	}
}
int rangeMinimumQuery(int *tree,int start,int end,int rangeStart,int rangeEnd,int index)
{
	int mid = (start + end)/2;
	if(rangeStart<=start && rangeEnd>=end)
		return tree[index];

	else if((rangeStart < start && rangeEnd<start) || (rangeStart > end && rangeEnd > end) )
		return 0;
	else
		return (rangeMinimumQuery(tree,start,mid,rangeStart,rangeEnd,2*index+1) + rangeMinimumQuery(tree,mid+1,end,rangeStart,rangeEnd,2*index+2));
}

int main()
{
	int N,Q;
	cin>>N>>Q;
	int * tree = new int [4*N+1];
	int * lazy = new int [4*N+1];
	Buildtree(tree,0,N-1,0);
	int a,b,c;
	while(Q--){
		cin>>a;
		cin>>b>>c;
		if(a==1)
		{
			cout<<rangeMinimumQuery(tree,lazy,0,N-1,b,c,0)<<endl;
		}
		if(a==0)
		{
			Toggle(tree,lazy,0,N-1,b,c,0);
			
		}
	}
}