#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


int main()
{
    int T;
    cin>>T;
    while (T)
    {
        T--;
        string s1,s2,s3;
        cin>>s1;
        cin>>s2;
        cin>>s3;
        int k;
        int l1=s1.size();
        int l2=s2.size();
        vector<vector<vector<int>>> dp(s1.size()+1, vector<vector<int>>(s2.size()+1,vector<int>(2,k+1)));
        for(int i=1;i<=s1.size();++i)
            dp[i][0][0]=1;
        for(int i=1;i<=s2.size();++i)
            dp[0][i][1]=1;
        
        for(int i=1;i<=s1.size();++i){
            for(int j=1;j<=s2.size();++j){
                dp[i][j][0]=k+1;
                dp[i][j][1]=k+1;
                if(s1[i-1]==s3[i+j-1]){
                    dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]+1);
                }
                if(s2[j-1]==s3[i+j-1]){
                    dp[i][j][1]=min(dp[i][j-1][0]+1,dp[i][j-1][1]);
                }
            }
        }
        if(dp[s1.size()][s2.size()][0]<=k || dp[s1.size()][s2.size()][1]<=k){
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }   
    }    
    return 0;
}

// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     vector<int> nums(n);
//     for(int i=0;i<n;++i){
//         scanf("%d",&nums[i]);
//     }
//     while (m)
//     {
//         --m;
//         vector<int> nums2(n);
//         for(int i=0;i<n;++i){
//             if(i % 2==0){
//                 nums2[i]=nums[n/2+i/2];
//             }
//             else
//                 nums2[i]=nums[i/2];
//         }
//         nums.swap(nums2);
//     }
//     for(int i=0;i<nums.size()-1;++i){
//         cout << nums[i] <<" ";
//     }
//     cout<<nums[nums.size()-1]<<endl;
//     return 0;
// }