/*
时间限制：1秒 空间限制：32768K 热度指数：207655

题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

//3ms 占用空间376k 
class Solution {
public:
    int rectCover(int number) {
        if(number == 0){
            return 0;
        }
        if(number == 1){
            return 1;
        }
        if(number == 2){
            return 2;
        }
        
        //最后剩两块横着摆和最后剩一块竖着摆
        
        int a1 = 1;
        int a2 = 2;
        int answer = 0;
        for(int i = 3; i <= number; i++){
            answer = a1 + a2;
            a1 = a2;
            a2 = answer;
        }
        return answer;
    }
};