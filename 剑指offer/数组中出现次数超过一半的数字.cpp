/*
时间限制：1秒 空间限制：32768K 热度指数：232031
本题知识点： 数组

题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

//4ms 占用空间488k
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()){
            return 0;
        }
        if(numbers.size() == 1){
            return numbers[0];
        }
        //记录数字
        int num_record = -1;
        int last_num_record = -1;
        //记录出现的次数 - 未出现的次数
        int k = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] != num_record){
                k--;
                last_num_record = num_record;
                if(k < 0){
                    num_record = numbers[i];
                    k = 1;
                }
            }
            else{
                last_num_record = num_record;
                k++;
            }
        }
        if(k > 0 && last_num_record == num_record){
            return num_record;
        }
        else{
            return 0;
        }
        
    }
};