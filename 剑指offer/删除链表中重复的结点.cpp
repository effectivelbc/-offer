/*
时间限制：1秒 空间限制：32768K 热度指数：220083
本题知识点： 链表

题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

//4ms 496k
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr){
            return pHead;
        }
        //链表已排好序
        //记录前一个是不是需要删除
        bool flag = false;
        ListNode* pHeadReturn = new ListNode{0};
        pHeadReturn -> next = pHead;
        ListNode* p1 = pHead;
        ListNode* pre = pHeadReturn;
        ListNode* prePre = pHeadReturn;
        int i = 0;
        while(pre != nullptr && p1 != nullptr){
            if(i != 0 && p1 -> val == pre -> val){
                //移除p1
                flag = true;
                pre -> next = p1 -> next;
                p1 = p1 -> next;
                if(p1 == nullptr){
                    //移除pre
                    prePre -> next = pre -> next;
                }
            }
            else{
                if(flag == true){
                    //连同pre一起删除
                    prePre -> next = pre -> next;
                    //更新pre
                    pre = prePre -> next;
                    if(pre == nullptr){
                        return pHeadReturn -> next;
                    }
                    //更新p1
                    p1 = pre -> next;
                    flag = false;
                   
                }
                else{
                    //不删除pre 同时更新prePre为pre
                    prePre = pre;
                    pre = pre -> next;
                    if(pre == nullptr){
                        return pHeadReturn -> next;
                    }
                    p1 = pre -> next;
                }
            }
            
            i++;
        }
        return pHeadReturn -> next;
    }
};