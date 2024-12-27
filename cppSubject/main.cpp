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
////#include <cmath>
//#include <climits>
////#include <unordered_map>
////#include <stack>
//#include <sstream>
//#include <algorithm>
//#include <cctype>
//#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

struct Person{
    string name;
    int y;
    int m;
    int d;
};

bool compare(Person a, Person b){
    if (a.y<b.y) {
        return true;
    }else if(a.y==b.y){
        if (a.m < b.m) {
            return true;
        }else if(a.m==b.m){
            if (a.d<b.d) {
                return true;
            }else if(a.d==b.d){
                return false;
            }else{
                return false;
            }
            
        }else{
            return false;
        }
    }else{
        return false;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<Person> pList(n);
    
    for (int i=0; i<n; i++) {
        cin>>pList[i].name;
        cin>>pList[i].y;
        cin>>pList[i].m;
        cin>>pList[i].d;
    }
    
    sort(pList.begin(), pList.end(), compare);
    
    for (Person p :pList)
    {
        cout<< p.name <<"\n";
    }
    
    return 1;
}


