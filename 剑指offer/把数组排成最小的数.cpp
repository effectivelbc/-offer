/*
时间限制：1秒 空间限制：32768K 热度指数：166229
本题知识点： 数组

题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323
*/

//4ms 占用空间504k
class Solution {
public:
    static bool cmp(const int& numbers1, const int& numbers2){
        string a1 = to_string(numbers1) + to_string(numbers2);
        string a2 = to_string(numbers2) + to_string(numbers1);
        return a1 < a2;
    }
    string PrintMinNumber(vector<int> numbers) {
        //正整数，不存在0
        if(numbers.size() == 0){
            return "";
        }
        stringstream ans;
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i : numbers){
            ans << to_string(i);
        }
        return ans.str();
    }
};