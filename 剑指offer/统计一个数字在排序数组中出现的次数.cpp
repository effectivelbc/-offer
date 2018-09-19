/*
时间限制：1秒 空间限制：32768K 热度指数：162739
本题知识点： 数组

题目描述
统计一个数字在排序数组中出现的次数
*/

//3ms 占用空间460k
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()){
            return 0;
        }
        int start = 0;
        int end = data.size() - 1;
        int i = (start + end) / 2;
        bool flag = false;
        //二分法找到数字
        while(start <= end){
            if(data[i] > k){
                end = i - 1;
            }
            else if(data[i] < k){
                start = i + 1;
            }
            else{
                flag = true;
                break;
            }
            i = (start + end) / 2;
        }
        if(flag == false){
            return 0;
        }
        int num = 1;
        int j = i - 1;
        //找k前面
        while(j >= 0 && data[j] == k){
            num++;
            j--;
        }
        j = i + 1;
        while(j <= data.size() - 1 && data[j] == k){
            num++;
            j++;
        }
        return num;
    }
};