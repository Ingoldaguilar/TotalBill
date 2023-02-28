#include "Shopping.h"

Shopping::Shopping() {
}

Shopping::~Shopping() {
}

void Shopping::menu()
{
    m:
    int choice;
    string email;
    string password;
    
    cout << "\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t                                        \n";
    cout << "\t\t\t\t           Supermarket Main Menu        \n";
    cout << "\t\t\t\t                                        \n";
    cout << "\t\t\t\t________________________________________\n";
    
    
    // Select wether it's and admin or a buyer.
    cout << "\t\t\t\t|  1) Administrator  |\n";
    cout << "\t\t\t\t|  2) Buyer          |\n";
    cout << "\t\t\t\t|  3) Exit           |\n";
    
    // ask & get the option
    cout << "\n\t\t\t Please select an option >"; cin >> choice;
    
    //
    switch(choice)
    {
        case 1:
            cout << "\t\t\t Please Login \n";
            cout << "\t\t\t Enter Email  \n"; cin >> email;
            cout << "\t\t\t Enter Password  \n"; cin >> password;
            
            if(email == "ingold@example.com" && password == "123example")
            {
                administrator();
            }
            else
            {
                cout << "Invalid email or password";
            }
            break;
            
        case 2:
        {
            buyer();
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            cout << "Please select a valid option!";
        }
    }
    
    goto m;
}

void Shopping::administrator()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator Menu ";
    cout << "\n\t\t\t|   1) Add a product    ";
    cout << "\n\t\t\t|   2) Modify a product ";
    cout << "\n\t\t\t|   3) Delete a product ";
    cout << "\n\t\t\t|   4) Back to main menu";
    
    cout << "\n\n\t Please enter your choice \n>"; cin >> choice;
    
    switch(choice)
    {
        case 1:
            add();
            break;
            
        case 2:
            edit();
            break;
        
        case 3:
            remove();
            break;
        
        case 4:
            menu();
            break;
            
        default:
            cout << "Invalid option!";     
    }
    goto m;
}

void Shopping :: buyer() 
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Buyer Menu ";
    cout << "\n\t\t\t|   1) Buy a product    ";
    cout << "\n\t\t\t|   2) Back to main menu";
    
    cout << "\n\n\t Please enter your choice \n>"; cin >> choice;
    
    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;
            
        default:
            cout << "Invalid option!";     
    }
    goto m;
}

void Shopping :: add()
{
    m:
    fstream data;
    int c, token = 0;
    float p, d;
    string n;
    
    int choice;
    cout << "\n\n\n\t\t\t Add a new product ";
    cout << "\n\t Product code\n>"; cin >> pcode;
    cout << "\n\t Name of the product\n>"; cin >> pname;
    cout << "\n\t Price of the product\n>"; cin >> price;
    cout << "\n\t Discount\n>"; cin >> dis;
    
    data.open("database.txt", ios::in);
    
    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n"; 
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        
        while(!data.eof())
        {
            if (c == pcode) 
            {
                token++;
            }
            data >> c >> n >> p >> d;
            
        }
        data.close();
    
    
        if (token == 1)
        {
            goto m;
        }
        else 
        {
            data.open("database.txt", ios::app|ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n"; 
            data.close();
        }
        
    }    
    cout << "\n\n\t\t Record inserted!";
}