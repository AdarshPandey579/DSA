#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

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

    // for(ListNode* p=head->next; p!=NULL; p=p->next){
    //     cout<<p->val<<" ";
    // }

    int left=2, right=4;

    ListNode* temp = head;
    ListNode* prevtemp = NULL;
    int position = 1;
    while(position<left){
        prevtemp = temp;
        temp = temp->next;
        position++;
    }
    // cout<<"temp: "<<temp->val<<endl;
    // cout<<"prevtemp: "<<prevtemp->val<<endl;

    ListNode* prev = NULL;
    ListNode* curr = temp;
    ListNode* next = NULL;
    int times = right - left + 1;
    while(times>0){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        times--;
    }

    temp->next = curr;
    if(prevtemp!=NULL){
        prevtemp->next = prev;
    }
    else{
        head = prev;
    }
    
    for(ListNode* p=head; p!=NULL; p=p->next){
        cout<<p->val<<" ";
    }

    return 0;


}