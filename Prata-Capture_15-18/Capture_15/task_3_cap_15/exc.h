#include <iostream>
#include <stdexcept>
#include <string>

class Exc : public std::logic_error{
private:
    
public:
    Exc(const std::string & s):std::logic_error(s){}
    
};

class Bad : public Exc{
public:
    Bad(const std::string & what_arg = "Zle... Bad_hmean\n"):Exc(what_arg){}
    virtual ~Bad()throw(){}
};


class Bad2 : public Exc{
public:
    Bad2(const std::string & what_arg = "Zle... Bad_gmean\n"):Exc(what_arg){}
    virtual ~Bad2()throw(){}
}; 

