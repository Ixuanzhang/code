#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len=coins.size();
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=amount;++i)
        {
            int v=0;
            for(int j=0;j<len;++j){
                if(i>=coins[j])
                    v+=dp[i-coins[j]];
            }
            dp[i]=v;
        }
        return dp[amount];
    }
};

int main()
{
    int amount;
    vector<int> coins={1,2,5};
    while (scanf("%d",&amount)!=EOF)
    {
        /* code */
        int result = Solution().change(amount, coins);
        printf("%d\n",result);
    }
    
    return 0;
}