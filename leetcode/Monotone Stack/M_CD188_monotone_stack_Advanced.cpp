#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<list>
#include<unordered_map>
#include<unordered_set>


using namespace std;

int main(){
    //针对数组中出现的重复元素进行了处理
    int n;
    scanf("%d",&n);
    int a[n+5];
    vector<vector<int> > result(n+5,vector<int> (2));
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    stack<int> s;
    queue<int> q;
    s.push(0);   // stack中存放的是数组中的位置
    int index=1;
    int temp_index;
    while(index<n){
        if((!s.empty()) && (a[index]< a[s.top()])){
            temp_index = s.top();
            s.pop();
            result[temp_index][1] = index;   //最小的右边
            if(!s.empty()){
                while ((!s.empty()) && (a[s.top()]==a[temp_index]))
                {
                    q.push(s.top());
                    s.pop();
                }
                while (!q.empty())
                {
                    result[q.front()][1] = index;
                    if(s.empty())
                        result[q.front()][0] = -1;
                    else
                        result[q.front()][0] = s.top();
                    q.pop();
                }
                if(s.empty())
                    result[temp_index][0] = -1;
                else
                    result[temp_index][0] = s.top();
            }
            else
                result[temp_index][0] = -1;
        }
        else{
            s.push(index);
            index++;
        }
    }
    while (!s.empty())
    {
        int temp_index = s.top();
        result[temp_index][1] = -1;
        s.pop();
        if(!s.empty()){
            while ((!s.empty()) && (a[s.top()]==a[temp_index]))
            {
                q.push(s.top());
                s.pop();
            }
            while (!q.empty())
            {
                result[q.front()][1] = -1;
                if(s.empty())
                    result[q.front()][0] = -1;
                else
                    result[q.front()][0] = s.top();
                q.pop();
            }
            if(s.empty())
                result[temp_index][0] = -1;
            else
                result[temp_index][0] = s.top();
        }
        else
            result[temp_index][0] = -1;
    }
    for(int i=0;i<n;i++){
        printf("%d %d\n",result[i][0],result[i][1]);
    }
    return 0;
}

/*  自测样例
9
3 1 3 4 3 5 3 2 2

-1 1
-1 -1
1 7
2 4
1 7
4 6
1 7
1 -1
1 -1
*/