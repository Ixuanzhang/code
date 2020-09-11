#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>


using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[n+5];
    vector<vector<int> > result(n+5,vector<int> (2));
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    stack<int> s;
    s.push(0);   // stack中存放的是数组中的位置
    int index=1;
    while(index<n){
        if((!s.empty()) && (a[index]< a[s.top()])){
            int temp = s.top();
            result[temp][1] = index;   //最小的右边
            s.pop();
            if(s.empty())
                result[temp][0] = -1;
            else
                result[temp][0] = s.top();   //最小的左边  新的s.top()的值
        }
        else{
            s.push(index);
            index++;
        }
    }
    while (!s.empty())
    {
        int temp_top_val = s.top();
        result[temp_top_val][1] = -1;
        s.pop();
        if(s.empty())
            result[temp_top_val][0]=-1;
        else{
            result[temp_top_val][0]=s.top();
        }
    }
    for(int i=0;i<n;i++){
        printf("%d %d\n",result[i][0],result[i][1]);
    }
    return 0;
}