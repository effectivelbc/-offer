/*
时间限制：1秒 空间限制：32768K 热度指数：78681

题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

//2ms 占用空间476k
class Solution {
public:
    int Add(int num1, int num2)
    {
        //二进制
        //进位值为0的时候停止
        while(num2 != 0){
            int temp = num1;
            num1 = num1 ^ num2;
            num2 = (temp & num2) << 1;
        }
        return num1;
    }
};