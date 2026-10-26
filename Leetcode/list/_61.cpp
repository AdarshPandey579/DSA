#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(k==0 || head==NULL || head->next==NULL) return head;
    
    ListNode* temp=head;
    int count=1;

    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }

    k%=count;
    if(k==0) return head;

    temp->next=head;
    int steps=count-k;
    while(steps>0){
        temp=temp->next;
        steps--;
    }

    ListNode* newHead=temp->next;
    temp->next=NULL;
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

    head = rotateRight(head, 2);
    
    ListNode* current = head;
    while(current != NULL){
        cout << current->val << " ";
        current = current->next;
    }
    return 0;
}