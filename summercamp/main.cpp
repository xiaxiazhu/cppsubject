//
//  main.cpp
//  summercamp
//
//  Created by zhuzhuxia on 2025/1/7.
//
#include <iostream>
using namespace std;

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


int main(int argc, const char * argv[]) {

    DoubleLink list;
    
    int n,k;
    
    cin>>n;
    cin>>k;
    
    for (int i=1; i<=n; i++) {
        list.append(i);
    }
    
    // 第k个出列
    Node*current = list.getHead();
    
    int index =0;
    bool direcetion=true; // 顺向

    while (current!=nullptr) {
        
        index++;
        
        if (index%k ==0) {
            Node*p=current->prev;
            Node*n=current->next;
            if (n==nullptr) {
                p->next=n;
//                n->prev=p;
                
            }else if(p==nullptr){
//                p->next=n;
                n->prev=p;

            }else{
                p->next=n;
                n->prev=p;

            }
            

        }
        
        if (current->prev==nullptr) {
            //到头
            direcetion=true;
        }
        
        if (current->next==nullptr) {
            //到尾
            direcetion=false;
        }
        
        if (direcetion) {
            current=current->next;
        } else {
            current=current->prev;
        }
        
        //跳出结尾
        if (current->next==nullptr && current->prev==nullptr) {
            cout<<current->data<<"\n";
            break;
        }
        
    }
    
    return 0;
}
