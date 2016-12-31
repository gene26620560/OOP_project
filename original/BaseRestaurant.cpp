/* code by yctseng */
#include <iostream>
#include <fstream>
#include "BaseRestaurant.h"
using namespace std;

BaseRestaurant::BaseRestaurant()
{
	// 開檔以便客戶訂單寫入
    f_order.open("order.txt",ios::out);
}

BaseRestaurant::~BaseRestaurant()
{
	// 關檔
    f_order.close();
}
