#include<stdio.h>
int main()
{
int i,n,q,l,r;
long long psum[n+1],arr[n];
scanf("%d %d",&n,&q); //taking no. of elements in array and no of queries
for(i=0;i<n;i++){
scanf("%lld",&arr[i]);                                                                                                                                                                                                                                                                                                                                             
}
psum[0]=0;
for(i=0;i<n;i++)
{
psum[i+1]=psum[i]+arr[i];     // suppose arr: 1 2 3  4   5
}                                                  //    psum:  0 1 3 6 10  15   
while(q--){
scanf("%d%d",&l,&r); //taking the value of l and r for each query
long long sum=0;
sum= psum[r]-psum[l-1];
printf("%lld\n",sum/r-l+1);
}
return 0;

} 
