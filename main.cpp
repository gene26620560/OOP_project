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
	BaseRestaurant* restaurant = new BaseRestaurant;   // �ŧi�����O �ðʺA�s�Wrestaurant����
    int rest_id;        // �x�s��J�\�U���s��
    string account;     // �x�s��J���Ȥ�W��

    // �e��ε�
    cout << "Welcome to HAHA restaurant" << endl;
    cout << "Please enter your account:";
    cin >> account;
    cout << "Hello! " << account << endl
         << "Please enter restaurant options:" << endl
         << "(1)Taipei (2)Taichung (3)Tainan (0)Quit" << endl;

    // ��J�\�U�s��(��J0����)
    while(cin>>rest_id && rest_id!=0)
    {
        system("cls");  //�M���e��

        // �ھڿ�ܪ��\�U�s�����O�����T�ӭl�����O
        switch (rest_id)
        {
            case 1:
			{
            	Rest_Taipei Taipei;        // �ŧi�x�_�\�U���l�����O
            	Taipei.setAccountFile(account);
                Taipei.menu();
                break;
            }
            case 2:
            {
            	Rest_Taichung Taichung;    // �ŧi�x���\�U���l�����O
            	Taichung.setAccountFile(account);
                Taichung.menu();
                break;
            }
            case 3:
            {
            	Rest_Tainan Tainan;        // �ŧi�x�n�\�U���l�����O
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

