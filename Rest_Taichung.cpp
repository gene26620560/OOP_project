/* coding by yctseng */
#include <iostream>
#include "Rest_Taichung.h"
using namespace std;

Rest_Taichung::Rest_Taichung()
{
    f_menu.open("menu_Taichung.txt", ios::in);
    if (!f_menu.is_open())
    {
        cout << "ERROR!";
        exit(1);
    }
}

void Rest_Taichung::menu()
{
    string s;
    cout << "Here is the Taichung's restaurant menu:" << endl;
    while(getline(f_menu,s))
    {
        cout << s << endl;
        list(s);
    }
    order();
}

void Rest_Taichung::list(string s)
{
    static int index = 0;
    product_price[index] = ((s[33]-48)*10+(s[34]-48));
    int tmp;
    for(int i=0; i<s.length(); i++)
        if(s[i]==' ' && s[i+1]=='N')
        {
            tmp = i;
            break;
        }
    for(int i=3; i<tmp; i++)
        product_name[index] += s[i];
    
    index++;
}

void Rest_Taichung::order()
{
    f_order << "Here is your order in Taichung's restaurant:" << endl << endl;
    cout << endl << "Please enter the product number with the end of \"0\":" << endl;
    int product_id;
    int total = 0;
    while(cin>>product_id && product_id!=0)
    {
        if(product_id<0 || product_id>6)
        {
            cout << "sorry, the menu id not found, please try again." << endl;
            continue;
        }
        f_order << product_name[product_id-1] << "   $";
        f_order << product_price[product_id-1] << endl;
        total += product_price[product_id-1];
    }
    f_order << endl << "Total:  $" << total << endl << "Thank for you custom.";
    cout << "Total: $" << total << endl;
}

Rest_Taichung::~Rest_Taichung()
{
    f_menu.close();
}
