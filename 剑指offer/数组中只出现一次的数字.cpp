/*
时间限制：1秒 空间限制：32768K 热度指数：155689
本题知识点： 数组

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
*/

//4ms 占用空间480k
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2){
            return;
        }
        int two_xor = 0;
        for(int i = 0; i < data.size(); i++){
            two_xor = two_xor ^ data[i];
        }
        //int ori_two_xor = two_xor;
        int k = 0;
        for(k = 0; k < 32; k++){
            if(two_xor & 1 == 1){
                break;
            }
            two_xor = two_xor >> 1;
        }
        //第k位 等于1，说明异或的两个数一个该位为0一个该位位1
        //找到该位为1的
        int a = 0, b = 0;
        for(int i = 0; i < data.size(); i++){
            int j = k;
            int m = data[i];
            while(j--){
                m = m >> 1;
            }
            if(m & 1 == 1){
                a = a ^ data[i];
            }
            else{
                b = b ^ data[i];
            }
        }
        for(int i = 0; i < data.size(); i++){
            if(data[i] == a){
                *num1 = data[i];
            }
            if(data[i] == b){
                *num2 = data[i];
            }
        }
    }
};