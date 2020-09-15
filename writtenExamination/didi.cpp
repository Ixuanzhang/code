#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<limits>
#include<algorithm>
#include<queue>

using namespace std;


//第一题
string myReverse(string s){
    int len=s.size();
    for(int i=0;i<len/2;++i){
        swap(s[i],s[len-1-i]);
    }
    return s;
}

int main(){
    int n;
    string s;
    char ch;
    scanf("%d",&n);
    scanf("%c",&ch);
    getline(cin,s);   //重要  这个才能输入一整行（不会因为空格断掉）  
                     // cin>>s  输入s，以空格作为结尾 比如输入：I am a beautiful girl  此时用用cin>>s 得到的s为"I"
    int len=s.size();
    if(n>=len)
        cout << myReverse(s);
    else
    {
        int i=0;
        while ((i+1)*n-1 < len)
        {
            string sub_s = s.substr(i*n,n);   //获得字符串s中从第i*n位开始的长度为5的字符串
            cout<<myReverse(sub_s);
            i += 1;
        }
        if(i*n < len){
            string sub_s = s.substr(i*n, len-i*n);
            cout << myReverse(sub_s);
            i+=1;
        }
        cout<<endl;
    }
    return 0;
}

/*
2
gogogoout

输出：ogogoguot

3
Gogo, go out!?

输出：goG ,o ogtuo?!
*/


// //第2题
// int main()
// {
//     int t;
//     scanf("%d",&t);
//     while (t--)
//     {
//         int n,m,k;
//         scanf("%d%d%d",&n,&m,&k);
//         int a[n+5][n+5];
//         int node_a,node_b,price;
//         memset(a,0,sizeof(a));
//         for(int i=0;i<m;i++)
//         {
//             scanf("%d%d",&node_a,&node_b);
//             scanf("%d",&price);
//             if(price<=k){
//                 a[node_a][node_b] = price;
//                 a[node_b][node_a] = price;
//             }
//         }
//         int visit[n+5];
//         memset(visit,0,sizeof(visit));
//         queue<int> q;
//         q.push(1);
//         visit[1]=1;
//         while (!q.empty())
//         {
//             int temp = q.front();
//             q.pop();
//             for(int j=1;j<=n;++j){
//                 if(visit[j]==0 && a[temp][j]>0){
//                     q.push(j);
//                     visit[j] = 1;
//                 }
//             }
//         }
//         int sum=0;
//         for(int i=1;i<=n;i++){
//             if(visit[i]==1)
//                 sum+=1;
//         }
//         if(sum==n)
//             printf("Yes\n");
//         else{
//             printf("No\n");
//         }
//     }
    
//     return 0;
// }


// /*
// 2
// 3 3 400
// 1 2 200
// 1 3 300
// 2 3 500
// 输出： Yes

// 3 3 400
// 1 2 500
// 1 3 600
// 2 3 700
// 输出：No
// */