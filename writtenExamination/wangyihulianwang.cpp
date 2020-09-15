#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int t,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        if(n<=0)
            printf("0\n");
        else
        {
            int a[n+1],b[n];
            for(int i=1;i<=n;++i){
                scanf("%d",&a[i]);
            }
            for(int i=1;i<=n-1;++i)
                scanf("%d",&b[i]);
            vector<vector<int> > dp(n+1,vector<int>(2,0));
            dp[1][0]=a[1];
            dp[1][1]= a[1];
            for(int i=2;i<=n;++i){
                dp[i][0] = min(dp[i-1][0],dp[i-1][1])+a[i];
                dp[i][1] = min(dp[i-2][0],dp[i-2][1])+b[i-1];
            }
            printf("%d\n",min(dp[n][0],dp[n][1]));
        }
    } 
    return 0;
}