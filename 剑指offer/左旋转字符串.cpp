/*
时间限制：1秒 空间限制：32768K 热度指数：141656
本题知识点： 字符串

题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
*/

//5ms 占用空间472k
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() == 0){
            return str;
        }
        int k = n % str.size();
        string a = "";
        for(int i = 0; i < k; i++){
            a += str[i];
        }
        string b = "";
        for(int i = k; i <= str.size() - 1; i++){
            b += str[i];
        }
        return b + a;
    }
};

