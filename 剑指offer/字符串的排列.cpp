/*
时间限制：1秒 空间限制：32768K 热度指数：266694
本题知识点： 字符串

题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母
*/

//3ms 占用空间608k
class Solution {
public:
    int length;
    vector<string> s;
    string temp;
    
    string one;
    vector<bool> flag;
    
    vector<string> Permutation(string str) {
        if(str.empty()){
            return vector<string>();
        }
        length = str.length();
        temp = str;
        
        sort(temp.begin(), temp.end());
        flag.resize(length, 0);
        one.resize(length, '\0');
        dfs(0);
        return s;
    }
    void dfs(int num) {
        if(num == length){
            s.push_back(one);
            return;
        }
        for(int i = 0; i < length; i++){
            if(flag[i] == true){
                continue;
            }
            //重复且上一个未用
            if(i > 0 && temp[i] == temp[i - 1] && flag[i - 1] == false){
                continue;
            }
            one[num] = temp[i];
            flag[i] = true;
            dfs(num + 1);
            flag[i] = false;
        }
        
    }
};