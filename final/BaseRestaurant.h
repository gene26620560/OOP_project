/* code by yctseng */
#ifndef BaseRestaurant_h
#define BaseRestaurant_h
#include <fstream>
using namespace std;

class BaseRestaurant
{
public:
    BaseRestaurant();			// 關檔
    virtual void menu() = 0;	// menu為純虛擬函式 作為衍伸類別多型用途
    ~BaseRestaurant();			// 關檔
protected:
    fstream f_menu;				// 讀取作為菜單的檔案
    fstream f_order;			// 寫入客戶訂單的檔案
};

#endif
