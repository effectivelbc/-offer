/*
时间限制：1秒 空间限制：32768K 热度指数：233071

题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

//将跳台阶的前两项的和推广到前n项的和，递归

//4ms 占用空间484k
class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 0){
            return 0;
        }
        if(number == 1){
            return 1;
        }
        if(number == 2){
            return 2;
        }
        int sum = 0;
        for(int i = 1; i <= number - 1; i++){
            sum = sum + jumpFloorII(i);
        }
        sum += 1;
        return sum;
    }
};

//优化方法使用动态规划
//2ms 占用空间476k
class Solution {
public:
    int jumpFloorII(int number) {
        //动态规划方程
        //dp[n] = dp[n - 1] + dp[n - 2] + ...... + dp[1] + 1
        //dp[1] = 1
        vector<int> dp(number + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= number; i++){
            for(int j = 1; j <= i - 1; j++){
                dp[i] += dp[j];
            }
            dp[i] += 1;
        }
        return dp[number];
        
    }
};
