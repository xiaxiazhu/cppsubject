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
    string name;
    int ageYear;
    int ageMonth;
    int ageDay;
};

bool compare(const Person &a,const Person &b){
    
    if (a.ageYear == b.ageYear) {
        
        if (a.ageMonth == b.ageMonth) {

            if(a.ageDay==b.ageDay){
                
                return true;
            
            }else{
                
                return a.ageDay<b.ageDay;
            }
            
        }else{
            
            return a.ageMonth < b.ageMonth;
        }
    }else{
        return a.ageYear < b.ageYear;
    }
}

int main(){
    int n;
    cin>>n;
    
    vector<Person> persons(n);
    
    for (int i=0; i<n; i++) {
        cin>>persons[i].name;
        cin>>persons[i].ageYear;
        cin>>persons[i].ageMonth;
        cin>>persons[i].ageDay;
    }
    
    // out put by order
    sort(persons.begin(), persons.end(), compare);
    
    for (int j = 0 ; j<n; j++) {
        
        cout<<persons[j].name << "\n";
    }
    
}
