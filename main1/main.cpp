//
//  main.cpp
//  main1
//
//  Created by zhuzhuxia on 2024/12/28.
//

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

struct Student{
    string name;
    int height;
    int id;
};

bool compare(const Student&a,const Student&b){
    
    if (a.height > b.height) {
        return true;
    }else if(a.height==b.height){
        if (a.id<b.id) {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    
    vector<Student> sList(n);
    
    for (int i=0; i<n; i++) {
        cin>>sList[i].name;
        cin>>sList[i].height;
        cin>>sList[i].id;
    }
    
    sort(sList.begin(), sList.end(), compare);
    
    Student st = sList[0];

    cout<< st.name <<" "<<st.height<<" "<<st.id<<"\n";
    
    return 0;
}
