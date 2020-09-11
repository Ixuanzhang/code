//带权并查集

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

/*
思路：
构建带权值边的并查集，对于每个方程式有两种情况

查询是否联通，若不联通，则答案为-1.0
若联通，则求出其与根相除的结果，根据结果计算方程式。
例如，对于题目示例：

构造并查集：a->b->c，其中a->b的边的权值为2.0，b->c的边的权值为3.0
以计算b/a时为例，以root结点为桥梁，计算b/a的值：
1. 首先计算b/root，这里root为c，则b/c = 3.0
2. 然后计算a/root，这里root为c，则a/c = a/b * b/c = 2.0 * 3.0 = 6.0
3. 最后计算方程式结果：b/a = (b/root)/(a/root) = 3.0/6.0 = 0.5

实现思路
维护两个hash表， parent 表记录每个节点的祖先节点，dist 表记录该节点到祖先节点的距离（dist[i] = i / root）
初始化每个节点为一个集合 parent[i] = i，dist[i] = 1
遍历 equations、values 数组，将两个集合合并（后面详细介绍）
遍历 queries 数组，如果查询的两个节点（a、b）都存在且处于同一个集合中则向结果数组（res）添加dist[a] / dist[b]，否则添加 -1.0

参考链接：
https://leetcode-cn.com/problems/evaluate-division/solution/san-chong-jie-fa-by-baymaxhwy/
*/

class Solution {
public:
    unordered_map<string,string> parent;
    unordered_map<string,double> dist;

    //返回root和 a/root 的值
    pair<string,double> myFind(string a){
        if(parent.find(a) == parent.end())   //map中不存在该元素
            return {"",-1.0};
        double distance = 1.0;  //记录到root的比值大小
        while(parent[a]!=a){
            //未压缩路径
            distance *= dist[a];
            a = parent[a];
        }
        return {a,distance};
    }

    void myUnion(string a,string b,double a_b){
        pair<string,double> p1 = myFind(a);
        pair<string,double> p2 = myFind(b);
        if((p1.first == "") || (p2.first == ""))
            return;
        if(p1.first == p2.first)
            return;
        parent[p1.first] = p2.first;
        dist[p1.first] = 1/p1.second * a_b *p2.second;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        //merge
        for(int i=0;i<len;++i){
            string a = equations[i][0];
            string b = equations[i][1];

            //并集初始化
            if(parent.find(a) == parent.end()){
                parent[a]=a;
                dist[a]=1.0;
            }
            if(parent.find(b) == parent.end()){
                parent[b]=b;
                dist[b]=1.0;
            }

            myUnion(a,b,values[i]);
        }

        //查
        int query_len = queries.size();
        vector<double> result;
        for(int i=0;i<query_len;++i){
            string a = queries[i][0];
            string b = queries[i][1];

            pair<string,double> p1 = myFind(a);  // result_a.second = a/result_a.first
            pair<string,double> p2 = myFind(b);   // result_b.second = b/result_b.first
            //cout<<p1.first <<":" <<p1.second << "       "<<p2.first<<":"<<p2.second<<endl;
            if((p1.first=="") || (p2.first == "") || (p1.first != p2.first))
                result.push_back(-1.0);
            else
            {
                result.push_back(p1.second /p2.second);
            }   
        }
        return result;
    }
};

int main()
{
    return 0;
}