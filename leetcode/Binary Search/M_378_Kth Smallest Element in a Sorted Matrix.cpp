//#include<bits/stdc++.h>
#include<iostream>
#include<Pro

using namespace std;

// // 方法一：二分查找
// class Solution {
// public:
//     int checkNum(vector<vector<int> >& matrix,int n,int mid){
//         int i=n-1,j=0;
//         int sum=0;
//         while (i>=0 && (j<n))
//         {
//             if(matrix[i][j]<=mid)
//                 j++;
//             else{
//                 sum+=j;
//                 i--;
//             }
            
//         }
//         while (i>=0){
//             sum+=j;
//             i--;
//         }
//         return sum;
//     }
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n=matrix.size();
//         if(n<=0 || (k<=0) || (k>n*n))
//             return 0;
//         int low = matrix[0][0],high = matrix[n-1][n-1],mid;
//         int sum;
//         while (high-low>0)
//         {
//             mid = (high+low)/2;
//             sum = checkNum(matrix,n,mid);
//             if(sum<k){
//                 low = mid+1;
//             }
//             else
//                 high=mid;  
//         }
//         return high;
//     }
// };

//方法二：小顶堆

class Solution {
public:
    int checkNum(vector<vector<int> >& matrix,int n,int mid){

    }
}；

int main()
{
    printf("%d",(int)sqrt(5));
    return 0;
}