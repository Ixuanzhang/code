//爱奇艺算法岗的笔试题

#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// int inverse_equal(string s1,string s2){
//     //比较翻转后的s1（翻转：s1[0]和s[len1-1]交换  s1[1]和s1[len1-2]交换  依次类推）
//     int len1=s1.size(),len2=s2.size();
//     int i=len1-1,j=0;
//     int result=0;   // 0：等于  -1：inverse(s1)>s2   1：inverse(s1)<s2
//     while (i>=0 && (j<len2))
//     {
//         if(s1[i]==s2[j])
//             continue;
//         else if(s1[i]<s2[j]){
//             result=1；
//             break;
//         }
//         else
//         {
//             result=-1;
//             break;
//         }
//         i--;
//         j++;
//     }
//     return result;
// }

string myReverse(string s){
    int len=s.size();
    for(int i=0;i<len/2;++i){
        swap(s[i],s[len-1-i]);
    }
    return s;
}

int main()
{
    int n;
    cin >>n;
    if(n<=0)
        printf("0\n");
    else{
        vector<int> c(n+1);
        string s[n+1];
        vector<string> reverse_s(n+1);
        for(int i=0;i<n;++i)
            cin >> c[i];
        for(int i=0;i<n;++i){
            cin >> s[i];
            string temp_s = myReverse(s[i]);
            reverse_s[i]=temp_s;
            //cout<<s[i]<<endl;
            //cout<<temp_s<<endl;
        }
        vector<vector<int> > dp(n+1, vector<int>(2,999999));
        dp[0][0]=0;
        dp[0][1]=c[0];
        int last_flag = 1;
        for(int i=1;i<n;i++){
            int flag=0;
            if(s[i-1]<=s[i]){
                dp[i][0]=dp[i-1][0];
                flag=1;
            }
            if(reverse_s[i-1]<=s[i]){
                dp[i][0]=min(dp[i][0],dp[i-1][1]);
                flag=1;
            }
            if(s[i-1]<=reverse_s[i]){
                dp[i][1]=dp[i-1][0]+c[i];
                flag=1;
            }
            if(reverse_s[i-1]<=reverse_s[i]){
                dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
                flag=1;
            }
            if(flag==0){
                last_flag=0;
                break;
            }
        }
        if(last_flag==0)
            printf("-1\n");
        else{
            printf("%d\n",min(dp[n-1][0],dp[n-1][1]));
        }
    }
    return 0;
}

/*
2
1 2
ba
ac
输出：1


2
5 5
bbb
aaa
输出：-1

3
1 3 1
aa
ba
ac
输出：1

*/

// // 第一题
// int main(){
//     int n,m;
//     cin >> n>>m;
//     if(n<=0 || n>1000)
//         printf("0\n");
//     vector<int> dp(n+1,0);
//     dp[0]=1;
//     dp[1]=1;
//     for(int i=2;i<=n;++i){
//         for(int j=1;j<=m && i-j>=0;++j){
//             dp[i]+=dp[i-j];
//             dp[i]%=(1000000000+3);
//         }
//     }
//     cout << dp[n] <<endl;
//     return 0;
// }