#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);

    head->next=l2;
    l2->next=l3;
    l3->next=NULL;

    if(head==NULL || head->next==NULL) {
        cout<< head->val<<endl;
        return 0;
    }

    ListNode* prev=NULL;
    ListNode* curr=head;

    while(curr!=NULL){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    cout<< prev->val<<endl;
    return 0;
}