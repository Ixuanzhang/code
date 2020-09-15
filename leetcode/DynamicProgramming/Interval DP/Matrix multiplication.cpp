#include<bits/stdc++.h>

using namespace std;

//矩阵连乘问题   区间dp：dp[i][j]   i:区间的起始坐标，j:区间的结束坐标
//区间dp的思想：分解为两个更小的子问题（子区间），最后再将两个子区间合并   
//针对矩阵连乘问题：遍历所有区间内能划分的子区间的情况，取最小

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+5];   //n个矩阵，n+1个维度数
    for(int i=0;i<n+1;++i){
        scanf("%d",&a[i]);
    }

    //执行如下区间dp操作
    int dp[n+5][n+5];
    memset(dp,,sizeof(dp));
    for(int i=1;i<=n;++i)
        dp[i][i]=0;    //单个矩阵不用进行乘法，故总的操作数为0
    for(int l=1;l<=n-1;l++){
        for(int j=i+1;j<=n;++j){

        }
    }
    for(int i=l;i<=r;i++){

    }
    return 0;
}