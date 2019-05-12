#include<iostream>
#include<climits>
using namespace std;
int cutRod(int n,int values[])
{
	int i,j,r[n+1],sol[n+1][n+1],k,m=0,p,flag=0;
	r[0]=0;
	for(i=1;i<=n;i++)
	{
		r[i]=INT_MIN;
		for(j=0;j<i;j++)
		{
			if(r[i]>values[j]+r[i-(j+1)])
			{
			    r[i]=r[i];
		    }  
			else
		    {
				r[i]=values[j]+r[i-(j+1)];
			}
		}
	}
	p=r[n];
	cout<<"Solution:";
	while(p>0)
	{
		for(j=0;j<n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(p-values[j]==r[k]||p-values[j]==0)
				{
					p=p-values[j];
					cout<<values[j]<<" ";
				}
			}
		}
	}
	return r[n];
}
int main()
{
	int n,i,result;
	cout<<"Enter the length of the rod:";
	cin>>n;
	if(n<0)
	{
		cout<<"The length of the rod is not negative.";
		return 1;
	}
	int values[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter the price of length "<<i+1<<" units:";
		cin>>values[i];
		if(i!=0&&values[i-1]>=values[i])
		{
			cout<<"Incorrect length.";
			return 1;
		}
	}
	result=cutRod(n,values);
	cout<<"\nMaximum profit:"<<result;
	return 0;
}
