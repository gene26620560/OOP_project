/* coding by yctseng */
#ifndef Rest_Taipei_h
#define Rest_Taipei_h

#include "BaseRestaurant.h"
using namespace std;

// 衍伸類別:Rest_Taipei
class Rest_Taipei : public BaseRestaurant
{
public:
    Rest_Taipei();		// 開檔
    void menu(void);	// 將menu檔案讀取後印出
    void list(string);	// 將menu讀取後在陣列中建表
    void order(void);	// 處理客戶選購的訂單
    ~Rest_Taipei();		// 關檔
    
private:
    string product_name[9];	// 將menu中的菜色用陣列建表
    int product_price[9];	// 將menu中的編號與價格製作對應表
};

#endif
