//
//  main.cpp
//  student
//
//  Created by zhuzhuxia on 2025/1/1.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
    string name;
    string gender;
    int year;
    int month;
};

bool compare(const student &a,const student&b){
    if (a.year>b.year) {
        return true;
    }else if(a.year==b.year){
        if (a.month>b.month) {
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
    
    vector<student> stdList(n);
    
    for (int i=0; i<n; i++) {
        cin>>stdList[i].name;
        cin>>stdList[i].gender;
        cin>>stdList[i].year;
        cin>>stdList[i].month;
    }
    
    sort(stdList.begin(), stdList.end(), compare);
    
    for(auto st :stdList){
        cout<<st.name<<" "<<st.gender<<" "<<st.year<<" "<<st.month<<"\n";
    }
    return 0;
}
