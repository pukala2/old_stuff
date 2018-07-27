#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

 typedef std::vector<std::string> vec_str;
 
 vec_str part_word(const std::string & word); //this fun part values.
 int sum(const std::string & word); // this fun return count of sign  
 double get_value(const std::string &str){  return atof(str.c_str()); }
 double Calculate(vec_str & li); //this fun return result

int main()
{
    std::string val;
    std::cout<<"Podaj dzialanie, ktore konczy sie cyfra:";
    std::cin>>val;  //example 5+10/2*5+10
    vec_str list = part_word(val);
    std::cout<<Calculate(list)<<std::endl;  
}

vec_str part_word(const std::string & word){
    int i = 0;
    std::string tmp; 
    std::vector<std::string> list;
    std::string sign;

    for(int j = 0; j < sum(word); j++){ 
        while((word[i] != '+') && (word[i] != '-') && (word[i] != '/') && (word[i] != '*')){
            tmp += word[i];
            i++;
        }
        sign += word[i];
        i++;
        list.push_back(tmp);     
        tmp = "";
    }
    while(word[i] != '\0'){
        tmp += word[i];
        i++;
    }
    list.push_back(tmp);
    list.push_back(sign);
    return list;
}

int sum(const std::string & word){
    int i = 0;
    int count = 0;
    while(word[i] != '\0'){
        if((word[i] == '+') || (word[i] == '-') || (word[i] == '/') || (word[i] == '*'))
            count += 1;
        i++;
    }
    return count;
}

 double Calculate(vec_str & li){
    double count = get_value(li[0]);
    std::string sign = li[li.size()-1];
    for(int i = 0; i < sign.size(); i++){
        if(sign[i] == '+')
            count += get_value(li[i+1]);
        else if(sign[i] == '-')
            count -= get_value(li[i+1]);
        else if(sign[i] == '*')
            count *= get_value(li[i+1]);
        else if(sign[i] == '/')
            count /= get_value(li[i+1]);
    }
    return count;
 }

