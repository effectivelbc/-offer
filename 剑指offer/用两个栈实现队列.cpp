/*
时间限制：1秒 空间限制：32768K 热度指数：292328
本题知识点： 队列 栈

题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

//2ms 占用空间484k
class Solution
{
public:
    void push(int node) {
        //push时放入stack1
        stack1.push(node);
    }

    int pop() {
        //pop时从stack2pop 如果stack2为空则将stack1中元素压入stack2
        if(!stack2.empty()){
            int a = stack2.top();
            stack2.pop();
            return a;
        }
        else{
            while(!stack1.empty()){
                int a = stack1.top();
                stack1.pop();
                stack2.push(a);
            }
            if(stack2.empty()){
                return -1;
            }
            else{
                int a = stack2.top();
                stack2.pop();
                return a;
            }
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};