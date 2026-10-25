#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPair(ListNode* head){
    if(head==NULL || head->next==NULL) return head;

    ListNode* newHead = head->next;
    head->next = swapPair(newHead->next);
    newHead->next = head;
    return newHead;
}

int main(){
    ListNode* head = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);

    head->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l5;

    head = swapPair(head);

    for(ListNode* p=head; p!=NULL; p=p->next){
        cout<<p->val<<" ";
    }
    return 0;
}