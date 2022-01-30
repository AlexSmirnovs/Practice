#include<iostream> //header files
#include<fstream>
#include<iomanip>
#include<cstring>
#include<windows.h>
using namespace std;

//functions
void menu();
void pascode();
void cpascode();
void call_dr();
void pinfoshow();

//class declaration
class one{
    public:
   virtual void get()=0;
   virtual void show()=0;
};
class info:public one
{
    public:
    char name[50],time[50];
    int num,age;
    void get()
    {
        system("cls");
        cin.sync();
        cout<<"\nEnter the patient's name: ";
        cin.getline(name,50);
        cout<<"\n Enter age: ";
        cin>>age;
        cout<<"\nEnter appointment number: ";
        cin>>num;
        cout<<"\nEnter Appointment Time: ";
    }
    void show()
    {
        cout<<"\nName: "<<name;
        cout<<"\nAge: "<<age;
        cout<<"\nNO: "<<num;
        cout<<"\nTime: "<<time;
    }
};

class staff:public one                      //staff data
{
 public:
 char all[1000],name[50],age[50],sal[50],pos[50];
 void get()
 {
    ofstream out("staff.txt",ios::app);
    {
        system("cls");
        cout<<"\nEnter name: ";
        cin.getline(name,50);
        cout<<"\nage: ";
        cin.getline(age,50);
        cout<<"\nEnter Salary: ";
        cin.getline(sal,50);
        cout<<"\nEnter working position: ";
        cin.getline(pos,50);
    }
    out<<"\n Name: "<<name<<"\nage "<<age<<"\nsalary: "<<"\nPosition: "<<pos;
    out.close();
    cout<<"\nYour information is being saved";
    menu();

 }
 void show()
 {
    ifstream in("staff.txt");
  if(!in)
  {
      cout<<"\nFile open error\n";
  }
  while(!(in.eof()))
  {
      in.getline(all,1000);
      cout<<all<<endl;
  }

  cout<<"\n\n\tPress any key to continue";
  menu();
 }

};
class rana:public info                   //doctor  1
{
 public:
 info a1;
 void get()
 {
     system("cls");
     ofstream out("Rana.txt", ios::app|ios::binary);
     a1.get();
     out.write((char*)&a1,sizeof(info));
     out.close();
     cout<<"\nYour enrty has been saved";
     menu();
 }
 void show()
 {
     ifstream in("Rana.txt");
     if(in==NULL)
     {
         cout<<"\n\n No data in the file\n\n";
         cout<<"\n\nPress any  key  to continue\n\n";
         menu();
     }
     else
     {
         while(!in.eof())
         {
             in.read((char*)&a1,sizeof(a1));
             a1.show();
         }
         in.close();
         menu();
     }
 }
};
class waqar:public info                   //doctor 2
{
    public:
 info a1;
 void get()
 {
     system("cls");
     ofstream out("Rana.txt", ios::app|ios::binary);
     a1.get();
     out.write((char*)&a1,sizeof(info));
     out.close();
     cout<<"\nYour enrty has been saved";
     menu();
     }
     void show()
     {
     ifstream in("waqar.txt");
     if(in==NULL)
     {
         cout<<"\n\n No data in the file\n\n";
         cout<<"\n\nPress any  key  to continue\n\n";
         menu();
     }
     else
     {
         while(!in.eof())
         {
             in.read((char*)&a1,sizeof(a1));
             a1.show();
         }
         in.close();
         menu();
       }
    }

};
class ahmad:public info                  // doctor 3
{
    public:
 info a1;
 void get()
 {
     system("cls");
     ofstream out("Rana.txt", ios::app|ios::binary);
     a1.get();
     out.write((char*)&a1,sizeof(info));
     out.close();
     cout<<"\nYour entry has been saved";
     menu();
 }
 void show()
 {
     ifstream in("ahmad.txt");
     if(in==NULL)
     {
         cout<<"\n\n No data in the file\n\n";
         cout<<"\n\nPress any  key  to continue\n\n";
         menu();
     }
     else
     {
         while(!in.eof())
         {
             in.read((char*)&a1,sizeof(a1));
             a1.show();
         }
         in.close();
         menu();
     }
 }

 };
 class information{
    public:
    void drinfo()
    {
        system("cls");
        system("color f3");
        cout<<"\n===================================================================================\n";
        cout<<"\n Three doctors are available timing is given below\n";
        cout<<"\t\tDr Rana\n";
        cout<<"\t\t\tTimings\n" ;
        cout<<"\tMonday to Friday \t\t9AM to 5PM" ;
        cout<<"\tSaturday \t\t9AM to 1PM" ;
        cout<<"\tSunday \t\tDay off" ;
        cout<<"\n===================================================================================\n";
        cout<<"\t\tDr waqar\n";
        cout<<"\t\t\tTimings\n" ;
        cout<<"\tMonday to Friday \t\t9AM to 5PM" ;
        cout<<"\tSaturday \t\t9AM to 1PM" ;
        cout<<"\tSunday \t\tDay off" ;
        cout<<"\n===================================================================================\n";
        cout<<"\t\tDr Ahmad\n";
        cout<<"\t\t\tTimings\n" ;
        cout<<"\tMonday to Friday \t\t9AM to 5PM" ;
        cout<<"\tSaturday \t\t9AM to 1PM" ;
        cout<<"\tSunday \t\tDay off" ;
    }

};
void call_dr()
{
    system("cls");
    int choice;
    cout<<"\n\n\t1. Press 1 for Dr Rana \n\n\t2. Press 2 for Dr waqar \n\n\t3. Press 3 for Dr Ahamd\n";
    cout<<"\n Please enter your choice\n";
    cin>>choice;
    one *ptr;
    rana s3;
    waqar s4;
    ahmad s5;
    if(choice==1 )
    {
 ptr=&s3;
 ptr->get();
    }
  else  if(choice==2 )
    {
       ptr=&s4;
       ptr->get();
    }
    else if(choice==3 )
    {
       ptr=&s5;
       ptr->get();
    }
    else {
        cout<<"\n Sorry Invalid choice\n";
        menu();
    }
  }

  void pinfoshow()
  {
    system("cls");
    int choice;
    cout<<"\n\n\t1. Press 1 for Dr Rana \n\n\t2. Press 2 for Dr waqar \n\n\t3. Press 3 for Dr Ahamd\n";
    cout<<"\n Please enter your choice\n";
    cin>>choice;
    one *ptr;
    rana s3;
    waqar s4;
    ahmad s5;
    if(choice==1 )
    {
     ptr=&s3;
    ptr->show();
    }
  else  if(choice==2 )
    {
       ptr=&s4;
       ptr->show();
    }
    else if(choice==3 )
    {
       ptr=&s5;
       ptr->show();
    }
    else {
        cout<<"\n Sorry Invalid choice\n";
        menu();
    }
}
void menu()
{
    system("cls");
    system("color FC");
    cout<<"\n";
    cout<<"\n";
    cout<<"\t\t          |       +++++++ Main Menu ++++++++++        |\n";
    cout<<"\t\t          |        Hospital management system         |\n";
    cout<<"\t\t          |===========================================|\n";
    cout<<"\t\t Please select an option\n";
    cout<<"\t1\tPress 1 for Doctor Information\n";
    cout<<"\t2\tPress 2 for Doctor appointment\n";
    cout<<"\t3\tPress 3 for saving staff information\n";
    cout<<"\t4\tPress 4 for checking patients appointment\n";
    cout<<"\t5\tPress 5 for checking staff information\n";
    cout<<"\t6\tPress 6 for change or create password\n";
    cout<<"\t7\t\t Press 7 for logout\n";
    cout<<"\n========================================================================================================================\n";
    cout<<"\n Please enter your choice";
    information a1;
    one *ptr;
    staff a2;
    int a;
    cin>>a;
    if(a==1)
    {
        a1.drinfo();
    }
    else if(a==2)
    {
        call_dr();
    }
    else if(a==3)
    {
       ptr=&a2;
       ptr->get();
    }
    else if(a==4)
    {
       pinfoshow();
    }
    else if(a==5)
    {
        ptr=&a2;
        ptr->show();
    }
    else if(a==6)
    {
        cpascode();
    }
    else if(a==7)
    {
        pascode();
    }
    else
    {
        cout<<"\n Sorry Invalid choice\n";
    }
}
void pascode(){
    system("cls");
    char p1[50],p2[50],p3[50];
    system("color FC");
    ifstream in("password.txt");
    {
        cin.sync();
        cout<<"\t\t\t\nEnter the password: ";
        cin.getline(p1,50);
        in.getline(p2,50);
        if(strcmp(p2,p2)==0)
        {
        menu();
        }
        else
        {
            cout<<"\t\t\t\n Incorrect passord Please try again......";
            Sleep(999);
            pascode();
        }
    }
    in.close();

}
void cpascode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\tEnter the new password\n";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\nYour password has been saved\n";
    menu();
}
int main()
{
    pascode();
    system("pause");
}
