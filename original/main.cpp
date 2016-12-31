/* code by yctseng */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "BaseRestaurant.h"
#include "Rest_Taipei.h"
#include "Rest_Taichung.h"
#include "Rest_Tainan.h"

using namespace std;

int main()
{
    cout << "Welcome to HAHA restaurant" << endl;
    cout << "Please enter your account:";
    
    string account;     // 客戶名稱
    cin >> account;
    
    int rest_id;                    // 儲存輸入餐廳的編號
    BaseRestaurant* city;           // 宣告基底類別的物件指標
    Rest_Taipei Taipei(account);    // 宣告衍伸類別的物件 同時進行客戶名稱的檔案寫入
    Rest_Taichung Taichung(account);
    Rest_Tainan Tainan(account);
    
    cout << "Hello! " << account << endl
         << "Please enter restaurant options:" << endl
         << "(1)Taipei (2)Taichung (3)Tainan (0)Quit" << endl;
	
    // 輸入餐廳編號(輸入0結束)
    while(cin>>rest_id && rest_id!=0)
    {
        system("cls");
        switch (rest_id)
        {
            case 1:
                // 將繼承的物件透過指標傳給基底類別 以便稍後使用多型
            	city = &Taipei;
                break;
            case 2:
            	city = &Taichung;
                break;
            case 3:
            	city = &Tainan;
                break;
            default:
                cout << "sorry, Please enter again..." << endl;
                break;
        }
        if(rest_id==1 || rest_id==2 || rest_id==3)
        {
            // 根據基底類別接收到的物件進行相對應的後續
        	city -> menu();
            cout << "Please check your order in file. Thank for you custom." << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
