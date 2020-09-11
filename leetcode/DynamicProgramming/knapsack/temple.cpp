#include<iostream>
#include<cstdio>
#include<limits>
#include<cmath>

using namespace std;

int zeroOnePack(int N,int V,int c[],int w[])   //基础的0-1背包  优化了空间复杂度
{
    // （1）题目要求“恰好装满背包”的最优解 ：  初始化 F[0]=0,其他F[1..V]均设为 负无穷  （背包装满的情况下，价值最大）
    // （2）题目没有要求必须把背包装满 ：  初始化 F[0..V]=0

    // 公式：dp[i][v] = max(dp[i-1][v],dp[i-1][v-c[i]]+w[i])
    int[] dp = new int[V+1];
    //根据上面进行所述进行初始化  下面针对情况（1）初始化
    dp[0]=0;
    for(int i=1;i<=V;++i)
        dp[i]=INT8_MIN;
    int v;
    for(int i=0;i<N;++i){
        for(int v=V;v>=1;--v){
            if(v>=w[i])
                dp[v]=max(dp[v],dp[v-c[i]]+w[i]);
        }
    }
    return dp[V];
}

int main()
{
    return 0;
}