//
//  main.cpp
//  doublelink
//
//  Created by zhuzhuxia on 2025/1/4.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node*prev;
    Node(int value):data(value),next(nullptr),prev(nullptr){}
};

class DoubleLink{
private:
    Node*head;
    Node*tail;
public:
    DoubleLink():head(nullptr),tail(nullptr){};
    
    void append(int data){
        Node * newNode = new Node(data);
        
        if (!head) {
            head= tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail=newNode;
        }
    }
    
    void prepend(int data){
        Node * newNode = new Node(data);
        if (!head) {
            head=tail=newNode;
        }else{
            head->prev = newNode;
            newNode->next=head;
            head=newNode;
        }
    }
    
    void deleteElment(int data){
        // search value
        if (!head&&!tail) return;
        
        Node * current = head;
        while (current!=nullptr) {
            if (current->data == data) {
                break;
            }
            current=current->next;
        }
        
        // delete node
        // head or tail
        if (current->next==nullptr ) {
            // tail
            delete current;
        }
        if(current->prev==nullptr){
            // head
            delete current;
        }
        // middle
        
        Node* cprev= current->prev;
        Node* cnext = current->next;
        
        cnext->prev = cprev;
        cprev->next = cnext;
        
        delete current;
    }
    
    void insert(int data){
        
        Node * insertNode = new Node(data);
        // 顺序遍历寻找合适的位置
        
        bool shengxu = true;
        
        if (!head) {
            head=tail=insertNode;
        }else{
            
            Node * current = head;
            
            while( current != nullptr ){
                
                if (current->next == nullptr ) {
                    if (current->data >data) {
                        shengxu?prepend(data) :append(data);
                    }else{
                        shengxu?append(data):prepend(data);
                    }
                    break;
                }
                
                if (current->next != nullptr) {
                    
                    Node * cNext = current->next;
                    
                    bool condition;
                    if (!shengxu) {
                        condition =(current->data >= insertNode->data && insertNode->data >= cNext->data);
                    }else{
                        condition =(current->data <=insertNode->data && insertNode->data <= cNext->data);
                    }
                    
                    if (condition)
                    {
                        insertNode->next=cNext;
                        insertNode->prev=current;
                        current->next=insertNode;
                        cNext->prev = insertNode;
                        break;
                    }
                    current=current->next;
                }
            }
            
        }
    }
    
    
    void printBackward(){
        Node*current = tail;
        
        while (current!= nullptr) {
            cout<< current->data <<" ";
            current=current->prev;
        }
        
        delete current;
    };
    
    void printForward(){
        Node*current = head;
        
        while (current!=nullptr) {
            cout<<current->data<<" ";
            current = current->next;
        }
        delete current;
    }
    
};


int main(int argc, const char * argv[]) {
    
    DoubleLink list;
    
    int n,x;
    cin>>n;
    cin>>x;
    
    for (int i =0; i<n; i++) {
        int a;
        cin>>a;
        list.append(a);
    }
    
    list.deleteElment(x);
    
    
//    int iValue;
//    cin>>iValue;
    
//    list.insert(iValue);
    
    list.printForward();
    //    list.printBackward();
    
    return 0;
}
