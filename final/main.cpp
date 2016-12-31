/* code by yctseng */
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#include "BaseRestaurant.h"
#include "Rest_Taipei.h"
#include "Rest_Taichung.h"
#include "Rest_Tainan.h"

using namespace std;

void gotoxy(int, int);
int DynamicSelection(void);

int main()
{
    system("color F0"); // 變更字體和背景顏色
    cout << "Welcome to HAHA restaurant" << endl;
    cout << "Please enter your account:";
    
    string account;     // 客戶名稱
    cin >> account;

    int rest_id;                    // 儲存輸入餐廳的編號
    BaseRestaurant* city;           // 宣告基底類別的物件指標
    Rest_Taipei Taipei(account);    // 宣告衍伸類別的物件 同時進行客戶名稱的檔案寫入
    Rest_Taichung Taichung(account);
    Rest_Tainan Tainan(account);
    
    system("cls");
    cout << "Hello! " << account << endl
         << "Please enter restaurant options:" << endl
         << "->(1)Taipei\n  (2)Taichung\n  (3)Tainan\n  (4)Quit" << endl;
	
	
    // 選擇餐廳選項(回傳箭號位置,且為了對應餐廳編,故減一)
	rest_id = DynamicSelection() - 1;

    system("cls");  // 清除畫面
    
    // 根據餐廳選項將繼承的物件透過指標傳給基底類別 以便使用多型
    switch (rest_id)
    {
        case 1:
           	city = &Taipei;
            break;
        case 2:
           	city = &Taichung;
            break;
        case 3:
            city = &Tainan;
            break;
		case 4:
			system("cls");   // 清除畫面
    		cout << "Byebye! See you then." << endl;
    }

    // 根據基底類別接收到的物件進行多型展開
	if(rest_id==1 || rest_id==2 || rest_id==3)
    {
        city -> menu(); //多型
        cout << "Please check your order in file. Thank for you custom." << endl << endl;
    }

    system("pause");
    return 0;
}

// 更改游標位置,參數傳入為x,y座標
// 備註:以cmd左上為原點,x軸向右為正/y軸向下為正
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

// 動態選擇
int DynamicSelection()
{
	int key;           // 抓取鍵盤上輸入的按鍵(轉ASCII整數)
	int x = 0;         // 游標的起始位置(X軸)
	int select = 2;    // 游標的起始位置(Y軸)
	while(true)
    {
        // 利用getch函式抓每次輸入的按鍵
        key = getch();

        // 根據輸入的按鍵(ASCII)進行對應的行為
        switch(key)
        {
            // down
            case 80:
                // 避免選擇的箭號超出範圍
	            if(select < 5)
	            {
                    // 箭號移動時 將原本位置顯示空白
	                gotoxy(x, select);
					cout << "  ";
					select++;

                    // 箭號移動時 再下個位置顯示箭號
					gotoxy(x, select);
					cout << "->";
				}
	            break;

            // up
            case 72:
                if(select > 2)
                {
                    gotoxy(x, select);
                    cout << "  ";
                    select--;
                    gotoxy(x, select);
                    cout << "->";
                }
                break;

            // enter
            case 13:
                // 當按下enter時回傳箭號位置
				return select;
            }
		}
    }
