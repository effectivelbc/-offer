/*
时间限制：1秒 空间限制：32768K 热度指数：124068

题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 */
 
// 3ms 476k
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if(size == 0 || num.size() == 0){
            return vector<int>();
        }
        vector<int> vec;
        //用一个队列存储一个滑动窗口中最大的值的数组下标
        deque<int> q;
        //存储是否到了滑动窗口的大小
        int k = 0;
        for(int i = 0; i < num.size(); i++){
            if(q.empty()){
                q.push_back(i);
                if(i + 1 >= size){
                    vec.push_back(num[q.front()]);
                }
                continue;
            }
            //当前下标 - 队伍头下标 大于 滑动窗口的大小
            if(i - q.front() + 1 > size){
                //取出队伍头
                q.pop_front();
            }
            if(num[i] < num[q.back()]){
                //插入到队列尾
                q.push_back(i);
            }
            else{
                //取出队列里所有比它小的
                while(!q.empty() && num[q.back()] <= num[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
            
            if(i + 1 >= size){
                vec.push_back(num[q.front()]);
            }
        }
        return vec;
    }
};