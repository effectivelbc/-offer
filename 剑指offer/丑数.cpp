/*
时间限制：1秒 空间限制：32768K 热度指数：186378
本题知识点： 数组

题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

//3ms 占用空间608k
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> dp(index + 1, 0);
        int i1 = 1, i2 = 1, i3 = 1;
        dp[1] = 1;
        for(int i = 2;i <= index; i++){
            int a1 = dp[i1] * 2;
            int a2 = dp[i2] * 3;
            int a3 = dp[i3] * 5;
            
            dp[i] = min({a1, a2, a3});
            if(dp[i] == a1){
                i1++;
            }
            if(dp[i] == a2){
                i2++;
            }
            if(dp[i] == a3){
                i3++;
            }
            
        }
        return dp[index];
    }
};