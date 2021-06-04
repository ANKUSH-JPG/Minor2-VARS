#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<windows.h>
#include <ctime>
#include <dos.h>
#include<fstream>
#include<string>
#include <ctime>

using namespace std;

//*******************************  CLASSES *****************************************
class admin
{
   protected:
       string username="admin";
       string pass="12345";
       fstream file;
   public:
       void admin_home();
       void addToMenu();
       void orderList();
};

class customer
{
    public:
       string username;
       string pass="qwerty";
       map<int,map<string,string> > m;
       map<float,string> selected_item;
    public:

        void customer_home();
};

class login:public admin,public customer
{
public:

    int check_login();

};

class varsSystem:public login
{
public:

    void generate_bill(login &l);
};




//******************************* FUNCTIONS *************************************

// --------- LOGIN ---------------

int login::check_login()
{
 int what;
 string u;
 string p;
system("Color F0");
     cout<<"\n\n\n\t\t\t\t\t\t\t---------- WELCOME TO VARS -----------";
     cout<<"\n\n\n\t\t\t\t\t 1. ADMIN \t\t\t\t 2. CUSTOMER \n";

     cin>>what;

system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t---------------------";
    cout<<"\n\t\t\t\t\t\t\t ENTER USERNAME = ";
    cin>>u;
    cout<<"\n\t\t\t\t\t\t\t ENTER PASSWORD = ";
    cin>>p;

    cout<<"\t\t\t\t\t\t\t---------------------";

    if(what==1)
    {
        cout<<"\n\n\t\t\t\t\t\t\t Loading";
        for(int i=0;i<5;i++)
        {
                    cout<<". ";
                    Sleep(500);
        }

        if( admin::username==u && p==admin::pass)
        {
            MessageBox( 0,  " LOGIN SUCCESSFUL ", "Greetings", 0 );

            system("CLS");
            return 1;
        }
        else
        {
             MessageBox( 0,  " LOGIN FAILED", "sorry try again", 0 );
             system("CLS");
             return 0;
        }

    }

        {


    if(what==2)
    {
        cout<<"\n\n\t\t\t\t\t\t\t Loading";
        for(int i=0;i<5;i++)
                    cout<<". ";
                    Sleep(500);
        }

        customer::username=u;
        if(p==customer::pass)
        {
            MessageBox( 0,  " LOGIN SUCCESSFUL ", "Greetings", 0 );

            system("CLS");
            return 2;
        }
        else
        {
             MessageBox( 0,  " LOGIN FAILED", "sorry try again", 0 );
             system("CLS");
            return 0;
        }

    }
}


// --------- ADMIN ---------------

void admin::addToMenu()
{

    string item;
    float price;
    float rating;

    admin::file.open("menu.csv", ios::app);

    system("CLS");

                        cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;
						cout << "\t\t\t\t\t\t\t       |               ADD ITEM           |"<<endl;
						cout << "\t\t\t\t\t\t\t ================================================"<<endl;

						cout<<endl<<endl<<endl<<endl;

						cout << "\n\t\t\t\t\t\t\t ================================ "<<endl;
						cout<<"\n\t\t\t\t\t\t\t  ITEM NAME: ";
						cin>>item;
						cout<<"\n\t\t\t\t\t\t\t  ITEM PRICE: ";
						cin>>price;
						cout<<"\n\t\t\t\t\t\t\t  ITEM RATING: ";
						cin>>rating;
						cout << "\n\t\t\t\t\t\t\t ================================ "<<endl;

						file<<item<<","<<price<<","<<rating<<endl;

						MessageBox( 0,  " Item added", "success", 0 );

        file.close();

}

void admin::admin_home()
{
						cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;
						cout << "\t\t\t\t\t\t\t  |               WELCOME ADMIN            |"<<endl;
						cout << "\t\t\t\t\t\t\t ================================================"<<endl;

                        cout << endl;
						cout << endl;

						cout << "\t\t\t\t\t  1. CHECK ORDERS      \t\t 2. ADD TO MENU  \t\t 3. EXIT"<<endl;
						int n;

						cin>>n;

						if(n==1)
                        {
                           system("CLS");
                           orderList();
                        }
                        else if(n==2)
                        {
                            addToMenu();
                            system("CLS");
                            admin_home();
                        }
                        else
                        {
                            exit(0);
                        }
}

void admin::orderList()
{
    fstream order;
    order.open("order.csv",ios::in);

    cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;
    cout << "\t\t\t\t\t\t\t  |               ORDER LIST            |"<<endl;
    cout << "\t\t\t\t\t\t\t ================================================"<<endl<<endl;

    cout << "\t\t\t\t\t\t\t NAME \t\t DATE \t\t\t\t ITEMS "<<endl;
    cout<<"\t\t\t\t\t\t\t";
    while(!order.eof())
    {
        string o;
        order>>o;

        if(o=="|")
           cout<<endl<<"\t\t\t\t\t\t\t";
        else
           cout<<o;
    }
}


