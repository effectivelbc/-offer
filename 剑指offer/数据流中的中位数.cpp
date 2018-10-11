/*
时间限制：1秒 空间限制：32768K 热度指数：93073

题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

//3ms 376k
class Solution {
public:
    //记录奇偶
    //最大堆
    //维护前n/2
    vector<int> max;
    //最小堆
    //维护后n/2
    vector<int> min;
    void Insert(int num)
    {
        //数据数量是偶数
        if( ((max.size() + min.size()) & 1) == 0 ){
            //在最小堆中插入元素
            //如果这个值比最大堆最大的小，则插入最大堆中，替换出最大堆的最大值，插入最小堆中
            if(max.size() > 0 && num < max[0]){
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                //pop的值被放在尾端
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        //数据数量是奇数
        else{
            //在最大堆中插入元素
            if(min.size() > 0 && num > min[0]){
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back(); 
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    {
        if(min.size() + max.size() == 0){
            return -1;
        }
        if( ((min.size() + max.size()) & 1) == 0 ){
            return (double) (max[0] + min[0]) / 2;
        }
        else{
            return (double) min[0];
        }
    }

};