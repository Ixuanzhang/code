#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;


// //使用优先队列的版本   优先队列  是一个二叉堆
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq;
//         int len=nums.size();
//         if((len<=0) || (k>len))
//             return -1;
//         for(int i=0;i<len;++i){
//             pq.push(nums[i]);
//         }
//         int i=1;
//         while ((!pq.empty()) && (i<k))
//         {
//             pq.pop();
//             i++;
//         }
//         return pq.top();
//     }
// };

//基于自己实现最大堆实现
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
    }
};

//使用自己实现堆

int main()
{
    return 0;
}