//统计图中连通块数量：dfs、bfs、并查集
// 按秩合并、路径压缩后代码
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int MAX_V = 1004;
int father[MAX_V];
int rank[MAX_V];

int find(int x)
{

}

void init(int n)
{
    for(int i=1;i<=n;i++){
        father[i]=i;
        rank[i]=1;
    }
}

int merge(int i,int j)
{
    int x = find(i), y =find(j);
    if(rank[x]<=rank[y])

}

int main()
{
    return 0;
}