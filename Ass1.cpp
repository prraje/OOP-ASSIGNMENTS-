                /*Develop an OOP program to in C++ to create a database of students' information system containing the folloing information : name,
                  roll no, class, division, date of birth, blood group, contact address, telephone number, driving license... Construct the
                  database with suitable member functions, static member functions, friend class/function, 'this' pointer, inline code and dynamic
                  memory allocation operators like new and delete. Implement all the keywords as mentioned in the problem statement*/

                #include<iostream>
                #include<string>

                using namespace std;

                class Stud_Database
                {
                    private:
                    int code;
                    public:
                    unsigned int month,day,year;        //unsigned as date of birth should not be negative
                    int switch1=0,switch3=0,switch5=0,switch2=0,switch4=0,switch6=0,i=0,s1,j=0,ch=0;
                    unsigned int rollno,l1=0,l2=0,l3=0;                //unsigned as roll no should not be negative
                    string blgroup;
                    string sclass,add,name;
                    char division;
                    string licenseno;
                    unsigned long long phno,p1,p2;            //long long as telephone number has 10 digits
                    friend void show_code(Stud_Database sd);

                    Stud_Database()                  //constructor
                    {
                        name="Parikshit";
                        rollno=000000;
                        sclass="Comp";
                        division='A';
                        month=1;
                        day=1;
                        year=1997;
                        add="G-2 Neelkanth Residency";
                        licenseno="MHxxxxxxxxxxxxxx";
                        blgroup="O+";
                    }
                    inline void format();                  //inline function
                    void accept();
                    void display();
                };

                    void Stud_Database::format()
                    {
                        cout<<endl<<"Please enter the data in the given format : "<<endl<<endl;
                        cout<<"Name             : "<<name<<endl;
                        cout<<"Roll Number      : "<<rollno<<endl;
                        cout<<"Class            : "<<sclass<<endl;
                        cout<<"Division         : "<<division<<endl;
                        cout<<"Date of birth    : "<<day<<" "<<month<<" "<<year<<endl;
                        cout<<"Blood Group      : "<<blgroup<<endl;
                        cout<<"Address          : "<<add<<endl;
                        cout<<"Telephone Number : 8087903300"<<endl;
                        cout<<"License Number   : "<<licenseno<<endl;
                    }

                    void Stud_Database::accept()
                    {
                        cout<<"Please enter the data: "<<endl;
                        cout<<"Enter full name: ";
                        cin.ignore();
                        getline(cin,name);
                        cout<<endl<<"Enter the Roll No: ";
                        cin>>rollno;
                        cout<<endl<<"Enter the Class: ";
                        cin.ignore();
                        getline(cin,sclass);
                        cout<<endl<<"Enter the Division(A-Z): ";
                        do
                        {
                            switch2=0;
                            cin>>division;

                            for(i=65;i<=90;i++)
                            {
                                if(division ==i)
                                {
                                    switch2=1;
                                }
                            }

                            if(switch2==0)
                            {
                                cout<<"Invalid Section!\nRe-enter Section: ";
                            }

                        }while(switch2==0);

                        cout<<endl<<"Enter the Date of Birth: ";
                        do
                        {
                            switch1=0;
                            cout<<endl<<"Enter Date: ";
                            cin>>day;
                            cout<<endl<<"Enter Month: ";
                            cin>>month;
                            cout<<endl<<"Enter Year: ";
                            cin>>year;

                            if(day>31 || month>12 || year>2001 || year<1997)
                            {
                               switch1++;
                               cout<<"Invalid Date of Birth!\nRe-enter Date of Birth:\n";
                            }
                            else if(day==29 && month==2 && (year%4)!=0)
                            {
                                switch1++;
                                cout<<"Invalid Date of Birth!\nRe-enter Date of Birth:\n";
                            }

                            else if(day>29 && (month==2 || month==4 || month==6 || month==9 || month==11))
                            {
                               switch1++;
                               cout<<"Invalid Date of Birth!\nRe-enter Date of Birth:\n";
                            }
                        }while(switch1==1);

                        do
                        {   switch1=0;
                            ch=0;
                            cout<<endl<<"Enter the Blood Group :\n1. A+\n2. A-\n3. B+\n4. B-\n5. AB+\n6. AB-\n7. O+\n8. O-"<<endl<<"Enter your choice : ";
                            cin>>ch;
                            switch(ch)
                            {
                                case 1:blgroup="A+";
                                break;
                                case 2:blgroup="A-";
                                break;
                                case 3:blgroup="B+";
                                break;
                                case 4:blgroup="B-";
                                break;
                                case 5:blgroup="AB+";
                                break;
                                case 6:blgroup="AB-";
                                break;
                                case 7:blgroup="O+";
                                break;
                                case 8:blgroup="O-";
                                break;
                                default: cout<<endl<<"Invalid choice!\nRe-enter choice:\n";
                                         switch1=1;
                                break;
                            }
                        }while(switch1==1);

                        cout<<endl<<"Enter the Address:\n";
                        cin.ignore();
                        getline(cin,add); //using getline as the address may contain spaces

                        do
                        {
                            switch1=0;
                            cout<<endl<<"Enter the Telephone Number: ";
                            cin>>phno;

                            if(phno<6000000000 || phno>9999999999) //range of mobile nos used in India
                            {
                                switch1=1;
                                cout<<"Invalid phone no!\nRe-enter phone no:\n";
                            }
                        }while(switch1==1);

                        cout<<endl<<"Enter the Driving License Number: ";
                        do
                       {
                            switch1=switch2=switch3=switch4=0;
                            cin>>licenseno;

                            i=j=0;
                            while((licenseno[i])!='\0')
                            {
                                j++;
                                i++;
                            }

                            if(j!=16)
                            {
                                switch1=1;
                            }

                            for(i=65;i<=90;i++)
                            {
                                if(licenseno[0]==i)
                                {
                                   switch2++;
                                }
                                 if(licenseno[1]==i)
                                {
                                   switch3++;
                                }
                            }

                                j=2;
                                while(j<=15)
                                {

                                    if((int)licenseno[j]>=48 && (int)licenseno[j]<=57)
                                        {
                                            switch4++;
                                        }

                                   j++;
                                }

                            if(switch1==1 || switch2==0 || switch3==0 || switch4!=14)
                            {
                                cout<<endl<<"Invalid Licence No! Re-enter License no.:";
                            }

                        }while(switch1==1 || switch2==0 || switch3==0 || switch4!=14);

                        cout<<endl<<"Enter Subject Code: ";
                        cin>>code;
                    }

                    void show_code(Stud_Database obj)     //friend function to class
                    {
                        cout<<"Subject Code    : "<<obj.code<<endl<<endl;
                    }

                    void Stud_Database::display()
                    {
                        cout<<endl<<"Name            : "<<name;
                        cout<<endl<<"Roll Number     : "<<rollno;
                        cout<<endl<<"Class           : "<<sclass;
                        cout<<endl<<"Division        : "<<division;
                        cout<<endl<<"Date of Birth   : "<<day<<"/"<<month<<"/"<<year;
                        cout<<endl<<"Blood Group     : "<<blgroup;
                        cout<<endl<<"Address         : "<<add;
                        cout<<endl<<"Telephone Number: "<<phno;
                        cout<<endl<<"License Number  : "<<licenseno<<endl;
                    }

                int main()
                {
                    static int n,n2;            //static as it should not have multiple copies

                    cout<<"Enter the number of students : ";
                    cin>>n;
                    n2=n;
                    Stud_Database obj[n];           //array of objects
                    while(n--)
                    {
                        obj[n].format();
                        cout<<endl<<endl;
                        obj[n].accept();
                        cout<<endl<<endl;
                    }

                    while(n2--)
                    {
                        obj[n2].display();
                        show_code(obj[n2]);
                        cout<<endl<<endl;
                    }

                    return 0;
                }
