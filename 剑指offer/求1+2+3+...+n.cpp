/*
时间限制：1秒 空间限制：32768K 热度指数：123718

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//4ms 占用空间476k
class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        bool a = (n == 0) || (sum += Sum_Solution(n - 1)) > 0;
        return sum;
    }
};