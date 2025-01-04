//
//  main.cpp
//  linklist
//
//  Created by zhuzhuxia on 2025/1/3.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node(int val){data=val;next=nullptr;}
};

int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    Node * head=nullptr;
    Node * current=nullptr;

    for (int i = 0 ; i<n; i++) {
        int val;
        cin>>val;
        if(!head){
            head = current = new Node(val);
        }else{
            current->next = new Node(val);
            current=current->next;
        }
    }
    
    current =head;
    while (current!=nullptr) {
        cout<<current->data<<" ";
        current=current->next;
    }
    
    return 0;
}
