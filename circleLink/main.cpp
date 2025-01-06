//
//  main.cpp
//  circleLink
//
//  Created by zhuzhuxia on 2025/1/6.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int val):data(val),next(nullptr){};
};

int main(int argc, const char * argv[]) {
    
    int n,k;
    cin>>n;
    cin>>k;
    // 构建环形链表
    Node * head = new Node(1);
    Node * current = head;
    
    for (int i=2; i<=n-1; i++) {
        Node * newNode = new Node(i);
        
        current->next = newNode;
        current = newNode;
    }
    
    Node * newLastNode = new Node(n);
    current->next = newLastNode;
    current=newLastNode;
    
    newLastNode->next=head;
    current = head;
    
    //使用环形链表
    int step =1;
    while (current!=nullptr ) {
        //4
        step++;
        // 备份一个current之前的节点
        Node* forwardPoint = current;
        current=current->next;
        
        if (step%k==0) {
            cout<<current->data<<" ";
            // delete 当前node
            forwardPoint->next = current->next;
//            current = current->next;
            if (forwardPoint->data == current->data) {
                break;
            }
        }
    }
    
    return 0;
}
