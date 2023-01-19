#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class registeration {
protected:
    string email;
    string password;
    int select;
public:
    void reg_data() {
        system("cls");
        cout << "\n\n\n\n\t\tENTER EMAIL :";
        cin >> email;
        cout << "\t\tCREATE PASSWORD :";
        cin >> password;
        ifstream file("database.txt");
        ofstream Enter("database.txt", ios::app);
        Enter << email << " " << password << endl;
        system("cls");
        cout << "\n\n\n \t\t\t <---------REGISTERATION SUCCESSFULL-------->\n";
    }
};
class login :public registeration {
protected:
    string emailFile;
    string passFile;
    string name;
    int number;
    int days;
    int advamt;
    int total;
    int per_day;
    string n;
    int remaining;
public:

    void welcom() {
        cout << "\n \t\t\t ASSALAM U ALAIKUM---->" << email << "\n \t\t\t <---THANKS FOR LOGGING IN--->\n\n\n\n";
    }
    void service() {
        cout << "\t\t|. Select 1 For Honda civic 2022 (White)            |" << endl;
        cout << "\t\t|. Select 2 For Honda Civic 2020 (Black)            |" << endl;
        cout << "\t\t|. Select 3 For Toyota Corolla 2022(white)          |" << endl;
        cout << "\t\t|. Select 4 For Toyota Corolla Grandy 2022  (White) |" << endl;
        cout << "\t\t|. Select 5 For Toyota Fortuner 2022(white)         |" << endl;
        cout << "\t\t|. Select 6 For Toyota Fortuner 2022(Black)         |" << endl;
        cout << "\t\t|. Select 7 Exit                                    |" << endl;
    }
    void customer_data() {
        cout << "\n\t\tPer day price is= 500" << endl;
        cout << "\n\n\t\t\tENTER NAME : ";
        cin >> name;
        n = name;
        cout << "\t\t\tNUMBER OF CARS : ";
        cin >> number;
        cout << "\t\t\tNUMBER OF DAYS : ";
        cin >> days;
        cout << "\t\t\tADVANCE AMOUNT : ";
        cin >> advamt;
        per_day = 500;
        total = number * (days * per_day);
        remaining = total - advamt;
        fstream ent("name.txt", ios::app);
        ent << "Name is : " << name << endl;
        ent << "Number of Cars = : " << number << endl;
        ent << "Number of Days = " << days << endl;
        ent << "Total Amount = " << total << endl;
        ent << "Advance Amount = " << advamt << endl;
        ent << "Remaining Balance is = " << remaining << endl << endl;
    }
    void display() {
        ifstream read("name.txt");
        while (read >> name) {
            if (n == name) {
                system("cls");
                cout << "\t\t\t\t     _______________Car Rental Customer Invoice______" << endl << endl;
                cout << "\t\t\t\t\t //////////////////////////////////////////////////////" << endl;
                cout << "\t\t\t\t\t |Invoice No. :" << "_________________________|" << setw(10) << "3CNC8123" << "|" << endl;
                cout << "\t\t\t\t\t |Customer Name. :" << "______________________|" << setw(10) << name << "|" << endl;
                cout << "\t\t\t\t\t |Number of cars. :" << "_____________________|" << setw(10) << number << "|" << endl;
                cout << "\t\t\t\t\t |Number of Days :" << "______________________|" << setw(10) << days << "|" << endl;
                cout << "\t\t\t\t\t |Your Rental Amount is. :" << "______________|" << setw(10) << total << "|" << endl;
                cout << "\t\t\t\t\t |Advance Amount. :" << "_____________________|" << setw(10) << advamt << "|" << endl;
                cout << "\t\t\t\t\t |Remaining Balance. :" << "__________________|" << setw(10) << remaining << "|" << endl;
                cout << endl;
                cout << "\t\t\t\t\t ///////////////////////////////////////////////////////" << endl << endl;
                cout << "\t\t\t\t\t |You have advise to pay before due date______|" << endl;
                cout << "\t\t\t\t\t |Otherwise penelty will be applied___________|" << endl << endl;
                cout << "\t\t\t\t\t ///////////////////////////////////////////////////////" << endl;


            }
        }
    }
    void log_data();
};
class forget :public login {
protected:
    string findEmail;
    string findpass;
    string check;
    char select;
    char option;
public:
    void menu();
    void fog_process() {
        system("cls");
        cout << "\n\n\t\t\t 1.Find Password By Email" << endl;
        cout << " \t\t\t 2.Find Email By Password" << endl;
        cout << " \t\t\t 3.Return Back To Main Menu" << endl;
        cout << "PRESS THE BUTTON :";
        option = _getch();
        switch (option)
        {
        case '1':
        {
            int count = 0;
            cout << "\n \t\t\t ENTER EMAIL :";
            cin >> findEmail;
            ifstream findE("database.txt");
            while (findE >> email >> password)
            {
                if (email == findEmail)
                {
                    count = 1;

                    check = password;
                }
            }
            findE.close();
            if (count == 1)
            {
                cout << "\n \t\t\t |.....Your Account is Found Congrats.....|";
                cout << "\n \t\t\t |.....Your password is :" << check << "     |";
                cout << "\n\nPress Enter For Return Back To Main Menu";
                cin.get();
                cin.get();
                system("cls");
            }
            else
            {
                cout << "\n \t\t\t Your Email Id is not matched\n";
                cout << "Press Enter For Return Back To Main Menu\n";
                cin.get();
                cin.get();
                system("cls");
            }
            break;
        }
        case '2':
        {
            int count = 0;
            cout << "\n \t\t\tEnter the remembered password :";
            cin >> findpass;

            ifstream findP("database.txt");
            while (findP >> email >> password)
            {
                if (password == findpass)
                {
                    count = 1;
                    check = email;
                }

            }
            findP.close();
            if (count == 1)
            {
                cout << "\n \t\t\t |.....Congratulations your password is matched.....| ";
                cout << "\n \t\t\t |.....Your Id is : " << check << "    |";
                cout << "\n\nPress Enter For Return Back To Main Menu";
                cin.get();
                cin.get();
                system("cls");
                menu();
            }
            else
            {
                cout << "\n \t\t\t Unfortunately Your Password Is Not Matched";
                cout << "\nPress Enter For Return Back To Main Menu";
                cin.get();
                cin.get();
                system("cls");
                menu();
            }

            break;
        }
        case '3':
        {
            system("cls");
            menu();
        }
        default:
            system("cls");
            cout << "\n \t\t\t |.....Enter Valid Number......|" << endl;
            fog_process();
        }
    }
};
void forget::menu() {
    cout << "\n\n\n\t\t\t     .......MENU.......\n\n";
    cout << "\t\t\t|.   Select 1 For Login                |" << endl;
    cout << "\t\t\t|.   Select 2 For Registration         |" << endl;
    cout << "\t\t\t|.   Select 3 For Forgotten Password   |" << endl;
    cout << "\t\t\t|.   Select 4 For Exit                 |\n\n" << endl;
    login log;
    registeration reg;
    cout << "\t\t PRESS THE BUTTON :";
    select = _getch();
    cout << endl;
    switch (select)
    {
    case '1':
        log_data();
        break;
    case'2':
        reg_data();
        menu();
        break;
    case '3':
        fog_process();
        menu();
        break;
    case '4':
        system("cls");
        cout << "\n\n\n\n\n\t\t\t\t\t.....Thanks For Your Time.......\n\n\n\n\n";
        break;
    default:
        system("cls");
        cout << "Enter valid Selection" << endl;
        menu();

    }
}
void login::log_data() {
    int count = 0;
    system("cls");
    cout << "\n\n\t\t|...... Give Your Detail Here......|\n" << endl;
    cout << "\t\t\t ENTER YOUR EMAIL :";
    cin >> email;
    cout << "\t\t\t ENTER YOUR PASSWORD :";
    cin >> password;
    ifstream read("database.txt");
    while (read >> emailFile >> passFile)
    {
        if (emailFile == email && passFile == password)

        {
            count = 1;
            system("cls");
        }
    }
    read.close();
    if (count == 1)
    {
    loop:welcom();
        service();
        cout << "\t\t PRESS THE BUTTON :";
        select = _getch();
        cout << endl;
        system("cls");
        switch (select)
        {
        case '1':
            cout << "\n\n\t\tYou Have Selected Honda Civic 2022    ";
            customer_data();
            display();
            break;
        case '2':
            cout << "\n\n\t\tYou Have Selected Honda Civic 2020    ";
            customer_data();
            display();
            break;
        case '3':
            cout << "\n\n\t\tYou Have Selected Toyota Corolla 2022    ";
            customer_data();
            display();
            break;
        case '4':
            cout << "\n\n\t\tYou Have Selected Toyota Corolla Grandy 2022    ";
            customer_data();
            display();
            break;
        case '5':
            cout << "\n\n\t\tYou Have Selected Toyota Fortuner 2022 White   ";
            customer_data();
            display();
            break;
        case '6':
            cout << "\n\n\t\tYou Have Selected Toyota Fortuner 2022 Black   ";
            customer_data();
            display();
            break;
        case '7':
            cout << "\n\n\n\n\n\t\t\t\t\t.....Thanks For Your Time.......\n\n\n\n\n";
            break;
        default:
            system("cls");
            cout << "Enter valid Selection" << endl;
            goto loop;

        }
    }
    else
    {
        system("cls");
        cout << "\n \t\t\t Your Email Or Password Is Incorrect\n";
        forget fog;
        fog.menu();

    }
}
int main()
{
    system("color E");
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t      ................**................\n\n";
    cout << "\t\t\t\t      ....WELCOME TO BUDDY RENTALS....\n\n";
    cout << "\t\t\t\t      ................**................\n\n";
    cout << "\n\n\n\n\t\t\t\t       --> Press ENTER key to get Main Menu\n\n\n";
    cin.get();

    system("cls");
    login log;
    forget fog;
    fog.menu();

}