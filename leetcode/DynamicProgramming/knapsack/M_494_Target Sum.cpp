#include<iostream>
#include<cstdio>
#include<limits>
#include<cmath>
#include<memory>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]   //j-nums[i] 和 j+nums[i] 不越界的时候加
        int len=nums.size();
        if(len<=0)
            return 0;
        int dp[len+1][S+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=len;++i){
            for(int j=1;j<=S;++j){
                if()
            }
        }
    }
};

int main()
{
    return 0;
}