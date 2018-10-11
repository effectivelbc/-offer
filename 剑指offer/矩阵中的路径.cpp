/*
时间限制：1秒 空间限制：32768K 热度指数：119332

题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
路径不能再次进入该格子。
*/

//5ms 380k
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows == 0 || cols == 0 || str == nullptr){
            return false;
        }
        bool flag[rows * cols + 1];
        for(int i = 0; i < rows * cols + 1; i++){
            flag[i] = false;
        }
        int length = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dfs(matrix, rows, cols, str, flag, i, j, length)){
                    return true;
                }
            }
        }
        return false;        
    }
    
    bool dfs(char* matrix, int rows, int cols, char* str, bool* flag, int i, int j, int &length){
        if(length == strlen(str)){
            return true;
        }
        bool hasPath = false;
        //不越界 且 值相等
        if(i >= 0 && i < rows && j >= 0 && j < cols && matrix[i * cols + j] == str[length]
          && flag[i * cols + j] == false){
            length ++;
            flag[i * cols + j] = true;
            
            hasPath = dfs(matrix, rows, cols, str, flag, i + 1, j, length)
                || dfs(matrix, rows, cols, str, flag, i - 1, j, length)
                || dfs(matrix, rows, cols, str, flag, i, j + 1, length)
                || dfs(matrix, rows, cols, str, flag, i, j - 1, length);
                
            //没找到 回溯
            if(!hasPath){
                length --;
                flag[i * cols + j] = false;
            }
        }
        
        
        return hasPath;
    }


};