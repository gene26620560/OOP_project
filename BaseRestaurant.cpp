/* coding by yctseng */
#include <iostream>
#include <fstream>
#include "BaseRestaurant.h"
using namespace std;

BaseRestaurant::BaseRestaurant()
{
	// 開檔以便客戶訂單的寫入
    f_order.open("order.txt",ios::out);
}

void BaseRestaurant::setAccountFile(string account)
{
	// 將客戶名稱寫入order檔案
    f_order << "To " << account << "," << endl;
}

BaseRestaurant::~BaseRestaurant()
{
	// 關檔
    f_order.close();
}
