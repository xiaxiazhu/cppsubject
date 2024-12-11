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
//#include <climits>
//#include <unordered_map>
//#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;



int main(){
    int n;
    cin>>n;// 一共有n行
    // 清除 cin 留下的换行符
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    vector<string> message(n);
    
    for (int i = 0; i<n; i++) {
        getline(cin, message[i]);
    }
    
    // 开始破解
    //1，当你发现一个退格符"#"，则表示前一个字符无效；
    //2，如果发现一个退行符"@"，以表示该行中 “@”前的所有字符均无效。 如果已经在行首'#'符号无效
    //whli##ilr#e (s#*s)
    //I am daifu@
    //   outcha@putchar(*s=#++);
    
    for (int j = 0; j< n; j++) {
        
        for (int k =0; k<message[j].size();k++) {
            
//          string test = message[j];
            if (k==0&&message[j][k]=='#') {
                message[j].erase(k,1);
            }
            
            while (message[j][k] == '#' && k!= 0) {
                message[j].erase(k-1,2);
                k--;
            }
            
            if (message[j][k] == '@' ){
                message[j].erase(0,k+1);
            }
            
        }
        message[j]+='\n';
    }
    
    for(string line : message){
        cout<<line;
    }
    
    return 0;
}
