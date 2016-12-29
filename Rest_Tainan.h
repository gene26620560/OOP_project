/* coding by yctseng */
#ifndef Rest_Tainan_h
#define Rest_Tainan_h

#include "BaseRestaurant.h"
using namespace std;

// 衍伸類別:Rest_Tainan
class Rest_Tainan : public BaseRestaurant
{
public:
    Rest_Tainan();		// 開檔
    void menu(void);	// 將menu檔案讀取後印出
    void list(string);	// 將menu讀取後在陣列中建表
    void order(void);	// 處理客戶選購的訂單
    ~Rest_Tainan();		// 關檔
    
private:
    string product_name[8];	// 將menu中的菜色用陣列建表
    int product_price[8];	// 將menu中的編號與價格製作對應表
};

#endif
