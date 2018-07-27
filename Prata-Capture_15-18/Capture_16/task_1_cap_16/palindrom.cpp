#include <iostream>
#include <string>
#include <cctype>
#include "palindrom.h"
#include <algorithm>

char ToLower_char(char ch) { return tolower(ch); }

bool Palindrom(const std::string & wor){
    std::string tmp = wor;
    ToLower(tmp);
    Del_space(tmp);
    int sum = 0;
    int i = 0;
    int j = tmp.size()-1;

    while(i < tmp.size()){
        if(tmp[i] != tmp[j])
            break;
        sum+=1;
        i++;j--;
    }
    if(sum == tmp.size())
        return true;
    else
        return false;
}

std::string ToLower(std::string & s){
    std::transform(s.begin(), s.end(), s.begin(), ToLower_char);
    return s;
}

std::string Del_space(std::string & s){
    std::string tmp;
    for(int i = 0; i < s.size(); i++)
        if(s[i] != ' ')
            tmp += s[i];
    s = tmp;
    return s;
}
