/*
时间限制：3秒 空间限制：32768K 热度指数：400998
本题知识点： 查找

题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

//25ms 占用时间476k o(n)
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0){
            return 0;
        }
        
        if(rotateArray.size() == 1){
            return rotateArray[0];
        }
        
        for(int i = 0; i < rotateArray.size() - 1; i++){
            if(rotateArray[i] > rotateArray[i + 1]){
                return rotateArray[i + 1];
            }
        }
        return rotateArray[0];   
    }
};

//二分法优化版
//34ms 占用空间608k O(log2n)
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0){
            return 0;
        }
        
        if(rotateArray.size() == 1){
            return rotateArray[0];
        }
        
        int low = 0;
        int high = rotateArray.size() - 1;
        
        while(low + 1 < high){
            int mid = low + (high - low) / 2;
            if(rotateArray[mid] > rotateArray[high]){
                low = mid;
            }
            else if(rotateArray[mid] < rotateArray[high]){
                high = mid;
            }
            else{
                high--;
            }
        }
        return rotateArray[high];
    }
};