#include <iostream>
#include <stdexcept>
#include <string>

class Bad_hmean {
 private:
        double v1;
        double v2;
 public:
        Bad_hmean(double a = 0, double b = 0) :v1(a), v2(b) {}

        class Bad : public std::logic_error{
            public:
                Bad(const std::string & what_arg = "Zle... Bad_hmean\n"):std::logic_error(what_arg){}
                virtual ~Bad()throw(){}
        };
    virtual ~Bad_hmean(){}
};


class Bad_gmean {
 public:
     double v1;
     double v2;
     Bad_gmean(double a = 0, double b = 0) :v1(a), v2(b) {}

     class Bad2 : public Bad_hmean::Bad{
        public:
            Bad2(const std::string & what_arg = "Zle... Bad_gmean\n"):Bad_hmean::Bad(what_arg){}
            virtual ~Bad2()throw(){}
     };
}; 

