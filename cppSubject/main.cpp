//
//  main.cpp
//  cppSubject
//
//  Created by zhuzhuxia on 2024/11/13.
//

#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <climits>
//#include <unordered_map>
//#include <stack>
#include <sstream>

using namespace std;

int main(){
    
    string originStr;
    
    getline(cin, originStr);
    
    stringstream stream(originStr);
    
    vector<string>words;
    
    string word;
    
    while( stream >> word ){
        
        size_t pos = word.find(".");
        
        if (pos!= string::npos) {
            //delete
            word.erase(pos,1);
        }
        
        
        words.push_back(word);
        
    }
    
    int length = 0;
    string swMax = "";
    
    for(string sw:words){
        
        if(sw.size()>length){
            length = (int)sw.size();
            swMax = sw;
        }
    }
    cout<<swMax<<" "<<to_string(length);
        
    return 0;
}
