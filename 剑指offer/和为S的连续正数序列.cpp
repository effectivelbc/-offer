/*
时间限制：1秒 空间限制：32768K 热度指数：157420

题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum < 3){
            return vector<vector<int> >();
        }
        //至少包括两个数
        
        vector<vector<int> > seqs;
        int a = 1;
        int n = 2;
        int seq_sum;
        while(a <= sum / 2){
            seq_sum = 0;
            n = 2;
            while(seq_sum <= sum){
                seq_sum = (a + a + n - 1) * n / 2;
                if(seq_sum == sum){
                    int k = a;
                    int m = n;
                    vector<int> seq;
                    while(m--){
                        seq.push_back(k++);
                    }
                    seqs.push_back(seq);
                    break;
                }
                n++;
            }
            a++;
        }
        return seqs;
        
    }
};