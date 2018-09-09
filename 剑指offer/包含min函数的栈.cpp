/*
时间限制：1秒 空间限制：32768K 热度指数：193842
本题知识点： 栈

题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

//3ms 484k
class Solution {
    stack<int> s;
    stack<int> min_s;
public:
    void push(int value) {
        s.push(value);
        if(min_s.empty() || min_s.top() >= value){
            min_s.push(value);
        }
    }
    void pop() {
        if(min_s.top() == s.top()){
            min_s.pop();
        }
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return min_s.top();
    }
};