/*
时间限制：1秒 空间限制：32768K 热度指数：297773
本题知识点： 数组

题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

//3ms 占用空间376k
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() < k || k <= 0 || input.empty()){
            return vector<int>();
        }
        if(k == input.size()){
            return input;
        }
        //借鉴快速排序法的思想
        int l = 0;
        int r = input.size() - 1;
        int index = partition(input, l, r);
        while(index != k - 1){
            if(index > k - 1){
                index = partition(input, l, index - 1);
            }
            else{
                index = partition(input, index + 1, r);
            }
        }
        return vector<int>(input.begin(), input.begin() + k);
    }
    
    int partition(vector<int>& num, int l, int r){     
        int base = rand() % (r - l + 1) + l;
        swap(num[r], num[base]);
        int& mid = num[r];
        int i = l;
        //
        int j = r;
        while(i < j){
            while(num[i] <= mid && i < j){
                i++;
            }
            while(num[j] >= mid && i < j){
                j--;
            }
            if(i < j){
                swap(num[i], num[j]);
            }
        }
        swap(num[i], mid);
        return i;
    }
};