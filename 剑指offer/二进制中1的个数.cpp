/*
时间限制：1秒 空间限制：32768K 热度指数：279850

题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//运行时间 3ms 占用内存376k
class Solution {
public:
     int  NumberOf1(int n) {
         //int类型是32位
         //正数
         if(n >= 0){
             int countOne = 0;
             int k = 0;
             while(n != 0){
                 k = n % 2;
                 n = n / 2;
                 if(k == 1){
                     countOne++;
                 }
             }
             return countOne;
         }
         else{
             if(n == 0x80000000){
                 return 1;
             }
             int countOne = 1;
             int countZero = 0;
             //-n 二进制取反+1
             int k = 0;
             int continueZero = 0;
             //判断是否连续
             bool flag = true;
             //占用二进制位数
             int count = 0;
             while(-n != 0){
                 k = n % 2;
                 n = n / 2;
                 if(k == 0 && flag == true){
                     continueZero++;
                 }
                 else{
                     flag = false;
                 }
                 if(k == 0){
                     countZero++;
                 }
                 count++;
             }
             //1 + 取反后1的数量 - +1后1减少的数量 + 1
             countOne += ((31 - count) + (countZero - continueZero + 1));
             return countOne;
         }
     }
};

//使用移位法计算可以使正数负数有相同的计算方式。
//3ms 占用空间452k
class Solution {
public:
     int NumberOf1(int n) {
         int ret = 0;
         int N = sizeof(int) * 8;
         while(N--) {
             if(n & 1)
                 ret++;
             n >>= 1;
         }
         return ret;
     }
};