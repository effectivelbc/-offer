/*
时间限制：1秒 空间限制：32768K 热度指数：860208
本题知识点： 查找

题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
*/

//14ms O(m * n)
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //if array is empty
        if(array.empty() || array[0].empty()){
            return false;
        }
        
        if(target < array[0][0] || target > array[array.size() - 1][array[0].size() - 1]){
            return false;
        }
        
        for(int i = 0; i < array.size(); i++){
            for(int j = 0; j < array[0].size(); j++){
                if(target == array[i][j]){
                    return true;
                }
            }
        }
        return false;
    }
};

//改进方法，维护两个指针，从左下角开始查找，如果目标大于当前指针指向的值，则指针右移，
//小于则指针上移，可能是测试用例问题导致此方法竟然比暴力方法还慢了1ms。。。
//15ms O(m+n)
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //if array is empty
        if(array.empty() || array[0].empty()){
            return false;
        }
        
        if(target < array[0][0] || target > array[array.size() - 1][array[0].size() - 1]){
            return false;
        }
        
        for(int i = array.size() - 1, j = 0; i >= 0 && j < array[0].size(); ){
            if(target < array[i][j]){
                i--;
            }
            else if(target > array[i][j]){
                j++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};