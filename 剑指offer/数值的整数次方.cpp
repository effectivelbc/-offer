/*
时间限制：1秒 空间限制：32768K 热度指数：287690

题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

//3ms 占用空间358k
class Solution {
public:
    double Power(double base, int exponent) {
        double a = 1;
        if(exponent >= 0){
            for(int i = 0; i < exponent; i++){
                a *= base;
            }
            return a;
        }
        else{
            for(int i = 0; i > exponent; i--){
                a *= base;
            }
            return (double) 1 / a;
        }
        
    }
};

//改进方法 快速幂 x^n = (x * x)^n/2
//3ms 占用空间480k
class Solution {
public:
    double Power(double base, int exponent) {
        int p = abs(exponent);
        double ret = 1.0;
        while (p != 0) {
            if (p & 1)        // 如果是奇数
                ret *= base;
            base *= base;
            p >>= 1;
        }

        return exponent < 0 ? 1 / ret : ret;
    }
};
