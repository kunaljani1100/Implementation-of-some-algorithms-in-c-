#include<iostream>
using namespace std;
int sol[100];
int cnt;
void arrange(int m[],int n[],int ary[],int &value,int &count,int k)
{
	int i,j;
	for(i=0;ary[i]!=-1;i++)
	{
		if(value==ary[i])
		   return;
	}
	cout<<"\n";
	for(i=0;i<k;i++)
	{
		if(value==m[i]&&m[i]!=n[i])
		{
			ary[count++]=i;
			value=n[i];
			arrange(m,n,ary,value,count,k);
			break;
		}
	}
}
void findChain(int m[],int n[],int k)
{
	int i,j,x,value,ary[k],count=1,max=0,sub[k],flag;
	char ch;
	for(i=0;i<k;i++)
	{
		count=1;
		for(x=0;x<k;x++)
		{
			ary[x]=-1;
		}
		for(j=0;j<k;j++)
		{
			if(n[i]==m[j]&&i!=j)
			{
				ary[0]=i;
				ary[count++]=j;
				value=n[j];
				arrange(m,n,ary,value,count,k);
				if(max<count)
				{
					max=count;
					for(int x=0;x<max;x++)
					{
						sub[x]=ary[x];
					}
				}
			}
		}
	}
	cout<<"Longest possible chain:";
	for(i=0;i<max;i++)
	{
		ch='A';
		flag=1;
		for(j=0;j<i;j++)
		{
			if(sub[j]==sub[i])
		    {
		    	flag=0;
			}
		}
		ch=ch+sub[i];
		if(flag==1)
		{
		    cout<<ch<<" ";
	    }
	}
}
int main()
{
	int k,i,j;
	cout<<"Enter the number of matrices:";
	cin>>k;
	int m[k],n[k],ary[k+1];
	for(i=0;i<k;i++)
	{
		cout<<"Enter the number of rows of matrix "<<i<<":";
		cin>>m[i];
		cout<<"Enter the number of columns of matrix "<<i<<":";
		cin>>n[i];
	}
	findChain(m,n,k);
}
