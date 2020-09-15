#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

// int main()
// {
//     int n,m,k;
//     scanf("%d%d%d",&n,&m,&k);
//     int a[n+5],b[n+5];
//     vector<int> temp;
//     for(int i=0;i<n;i++){
//         scanf("%d",&a[i]);
//         if(a[i]<k)
//             temp.push_back(i);
//         b[i]=1;
//     }
//     int len=temp.size();
//     if(len>(n-m))
//         printf("0\n");
//     for(int i=0;i<len;++i){
//         //printf("%d %d %d\n",temp[i],temp[i]-(m-1),temp[i]+(m-1));
//         for(int j=temp[i]-(m-1);j<=temp[i]+(m-1);++j){
//             if(j<0 || (j>=n))
//                 continue;
//             else{
//                 b[j]=0;
//             }
//         }
//     }
//     int result=0;
//     for(int i=0;i<n;++i){
//         result+=b[i];
//     }
//     for(int i=1;i<len;++i){
//         if(temp[i]-temp[i-1]-1>=m)
//             result+=temp[i]-temp[i-1]-1-m;
//     }
//     printf("%d\n",result);
//     return 0;
// }

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[n+5];
    int start=0,end=1;
    if(n<=0 || (m>n))
        printf("0\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int result=0;
    while(end<n){
        if(a[end]>=k){
            end++;
            if(end-start==m){
                result+=1;
                start+=1;
            }
        }
        else{
            start = end+1;
            end = start+1;
        }
    }
    printf("%d\n",result);
    return 0;
}

/*
8 2 5
5 5 5 4 5 5 5 5

8 2 5
5 2 5 5 4 5 5 5

12 3 5
5 2 5 5 5 5 5 5 3 5 5 5
*/

// int main()
// {
//     return 0;
// }