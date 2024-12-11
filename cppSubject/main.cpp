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
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;



int main(){

    string inputStr,beReplaceWord,replaceWord;
    
    getline(cin, inputStr);
    
    cin>>beReplaceWord;
    
    cin>>replaceWord;
    
    
    istringstream stream(inputStr);
    
    string word;
    
    vector<string> words;
    
    while (stream >> word) {
        
        if (word == beReplaceWord) {
            word = replaceWord;
        }
        
        words.push_back(word);
    }
    
    string result;
    for(string wd:words){
        result+=wd+" ";
    }
    cout<<result;
    
    return 0;
}
