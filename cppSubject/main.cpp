//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <cmath>
#include <climits>
//#include <unordered_map>
//#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

struct Person{
    int totle;
    int id;
    int yuwen;
    int math;
    int english;
};

bool compare(Person &a,Person&b){
    
    if (a.totle==b.totle) {
        
        if (a.yuwen==b.yuwen) {
            
            return a.id<b.id;
            
        }else{
            return a.yuwen>b.yuwen;
            
        }
        
    }else{
        return a.totle>b.totle;
    }
}

int main(){
    
    int n;
    cin>>n;
    
    vector<Person> pList(n);
    
    for (int i =0; i<n; i++) {
        
        cin>>pList[i].yuwen;
        cin>>pList[i].math;
        cin>>pList[i].english;
        
        pList[i].totle = pList[i].yuwen+pList[i].math+pList[i].english;
        pList[i].id = i+1;
    }
    
    sort(pList.begin(), pList.end(), compare);
    
    vector<Person> output(5);
    
    for (int j =0 ; j<5; j++) {
        output[j]=pList[j];
    }
    
    for(auto p:output){
        cout << p.id <<" "<<p.totle<<"\n";
    };
    
}
