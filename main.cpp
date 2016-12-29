/* coding by yctseng */
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
	BaseRestaurant* restaurant = new BaseRestaurant;   // 宣告基底類別 並動態新增restaurant物件
    int rest_id;        // 儲存輸入餐廳的編號
    string account;     // 儲存輸入的客戶名稱

    // 前綴用詞
    cout << "Welcome to HAHA restaurant" << endl;
    cout << "Please enter your account:";
    cin >> account;
    cout << "Hello! " << account << endl
         << "Please enter restaurant options:" << endl
         << "(1)Taipei (2)Taichung (3)Tainan (0)Quit" << endl;

    // 輸入餐廳編號(輸入0結束)
    while(cin>>rest_id && rest_id!=0)
    {
        system("cls");  //清除畫面

        // 根據選擇的餐廳編號分別對應三個衍伸類別
        switch (rest_id)
        {
            case 1:
			{
            	Rest_Taipei Taipei;        // 宣告台北餐廳的衍伸類別
            	Taipei.setAccountFile(account);
                Taipei.menu();
                break;
            }
            case 2:
            {
            	Rest_Taichung Taichung;    // 宣告台中餐廳的衍伸類別
            	Taichung.setAccountFile(account);
                Taichung.menu();
                break;
            }
            case 3:
            {
            	Rest_Tainan Tainan;        // 宣告台南餐廳的衍伸類別
            	Tainan.setAccountFile(account);
                Tainan.menu();
                break;
            }
            default:
                cout << "sorry, Please enter again..." << endl;
                break;
        }
        if(rest_id==1 || rest_id==2 || rest_id==3)
        {
            cout << "Please check your order in file. Thank for you custom." << endl;
            break;
        }
    }
    delete restaurant;

    return 0;
}

