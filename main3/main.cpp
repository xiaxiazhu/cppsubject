//
//  main.cpp
//  main3
//
//  Created by zhuzhuxia on 2024/12/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    int score;
};

bool compare(const Student &a,const Student &b){
    if (a.score>b.score) {
        return true;
    }else if(a.score==b.score){
        return a.name[0]<b.name[0];
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
        cin>>sList[i].score;
    }
    
    sort(sList.begin(), sList.end(), compare);
    
    for(auto l:sList){
        cout<<l.name<<" "<<l.score<<"\n";
    }

    return 0;
}

