/* coding by yctseng */
#include <iostream>
#include "Rest_taipei.h"
using namespace std;

Rest_Taipei::Rest_Taipei()
{
    // 開檔並判斷是否成功
    f_menu.open("menu_Taipei.txt", ios::in);
    if (!f_menu.is_open())
    {
        cout << "ERROR!";
        exit(1);
    }
}

void Rest_Taipei::menu()
{
    string s;
    cout << "Here is the Taipei's restaurant menu:" << endl;

    // 將檔案的內容以字串形式讀取並印出
    while(getline(f_menu,s))
    {
        cout << s << endl;
        list(s);    // 讀取同時傳入list進行價格及菜色的建表
    }

    order(); // 結束後接續客戶訂單的函式
}

void Rest_Taipei::list(string s)
{
    static int index = 0;   // 宣告static的旗標以便在跳出函式後不會歸零

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

    // 接續上個迴圈的處理 將編號/菜色連同NT$之前的空白存進陣列中
    for(int i=0; i<tmp; i++)
        product_name[index] += s[i];
    
    index++;
}

void Rest_Taipei::order()
{
    f_order << "Here is your order in Taipei's restaurant:" << endl << endl;
    cout << endl << "Please enter the product number with the end of \"0\":" << endl;
    int product_id;     // 客戶所選擇的菜單編號
    int total = 0;      // 客戶訂單總金額

    // 客戶持續輸入菜單編號直到輸入0為止
    while(cin>>product_id && product_id!=0)
    {
        // 錯誤處理:當客戶輸入不如預期的菜單編號 將要求重新輸入
        if(product_id<0 || product_id>9)
        {
            cout << "sorry, the menu id not found, please try again." << endl;
            continue;
        }
        // 將選購的菜色寫入order檔案
        f_order << product_name[product_id-1] << "   $";

        // 將選購菜色的金額寫入order檔案
        f_order << product_price[product_id-1] << endl;

        // 總金額更新
        total += product_price[product_id-1];
    }

    // 將總金額寫入order檔案
    f_order << endl << "Total:  $" << total << endl << "Thank for you custom.";

    system("cls");  // 清除畫面

    cout << "Total: $" << total << endl;
}

Rest_Taipei::~Rest_Taipei()
{
    // 關檔
    f_menu.close();
}
