/* coding by yctseng */
#ifndef BaseRestaurant_h
#define BaseRestaurant_h

#include <fstream>
using namespace std;

// 基底類別:BaseRestaurant
class BaseRestaurant
{
public:
    BaseRestaurant();				// 開檔
    void setAccountFile(string);	// 將客戶名稱寫入檔案
    virtual void menu(){};			// 建立虛擬函式以便衍伸類別使用多型
    ~BaseRestaurant();				// 關檔
protected:
    fstream f_menu;		// 讀取作為菜單的檔案
    fstream f_order;	// 寫入客戶訂單的檔案
};

#endif
