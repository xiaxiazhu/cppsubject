//
//  main.cpp
//  linkMerge
//
//  Created by zhuzhuxia on 2025/1/5.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node*prev;
    Node*next;
    Node(int val):data(val),prev(nullptr),next(nullptr){};
};

class Doublelink{
private:
    Node*head;
    Node*tail;
public:
    Doublelink():head(nullptr),tail(nullptr){};
    
    void append(int data){
        Node*newNode=new Node(data);
        Node*current = newNode;
        
        if (!head) {
            head=tail=newNode;
        }else{
            tail->next=current;
            current->prev=tail;
            tail=current;
        }
    }
    
    Node* getHead(){
        return head;
    }
    
    void printForward(){
        Node*current = head;
        
        while (current!=nullptr) {
            cout<<current->data<<" ";
            current = current->next;
        }
        delete current;
    }
    void printBackward(){
        
        Node*current = tail;
        
        while (current!= nullptr) {
            cout<< current->data <<" ";
            current=current->prev;
        }
        
        delete current;
    };


};

Doublelink mergeLink(Doublelink l1,Doublelink l2){
    
    Node * current1 = l1.getHead();
    Node * current2 = l2.getHead();
    
    Doublelink merged;
    
    while (current1!=nullptr || current2!=nullptr) {
        
        if (current1==nullptr&&current2==nullptr) {
            break;
        }
        
        if (current1==nullptr) {
            if (current2!=nullptr) {
                merged.append(current2->data);
                current2=current2->next;
            }
        }
        
        if (current2==nullptr) {
            if (current1 != nullptr) {
                merged.append(current1->data);
                current1=current1->next;
            }
        }

        if (current1!= nullptr && current2!=nullptr) {
            
            if (current1->data >= current2->data) {
                merged.append(current2->data);
                current2 = current2->next;
            }else{
                merged.append(current1->data);
                current1 = current1->next;
            }
        }
    }
    delete current1;
    delete current2;
    return merged;
}

int main(int argc, const char * argv[]) {
    
    Doublelink list1,list2;
    int n;
    cin>>n;
    for (int i =0; i<n; i++) {
        int v1;
        cin>>v1;
        list1.append(v1);
    }
    
    int m;
    cin>>m;
    for (int j=0;j<m ; j++) {
        int v2;
        cin>>v2;
        list2.append(v2);
    }
    
    Doublelink result = mergeLink(list1, list2);
    
    result.printBackward();
    
    return 0;
}
