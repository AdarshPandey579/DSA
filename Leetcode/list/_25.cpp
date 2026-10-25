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


ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp=head;
    int count=0;
    while(count<k){
        if(temp==NULL) return head;
        temp=temp->next;
        count++;
    }

    ListNode* prevNode=reverseKGroup(temp,k);

    temp=head;
    count=0;
    ListNode* next=NULL;
    while(count<k){
        next=temp->next;
        temp->next=prevNode;
        prevNode=temp;
        temp=next;
        count++;
    }
    return prevNode;

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

    head = reverseKGroup(head,3);

    for(ListNode* p=head; p!=NULL; p=p->next){
        cout<<p->val<<" ";
    }
    return 0;
}