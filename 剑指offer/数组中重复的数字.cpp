/*
时间限制：1秒 空间限制：32768K 热度指数：156192
本题知识点： 数组

题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/

//3ms 占用空间480k
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == nullptr || length == 0){
            duplication = nullptr;
            return false;
        }
        //第一轮遍历，做交换
        for(int i = 0; i < length; i++){
            if(numbers[i] != numbers[numbers[i]]){
                int temp = numbers[i];
                numbers[i] = numbers[numbers[i]];
                numbers[temp] = temp;
            }
            //numbers[i]的位置不在它应该在的位置有相同值了
            if(numbers[i] != i && numbers[numbers[i]] == numbers[i]){
                *duplication = numbers[i];
                return true;
            }
        }
        //第二轮遍历
        duplication = nullptr;
        return false;
    }
};