/*
时间限制：1秒 空间限制：32768K 热度指数：111251

题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

//3ms 480k
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows <= 0||cols <= 0||threshold < 0){
            return 0;
        }
        //从坐标0 0 开始移动
        int sum = 0;
        int row = 0, col = 0;
        bool flag[rows * cols + 1];
        for(int i = 0; i < rows * cols; i++){
            flag[i] = false;
        }
        dfs(threshold, rows, cols, row, col, flag);
        for(int i = 0; i < rows * cols; i++){
            if(flag[i]){
                sum += 1;
            }
        }
        return sum;
    }
    
    void dfs(int k, int rows, int cols, int row, int col, bool* flag){
        if(row >= 0 && row < rows && col >= 0 && col < cols 
           && sumNumber(row, col) <= k && flag[row * cols + col] == false){
            flag[row * cols + col] = true;
            
            dfs(k, rows, cols, row + 1, col, flag);
            dfs(k, rows, cols, row, col + 1, flag);
            dfs(k, rows, cols, row - 1, col, flag);
            dfs(k, rows, cols, row, col - 1, flag);
            
        }
        return;
    }
    
    int sumNumber(int row, int col){
        int sum = 0;
        while(row != 0){
            sum += row % 10;
            row = row / 10;
        }
        while(col != 0){
            sum += col % 10;
            col = col / 10;
        }
        return sum;
    }
};