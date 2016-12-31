/* code by yctseng */
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include "Rest_taipei.h"

using namespace std;

Rest_Taipei::Rest_Taipei(string account)
{
    // 開檔並判斷是否成功
    f_menu.open("menu_Taipei.txt", ios::in);
    if (!f_menu.is_open())
    {
        cout << "ERROR!";
        exit(1);
    }
    // 將客戶名稱寫入order檔案
    f_order << "To " << account << "," << endl;
}

void Rest_Taipei::menu()
{
    string s;
    cout << "Here is the Taipei's restaurant menu:" << endl;
    cout << "Use arrow keys to order and add quantity, enter the\"Summit\" to the end." << endl;
    cout << "\tmenu\t\t\tprize\tquantity" << endl;
    
    cout << "->";
	bool index = false;    // 設定是否要印出空白的旗標(只有第一行菜色印出箭號)

    // 將檔案的內容以字串形式讀取並印出
    while(getline(f_menu,s))
    {
    	if(index)
			cout << "  ";
        cout << s << endl;
        list(s);    // 讀取的同時傳入list進行價格及菜色的建表
        index = true;
    }
    cout << "  Summit!";

    // 在x軸44,y軸3~12的位置先印出個菜單的數量起始值
    int x = 44;
	for(int i=3; i<12; i++)
	{
   		gotoxy(x, i);
   		cout << "0" << endl;
	}

    // 前置準備完成後 接續客戶對menu的動態選擇
	order();
}

// 更改游標位置,參數傳入為x,y座標
// 備註:以cmd左上為原點,x軸向右為正/y軸向下為正
void Rest_Taipei::gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void Rest_Taipei::list(string s)
{
    // 宣告static的旗標以便在跳出函式後不會歸零
    static int index = 0;

    // 每一行字串長度為35 因此將末二位數字以ASCII轉整數的方式儲存在陣列中
    product_price[index] = ((s[33]-48)*10+(s[34]-48));

    int tmp;    // 暫存用變數
    for(int i=0; i<s.length(); i++)
        // 當字串判讀到NT$時會將當下位置作為旗標儲存在tmp中
        if(s[i]==' ' && s[i+1]=='N')
        {
            tmp = i;
            break;
        }
    // 使用暫存用變數 將菜色連同NT$之前的空白存進陣列中
    for(int i=3; i<tmp; i++)
        product_name[index] += s[i];
    
    index++;
}

void Rest_Taipei::order()
{
    int key;                // 抓取鍵盤上輸入的按鍵(轉ASCII整數)
    int sx = 0;             // 將箭號的位置永遠鎖定在x=0
	int nx = 44;            // 將數量的位置永遠鎖定在x=44
    int pointer = 3;        // 設定箭號初始位置 
    bool flag = true;       // 判斷動態選擇是否繼續的旗標

    // 數量陣列初始化
    memset(product_amount, 0x00, sizeof(product_amount));
    
    while(flag)
    {
        // 利用getch函式抓每次輸入的按鍵
        key = getch();

        // 根據輸入的按鍵(ASCII)進行對應的行為
        switch(key)
        {
            // down
            case 80:
                // 避免選擇的箭號超出範圍
	            if(pointer < 12)
	            {
                    // 箭號移動時 將原本位置顯示空白
	                gotoxy(sx, pointer);
					cout << "  ";
					pointer++;

                    // 箭號移動時 再下個位置顯示箭號
					gotoxy(sx, pointer);
					cout << "->";
				}
	            break;

            // up
            case 72:
                if(pointer > 3)
                {
                    gotoxy(sx, pointer);
                    cout << "  ";
                    pointer--;
                    gotoxy(sx, pointer);
                    cout << "->";
                }
                break;

            // left
            case 75:
                // 當pointer==12為summit不動作
	            if(pointer != 12)
	        	{
                    // 設定當數量為0時 再往下算會回到9
	        		if(product_amount[pointer-3] == 0)
	                	product_amount[pointer-3] = 9;
                    // 除此之外往下算正常減一
					else
						product_amount[pointer-3]--;
	                gotoxy(nx, pointer);
	                cout << product_amount[pointer-3];
	    		}
	        	break;
	        
            // right
            case 77:
                if(pointer != 12)
                {
                    // 設定當數量為9時 再往上算會回到0
                	if(product_amount[pointer-3] == 9)
						product_amount[pointer-3] = 0;
                    // 除此之外往下算正常加一
					else
                    	product_amount[pointer-3]++;
                    gotoxy(nx, pointer);
                    cout << product_amount[pointer-3];
                }
                break;
                
            // enter
			case 13:
                // 當輸入enter時的位置在summit位置
				if(pointer == 12)
				{
                    // 將旗標轉為false表示不繼續動態選擇
					flag = false;

                    // 開始進行客戶訂單的寫檔
					file();
				}
            }
    }
}

void Rest_Taipei::file()
{
	f_order << "Here is your order in Taipei's restaurant:" << endl << endl;

	int total = 0;     // 總金額初始化
	bool tmp = false;  // 判斷訂單數量是否為空(0為無訂單選購)

    // 將訂單數量不為0的 菜色/價格/數量 寫檔,同時加總金額
	for(int i=0; i<9; i++)
		if(product_amount[i] != 0)
		{
			tmp = true;
			f_order << product_name[i] << "$";
			f_order << product_price[i] << "\t *";
			f_order << product_amount[i] << endl;
			total += product_amount[i]*product_price[i];
		}
	if(!tmp)
		f_order << "empty" << endl;
	
    // 總金額寫檔
	f_order << endl << "Total:  $" << total << endl << "Thank for you custom.";
    cout << "Total: $" << total << endl;
}

Rest_Taipei::~Rest_Taipei()
{
    f_menu.close();
}
