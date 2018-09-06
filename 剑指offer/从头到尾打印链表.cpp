/*
时间限制：1秒 空间限制：32768K 热度指数：645440
本题知识点： 链表

题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

//4ms O(n) 占用内存 460k
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> answer;
        while(head != nullptr){
            answer.insert(answer.begin(),head->val);
            head = head->next;
        }
        return answer;
    }
};