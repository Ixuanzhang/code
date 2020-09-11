#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

// 基础并查集

class Solution {
public:
    int find(int parent[], int x){
        while (parent[x]!=x)
        {
            //进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];   
        }
        return x;
    }

    void my_union(int parent[], int height[],int p,int q,int& count){
        int rootP = find(parent,p);
        int rootQ = find(parent,q);
        if(rootP == rootQ)  //已经在同一个集合中了
            return ;
        //小树接到大树上面，平衡 
        if(height[rootP]<height[rootQ]){
            parent[rootP]=rootQ;
            height[rootQ]=max(height[rootQ],height[rootP]+1);
        }
        else
        {
            parent[rootQ]=rootP;
            height[rootP]=max(height[rootP],height[rootQ]+1);
        }
        count--;
    }

    // 一种统计图中连通块数量的方法是：使用并查集
    int findCircleNum(vector<vector<int> >& M) {
        int n = M.size();
        if(n<=0)
            return 0;
        int parent[n];
        int height[n];
        for(int i=0;i<n;++i)
        {
            parent[i]=i;
            height[i]=1;
        }
        int count = n;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j){
                if(M[i][j]==1)
                    my_union(parent,height,i,j,count);
            }
        }
        return count;
    }
};


int main()
{
    return 0;
}