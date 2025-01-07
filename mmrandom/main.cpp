//
//  main.cpp
//  mmrandom
//
//  Created by zhuzhuxia on 2025/1/7.
//

//
//  doublelinklib.h
//  cppSubject
//
//  Created by zhuzhuxia on 2025/1/7.
//

#ifndef doublelinklib_h
#define doublelinklib_h

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
    
    Node* getHead(){
        return head;
    }
    
    void setHead(Node*hd){
        head = hd;
    }
    
    Node* getTail(){
        return tail;
    }
    
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
    
    void showSubLine(int x ){
        if ( head && tail ) {
            Node*current = tail;
            
            int index = 1;
            while (current!= nullptr) {
                if (index == x) {
                    break;
                }
                current=current->prev;
                index++;
            }
            // 遍历剩余部分
            
            while (current!=nullptr) {
                cout<<current->data<<" ";
                current=current->next;
            }
        }
    }
    
    void deleteElementByIndex(int x){
        if (head) {
            Node*current = head;
            
            int index = 1;
            while (current!=nullptr) {
                if (index == x) {
                    // delete
                    // head or tail
                    if (current->next==nullptr || current->prev==nullptr) {
                        //delete
                        delete current;
                    }else{
                        Node * cPrev = current->prev;
                        Node * cNext = current -> next;
                        
                        cPrev -> next = cNext;
                        cNext-> prev = cPrev;
                        
                        delete current;
                        break;
                    }
                    
                }else{
                    current = current->next;
                    index++;
                }
            }
        }
        // 否则不处理
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
    
    bool huiWenShu(){
        
        int index = 1;
        
        if ( head && tail ) {
            Node* cHead = head;
            Node* cTail = tail;
            string _cHead,_cTail;
            
            while (cHead!=nullptr&&cTail!=nullptr) {
                
                _cHead += cHead->data;
                _cTail += cTail->data;
                
                cHead=cHead->next;
                cTail=cTail->prev;
                
                index++;
            }
            
            if (_cHead==_cTail) {
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
    
};


#endif /* doublelinklib_h */


#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
    
    DoubleLink list;
    
    int n;
    cin>>n;
    
    for (int i=0; i<n; i++) {
        int val;
        cin>>val;
        list.insert(val);
    }
    
    Node * Head = list.getHead();
    Node * current = Head;
    
    int dlength = 0;
    
    while (current!=nullptr) {
        Node * nextNode = current->next;
        Node * prevNode = current->prev;
        
        if (current!=nullptr && nextNode!=nullptr &&  current->data == nextNode->data ) {
            //delete current
            
                if (current==Head) {
//                    current=nextNode;
                    list.setHead(current->next);
                }
                else{
                    // 不是开头
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                }
                dlength++;
        }
        current=current->next;
    }
    
    cout<<n-dlength<<"\n";
    list.printForward();
    
    return 0;
}
