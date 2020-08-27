#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int min_v = INT_MAX-1;
            for(int j=0;j<len;++j){
                if(i>=coins[j])
                {
                    if(min_v > dp[i-coins[j]])
                        min_v = dp[i-coins[j]];
                }
            }
            dp[i]=min_v+1;
        }
        if(dp[amount]==INT_MAX)   // 如果没有任何一种硬币组合能组成总金额，返回 -1。
            return -1;
        return dp[amount];
    }
};

int main()
{
    return 0;
}