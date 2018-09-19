/*
时间限制：1秒 空间限制：32768K 热度指数：190509
本题知识点： 字符串

题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
*/

//4ms 占用空间456k
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()){
            return -1;
        }
        //区分大小写一共52个字符
        //记录每个字符出现的第一个位置，如果出现了第二次，则值变为10001
        vector<int> pos(58 + 1, -1);
        
        for(int i = 0; i < str.length(); i++){
            if(pos[str[i] - 'A'] < 0){
                pos[str[i] - 'A'] = i;
            }
            else if(pos[str[i] - 'A'] < 10000){
                //在某位置出现过
                pos[str[i] - 'A'] = 10001;
            }
            else{
                //出现过多次了
                continue;
            }
        }
        int min_pos = 10001;
        int flag = 0;
        for(int i = 0; i < 58; i++){
            if(pos[i] >= 0 && pos[i] < 10000){
                min_pos = min(min_pos,pos[i]);
                flag = 1;
            }
        }
        if(flag == 1){
            return min_pos;
        }
        else{
            return -1;
        }
        
    }
};