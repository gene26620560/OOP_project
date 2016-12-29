#ifndef Rest_Taipei_h
#define Rest_Taipei_h
// 測試中文
#include "BaseRestaurant.h"
using namespace std;

class Rest_Taipei : public BaseRestaurant
{
public:
    Rest_Taipei();
    void menu(void);
    void list(string);
    void order(void);
    ~Rest_Taipei();
    
private:
    string product_name[9];
    int product_price[9];
};

#endif
