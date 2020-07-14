#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_ 1
#include<string>
#include<unordered_map>
class account final{
    private:
        std::unordered_map<std::string,std::string>     AllAccounts;
    public:
        account()=delete;
    account(std::string const&);
};
#endif//_ACCOUNT_H_
