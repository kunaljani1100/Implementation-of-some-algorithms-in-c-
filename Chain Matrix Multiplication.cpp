#include<iostream>
#include<climits>
using namespace std;
void printbracket(int i, int j, int n,int *b,char &m)
{
    if (i==j)
    {
        cout<<m++;
        return;
    }
    cout<<"(";
    printbracket(i,*((b+i*n)+j),n,b,m);
    printbracket(*((b+i*n)+j)+1,j,n,b,m);
    cout<<")";
}
void chain(int p[], int n)
{
    int m[n][n],i,L,j,q,k;
    char x;
    int b[n][n];
    for(i=1;i<n;i++)
    {
        m[i][i] = 0;
    }
    for(L=2;L<=n;L++)
    {
        for (i=1;i<n-L+1;i++)
        {
            j=i+L-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    b[i][j]=k;
                }
            }
        }
    }
    x='A';
    cout<<"Best bracket:";
    printbracket(1,n-1,n,(int *)b,x);
    cout<<"\nCost:"<<m[1][n-1];
}
int main()
{
    int n,i,size;
	cout<<"Enter the size of the array:";
    cin>>size;
    n=size;
    int ary[n];
    cout<<"Enter the elements of the array:";
    for(i=0;i<n;i++)
    {
    	cin>>ary[i];
	}
    chain(ary,n);
    return 0;
}
