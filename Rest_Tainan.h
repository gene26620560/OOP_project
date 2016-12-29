#ifndef Rest_Tainan_h
#define Rest_Tainan_h

#include "BaseRestaurant.h"
using namespace std;

class Rest_Tainan : public BaseRestaurant
{
public:
    Rest_Tainan();
    void menu(void);
    void list(string);
    void order(void);
    ~Rest_Tainan();
    
private:
    string product_name[8];
    int product_price[8];
};

#endif
