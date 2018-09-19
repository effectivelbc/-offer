/*
时间限制：1秒 空间限制：32768K 热度指数：165412
本题知识点： 数组

题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/

//3ms 占用空间452k
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        
        int max_sum = 0x80000000;
        int current = 0;
        int pre = 0;
        for(int i = 0; i < array.size(); i++){
            current = pre + array[i];
            if(current > max_sum){
                max_sum = current;
            }
            if(current < 0){
                pre = 0;
            }
            else{
                pre = current;
            }
        }
        return max_sum;
    }
};