// --------- CUSTOMER ---------------

void customer::customer_home()
{
    system("wscript main.vbs");
    map<int,map<string,string> >::iterator itr;
    map<string,string>::iterator in;
    string data;
    int c=1;
    fstream file;
    file.open("menu.csv", ios::in);

    system("CLS");

                        cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;
						cout << "\t\t\t\t\t\t\t       |               WELCOME "<<username<<"          |"<<endl;
						cout << "\t\t\t\t\t\t\t ================================================"<<endl;

						cout<<endl<<endl<<endl<<endl;

    while(!file.eof())
    {
        file>>data;
        int comma=0;
        string name,price;
        for(int i=0;i<(data.size());i++)
        {
            if(data[i]==',')
                comma++;
            else
            {
                            if(comma==0)
                            {
                                name.push_back(data[i]);
                            }
                            else if(comma==1)
                            {
                                price.push_back(data[i]);
                            }
            }

        }

        m[c][name]=price;
        c++;
    }




    file.close();


    for(itr=m.begin();itr!=m.end();itr++)
    {

        for(in=(itr->second).begin();in!=(itr->second).end();in++)
        {
            cout<<"\t\t\t\t\t\t\t"<<"["<<itr->first<<"]"<<"\t\t"<<in->first<<"\t\t"<<in->second<<endl;
        }
    }

    cout<<"\t\t\t\t\t\t\t ==================================================="<<endl;


    while(1)
    {
        cout<<"\t\t\t\t\t 1. SELECT ITEM  \t\t 2. PRODUCE BILL \t\t 3. VARS ASSISTANT"<<endl;
        int choice;
        cin>>choice;

        if(choice==2)
            break;
        else if(choice==3)
            system("wscript main.vbs");
        else
        {   int no;
            cout<<"\t\t\t\t\t\t\t\t\t *********************"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t ITEM NO :";
            cin>>no;
            cout<<"\t\t\t\t\t\t\t\t\t *********************"<<endl;

            for(in=m[no].begin();in!=m[no].end();in++)
            {
                selected_item[stof(in->second)]=in->first;
            }
        }

    }
}

// --------- SYSTEM ---------------

void varsSystem::generate_bill(login &l)
{

    fstream order;
    order.open("order.csv",ios::app);
    map<float,string>::iterator itr;
    float t_p=0.0;
    for(itr=l.selected_item.begin();itr!=l.selected_item.end();itr++)
    {

        //cout<<itr->first<<"                "<<itr->second<<endl;
        t_p=t_p+itr->first;
    }


                        time_t now = time(0);

                        char* dt = ctime(&now);

                        cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;
						cout << "\t\t\t\t\t\t\t|               VARS BILLING SYSTEM            |"<<endl;
						cout << "\t\t\t\t\t\t\t ================================================"<<endl;
						cout << endl;
						cout << endl;

						cout << "\t\t\t\t\t\t\t  NAME :"<<l.customer::username<<"           Date & time :"<<dt<<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t\t\t\t\t  Cashier :  VARS SYSTEM"<<endl;
						cout << endl;
                        cout<<"\t\t\t\t\t\t\t    YOUR TOTAL BILL IS Rs."<<t_p<<endl<<endl<<endl;

                        cout<<"\t\t\t\t\t\t\t\t          ************************* "<<endl;
                        cout<<"\t\t\t\t\t\t\t\t\t          ORDER LIST   "<<endl<<endl;

                        cout<<"\t\t\t\t\t\t\t\t\t    Item           Rupees   "<<endl;
                        order<<l.customer::username<<","<<dt<<",";
                            for(itr=l.selected_item.begin();itr!=l.selected_item.end();itr++)
                            {
                                order<<itr->second<<",";
                                cout<<"\t\t\t\t\t\t\t\t\t    "<<itr->second<<"           "<<itr->first<<endl;

                            }
                            order<<endl<<"|"<<endl;
//                        write<<"\t\t\t\t\t\t\t ";
//                       write<<"\t\t\t\t\t\t\tTOTAL BILL IS : "<<s;
						cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;

						cout<<endl<<endl<<endl;
						cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;
						cout << "\n\t\t\t\t\t\t\t || "<<"         PAYTM NO : 8053134899    "<<"     ||";
						cout << "\n\t\t\t\t\t\t\t ================================================"<<endl;

            system("wscript second.vbs");

}


int main()
{

    login l;
    varsSystem s;

    int r=l.check_login();

    if(r==1)
    {
         //admin
         l.admin_home();
    }
    else if(r==2)
    {
        //customer
        l.customer_home();
        system("CLS");
        s.generate_bill(l);
    }
    else
      l.check_login();

    return 0;
}
