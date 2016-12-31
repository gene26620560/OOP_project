/* code by yctseng */
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include "Rest_Tainan.h"
using namespace std;

Rest_Tainan::Rest_Tainan(string account)
{
    f_menu.open("menu_Tainan.txt", ios::in);
    if (!f_menu.is_open())
    {
        cout << "ERROR!";
        exit(1);
    }
    f_order << "To " << account << "," << endl;
}

void Rest_Tainan::menu()
{
    string s;
    cout << "Here is the Tainan's restaurant menu:" << endl;
    cout << "Use arrow keys to order and add quantity, enter the\"Summit\" to the end." << endl;
    cout << "\tmenu\t\t\tprize\tquantity" << endl;
    cout << "->";
	bool index = false;
    while(getline(f_menu,s))
    {
    	if(index)
			cout << "  ";
        cout << s << endl;
        list(s);
        index = true;
    }
    cout << "  Summit!";
    //---
    int x = 44;
	for(int i=3; i<11; i++)
	{
   		gotoxy(x, i);
   		cout << "0" << endl;
	}
	order();
}

void Rest_Tainan::gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void Rest_Tainan::list(string s)
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

void Rest_Tainan::order()
{
    int key;        // getchar
    int sx = 0;     // -> position
    int nx = 44;    // amount position
    memset(product_amount, 0x00, sizeof(product_amount));
    int pointer = 3;
    bool flag = true;
    while(flag)
    {
        key = getch();
        switch(key)
        {
            // down
            case 80:
	            if(pointer < 11)
	            {
	                gotoxy(sx, pointer);
					cout << "  ";
					pointer++;
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
	            if(pointer != 11)
	        	{
	        		if(product_amount[pointer-3] == 0)
	                	product_amount[pointer-3] = 9;
					else
						product_amount[pointer-3]--;
	                gotoxy(nx, pointer);
	                cout << product_amount[pointer-3];
	    		}
	        	break;

            // right
            case 77:
                if(pointer != 11)
                {
                	if(product_amount[pointer-3] == 9)
						product_amount[pointer-3] = 0;
					else
                    	product_amount[pointer-3]++;
                    gotoxy(nx, pointer);
                    cout << product_amount[pointer-3];
                }
                break;

            // enter
			case 13:
				if(pointer == 11)
				{
					flag = false;
					file();
				}
            }
    }
}

void Rest_Tainan::file()
{
	f_order << "Here is your order in Tainan's restaurant:" << endl << endl;

	int total = 0;
	bool tmp = false;
	for(int i=0; i<8; i++)
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

	f_order << endl << "Total:  $" << total << endl << "Thank for you custom.";
    cout << "Total: $" << total << endl;
}

Rest_Tainan::~Rest_Tainan()
{
    f_menu.close();
}
