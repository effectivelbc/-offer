/*
时间限制：1秒 空间限制：32768K 热度指数：96777
本题知识点： 字符串

题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是
*/

//4ms 占用空间376k
class Solution {
public:
    bool isNumeric(char* string)
    {
        //e前面只能是个位数跟小数点 后面只能是整数但不能是0
        //正负号只能出现在第一位或者e后面一位
        //小数点只能出现一次
        if(string == nullptr){
            return false;
        }
        char* str1 = string;
        int length = 0;
        bool is_first = true;
        bool is_symbol = false;
        
        while(*str1 != '\0'){
            if(length == 0 && (*str1 == '+' || *str1 == '-')){
                if(is_symbol == true){
                    return false;
                }
                str1++;
                is_symbol = true;
                continue;
            }
            if(length == 0 && *str1 == '0' && *(str1 + 1) != '.' && *(str1 + 1)!= '\0'){
                return false;
            }
            //.在最后一位
            if(*str1 == '.' && *(str1 + 1) == '\0' ){
                return false;
            }
            if(*str1 != 'e' && *str1 != 'E' && (*str1 < '0' || *str1 > '9') && *str1 != '.'){
                return false;
            }
            if(*str1 == 'e' || *str1 == 'E'){
                if(is_symbol){
                    return isNumeric_preE(string + 1, length ) && isNumeric_afterE(string + 1 + length + 1);
                }
                else{
                    return isNumeric_preE(string, length) && isNumeric_afterE(string + length + 1);
                }
                
            }
            if(*str1 == '.'){
                if(is_first){
                    is_first = false;
                }
                else{
                    return false;
                }
            }
            if(*str1 == '.' && *(str1 + 1) == '\0' ){
                return false;
            }
            length++;
            str1++;
        }
        if(is_symbol == true && length == 0){
            return false;
        }
        return true;
    }
    
    bool isNumeric_preE(char* string, int length){
        if(length == 0){
            return false;
        }
        //小数点只能在第二位
        //.在最后一位
        if(*(string + length - 1) == '.') {
            return false;
        }
        int length1 = 0;
        //假设没有小数点
        bool isPoint = false;
        bool is_symbol = false;
        while(length--){
            if(length1 == 0 && (*string == '+' || *string == '-')){
                if(is_symbol == true){
                    return false;
                }
                string++;
                is_symbol = true;
                continue;
            }
            //小数点在第一位
            if(length1 == 0 && *string == '.'){
                return false;
            }
            if( (*string < '0' || *string > '9') && *string != '.' ){
                return false;
            }
            if(*string == '.'){
                if(isPoint == true){
                    return false;
                }
                else{
                    isPoint = true;
                }
            }
            length1++;
            string++;
        }
        if(is_symbol == true && length1 == 0){
            return false;
        }
        return true;    
    }
    
    bool isNumeric_afterE(char* string){
        if(*string == '\0'){
            return false;
        }
        //只能是整数且不为0
        int length = 0;
        bool is_symbol = false;
        while(*string != '\0'){
            if(length == 0 && (*string == '+' || *string == '-')){
                if(is_symbol == true){
                    return false;
                }
                string++;
                is_symbol = true;
                continue;
            }
            if(length == 0 && *string == '0'){
                return false;
            }
            if(*string < '0' || *string > '9'){
                return false;
            }
            length++;
            string++;
        }
        //只有符号
        if(is_symbol == true && length == 0){
            return false;
        }
        return true;
    }

};