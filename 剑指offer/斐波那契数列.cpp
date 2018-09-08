/*
时间限制：1秒 空间限制：32768K 热度指数：391390

题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

//不能使用递归，必须迭代

//5ms O(n) 占用空间 468k
class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int a1 = 0;
        int a2 = 1;
        int answer = 0;
        for(int i = 2; i <= n; i++){
            answer = a1 + a2;
            a1 = a2;
            a2 = answer;
        }
        return answer;
    }
};