/*
时间限制：1秒 空间限制：32768K 热度指数：343310
本题知识点： 数组

题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

//3ms 占用空间608k O(n^2) 因为erase时会循环位移
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        for(int i = 0; i < size; ){
            if(array[i] & 1){
                i++;
            }
            else{
                array.push_back(array[i]);
                array.erase(array.begin() + i);
                size--;
            }
        }
    }
};

//采用冒泡的想法 每次冒一个偶数到最后
//3ms 占用空间480k
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i = 0; i < array.size(); i++){
            for(int j = 0; j < array.size() - i; j++){
                if(array[j] % 2 == 0 && (array[j + 1] & 1)){
                    swap(array[j], array[j + 1]);
                }
            }
        }
    }
};