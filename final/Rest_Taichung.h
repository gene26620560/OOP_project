/* code by yctseng */
#ifndef Rest_Taichung_h
#define Rest_Taichung_h

#include "BaseRestaurant.h"
using namespace std;

// 衍伸類別:Rest_Taichung
class Rest_Taichung : public BaseRestaurant
{
public:
    Rest_Taichung(string);      // menu開檔, 同時將客戶名稱寫入order檔案
    void menu(void);            // 將menu檔案讀取後印出
    void gotoxy(int, int);      // 更改游標位置,參數傳入為x,y座標
    void list(string);          // 將menu讀取後在陣列中建表
    void order(void);           // 動態選擇客戶所要的菜色及數量
    void file(void);            // 客戶訂單寫檔
    ~Rest_Taichung();           // 關檔
    
private:
    string product_name[6];     // 將menu中的菜色用陣列建表
    int product_price[6];       // 將menu中的編號與價格製作對應表
    int product_amount[6];      // 儲存客戶對菜色下單的數量
};

#endif
