/*
时间限制：1秒 空间限制：32768K 热度指数：145108

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

//4ms 占用空间460k
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2){
            return vector<int>();
        }
        //可能是负数
        //i,j双指针
        vector<int> a;
        int min_mul = 0x7fffffff;
        int i = 0, j = array.size() - 1;
        while(i < j){
            if(array[i] + array[j] < sum){
                i++;
            }
            else if(array[i] + array[j] > sum){
                j--;
            }
            else{
                int mul = array[i] * array[j];
                if(mul < min_mul){
                    a.clear();
                    min_mul = mul;
                    a.push_back(array[i]);
                    a.push_back(array[j]);
                }
                i++;
                j--;
            }
        }
        return a;
    }
};