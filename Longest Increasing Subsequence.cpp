#include <iostream>
#include<bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() 
{
	int ary[10],size,subsequences[2000][10];
	cout<<"Enter size of array:";
	cin>>size;
	cout<<"Enter elements of an array:";
	for(int i=0;i<size;i++)
	{
		cin>>ary[i];
	}
	int m=0,n[2000];
	for(int i=0;i<2000;i++)
	{
		n[i]=0;
	}
	unsigned int opsize=pow(2,size);
	for(int counter=1;counter<opsize;counter++)
	{
		for(int j=0;j<size;j++)
		{
			if((counter)&(1<<j))
			{
				subsequences[m][n[m]]=ary[j];
				n[m]++;
			}
		}
		m++;
	}
	int lengthofsubseq[2000];
	for(int i=0;i<2000;i++)
	{
		lengthofsubseq[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n[i]-1;j++)
		{
			if(subsequences[i][j]<subsequences[i][j+1])
			{
				lengthofsubseq[i]++;
			}
			else
			{
				lengthofsubseq[i]=0;
				break;
			}
		}
	}
	int max=lengthofsubseq[0];
	int storevalue=0;
	for(int i=1;i<2000;i++)
	{
		if(max<lengthofsubseq[i])
		{
			max=lengthofsubseq[i];
			storevalue=i;
		}
	}
	for(int i=0;i<n[storevalue];i++)
	{
		cout<<subsequences[storevalue][i];
	}
	return 0;
}
