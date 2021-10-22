#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[30],i,j,n,temp;
	cout<<"enter array size"<<endl;
	cin>>n;
	cout<<"enter an element"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
    for(i=1;i<n;i++)
    {
    	temp=a[i];
    	j=i-1;
    	if(j>=0&&a[j]>temp)
    	{
    		a[j+1]=a[j];
    		j--;
		}
		a[j+1]=temp;
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
