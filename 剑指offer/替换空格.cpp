/*
时间限制：1秒 空间限制：32768K 热度指数：729917
本题知识点： 字符串

题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

//4ms O(n) 占用内存408k
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length <= 0){
            return;
        }
        
        int spaceCount = 0;
        //space count statistics
        for(int i = 0; i < length; i++){
            if(str[i] == ' '){
                spaceCount++;
            }
        }
        
        int newLength = length + spaceCount * 2;
        //分配空间
        str = (char *)realloc(str, sizeof(char) * (newLength + 1));
        str[newLength] = '\0';
        
        for(int i = length - 1, j = newLength - 1; i >= 0; ){
            if(str[i] != ' '){
                str[j] = str[i];
                i--;
                j--;
            }
            else{
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }
        }
            
        
	}
};