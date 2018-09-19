/*
时间限制：1秒 空间限制：32768K 热度指数：134552
本题知识点： 字符串

题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
*/

//2ms 占用空间484k
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()){
            return 0;
        }
        int result = 0;
        int symbol = 1;
        int min_value = 0x80000000;
        if(str[0] == '-'){
            symbol = -1;
        }
        for(int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < str.size(); i++){
            if(!('0' <= str[i] && str[i] <= '9')){
                return 0;
            }
            //不正溢出
            if(symbol == 1 && result * 10 > 0x7fffffff - (str[i] - '0')){
                return 0;
            }
            //不负溢出
            if(symbol == -1 && -1 * result * 10 < min_value + (str[i] - '0')){
                return 0;
            }
            result = result * 10 + str[i] - '0';
            
        }
        return result * symbol;
    }
};