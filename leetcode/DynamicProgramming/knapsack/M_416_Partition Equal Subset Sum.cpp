#include<iostream>
#include<cstdio>
#include<limits>
#include<cmath>
#include<memory>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 0-1 背包问题   恰好装满类问题
        //不是常见0-1背包 装满情况下，价值最大问题，  只要能够装满即可，故采用动态规划的解决方案
        /*
        思路：
        1.定义一个状态转移数组dp,dp[i][j]表示前i个元素中能否找到和为j的元素的子集，dp数组的类型是布尔类型
        2.寻找状态转移方程：对于第i个元素，如果其放入“背包”中，那么dp[i][j]值应该是dp[i][j] = dp[i-1][j-nums[i]];如果不放入“背包”中，那么dp[i][j] = dp[i-1][j];
        3.确定初始值，dp[0][0] = true，因为对于前0个元素，其和就是0，所以是能够找到和为0的子集合的。
        */
        int len = nums.size();
        int sum=0;
        for(int i=0;i<len;++i)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        else
        {
            int target = sum/2;
            bool dp[len+1][target+1];
            //初始化
            memset(dp,false,sizeof(dp));
            dp[0][0] = true;

            for(int i=1;i<=len;++i){
                for(int j=1;j<=target;++j){
                    if(j>=nums[i-1])
                        dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
                    else
                        dp[i][j] = dp[i-1][j];
                    //cout << dp[i][j]<<endl;
                }
            }
            return dp[len][target];
        }
        
    }
};

//空间优化后代码
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 0-1 背包问题   恰好装满类问题
        //不是常见0-1背包 装满情况下，价值最大问题，  只要能够装满即可，故采用动态规划的解决方案
        /*
        思路：
        1.定义一个状态转移数组dp,dp[i][j]表示前i个元素中能否找到和为j的元素的子集，dp数组的类型是布尔类型
        2.寻找状态转移方程：对于第i个元素，如果其放入“背包”中，那么dp[i][j]值应该是dp[i][j] = dp[i-1][j-nums[i]];如果不放入“背包”中，那么dp[i][j] = dp[i-1][j];
        3.确定初始值，dp[0][0] = true，因为对于前0个元素，其和就是0，所以是能够找到和为0的子集合的。
        */
        int len = nums.size();
        int sum=0;
        for(int i=0;i<len;++i)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        else
        {
            int target = sum/2;
            bool dp[target+1];
            //初始化
            memset(dp,false,sizeof(dp));
            dp[0] = true;

            for(int i=1;i<=len;++i){
                for(int j=target;j>=1;--j){
                    if(j>=nums[i-1])
                        dp[j] = (dp[j-nums[i-1]] || dp[j]);  //否则不变  对应上面的dp[i][j]=dp[i-1][j]
                }
            }
            return dp[target];
        }      
    }
};

int main()
{
    cout << 0 || 0;
    return 0;
}