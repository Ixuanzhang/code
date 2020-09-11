#include<bits/stdc++.h>
#include<heap>

using namespace std;

class Solution {
public:
    int checkNum(vector<vector<int> >& matrix,int n,int mid){
        int i=n-1,j=0;
        int sum=0;
        while (i>=0 && (j<n))
        {
            if(matrix[i][j]<=mid)
                j++;
            else
                i--;

        }
        return sum;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //方法一： 二分查找
        //
        int n=matrix.size();
        if(n<=0 || (k<=0) || (k>n*n))
            return 0;
        int low = matrix[0][0],high = matrix[n-1][n-1],mid;
        int sum;
        while (high-low>=0)
        {
            mid = (high+low)/2;
            sum = check(matrix,n,mid);
            if(sum>=k){
                if(sum==k)
                    return mid;
                else
                    high = mid-1;
            }
            else
                low = mid+1；       
        }
        
    }
};

int main()
{
    printf("%d",(int)sqrt(5));
    return 0;
}