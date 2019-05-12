
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() 
{
	char str[100],subsequences[2000][10];
	int size;
	cout<<"Enter string 1:";
	cin>>str;
	for(size=0;str[size]!='\0';size++);
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
				subsequences[m][n[m]]=str[j];
				n[m]++;
			}
		}
		n[m]='\0';
		m++;
	}
	char str2[100],subsequences2[2000][10];
	int size2;
	cout<<"Enter string 2:";
	cin>>str2;
	for(size2=0;str2[size2]!='\0';size2++);
	int m2=0,n2[2000];
	for(int i=0;i<2000;i++)
	{
		n2[i]=0;
	}
	unsigned int opsize2=pow(2,size2);
	for(int counter2=1;counter2<opsize2;counter2++)
	{
		for(int j=0;j<size2;j++)
		{
			if((counter2)&(1<<j))
			{
				subsequences2[m2][n2[m2]]=str2[j];
				n2[m2]++;
			}
		}
		n2[m2]='\0';
		m2++;
	}
	int lengthofsubseq[2000];
	for(int i=0;i<2000;i++)
	{
		lengthofsubseq[i]=0;
	}
	int lengthofsubseq2[2000];
	for(int i=0;i<2000;i++)
	{
		lengthofsubseq2[i]=0;
	}
	
	int max=0;
	int index=0;
	char commonsubs[2000][100];
	int x=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m2;j++)
		{
			if(strcmp(subsequences[i],subsequences2[j])==0)
			{
			    strcpy(commonsubs[x],subsequences[i]);
			    x++;
			}
		}
	}
	int maximum;
	maximum=strlen(commonsubs[0]);
	for(int i=1;i<x;i++)
	{
		if(maximum<strlen(commonsubs[i]))
		{
			maximum=strlen(commonsubs[i]);
			index=i;
		}
	}
	cout<<commonsubs[index];
    return 0;
}
