/*
时间限制：2秒 空间限制：32768K 热度指数：222355
本题知识点： 数组

题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5
*/

//98ms 4288k
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()){
            return 0;
        }
        vector<int> temp(data.size());
        return MergeSort(data, temp, 0, data.size() - 1);
         
    }
    
    
    int MergeSort(vector<int>& data, vector<int>& temp, int start, int end){
        //左边的逆序数，右边的逆序数，合并的逆序数
        int left = 0, right = 0, count = 0;
        if(start == end){
            temp[start] = data[start];
        }
        else{
            int middle = (start + end) / 2;
            left = MergeSort(data, temp, start, middle);
            right = MergeSort(data, temp, middle + 1, end);
            count = Merge(data, temp, start, middle, end);
        }
        return (left + right + count) % 1000000007;
    }
    
    int Merge(vector<int>& data, vector<int>& temp, int start, int middle, int end){
        //int i = start;
        //int j = middle + 1;
        //int index = start;
        int i = middle;
        int j = end;
        int index = end;
        int count = 0;
        while(i >= start && j >= middle + 1 ){
            //前比后大
            if(data[i] > data[j]){
                
                count = count + j - middle;
                temp[index--] = data[i--];
                if(count >= 1000000007){
                    count = count % 1000000007;
                }
            }
            else{
                temp[index--] = data[j--];
            }
        }
        while(i >= start){
            temp[index--] = data[i--];
        }
        while(j >= middle + 1){
            temp[index--] = data[j--];
        }
        for (int i = start; i <= end; i++){
			data[i] = temp[i];
        }
        return count;
    }
};