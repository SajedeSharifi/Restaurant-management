#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct info {

    string id;
    string password;
};

struct pInfo {

    string firstName;
    string lastName;
    string fullName;
    string email;
    string emailPassword;
    string phoneNumber;
    string favoriteFood;
};

struct food {

    string name;
    long long unsigned int price;
};

struct invoice {

    food info[20];
    unsigned long long int totalPrice;
};

struct customer {

    info c_Information;
    pInfo c_PersonalInfo;
    food cart[20];
    long long unsigned int wallet;
    invoice invoice_c[10];

};

struct employee {

    info e_Information;
    pInfo e_PersonalInfo;

};

struct administration {

    info a_Information;
};

//--------------------------------------

template <class T>
void printmenu (T [] , int );

template<class T>
void printCustomerInfo (T [], int );

template<class T>
void printCode (T [], int );

template<class T>
void printEmployeesInfo (T [] , int );

template<class T>
void printCart (T [], int ,int );

template<class T>
void printInvoices (T [],int ,int ,int );

template<class T>
void addToFactor (T customers, int index, int len1, int &len2, int size_in);

//--------------------------------------

int main()
{
    int action = 0;
    //int size = 200;
    int sizeE = 3;                      //count of employees
    int sizeC = 2;                      //count of customers
    int sizeF = 10;                     //count of foods
    int size_c = 3;                     //count of discount codes
    int size_in = 0;                    //count of invoices
    int size_cart = 0;                  //count of orders
    int size_info = 0;                  //count of food in each invoice

    srand(time(0));

    administration admin;
    employee employees[200];
    customer customers[200];
    food menu[200];
    string discountCode[200];

    //intialization
    admin.a_Information.id = "amir@899";
    admin.a_Information.password = "Q4##56bN";


    employees[0].e_PersonalInfo.firstName = "Ahmad";
    employees[0].e_PersonalInfo.lastName = "Mosavi";
    employees[0].e_Information.id = "ahmad@sol";
    employees[0].e_Information.password = "23Cf@vcvbm";

    employees[1].e_PersonalInfo.firstName = "Siamak";
    employees[1].e_PersonalInfo.lastName = "Ansari";
    employees[1].e_Information.id = "Sia34mak";
    employees[1].e_Information.password = "3432SM@12";

    employees[2].e_PersonalInfo.firstName = "Ali";
    employees[2].e_PersonalInfo.lastName = "jamshidi";
    employees[2].e_Information.id = "Alireza12CV";
    employees[2].e_Information.password = "2277020CVVG";

    customers[0].c_PersonalInfo.firstName = "Ramin";
    customers[0].c_PersonalInfo.lastName = "ahamdian";
    customers[0].c_Information.id = "Ahmadia567";
    customers[0].c_Information.password = "20942XsvH@Z";

    customers[1].c_PersonalInfo.firstName = "Milad";
    customers[1].c_PersonalInfo.lastName = "farahani";
    customers[1].c_Information.id = "Farahan78887@f";
    customers[1].c_Information.password = "35664FTUn45";

    menu[0].name = "Ghormesabzi";
    menu[0].price = 32000;

    menu[1].name = "Zereshkpolo";
    menu[1].price = 37000;

    menu[2].name = "Ghime";
    menu[2].price = 30000;

    menu[3].name = "Noshabe";
    menu[3].price = 12000;

    menu[4].name = "Dogh";
    menu[4].price = 10000;

    menu[5].name = "Kabab";
    menu[5].price = 40000;

    menu[6].name = "Berenj";
    menu[6].price = 10000;

    menu[7].name = "Khoresht";
    menu[7].price = 23000;

    menu[8].name = "Delester";
    menu[8].price = 13000;

    menu[9].name = "Salad";
    menu[9].price = 15000;

    discountCode[0] = "23FCV%n&5";

    discountCode[1] = "sd67Hj#!x";

    discountCode[2] = "QWBv23@#v";

    while (true) {

        cout << endl << "Choose the action you want to do :  (Tell us a number) " << endl << endl;
        cout << "1 : Login" << endl;
        cout << "2 : Register" << endl;
        cout << "3 : Exit" << endl << endl;

        cin >> action;
        cout << endl << endl;

        if (action == 1) {

            bool flag = true;
            int userType = 0;

            while (flag) {

                cout << endl << "Which kind of user are you ?  (Tell us a number) " << endl << endl;
                cout << "1 : Administration" << endl;
                cout << "2 : Employee" << endl;
                cout << "3 : Customer" << endl;
                cout << "4 : Return" << endl << endl;

                cin >> userType;
                cout << endl << endl;

                if (userType == 1) {

                    string id1;
                    string pass1;

                    cout << endl << "Please tell us your id : ";
                    cin >> id1;

                    cout << endl << endl << "Now please tell us your password : ";
                    cin >> pass1;

                    if (id1 != admin.a_Information.id || pass1 != admin.a_Information.password) {

                        cout << endl << endl << "Error : Invalid Inputs!" << endl << endl << "Try Again!" << endl << endl;
                    }

                    else {

                        bool flag = true;

                        while (flag) {

                            int choice = 0;

                            cout << endl << endl << endl << "Please choose one of the options : " << endl << endl;

                            cout << "1 : view the list of foods along with their prices" << endl;
                            cout << "2 : change the list of available foods along with their prices" << endl;
                            cout << "3 : change employee information" << endl;
                            cout << "4 : change customer information" << endl;
                            cout << "5 : adding new discount codes" << endl;
                            cout << "6 : view all invoices for previous purchases" << endl;
                            cout << "7 : return to the login page" << endl << endl;

                            cin >> choice;

                            if (choice == 1) {

                                printmenu (menu,sizeF);
                            }

                            else if (choice == 2) {

                                bool temp = true;
                                int option = 0;

                                while (temp) {

                                    cout << endl << "choose the action you want to do : " << endl << endl;
                                    cout << "1 : edit" << endl;
                                    cout << "2 : add" << endl;
                                    cout << "3 : remove" << endl;
                                    cout << "4 : return" << endl << endl;

                                    cin >> option;

                                    if (option == 1) {

                                        string n;
                                        long long int p = 0;
                                        bool tmp = true;

                                        cout << endl << "Please tell us the name of food : ";
                                        cin >> n;

                                        for (int i = 0; i < sizeF && tmp; i++) {

                                            if (n == menu[i].name) {

                                                cout << endl << "Please tell us the new price : ";
                                                cin >> p;

                                                if (p > 0) {

                                                    menu[i].price = p;

                                                    cout << endl << "Mission Completed!" << endl << endl;

                                                    cout << endl << endl;

                                                    printmenu(menu,sizeF);

                                                    tmp = false;
                                                }

                                                else {

                                                    cout << endl << "Error!" << endl << endl;

                                                    tmp = false;
                                                }
                                            }
                                        }

                                        if (tmp) {

                                            cout << endl << "The food is not in the list!" << endl << endl;
                                        }
                                    }

                                    else if (option == 2) {

                                        string n;
                                        long long unsigned int p;
                                        bool tmp = true;

                                        cout << endl << "Please tell us the name of new food : ";
                                        cin >> n;

                                        for (int i = 0; i < sizeF && tmp; i++) {

                                            if (n == menu[i].name) {

                                                tmp = false;
                                            }
                                        }

                                        if (tmp) {

                                            cout << endl << "please tell us the price : ";
                                            cin >> p;

                                            sizeF++;
                                            menu[sizeF-1].name = n;
                                            menu[sizeF-1].price = p;

                                            cout << endl << endl;

                                            printmenu(menu,sizeF);
                                        }

                                        else {

                                            cout << endl << "The food is in the list already!" << endl << endl;
                                        }
                                    }

                                    else if (option == 3) {

                                        string n;
                                        bool tmp = true;

                                        cout << endl << "please tell us the name of food you want to remove : ";
                                        cin >> n;

                                        for (int i = 0; i < sizeF && tmp; i++) {

                                            if (n.compare(menu[i].name) == 0) {

                                                for (int j = i; j < sizeF-1; j++) {

                                                    menu[j].name = menu[j+1].name;
                                                    menu[j].price = menu[j+1].price;
                                                }

                                                i--;
                                                sizeF--;

                                                cout << endl << "Mission Completed!" << endl << endl;

                                                cout << endl << endl;

                                                printmenu(menu,sizeF);

                                                tmp = false;
                                            }
                                        }

                                        if (tmp) {

                                            cout << endl << "The food is not in the list!" << endl << endl;
                                        }
                                    }

                                    else if (option == 4) {

                                        temp = false;
                                    }

                                    else {

                                        cout << endl << "Error : Your choise is not in the definded renge!" << endl << endl;

                                        temp = false;
                                    }
                                }
                            }

                            else if (choice == 3) {

                                bool fl = true;
                                int option = 0;

                                while (fl) {

                                    cout << endl << "choose the action you want to do : " << endl << endl;
                                    cout << "1 : add the information of new employee" << endl;
                                    cout << "2 : remove the information of an employee" << endl;
                                    cout << "3 : edit the information of employees" << endl;
                                    cout << "4 : return" << endl << endl;

                                    cin >> option;

                                    if (option == 1) {

                                        string n;                   //id
                                        string f;                   //first name
                                        string l;                   //last name
                                        string p;                   //password
                                        string e;                   //email
                                        string eP;                  //email password
                                        string f2;                  //favorite food
                                        string pN;                  //phone number
                                        char ch;
                                        bool t = true;

                                        cout << endl << "Please fill the form : " << endl << endl;

                                        while (t) {

                                            bool tmp = true;

                                            cout << "ID : ";
                                            cin >> n;

                                            if (n.length() >= 5) {

                                                for (int i = 0; i < sizeE && tmp; i++) {

                                                    if (n.compare(employees[i].e_Information.id) == 0) {

                                                        cout << endl << "The employee is working here already!" << endl << endl;

                                                        tmp = false;
                                                    }
                                                }

                                                for (int i = 0; i < sizeC && tmp; i++) {

                                                    if (n.compare(customers[i].c_Information.id) == 0) {

                                                        cout << endl << "Error : This id has been taken!" << endl << endl;

                                                        tmp = false;
                                                    }
                                                }

                                                if (n.compare(admin.a_Information.id) == 0) {

                                                    cout << endl << "This id is yours! 0_0 " << endl << endl;
                                                    tmp = false;
                                                }

                                                if (tmp) {

                                                    int pass = 0;
                                                    int change = 0;

                                                    cout << endl;

                                                    pass = rand() % 30000 + 452000;

                                                    p = to_string(pass) + "FN";

                                                    cout << endl << "Random password for this employee is : " << p << endl;
                                                    cout << endl << "If you want to change it enter '1' if not enter '0' : ";
                                                    cin >> change;
                                                    cout << endl;

                                                    if (change == 1) {

                                                        bool a = true;

                                                        while (a) {

                                                            cout << "Password : ";
                                                            cin >> p;

                                                            cout << endl << endl;

                                                            if (p.length() >= 8) {

                                                                sizeE++;

                                                                employees[sizeE-1].e_Information.id = n;

                                                                employees[sizeE-1].e_Information.password = p;

                                                                cout << "First Name : ";
                                                                cin.get(ch);
                                                                getline(cin , f);
                                                                employees[sizeE-1].e_PersonalInfo.firstName = f;

                                                                cout << endl << endl;

                                                                cout << "Last Name : ";
                                                                getline(cin , l);
                                                                employees[sizeE-1].e_PersonalInfo.lastName = l;

                                                                cout << endl << endl;

                                                                bool b = true;

                                                                while (b) {

                                                                    cout << "Email : ";
                                                                    cin >> e;

                                                                    bool temp = true;

                                                                    for (int i = 0; i < sizeE && temp; i++) {

                                                                        if (e.compare(employees[i].e_PersonalInfo.email) == 0) {

                                                                            cout << endl << "Error : The email has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int i = 0; i < sizeC && temp; i++) {

                                                                        if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                                                            cout << endl << "Error : This email has been taken!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    if (temp) {

                                                                        employees[sizeE-1].e_PersonalInfo.email = e;
                                                                        b = false;
                                                                    }
                                                                }

                                                                cout << endl << endl;

                                                                cout << "Email Password : ";
                                                                cin >> eP;
                                                                employees[sizeE-1].e_PersonalInfo.emailPassword = eP;

                                                                cout << endl << endl;

                                                                b = true;

                                                                while (b) {

                                                                    cout << "Phone Number : ";
                                                                    cin >> pN;

                                                                    bool temp = true;

                                                                    for (int i = 0; i < sizeE && temp; i++) {

                                                                        if (pN.compare(employees[i].e_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : The phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int i = 0; i < sizeC && temp; i++) {

                                                                        if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    if (temp) {

                                                                        employees[sizeE-1].e_PersonalInfo.phoneNumber = pN;
                                                                        b = false;
                                                                    }
                                                                }

                                                                cout << endl << endl;

                                                                cout << "Favorite Food : ";
                                                                cin.get(ch);
                                                                getline (cin , f2);
                                                                employees[sizeE-1].e_PersonalInfo.favoriteFood = f2;

                                                                cout << endl << endl;

                                                                printEmployeesInfo (employees , sizeE);

                                                                a = false;
                                                                t = false;
                                                            }

                                                            else {

                                                                cout << endl << "Error : password must be at least 8 character!" << endl << endl;
                                                            }
                                                        }
                                                    }

                                                    else {

                                                        sizeE++;

                                                        employees[sizeE-1].e_Information.id = n;

                                                        employees[sizeE-1].e_Information.password = p;

                                                        cout << "First Name : ";
                                                        cin.get(ch);
                                                        getline(cin , f);
                                                        employees[sizeE-1].e_PersonalInfo.firstName = f;

                                                        cout << endl << endl;

                                                        cout << "Last Name : ";
                                                        getline(cin , l);
                                                        employees[sizeE-1].e_PersonalInfo.lastName = l;

                                                        cout << endl << endl;

                                                        bool b = true;

                                                        while (b) {

                                                            cout << "Email : ";
                                                            cin >> e;

                                                            bool temp = true;

                                                            for (int i = 0; i < sizeE && temp; i++) {

                                                                if (e.compare(employees[i].e_PersonalInfo.email) == 0) {

                                                                    cout << endl << "Error : The email has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int i = 0; i < sizeC && temp; i++) {

                                                                if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                                                    cout << endl << "Error : This email has been taken!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                employees[sizeE-1].e_PersonalInfo.email = e;
                                                                b = false;
                                                            }
                                                        }

                                                        cout << endl << endl;

                                                        cout << "Email Password : ";
                                                        cin >> eP;
                                                        employees[sizeE-1].e_PersonalInfo.emailPassword = eP;

                                                        cout << endl << endl;

                                                        b = true;

                                                        while (b) {

                                                            cout << "Phone Number : ";
                                                            cin >> pN;

                                                            bool temp = true;

                                                            for (int i = 0; i < sizeE && temp; i++) {

                                                                if (pN.compare(employees[i].e_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : The phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int i = 0; i < sizeC && temp; i++) {

                                                                if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                employees[sizeE-1].e_PersonalInfo.phoneNumber = pN;
                                                                b = false;
                                                            }
                                                        }

                                                        cout << endl << endl;

                                                        cout << "Favorite Food : ";
                                                        cin.get(ch);
                                                        getline (cin , f2);
                                                        employees[sizeE-1].e_PersonalInfo.favoriteFood = f2;

                                                        cout << endl << endl;

                                                        printEmployeesInfo (employees , sizeE);

                                                        t = false;

                                                    }
                                                }
                                            }

                                            else {

                                                cout << endl << "Error : id must be at least 5 character!" << endl << endl;
                                            }
                                        }
                                    }

                                    else if (option == 2) {

                                        string n;
                                        bool tmp = true;

                                        cout << endl << "Please tell us the id of employee : ";
                                        cin >> n;

                                        cout << endl;

                                        for (int i = 0; i < sizeE && tmp; i++) {

                                            if (n.compare(employees[i].e_Information.id) == 0) {

                                                for (int j = i; j < sizeE-1; j++) {

                                                    employees[j].e_Information.id = employees[j+1].e_Information.id;
                                                    employees[j].e_Information.password = employees[j+1].e_Information.password;
                                                    employees[j].e_PersonalInfo.firstName = employees[j+1].e_PersonalInfo.firstName;
                                                    employees[j].e_PersonalInfo.lastName = employees[j+1].e_PersonalInfo.lastName;
                                                    employees[j].e_PersonalInfo.email = employees[j+1].e_PersonalInfo.email;
                                                    employees[j].e_PersonalInfo.emailPassword = employees[j+1].e_PersonalInfo.emailPassword;
                                                    employees[j].e_PersonalInfo.phoneNumber = employees[j+1].e_PersonalInfo.phoneNumber ;
                                                    employees[j].e_PersonalInfo.favoriteFood = employees[j+1].e_PersonalInfo.favoriteFood ;
                                                }

                                                i--;
                                                sizeE--;

                                                cout << endl << "Mission Completed!" << endl << endl;

                                                printEmployeesInfo(employees,sizeE);

                                                tmp = false;
                                            }
                                        }

                                        if (tmp) {

                                            cout << endl << "This person is not working here!" << endl << endl;
                                        }
                                    }

                                    else if (option == 3) {

                                        string n;                   //id
                                        string f;                   //first name
                                        string l;                   //last name
                                        string p;                   //password
                                        string e;                   //email
                                        string eP;                  //email password
                                        string f2;                  //favorite food
                                        string pN;                  //phone number
                                        char ch;
                                        int c = 0;
                                        bool t = true;
                                        bool tmp = true;

                                        cout << endl << "Please tell us the id of employee : ";
                                        cin >> n;

                                        for (int i = 0; i < sizeE && tmp; i++) {

                                            if (n.compare(employees[i].e_Information.id) == 0) {

                                                while (t) {

                                                    cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                    cout << "1 : Login Password" << endl;
                                                    cout << "2 : Email" << endl;
                                                    cout << "3 : Email Password" << endl;
                                                    cout << "4 : Phone Number" << endl;
                                                    cout << "5 : Favorite Food" << endl;
                                                    cout << "6 : return" << endl << endl;

                                                    cin >> c;

                                                    if (c == 1) {

                                                        cout << endl << "Tell us the new password : ";
                                                        cin >> p;

                                                        if (p.length() >= 8) {

                                                            employees[i].e_Information.password = p;
                                                        }

                                                        else {

                                                            cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                        }
                                                    }

                                                    else if (c == 2) {

                                                        cout << endl << "Tell us the new email address : ";
                                                        cin >> e;

                                                        bool temp = true;

                                                        for (int j = 0; j < sizeE && temp; j++) {

                                                            if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                                cout << endl << "Error : The email has been used!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        for (int i = 0; i < sizeC && temp; i++) {

                                                            if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                                                cout << endl << "Error : This email has been taken!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        if (temp) {

                                                            employees[i].e_PersonalInfo.email = e;
                                                        }
                                                    }

                                                    else if (c == 3) {

                                                        cout << endl << "Tell us the new email password : ";
                                                        cin >> eP;

                                                        employees[i].e_PersonalInfo.emailPassword = eP;
                                                    }

                                                    else if (c == 4) {

                                                        cout << endl << "Tell us the new phone number : ";
                                                        cin >> pN;

                                                        bool temp = true;

                                                        for (int j = 0; j < sizeE && temp; j++) {

                                                            if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                                cout << endl << "Error : The phone number has been used!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        for (int j = 0; j < sizeC && temp; j++) {

                                                            if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                                cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        if (temp) {

                                                            employees[i].e_PersonalInfo.phoneNumber = pN;
                                                        }
                                                    }

                                                    else if (c == 5) {

                                                        cout << endl << "Tell us the favorite food : ";
                                                        cin.get(ch);
                                                        getline (cin , f2);

                                                        employees[i].e_PersonalInfo.favoriteFood = f2;
                                                    }

                                                    else if (c == 6) {

                                                        t = false;
                                                    }

                                                    else {

                                                        cout << endl << "Error : choose one of the options!" << endl << endl;

                                                        t = false;
                                                    }
                                                }

                                                printEmployeesInfo (employees,sizeE);

                                                tmp = false;
                                            }
                                        }

                                        if (tmp) {

                                            cout << endl << "This person is not working here!" << endl << endl;
                                        }
                                    }

                                    else if (option == 4) {

                                        fl = false;
                                    }

                                    else {

                                        cout << endl << "Error : Your choise is not in the definded renge!" << endl << endl;

                                        fl = false;
                                    }
                                }
                            }

                            else if (choice == 4) {

                                bool fl = true;
                                int option = 0;

                                while (fl) {

                                    cout << endl << "choose the action you want to do : " << endl << endl;
                                    cout << "1 : add the information of new customer" << endl;
                                    cout << "2 : remove the information of a customer" << endl;
                                    cout << "3 : edit the information of customers" << endl;
                                    cout << "4 : return" << endl << endl;

                                    cin >> option;

                                    if (option == 1) {

                                        string n;                   //id
                                        string f;                   //first name
                                        string l;                   //last name
                                        string p;                   //password
                                        string e;                   //email
                                        string eP;                  //email password
                                        string f2;                  //favorite food
                                        string pN;                  //phone number
                                        char ch;
                                        bool tmp = true;

                                        cout << endl << "Please fill the form : " << endl << endl;

                                        while (tmp) {

                                            bool t = true;
                                            cout << "ID : ";
                                            cin >> n;

                                            if (n.length() >= 5) {

                                                for (int i = 0; i < sizeC && t; i++) {

                                                    if (n.compare(customers[i].c_Information.id) == 0) {

                                                        cout << endl << "The information of customer exists already!" << endl << endl;

                                                        t = false;
                                                    }
                                                }

                                                for (int i = 0; i < sizeE && t; i++) {

                                                    if (n.compare(employees[i].e_Information.id) == 0) {

                                                        cout << endl << "This id has been taken!" << endl << endl;

                                                        t = false;
                                                    }
                                                }

                                                if (n.compare(admin.a_Information.id) == 0 && t) {

                                                    cout << endl << "Error : This id is yours! o_o" << endl << endl;

                                                    t = false;
                                                }

                                                if (t) {

                                                    int pass = 0;
                                                    int change = 0;

                                                    cout << endl;

                                                    pass = rand() % 30000 + 452000;

                                                    p = to_string(pass) + "FN";

                                                    cout << endl << "Random password for this customer is : " << p << endl;
                                                    cout << endl << "If you want to change it enter '1' if not enter '0' : ";
                                                    cin >> change;

                                                    cout << endl;

                                                    if (change == 1) {

                                                        bool a = true;

                                                        while (a) {

                                                            cout << "Password : ";
                                                            cin >> p;

                                                            if (p.length() >= 8) {

                                                                sizeC++;

                                                                customers[sizeC-1].c_Information.id = n;

                                                                customers[sizeC-1].c_Information.password = p;

                                                                cout << endl << endl;

                                                                cout << "First Name : ";
                                                                cin.get(ch);
                                                                getline(cin , f);
                                                                customers[sizeC-1].c_PersonalInfo.firstName = f;

                                                                cout << endl << endl;

                                                                cout << "Last Name : ";
                                                                //cin.get(ch);
                                                                getline(cin , l);
                                                                customers[sizeC-1].c_PersonalInfo.lastName = l;

                                                                cout << endl << endl;

                                                                bool b = true;

                                                                while (b) {

                                                                    cout << "Email : ";
                                                                    cin >> e;

                                                                    bool temp = true;

                                                                    for (int i = 0; i < sizeC && temp; i++) {

                                                                        if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                                                            cout << endl << "This email has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int i = 0; i < sizeE && temp; i++) {

                                                                        if (e.compare(employees[i].e_PersonalInfo.email) == 0) {

                                                                            cout << endl << "This email has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    if (temp) {

                                                                        customers[sizeC-1].c_PersonalInfo.email = e;

                                                                        b = false;
                                                                    }
                                                                }

                                                                cout << endl << endl;

                                                                cout << "Email Password : ";
                                                                cin >> eP;
                                                                customers[sizeC-1].c_PersonalInfo.emailPassword = eP;

                                                                cout << endl << endl;

                                                                b = true;

                                                                while (b) {

                                                                    cout << "Phone Number : ";
                                                                    cin >> pN;

                                                                    bool temp = true;

                                                                    for (int i = 0; i < sizeC && temp; i++) {

                                                                        if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int i = 0; i < sizeE && temp; i++) {

                                                                        if (pN.compare(employees[i].e_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    if (temp) {

                                                                        customers[sizeC-1].c_PersonalInfo.phoneNumber = pN;
                                                                        b = false;
                                                                    }
                                                                }

                                                                cout << endl << endl;

                                                                cout << "Favorite Food : ";
                                                                cin.get(ch);
                                                                getline (cin , f2);
                                                                customers[sizeC-1].c_PersonalInfo.favoriteFood = f2;

                                                                cout << endl << endl;

                                                                printCustomerInfo (customers,sizeC);

                                                                a = false;

                                                                tmp = false;
                                                            }

                                                            else {

                                                                cout << endl << "Error : password must be at least 8 character!" << endl << endl;
                                                            }
                                                        }
                                                    }

                                                    else {

                                                        sizeC++;

                                                        customers[sizeC-1].c_Information.id = n;

                                                        customers[sizeC-1].c_Information.password = p;

                                                        cout << endl << endl;

                                                        cout << "First Name : ";
                                                        cin.get(ch);
                                                        getline(cin , f);
                                                        customers[sizeC-1].c_PersonalInfo.firstName = f;

                                                        cout << endl << endl;

                                                        cout << "Last Name : ";
                                                        getline(cin , l);
                                                        customers[sizeC-1].c_PersonalInfo.lastName = l;

                                                        cout << endl << endl;

                                                        bool b = true;

                                                        while (b) {

                                                            cout << "Email : ";
                                                            cin >> e;

                                                            bool temp = true;

                                                            for (int i = 0; i < sizeC && temp; i++) {

                                                                if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                                                    cout << endl << "This email has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int i = 0; i < sizeE && temp; i++) {

                                                                if (e.compare(employees[i].e_PersonalInfo.email) == 0) {

                                                                    cout << endl << "This email has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                customers[sizeC-1].c_PersonalInfo.email = e;

                                                                b = false;
                                                            }
                                                        }

                                                        cout << endl << endl;

                                                        cout << "Email Password : ";
                                                        cin >> eP;
                                                        customers[sizeC-1].c_PersonalInfo.emailPassword = eP;

                                                        cout << endl << endl;

                                                        b = true;

                                                        while (b) {

                                                            cout << "Phone Number : ";
                                                            cin >> pN;

                                                            bool temp = true;

                                                            for (int i = 0; i < sizeC && temp; i++) {

                                                                if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int i = 0; i < sizeE && temp; i++) {

                                                                if (pN.compare(employees[i].e_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                customers[sizeC-1].c_PersonalInfo.phoneNumber = pN;
                                                                b = false;
                                                            }
                                                        }

                                                        cout << endl << endl;

                                                        cout << "Favorite Food : ";
                                                        cin.get(ch);
                                                        getline (cin , f2);
                                                        customers[sizeC-1].c_PersonalInfo.favoriteFood = f2;

                                                        cout << endl << endl;

                                                        printCustomerInfo (customers,sizeC);

                                                        tmp = false;
                                                    }
                                                }
                                            }

                                            else {

                                                cout << endl << "Error : id must be at least 5 character!" << endl << endl;
                                            }
                                        }
                                    }

                                    else if (option == 2) {

                                        string n;
                                        bool tmp = true;

                                        cout << endl << "Please tell us the id of customer : ";
                                        cin >> n;

                                        cout << endl;

                                        for (int i = 0; i < sizeC && tmp; i++) {

                                            if (n.compare(customers[i].c_Information.id) == 0) {

                                                for (int j = i; j < sizeC-1; j++) {

                                                    customers[j].c_Information.id = customers[j+1].c_Information.id;
                                                    customers[j].c_Information.password = customers[j+1].c_Information.password;
                                                    customers[j].c_PersonalInfo.firstName = customers[j+1].c_PersonalInfo.firstName;
                                                    customers[j].c_PersonalInfo.lastName = customers[j+1].c_PersonalInfo.lastName;
                                                    customers[j].c_PersonalInfo.email = customers[j+1].c_PersonalInfo.email;
                                                    customers[j].c_PersonalInfo.emailPassword = customers[j+1].c_PersonalInfo.emailPassword;
                                                    customers[j].c_PersonalInfo.phoneNumber = customers[j+1].c_PersonalInfo.phoneNumber ;
                                                    customers[j].c_PersonalInfo.favoriteFood = customers[j+1].c_PersonalInfo.favoriteFood ;
                                                }

                                                i--;
                                                sizeC--;

                                                cout << endl << "Mission Completed!" << endl << endl;

                                                printCustomerInfo (customers,sizeC);

                                                tmp = false;
                                            }
                                        }

                                        if(tmp) {

                                            cout << endl << "This person is not our customer!" << endl << endl;
                                        }
                                    }

                                    else if (option == 3) {

                                        string n;                   //id
                                        string f;                   //first name
                                        string l;                   //last name
                                        string p;                   //password
                                        string e;                   //email
                                        string eP;                  //email password
                                        string f2;                  //favorite food
                                        string pN;                  //phone number
                                        char ch;
                                        int c = 0;
                                        bool t = true;
                                        bool tmp = true;

                                        cout << endl << "Please tell us the id of customer : ";
                                        cin >> n;

                                        for (int i = 0; i < sizeC && tmp; i++) {

                                            if (n.compare(customers[i].c_Information.id) == 0) {

                                                while (t) {

                                                    cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                    cout << "1 : Login Password" << endl;
                                                    cout << "2 : Email" << endl;
                                                    cout << "3 : Email Password" << endl;
                                                    cout << "4 : Phone Number" << endl;
                                                    cout << "5 : Favorite Food" << endl;
                                                    cout << "6 : return" << endl << endl;

                                                    cin >> c;

                                                    if (c == 1) {

                                                        cout << endl << "Tell us the new password : ";
                                                        cin >> p;

                                                        if (p.length() >= 8) {

                                                            customers[i].c_Information.password = p;
                                                        }

                                                        else {

                                                            cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                        }
                                                    }

                                                    else if (c == 2) {

                                                        cout << endl << "Tell us the new email address : ";
                                                        cin >> e;

                                                        bool temp = true;

                                                        for (int j = 0; j < sizeC && temp; j++) {

                                                            if (e.compare(customers[j].c_PersonalInfo.email) == 0) {

                                                                cout << endl << "Error : This email has been used!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        for (int j = 0; j < sizeE && temp; j++) {

                                                            if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                                cout << endl << "Error : This email has been used!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        if (temp) {

                                                            customers[i].c_PersonalInfo.email = e;
                                                        }
                                                    }

                                                    else if (c == 3) {

                                                        cout << endl << "Tell us the new email password : ";
                                                        cin >> eP;

                                                        customers[i].c_PersonalInfo.emailPassword = eP;
                                                    }

                                                    else if (c == 4) {

                                                        cout << endl << "Tell us the new phone number : ";
                                                        cin >> pN;

                                                        bool temp = true;

                                                        for (int j = 0; j < sizeC && temp; j++) {

                                                            if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                                cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        for (int j = 0; j < sizeE && temp; j++) {

                                                            if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                                cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                temp = false;
                                                            }
                                                        }

                                                        if (temp) {

                                                            customers[i].c_PersonalInfo.phoneNumber = pN;
                                                        }
                                                    }

                                                    else if (c == 5) {

                                                        cout << endl << "Tell us the favorite food : ";
                                                        cin.get(ch);
                                                        getline (cin , f2);

                                                        customers[i].c_PersonalInfo.favoriteFood = f2;
                                                    }

                                                    else if (c == 6) {

                                                        t = false;
                                                    }

                                                    else {

                                                        cout << endl << "Error : choose one of the options!" << endl << endl;

                                                        t = false;
                                                    }
                                                }

                                                printCustomerInfo (customers,sizeC);

                                                tmp = false;
                                            }
                                        }

                                        if (tmp) {

                                            cout << endl << "This person is not our customer!" << endl << endl;
                                        }
                                    }

                                    else if (option == 4) {

                                        fl = false;
                                    }

                                    else {

                                        cout << endl << "Error : Your choise is not in the definded renge!" << endl << endl;

                                        fl = false;
                                    }
                                }
                            }

                            else if (choice == 5) {

                                string c;
                                bool t = true;

                                cout << endl << "Enter the new discount code : ";
                                cin >> c;

                                for (int i = 0; i < size_c && t; i++) {

                                    if (c.compare(discountCode[i]) == 0) {

                                        cout << endl << "The code exists already!" << endl << endl;

                                        t = false;
                                    }
                                }

                                if (t) {

                                    size_c++;

                                    discountCode[size_c-1] = c;

                                    cout << endl << "Mission Completed!" << endl << endl;

                                    printCode (discountCode,size_c);
                                }
                            }

                            else if (choice == 6) {

                                string n;
                                string e;
                                string pN;
                                bool tmp = true;
                                int search = 0;

                                cout << endl << "Please choose on of the options : " << endl << endl;
                                cout << "1 : search based on ID " << endl;
                                cout << "2 : search based on Email " << endl;
                                cout << "3 : search based on Phone Number " << endl << endl;

                                cin >> search;

                                if (search == 1) {

                                    cout << endl << "Please tell us the id of customer : ";
                                    cin >> n;

                                    for (int i = 0; i < sizeC && tmp; i++) {

                                        if (n.compare(customers[i].c_Information.id) == 0) {

                                            printInvoices (customers,i,size_in,size_info);

                                            tmp = false;
                                        }
                                    }

                                    if (tmp) {

                                        cout << endl << "This person is not a customers!" << endl << endl;
                                    }
                                }

                                else if (search == 2) {

                                    cout << endl << "Please tell us Email of customer : ";
                                    cin >> e;

                                    for (int i = 0; i < sizeC && tmp; i++) {

                                        if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                            printInvoices (customers,i,size_in,size_info);

                                            tmp = false;
                                        }
                                    }

                                    if (tmp) {

                                        cout << endl << "This person is not a customers!" << endl << endl;
                                    }
                                }

                                else if (search == 3) {

                                    cout << endl << "Please tell us Phone Number of customer : ";
                                    cin >> pN;

                                    for (int i = 0; i < sizeC && tmp; i++) {

                                        if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0) {

                                            printInvoices (customers,i,size_in,size_info);

                                            tmp = false;
                                        }
                                    }

                                    if (tmp) {

                                        cout << endl << "This person is not a customers!" << endl << endl;
                                    }
                                }

                                else {

                                    cout << endl << "Error : Invalid choice!" << endl << endl;
                                }
                            }

                            else if (choice == 7) {

                                flag = false;
                            }

                            else {

                                cout << endl << "Error : You have to choose one of the options above!" << endl;

                                flag = false;
                            }
                        }
                    }
                }

                else if (userType == 2) {

                    bool check = true;
                    string d;
                    string pass;

                    cout << endl << "Enter your id : ";
                    cin >> d;

                    cout << endl;

                    cout << endl << "Enter your password : ";
                    cin >> pass;

                    cout << endl;

                    for (int i = 0; i < sizeE && check; i++) {

                        if (d.compare(employees[i].e_Information.id) == 0 && pass.compare(employees[i].e_Information.password) == 0) {

                            bool fl = true;

                            while (fl) {

                                int choice = 0;

                                cout << endl << endl << "Please choose one of the options : " << endl << endl;

                                cout << "1 : view the list of foods along with their prices" << endl;
                                cout << "2 : change the list of available foods along with their prices" << endl;
                                cout << "3 : change your information" << endl;
                                cout << "4 : adding new discount codes" << endl;
                                cout << "5 : view all invoices for previous purchases" << endl;
                                cout << "6 : return to the login page" << endl << endl;

                                cin >> choice;

                                if (choice == 1) {

                                    printmenu (menu,sizeF);
                                }

                                else if (choice == 2) {

                                    string n;
                                    long long int p = 0;
                                    bool tmp = true;
                                    cout << endl << "Please tell us the name of food : ";
                                    cin >> n;

                                    for (int i = 0; i < sizeF && tmp; i++) {

                                        if (n == menu[i].name) {

                                            cout << endl << "Please tell us the new price : ";
                                            cin >> p;

                                            if (p > 0) {

                                                menu[i].price = p;

                                                printmenu(menu,sizeF);

                                                tmp = false;
                                            }

                                            else {

                                                cout << endl << "Error!" << endl << endl;

                                                tmp = false;
                                            }
                                        }
                                    }

                                    if (tmp) {

                                        cout << endl << "The food is not in the list!" << endl << endl;
                                    }
                                }

                                else if (choice == 3) {

                                    string f;                   //first name
                                    string l;                   //last name
                                    string p;                   //password
                                    string e;                   //email
                                    string eP;                  //email password
                                    string f2;                  //favorite food
                                    string pN;                  //phone number
                                    char ch;
                                    int c = 0;
                                    bool t = true;

                                    for (int i = 0; i < sizeE; i++) {

                                        if (d.compare(employees[i].e_Information.id) == 0) {

                                            while (t) {

                                                cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                cout << "1 : Login Password" << endl;
                                                cout << "2 : Email" << endl;
                                                cout << "3 : Email Password" << endl;
                                                cout << "4 : Phone Number" << endl;
                                                cout << "5 : Favorite Food" << endl;
                                                cout << "6 : return" << endl << endl;

                                                cin >> c;

                                                if (c == 1) {

                                                    cout << endl << "Tell us the new password : ";
                                                    cin >> p;

                                                    if (p.length() >= 8) {

                                                        employees[i].e_Information.password = p;
                                                    }

                                                    else {

                                                        cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                    }
                                                }

                                                else if (c == 2) {

                                                    bool temp = true;

                                                    cout << endl << "Tell us the new email address : ";
                                                    cin >> e;

                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                        if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                            cout << endl << "Error : This email has been used!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }

                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                        if (e.compare(customers[j].c_PersonalInfo.email) == 0) {

                                                            cout << endl << "Error : This email has been used!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }
                                                    if (temp) {

                                                        employees[i].e_PersonalInfo.email = e;
                                                    }
                                                }

                                                else if (c == 3) {

                                                    cout << endl << "Tell us the new email password : ";
                                                    cin >> eP;

                                                    employees[i].e_PersonalInfo.emailPassword = eP;
                                                }

                                                else if (c == 4) {

                                                    bool temp = true;

                                                    cout << endl << "Tell us the new phone number : ";
                                                    cin >> pN;

                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                        if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }

                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                        if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }

                                                    if (temp) {

                                                        employees[i].e_PersonalInfo.phoneNumber = pN;
                                                    }
                                                }

                                                else if (c == 5) {

                                                    cout << endl << "Tell us the favorite food : ";
                                                    cin.get(ch);
                                                    getline (cin , f2);

                                                    employees[i].e_PersonalInfo.favoriteFood = f2;
                                                }

                                                else if (c == 6) {

                                                    t = false;
                                                }

                                                else {

                                                    cout << endl << "Error : choose one of the options!" << endl << endl;

                                                    t = false;
                                                }
                                            }

                                            employees[i].e_PersonalInfo.fullName = employees[i].e_PersonalInfo.firstName + ' ' + employees[i].e_PersonalInfo.lastName;
                                            cout << endl << "Your information are :" << endl << endl;
                                            cout << "Name : " << employees[i].e_PersonalInfo.fullName << endl << endl;
                                            cout << "ID : " << employees[i].e_Information.id << endl << endl;
                                            cout << "Login Password : " << employees[i].e_Information.password << endl << endl;
                                            cout << "Email : " << employees[i].e_PersonalInfo.email << endl << endl;
                                            cout << "Email Password : " << employees[i].e_PersonalInfo.emailPassword << endl << endl;
                                            cout << "Phone Number : " << employees[i].e_PersonalInfo.phoneNumber << endl << endl;
                                            cout << "Favorite Food : " << employees[i].e_PersonalInfo.favoriteFood << endl << endl;
                                        }
                                    }
                                }

                                else if (choice == 4) {

                                    string c;
                                    bool t = true;

                                    cout << endl << "Enter the new discount code : ";
                                    cin >> c;

                                    for (int i = 0; i < size_c && t; i++) {

                                        if (c.compare(discountCode[i]) == 0) {

                                            cout << endl << "The code exists already!" << endl << endl;

                                            t = false;
                                        }
                                    }

                                    if (t) {

                                        size_c++;

                                        discountCode[size_c-1] = c;

                                        cout << endl << "Mission Completed!" << endl << endl;

                                        printCode (discountCode,size_c);
                                    }
                                }

                                else if (choice == 5) {

                                    string n;
                                    bool temp = true;

                                    cout << endl << "Please tell us the id of customer : ";
                                    cin >> n;

                                    for (int i = 0; i < sizeC && temp; i++) {

                                        if (n.compare(customers[i].c_Information.id) == 0) {

                                            printInvoices (customers,i,size_in,size_info);

                                            temp = false;
                                        }
                                    }

                                    if (temp) {

                                        cout << endl << "The person is not our customer!" << endl << endl;
                                    }
                                }

                                else if (choice == 6) {

                                    fl = false;
                                }

                                else {

                                    cout << endl << "Error : You have to choose one of the options above!" << endl;

                                    fl = false;
                                }
                            }

                            check = false;
                        }
                    }

                    if (check) {

                        int forget;

                        cout << endl << "Error : Invalid Inputs!" << endl;

                        cout << endl << "If you have forgoten your login inforamtion enter '1' if not enter '0' : ";
                        cin >> forget;
                        cout << endl;

                        if (forget == 1) {

                            string e;

                            cout << endl << "Tell us your email : ";
                            cin >> e;
                            cout << endl;
                            cout << endl << "Tell us your email password : ";
                            cin >> pass;

                            for (int i = 0; i < sizeE && check; i++) {

                                if (e.compare(employees[i].e_PersonalInfo.email) == 0 && pass.compare(employees[i].e_PersonalInfo.emailPassword) == 0) {

                                    bool fl = true;

                                    while (fl) {

                                        int choice = 0;

                                        cout << endl << endl << "Please choose one of the options : " << endl << endl;

                                        cout << "1 : view the list of foods along with their prices" << endl;
                                        cout << "2 : change the list of available foods along with their prices" << endl;
                                        cout << "3 : change your information" << endl;
                                        cout << "4 : adding new discount codes" << endl;
                                        cout << "5 : view all invoices for previous purchases" << endl;
                                        cout << "6 : return to the login page" << endl << endl;

                                        cin >> choice;

                                        if (choice == 1) {

                                            printmenu (menu,sizeF);
                                        }

                                        else if (choice == 2) {

                                            string n;
                                            long long int p = 0;
                                            bool tmp = true;
                                            cout << endl << "Please tell us the name of food : ";
                                            cin >> n;

                                            for (int i = 0; i < sizeF && tmp; i++) {

                                                if (n == menu[i].name) {

                                                    cout << endl << "Please tell us the new price : ";
                                                    cin >> p;

                                                    if (p > 0) {

                                                        menu[i].price = p;

                                                        printmenu(menu,sizeF);

                                                        tmp = false;
                                                    }

                                                    else {

                                                        cout << endl << "Error!" << endl << endl;

                                                        tmp = false;
                                                    }
                                                }
                                            }

                                            if (tmp) {

                                                cout << endl << "The food is not in the list!" << endl << endl;
                                            }
                                        }

                                        else if (choice == 3) {

                                            string f;                   //first name
                                            string l;                   //last name
                                            string p;                   //password
                                            string e;                   //email
                                            string eP;                  //email password
                                            string f2;                  //favorite food
                                            string pN;                  //phone number
                                            char ch;
                                            int c = 0;
                                            bool t = true;

                                            for (int i = 0; i < sizeE; i++) {

                                                if (d.compare(employees[i].e_Information.id) == 0) {

                                                    while (t) {

                                                        cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                        cout << "1 : Login Password" << endl;
                                                        cout << "2 : Email" << endl;
                                                        cout << "3 : Email Password" << endl;
                                                        cout << "4 : Phone Number" << endl;
                                                        cout << "5 : Favorite Food" << endl;
                                                        cout << "6 : return" << endl << endl;

                                                        cin >> c;

                                                        if (c == 1) {

                                                            cout << endl << "Tell us the new password : ";
                                                            cin >> p;

                                                            if (p.length() >= 8) {

                                                                employees[i].e_Information.password = p;
                                                            }

                                                            else {

                                                                cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                            }
                                                        }

                                                        else if (c == 2) {

                                                            bool temp = true;

                                                            cout << endl << "Tell us the new email address : ";
                                                            cin >> e;

                                                            for (int j = 0; j < sizeE && temp; j++) {

                                                                if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                                    cout << endl << "Error : This email has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int j = 0; j < sizeC && temp; j++) {

                                                                if (e.compare(customers[j].c_PersonalInfo.email) == 0) {

                                                                    cout << endl << "Error : This email has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }
                                                            if (temp) {

                                                                employees[i].e_PersonalInfo.email = e;
                                                            }
                                                        }

                                                        else if (c == 3) {

                                                            cout << endl << "Tell us the new email password : ";
                                                            cin >> eP;

                                                            employees[i].e_PersonalInfo.emailPassword = eP;
                                                        }

                                                        else if (c == 4) {

                                                            bool temp = true;

                                                            cout << endl << "Tell us the new phone number : ";
                                                            cin >> pN;

                                                            for (int j = 0; j < sizeE && temp; j++) {

                                                                if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int j = 0; j < sizeC && temp; j++) {

                                                                if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                employees[i].e_PersonalInfo.phoneNumber = pN;
                                                            }
                                                        }

                                                        else if (c == 5) {

                                                            cout << endl << "Tell us the favorite food : ";
                                                            cin.get(ch);
                                                            getline (cin , f2);

                                                            employees[i].e_PersonalInfo.favoriteFood = f2;
                                                        }

                                                        else if (c == 6) {

                                                            t = false;
                                                        }

                                                        else {

                                                            cout << endl << "Error : choose one of the options!" << endl << endl;

                                                            t = false;
                                                        }
                                                    }

                                                    employees[i].e_PersonalInfo.fullName = employees[i].e_PersonalInfo.firstName + ' ' + employees[i].e_PersonalInfo.lastName;
                                                    cout << endl << "Your information are :" << endl << endl;
                                                    cout << "Name : " << employees[i].e_PersonalInfo.fullName << endl << endl;
                                                    cout << "ID : " << employees[i].e_Information.id << endl << endl;
                                                    cout << "Login Password : " << employees[i].e_Information.password << endl << endl;
                                                    cout << "Email : " << employees[i].e_PersonalInfo.email << endl << endl;
                                                    cout << "Email Password : " << employees[i].e_PersonalInfo.emailPassword << endl << endl;
                                                    cout << "Phone Number : " << employees[i].e_PersonalInfo.phoneNumber << endl << endl;
                                                    cout << "Favorite Food : " << employees[i].e_PersonalInfo.favoriteFood << endl << endl;
                                                }
                                            }
                                        }

                                        else if (choice == 4) {

                                            string c;
                                            bool t = true;

                                            cout << endl << "Enter the new discount code : ";
                                            cin >> c;

                                            for (int i = 0; i < size_c && t; i++) {

                                                if (c.compare(discountCode[i]) == 0) {

                                                    cout << endl << "The code exists already!" << endl << endl;

                                                    t = false;
                                                }
                                            }

                                            if (t) {

                                                size_c++;

                                                discountCode[size_c-1] = c;

                                                cout << endl << "Mission Completed!" << endl << endl;

                                                printCode (discountCode,size_c);
                                            }
                                        }

                                        else if (choice == 5) {

                                            string n;
                                            bool temp = true;

                                            cout << endl << "Please tell us the id of customer : ";
                                            cin >> n;

                                            for (int i = 0; i < sizeC && temp; i++) {

                                                if (n.compare(customers[i].c_Information.id) == 0) {

                                                    printInvoices (customers,i,size_in,size_info);

                                                    temp = false;
                                                }
                                            }

                                            if (temp) {

                                                cout << endl << "The person is not our customer!" << endl << endl;
                                            }
                                        }

                                        else if (choice == 6) {

                                            fl = false;
                                        }

                                        else {

                                            cout << endl << "Error : You have to choose one of the options above!" << endl;

                                            fl = false;
                                        }
                                    }

                                    check = false;
                                }
                            }

                            if (check) {

                                int sure = 0;
                                string pN;
                                string f2;

                                cout << endl << "Invalid Inputs!" << endl << endl;
                                cout << endl << "If you are sure about being registered enter '1' if not enter '0' : ";
                                cin >> sure;

                                if (sure == 1) {

                                    check = true;
                                    cout << endl << "Tell us your phone number : ";
                                    cin >> pN;
                                    cout << endl;
                                    cout << endl << "Now tell us your favorite food : ";
                                    cin >> f2;
                                    cout << endl;

                                    for (int i = 0; i < sizeE && check; i++) {

                                        if (pN.compare(employees[i].e_PersonalInfo.phoneNumber) == 0 && f2.compare(employees[i].e_PersonalInfo.favoriteFood) == 0) {

                                            bool fl = true;

                                            while (fl) {

                                                int choice = 0;

                                                cout << endl << endl << "Please choose one of the options : " << endl << endl;

                                                cout << "1 : view the list of foods along with their prices" << endl;
                                                cout << "2 : change the list of available foods along with their prices" << endl;
                                                cout << "3 : change your information" << endl;
                                                cout << "4 : adding new discount codes" << endl;
                                                cout << "5 : view all invoices for previous purchases" << endl;
                                                cout << "6 : return to the login page" << endl << endl;

                                                cin >> choice;

                                                if (choice == 1) {

                                                    printmenu (menu,sizeF);
                                                }

                                                else if (choice == 2) {

                                                    string n;
                                                    long long int p = 0;
                                                    bool tmp = true;
                                                    cout << endl << "Please tell us the name of food : ";
                                                    cin >> n;

                                                    for (int i = 0; i < sizeF && tmp; i++) {

                                                        if (n == menu[i].name) {

                                                            cout << endl << "Please tell us the new price : ";
                                                            cin >> p;

                                                            if (p > 0) {

                                                                menu[i].price = p;

                                                                printmenu(menu,sizeF);

                                                                tmp = false;
                                                            }

                                                            else {

                                                                cout << endl << "Error!" << endl << endl;

                                                                tmp = false;
                                                            }
                                                        }
                                                    }

                                                    if (tmp) {

                                                        cout << endl << "The food is not in the list!" << endl << endl;
                                                    }
                                                }

                                                else if (choice == 3) {

                                                    string f;                   //first name
                                                    string l;                   //last name
                                                    string p;                   //password
                                                    string e;                   //email
                                                    string eP;                  //email password
                                                    string f2;                  //favorite food
                                                    string pN;                  //phone number
                                                    char ch;
                                                    int c = 0;
                                                    bool t = true;

                                                    for (int i = 0; i < sizeE; i++) {

                                                        if (d.compare(employees[i].e_Information.id) == 0) {

                                                            while (t) {

                                                                cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                                cout << "1 : Login Password" << endl;
                                                                cout << "2 : Email" << endl;
                                                                cout << "3 : Email Password" << endl;
                                                                cout << "4 : Phone Number" << endl;
                                                                cout << "5 : Favorite Food" << endl;
                                                                cout << "6 : return" << endl << endl;

                                                                cin >> c;

                                                                if (c == 1) {

                                                                    cout << endl << "Tell us the new password : ";
                                                                    cin >> p;

                                                                    if (p.length() >= 8) {

                                                                        employees[i].e_Information.password = p;
                                                                    }

                                                                    else {

                                                                        cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                                    }
                                                                }

                                                                else if (c == 2) {

                                                                    bool temp = true;

                                                                    cout << endl << "Tell us the new email address : ";
                                                                    cin >> e;

                                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                                        if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                                            cout << endl << "Error : This email has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                                        if (e.compare(customers[j].c_PersonalInfo.email) == 0) {

                                                                            cout << endl << "Error : This email has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }
                                                                    if (temp) {

                                                                        employees[i].e_PersonalInfo.email = e;
                                                                    }
                                                                }

                                                                else if (c == 3) {

                                                                    cout << endl << "Tell us the new email password : ";
                                                                    cin >> eP;

                                                                    employees[i].e_PersonalInfo.emailPassword = eP;
                                                                }

                                                                else if (c == 4) {

                                                                    bool temp = true;

                                                                    cout << endl << "Tell us the new phone number : ";
                                                                    cin >> pN;

                                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                                        if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                                        if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    if (temp) {

                                                                        employees[i].e_PersonalInfo.phoneNumber = pN;
                                                                    }
                                                                }

                                                                else if (c == 5) {

                                                                    cout << endl << "Tell us the favorite food : ";
                                                                    cin.get(ch);
                                                                    getline (cin , f2);

                                                                    employees[i].e_PersonalInfo.favoriteFood = f2;
                                                                }

                                                                else if (c == 6) {

                                                                    t = false;
                                                                }

                                                                else {

                                                                    cout << endl << "Error : choose one of the options!" << endl << endl;

                                                                    t = false;
                                                                }
                                                            }

                                                            employees[i].e_PersonalInfo.fullName = employees[i].e_PersonalInfo.firstName + ' ' + employees[i].e_PersonalInfo.lastName;
                                                            cout << endl << "Your information are :" << endl << endl;
                                                            cout << "Name : " << employees[i].e_PersonalInfo.fullName << endl << endl;
                                                            cout << "ID : " << employees[i].e_Information.id << endl << endl;
                                                            cout << "Login Password : " << employees[i].e_Information.password << endl << endl;
                                                            cout << "Email : " << employees[i].e_PersonalInfo.email << endl << endl;
                                                            cout << "Email Password : " << employees[i].e_PersonalInfo.emailPassword << endl << endl;
                                                            cout << "Phone Number : " << employees[i].e_PersonalInfo.phoneNumber << endl << endl;
                                                            cout << "Favorite Food : " << employees[i].e_PersonalInfo.favoriteFood << endl << endl;
                                                        }
                                                    }
                                                }

                                                else if (choice == 4) {

                                                    string c;
                                                    bool t = true;

                                                    cout << endl << "Enter the new discount code : ";
                                                    cin >> c;

                                                    for (int i = 0; i < size_c && t; i++) {

                                                        if (c.compare(discountCode[i]) == 0) {

                                                            cout << endl << "The code exists already!" << endl << endl;

                                                            t = false;
                                                        }
                                                    }

                                                    if (t) {

                                                        size_c++;

                                                        discountCode[size_c-1] = c;

                                                        cout << endl << "Mission Completed!" << endl << endl;

                                                        printCode (discountCode,size_c);
                                                    }
                                                }

                                                else if (choice == 5) {

                                                    string n;
                                                    bool temp = true;

                                                    cout << endl << "Please tell us the id of customer : ";
                                                    cin >> n;

                                                    for (int i = 0; i < sizeC && temp; i++) {

                                                        if (n.compare(customers[i].c_Information.id) == 0) {

                                                            printInvoices (customers,i,size_in,size_info);

                                                            temp = false;
                                                        }
                                                    }

                                                    if (temp) {

                                                        cout << endl << "The person is not our customer!" << endl << endl;
                                                    }
                                                }

                                                else if (choice == 6) {

                                                    fl = false;
                                                }

                                                else {

                                                    cout << endl << "Error : You have to choose one of the options above!" << endl;

                                                    fl = false;
                                                }
                                            }

                                            check = false;
                                        }
                                    }

                                    if (check) {

                                        cout << endl << "It seems like you haven't been registered!"
                                                        " So please visit the Administration!" << endl << endl;
                                    }
                                }

                                else {

                                    check = false;
                                }
                            }
                        }

                        else {

                            check = false;
                        }
                    }
                }

                else if (userType == 3) {

                    bool tmp = true;
                    bool fl = true;
                    string n;
                    string pass;

                    cout << endl << "Please Enter your id : ";
                    cin >> n;
                    cout << endl;
                    cout << endl << "Now enter your password : ";
                    cin >> pass;
                    cout << endl;

                    for (int i = 0; i < sizeC && tmp; i++) {

                        if (n.compare(customers[i].c_Information.id) == 0 && pass.compare(customers[i].c_Information.password) == 0) {

                            while (fl) {

                                int choice = 0;

                                cout << endl << endl << "Please choose one of the options : " << endl << endl;

                                cout << "1 : view the list of foods along with their prices" << endl;
                                cout << "2 : add and remove food from the cart" << endl;
                                cout << "3 : final registration of purchase and payment" << endl;
                                cout << "4 : change your information" << endl;
                                cout << "5 : charge the wallet" << endl;
                                cout << "6 : view all your invoices for previous purchases" << endl;
                                cout << "7 : return to the login page" << endl << endl;

                                cin >> choice;

                                if (choice == 1) {

                                    printmenu (menu , sizeF);
                                }

                                else if (choice == 2) {

                                    bool orderType = true;
                                    int act = 0;

                                    while (orderType) {

                                        cout << endl << "choose one of the actions :" << endl;
                                        cout << endl << "1 : add" << endl;
                                        cout << endl << "2 : remove" << endl;
                                        cout << endl << "3 : return" << endl << endl;

                                        cin >> act;

                                        if (act == 1) {

                                            string order;
                                            bool temp = true;

                                            cout << endl << "Please tell us your new order : ";

                                            char ch;
                                            cin.get(ch);
                                            getline (cin,order);

                                            for (int k = 0; k < sizeF && temp; k++) {

                                                if (order.compare(menu[k].name) == 0) {

                                                    size_cart++;
                                                    customers[i].cart[size_cart-1].name = order;
                                                    customers[i].cart[size_cart-1].price = menu[k].price;

                                                    cout << endl << "Mission Completed!" << endl << endl;

                                                    printCart (customers,i,size_cart);

                                                    cout << endl << endl;

                                                    temp = false;
                                                }
                                            }

                                            if (temp) {

                                                cout << endl << "Sorry the food is not in the menu!" << endl << endl;
                                            }
                                        }

                                        else if (act == 2) {

                                            if (size_cart != 0) {

                                                string order;
                                                bool temp = true;

                                                printCart (customers,i,size_cart);

                                                cout << endl << "Please tell us which food do you want to remove : ";
                                                cin >> order;

                                                for (int k = 0; k < size_cart && temp; k++) {

                                                    if (order.compare(customers[i].cart[k].name) == 0) {

                                                        for (int j = k; j < size_cart-1; j++) {

                                                            customers[i].cart[j].name = customers[i].cart[j+1].name;
                                                            customers[i].cart[j].price = customers[i].cart[j+1].price;
                                                        }

                                                        k--;
                                                        size_cart--;

                                                        cout << endl << "Mission Completed!" << endl << endl;

                                                        printCart (customers,i,size_cart);

                                                        temp = false;
                                                    }
                                                }

                                                if (temp) {

                                                    cout << endl << "This Food is not in your cart!" << endl << endl;
                                                }
                                            }

                                            else {

                                                cout << endl << "Your cart is empty! :(" << endl << endl;
                                            }
                                        }

                                        else {

                                            orderType = false;
                                        }
                                    }
                                }

                                else if (choice == 3) {

                                    bool temp = true;
                                    int act = 0;
                                    long long unsigned int sum = 0;
                                    long long unsigned int total = 0;

                                    printCart (customers,i,size_cart);

                                    for (int k = 0; k < size_cart; k++) {

                                        sum += customers[i].cart[k].price;
                                    }

                                    customers[i].invoice_c[size_in].totalPrice = sum;

                                    for (int k = 0; k < size_in; k++) {

                                        total += customers[i].invoice_c[k].totalPrice;
                                    }

                                    cout << endl << "Total price of your orders is : " << sum << endl;

                                    while (temp) {

                                        cout << endl << "which action would you like to take :" << endl << endl;

                                        cout << "1 : final registration of purchase and payment" << endl;
                                        cout << "2 : return" << endl << endl;

                                        cin >> act;

                                        if (act == 1) {

                                            int x = 0;

                                            cout << endl << "If you have discount code enter '1' if not enter '0' : ";
                                            cin >> x;

                                            if (x == 1) {

                                                string c;
                                                bool check = true;

                                                cout << endl << "Enter the discount code : ";
                                                cin >> c;

                                                for (int k = 0; k < size_c && check; k++) {

                                                    if (c.compare(discountCode[k]) == 0) {

                                                        sum = (sum * 5) / 10;

                                                        for (int j = k; j < size_c-1; j++) {

                                                            discountCode[j] = discountCode[j+1];
                                                        }

                                                        k--;
                                                        size_c--;

                                                        cout << endl << "discount code applied successfully!" << endl << endl;

                                                        if (sum > customers[i].wallet) {

                                                            cout << endl << "But unfortunately you still don't have enough money!" << endl;
                                                            cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                            sum = (sum * 10) / 5;

                                                            size_c++;
                                                            discountCode[size_c-1] = c;
                                                        }

                                                        else {

                                                            int sure = 0;

                                                            cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                            cin >> sure;

                                                            if (sure == 1) {

                                                                customers[i].invoice_c[size_in].totalPrice = sum;
                                                                customers[i].wallet -= sum;
                                                                addToFactor(customers,i,size_cart,size_info,size_in);
                                                                size_in++;
                                                                sum = 0;
                                                                size_cart = 0;

                                                                cout << endl << "Mission Completed!" << endl;
                                                                cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                            }

                                                            else {

                                                                sum = (sum * 10) / 5;

                                                                size_c++;
                                                                discountCode[size_c-1] = c;

                                                                check = false;
                                                            }
                                                        }

                                                        check = false;
                                                    }
                                                }

                                                if (check) {

                                                    cout << endl << "Sorry this code has been expired!" << endl << endl;

                                                    if (total >= 150000) {

                                                        cout << endl << "You still can get 20% discount becouse of your previous purchases :)" << endl << endl;

                                                        sum = (sum * 8) / 10;

                                                        cout << endl << "discount applied successfully!" << endl << endl;

                                                        if (sum > customers[i].wallet) {

                                                            sum = (sum * 10) / 8;

                                                            cout << endl << "But unfortunately you still don't have enough money!" << endl;
                                                            cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;
                                                        }

                                                        else {

                                                            int sure = 0;

                                                            cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                            cin >> sure;

                                                            if (sure == 1) {

                                                                customers[i].invoice_c[size_in].totalPrice = sum;
                                                                customers[i].wallet -= sum;
                                                                addToFactor(customers,i,size_cart,size_info,size_in);
                                                                size_in++;
                                                                sum = 0;
                                                                size_cart = 0;

                                                                cout << endl << "Mission Completed!" << endl;
                                                                cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                            }

                                                            else {

                                                                sum = (sum * 10) / 8;

                                                                temp = false;
                                                            }
                                                        }
                                                    }

                                                    else {

                                                        if (sum > customers[i].wallet) {

                                                            cout << endl << "And unfortunately you don't have enough money!" << endl;
                                                            cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;
                                                        }

                                                        else {

                                                            int sure = 0;

                                                            cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                            cin >> sure;

                                                            if (sure == 1) {

                                                                customers[i].invoice_c[size_in].totalPrice = sum;
                                                                customers[i].wallet -= sum;
                                                                addToFactor(customers,i,size_cart,size_info,size_in);
                                                                size_in++;
                                                                sum = 0;
                                                                size_cart = 0;

                                                                cout << endl << "Mission Completed!" << endl;
                                                                cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                            }

                                                            else {

                                                                temp = false;
                                                            }
                                                        }
                                                    }
                                                }
                                            }

                                            else if (x == 0) {

                                                if (total >= 150000) {

                                                    sum = (sum * 8) / 10;

                                                    cout << endl << "*** Congratulation! ***" << endl;
                                                    cout << endl << "Becouse of your previous purchases you got 20% discount!" << endl;
                                                    cout << endl << "Now total price of your orders is : " << sum << endl << endl;

                                                    if (sum > customers[i].wallet) {

                                                        sum = (sum * 10) / 8;

                                                        cout << endl << "But unfortunately you don't have enough money!" << endl;
                                                        cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                        temp = false;
                                                    }

                                                    else {

                                                        int sure = 0;

                                                        cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                        cin >> sure;

                                                        if (sure == 1) {

                                                            customers[i].invoice_c[size_in].totalPrice = sum;
                                                            customers[i].wallet -= sum;
                                                            addToFactor(customers,i,size_cart,size_info,size_in);
                                                            size_in++;
                                                            sum = 0;
                                                            size_cart = 0;

                                                            cout << endl << "Mission Completed!" << endl;
                                                            cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                        }

                                                        else {

                                                            temp = false;
                                                        }
                                                    }
                                                }

                                                else {

                                                    if (sum > customers[i].wallet) {

                                                        cout << endl << "Sorry but you don't have enough money!" << endl;
                                                        cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                        temp = false;
                                                    }

                                                    else {

                                                        int sure = 0;

                                                        cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                        cin >> sure;

                                                        if (sure == 1) {

                                                            customers[i].invoice_c[size_in].totalPrice = sum;
                                                            customers[i].wallet -= sum;
                                                            addToFactor(customers,i,size_cart,size_info,size_in);
                                                            size_in++;
                                                            sum = 0;
                                                            size_cart = 0;

                                                            cout << endl << "Mission Completed!" << endl;
                                                            cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                        }

                                                        else {

                                                            temp = false;
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        else {

                                            temp = false;
                                        }
                                    }
                                }

                                else if (choice == 4) {

                                    string p;                   //password
                                    string e;                   //email
                                    string eP;                  //email password
                                    string f2;                  //favorite food
                                    string pN;                  //phone number
                                    char ch;
                                    int c = 0;
                                    bool t = true;

                                    for (int i = 0; i < sizeC; i++) {

                                        if (n.compare(customers[i].c_Information.id) == 0) {

                                            while (t) {

                                                cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                cout << "1 : Login Password" << endl;
                                                cout << "2 : Email" << endl;
                                                cout << "3 : Email Password" << endl;
                                                cout << "4 : Phone Number" << endl;
                                                cout << "5 : Favorite Food" << endl;
                                                cout << "6 : return" << endl << endl;

                                                cin >> c;

                                                if (c == 1) {

                                                    cout << endl << "Tell us the new password : ";
                                                    cin >> p;

                                                    if (p.length() >= 8) {

                                                        customers[i].c_Information.password = p;
                                                    }

                                                    else {

                                                        cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                    }
                                                }

                                                else if (c == 2) {

                                                    bool temp = true;

                                                    cout << endl << "Tell us the new email address : ";
                                                    cin >> e;

                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                        if (e.compare(customers[j].c_PersonalInfo.email) == 0) {

                                                            cout << endl << "Error : This email has been taken!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }

                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                        if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                            cout << endl << "Error : This email has been taken!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }

                                                    if (temp) {

                                                        customers[i].c_PersonalInfo.email = e;
                                                    }
                                                }

                                                else if (c == 3) {

                                                    cout << endl << "Tell us the new email password : ";
                                                    cin >> eP;

                                                    customers[i].c_PersonalInfo.emailPassword = eP;
                                                }

                                                else if (c == 4) {

                                                    bool temp = true;

                                                    cout << endl << "Tell us the new phone number : ";
                                                    cin >> pN;

                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                        if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }

                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                        if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                            temp = false;
                                                        }
                                                    }

                                                    if (temp) {

                                                        customers[i].c_PersonalInfo.phoneNumber = pN;
                                                    }
                                                }

                                                else if (c == 5) {

                                                    cout << endl << "Tell us the favorite food : ";
                                                    cin.get(ch);
                                                    getline (cin , f2);

                                                    customers[i].c_PersonalInfo.favoriteFood = f2;
                                                }

                                                else if (c == 6) {

                                                    t = false;
                                                }

                                                else {

                                                    cout << endl << "Error : choose one of the options!" << endl << endl;

                                                    t = false;
                                                }
                                            }

                                            cout << endl;
                                            cout << "------------------------" << endl << endl;
                                            cout << " Your information are : " << endl << endl;
                                            cout << "------------------------" << endl << endl;
                                            cout << "Name : " << customers[i].c_PersonalInfo.fullName << endl << endl;
                                            cout << "ID : " << customers[i].c_Information.id << endl << endl;
                                            cout << "Login Password : " << customers[i].c_Information.password << endl << endl;
                                            cout << "Email Address : " << customers[i].c_PersonalInfo.email << endl << endl;
                                            cout << "Email Password : " << customers[i].c_PersonalInfo.emailPassword << endl << endl;
                                            cout << "Phone Number : " << customers[i].c_PersonalInfo.phoneNumber << endl << endl;
                                            cout << "Favorite Food : " << customers[i].c_PersonalInfo.favoriteFood << endl << endl;
                                        }
                                    }
                                }

                                else if (choice == 5) {

                                    long long int deposit;

                                    cout << endl << "Please enter the deposit amount : ";
                                    cin >> deposit;

                                    if (deposit >= 0) {

                                        customers[i].wallet += deposit;

                                        cout << endl << "------------------" << endl;
                                        cout << endl << "Mission Completed!" << endl;
                                        cout << endl << "Now you have " << " ' " << customers[i].wallet << " ' " << " Toman in your wallet" << endl;
                                        cout << endl << "Have a nice day :)" << endl;
                                        cout << endl << "------------------" << endl;
                                    }

                                    else {

                                        cout << endl << "Error!" << endl << endl;
                                    }
                                }

                                else if (choice == 6) {

                                    long long int total = 0;

                                    for (int k = 0; k < size_in; k++) {

                                        total += customers[i].invoice_c[k].totalPrice;
                                    }

                                    printInvoices (customers,i,size_in,size_info);

                                    cout << endl << "Total price of your food invoices is : " << total << endl << endl;
                                }

                                else if (choice == 7) {

                                    fl = false;
                                }

                                else {

                                    cout << endl << "Error : You have to choose one of the options above!" << endl;

                                    fl = false;
                                }
                            }

                            tmp = false;
                        }
                    }

                    if (tmp) {

                        int forget = 0;

                        cout << endl << "Invalid Inputs!" << endl << endl;

                        cout << endl << "If you have forgoten your login inforamtion enter '1' if not enter '0' : ";
                        cin >> forget;
                        cout << endl;

                        if (forget == 1) {

                            string e;
                            string pass;

                            cout << endl << "Tell us your email : ";
                            cin >> e;
                            cout << endl;
                            cout << endl << "Tell us your email password : ";
                            cin >> pass;

                            for (int i = 0; i < sizeC && tmp; i++) {

                                if (e.compare(customers[i].c_PersonalInfo.email) == 0 && pass.compare(customers[i].c_PersonalInfo.emailPassword) == 0) {

                                    bool fl = true;

                                    while (fl) {

                                        int choice = 0;

                                        cout << endl << endl << "Please choose one of the options : " << endl << endl;

                                        cout << "1 : view the list of foods along with their prices" << endl;
                                        cout << "2 : add and remove food from the cart" << endl;
                                        cout << "3 : final registration of purchase and payment" << endl;
                                        cout << "4 : change your information" << endl;
                                        cout << "5 : charge the wallet" << endl;
                                        cout << "6 : view all your invoices for previous purchases" << endl;
                                        cout << "7 : return to the login page" << endl << endl;

                                        cin >> choice;

                                        if (choice == 1) {

                                            printmenu (menu , sizeF);
                                        }

                                        else if (choice == 2) {

                                            bool orderType = true;
                                            int act = 0;

                                            while (orderType) {

                                                cout << endl << "choose one of the actions :" << endl;
                                                cout << endl << "1 : add" << endl;
                                                cout << endl << "2 : remove" << endl;
                                                cout << endl << "3 : return" << endl << endl;

                                                cin >> act;

                                                if (act == 1) {

                                                    string order;
                                                    bool temp = true;

                                                    cout << endl << "Please tell us your new order : ";

                                                    char ch;
                                                    cin.get(ch);
                                                    getline (cin,order);

                                                    for (int k = 0; k < sizeF && temp; k++) {

                                                        if (order.compare(menu[k].name) == 0) {

                                                            size_cart++;
                                                            customers[i].cart[size_cart-1].name = order;
                                                            customers[i].cart[size_cart-1].price = menu[k].price;

                                                            cout << endl << "Mission Completed!" << endl << endl;

                                                            printCart (customers,i,size_cart);

                                                            cout << endl << endl;

                                                            temp = false;
                                                        }
                                                    }

                                                    if (temp) {

                                                        cout << endl << "Sorry the food is not in the menu!" << endl << endl;
                                                    }
                                                }

                                                else if (act == 2) {

                                                    if (size_cart != 0) {

                                                        string order;
                                                        bool temp = true;

                                                        printCart (customers,i,size_cart);

                                                        cout << endl << "Please tell us which food do you want to remove : ";
                                                        cin >> order;

                                                        for (int k = 0; k < size_cart && temp; k++) {

                                                            if (order.compare(customers[i].cart[k].name) == 0) {

                                                                for (int j = k; j < size_cart-1; j++) {

                                                                    customers[i].cart[j].name = customers[i].cart[j+1].name;
                                                                    customers[i].cart[j].price = customers[i].cart[j+1].price;
                                                                }

                                                                k--;
                                                                size_cart--;

                                                                cout << endl << "Mission Completed!" << endl << endl;

                                                                printCart (customers,i,size_cart);

                                                                temp = false;
                                                            }
                                                        }

                                                        if (temp) {

                                                            cout << endl << "This Food is not in your cart!" << endl << endl;
                                                        }
                                                    }

                                                    else {

                                                        cout << endl << "Your cart is empty! :(" << endl << endl;
                                                    }
                                                }

                                                else {

                                                    orderType = false;
                                                }
                                            }
                                        }

                                        else if (choice == 3) {

                                            bool temp = true;
                                            int act = 0;
                                            long long unsigned int sum = 0;
                                            long long unsigned int total = 0;

                                            printCart (customers,i,size_cart);

                                            for (int k = 0; k < size_cart; k++) {

                                                sum += customers[i].cart[k].price;
                                            }

                                            customers[i].invoice_c[size_in].totalPrice = sum;

                                            for (int k = 0; k < size_in; k++) {

                                                total += customers[i].invoice_c[k].totalPrice;
                                            }

                                            cout << endl << "Total price of your orders is : " << sum << endl;

                                            while (temp) {

                                                cout << endl << "which action would you like to take :" << endl << endl;

                                                cout << "1 : final registration of purchase and payment" << endl;
                                                cout << "2 : return" << endl << endl;

                                                cin >> act;

                                                if (act == 1) {

                                                    int x = 0;

                                                    cout << endl << "If you have discount code enter '1' if not enter '0' : ";
                                                    cin >> x;

                                                    if (x == 1) {

                                                        string c;
                                                        bool check = true;

                                                        cout << endl << "Enter the discount code : ";
                                                        cin >> c;

                                                        for (int k = 0; k < size_c && check; k++) {

                                                            if (c.compare(discountCode[k]) == 0) {

                                                                sum = (sum * 5) / 10;

                                                                for (int j = k; j < size_c-1; j++) {

                                                                    discountCode[j] = discountCode[j+1];
                                                                }

                                                                k--;
                                                                size_c--;

                                                                cout << endl << "discount code applied successfully!" << endl << endl;

                                                                if (sum > customers[i].wallet) {

                                                                    cout << endl << "But unfortunately you still don't have enough money!" << endl;
                                                                    cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                                    sum = (sum * 10) / 5;

                                                                    size_c++;
                                                                    discountCode[size_c-1] = c;
                                                                }

                                                                else {

                                                                    int sure = 0;

                                                                    cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                    cin >> sure;

                                                                    if (sure == 1) {

                                                                        customers[i].invoice_c[size_in].totalPrice = sum;
                                                                        customers[i].wallet -= sum;
                                                                        addToFactor(customers,i,size_cart,size_info,size_in);
                                                                        size_in++;
                                                                        sum = 0;
                                                                        size_cart = 0;

                                                                        cout << endl << "Mission Completed!" << endl;
                                                                        cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                    }

                                                                    else {

                                                                        sum = (sum * 10) / 5;

                                                                        size_c++;
                                                                        discountCode[size_c-1] = c;

                                                                        check = false;
                                                                    }
                                                                }

                                                                check = false;
                                                            }
                                                        }

                                                        if (check) {

                                                            cout << endl << "Sorry this code has been expired!" << endl << endl;

                                                            if (total >= 150000) {

                                                                cout << endl << "You still can get 20% discount becouse of your previous purchases :)" << endl << endl;

                                                                sum = (sum * 8) / 10;

                                                                cout << endl << "discount applied successfully!" << endl << endl;

                                                                if (sum > customers[i].wallet) {

                                                                    sum = (sum * 10) / 8;

                                                                    cout << endl << "But unfortunately you still don't have enough money!" << endl;
                                                                    cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;
                                                                }

                                                                else {

                                                                    int sure = 0;

                                                                    cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                    cin >> sure;

                                                                    if (sure == 1) {

                                                                        customers[i].invoice_c[size_in].totalPrice = sum;
                                                                        customers[i].wallet -= sum;
                                                                        addToFactor(customers,i,size_cart,size_info,size_in);
                                                                        size_in++;
                                                                        sum = 0;
                                                                        size_cart = 0;

                                                                        cout << endl << "Mission Completed!" << endl;
                                                                        cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                    }

                                                                    else {

                                                                        sum = (sum * 10) / 8;

                                                                        temp = false;
                                                                    }
                                                                }
                                                            }

                                                            else {

                                                                if (sum > customers[i].wallet) {

                                                                    cout << endl << "And unfortunately you don't have enough money!" << endl;
                                                                    cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;
                                                                }

                                                                else {

                                                                    int sure = 0;

                                                                    cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                    cin >> sure;

                                                                    if (sure == 1) {

                                                                        customers[i].invoice_c[size_in].totalPrice = sum;
                                                                        customers[i].wallet -= sum;
                                                                        addToFactor(customers,i,size_cart,size_info,size_in);
                                                                        size_in++;
                                                                        sum = 0;
                                                                        size_cart = 0;

                                                                        cout << endl << "Mission Completed!" << endl;
                                                                        cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                    }

                                                                    else {

                                                                        temp = false;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }

                                                    else if (x == 0) {

                                                        if (total >= 150000) {

                                                            sum = (sum * 8) / 10;

                                                            cout << endl << "*** Congratulation! ***" << endl;
                                                            cout << endl << "Becouse of your previous purchases you got 20% discount!" << endl;
                                                            cout << endl << "Now total price of your orders is : " << sum << endl << endl;

                                                            if (sum > customers[i].wallet) {

                                                                sum = (sum * 10) / 8;

                                                                cout << endl << "But unfortunately you don't have enough money!" << endl;
                                                                cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                                temp = false;
                                                            }

                                                            else {

                                                                int sure = 0;

                                                                cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                cin >> sure;

                                                                if (sure == 1) {

                                                                    customers[i].invoice_c[size_in].totalPrice = sum;
                                                                    customers[i].wallet -= sum;
                                                                    addToFactor(customers,i,size_cart,size_info,size_in);
                                                                    size_in++;
                                                                    sum = 0;
                                                                    size_cart = 0;

                                                                    cout << endl << "Mission Completed!" << endl;
                                                                    cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                }

                                                                else {

                                                                    temp = false;
                                                                }
                                                            }
                                                        }

                                                        else {

                                                            if (sum > customers[i].wallet) {

                                                                cout << endl << "Sorry but you don't have enough money!" << endl;
                                                                cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                                temp = false;
                                                            }

                                                            else {

                                                                int sure = 0;

                                                                cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                cin >> sure;

                                                                if (sure == 1) {

                                                                    customers[i].invoice_c[size_in].totalPrice = sum;
                                                                    customers[i].wallet -= sum;
                                                                    addToFactor(customers,i,size_cart,size_info,size_in);
                                                                    size_in++;
                                                                    sum = 0;
                                                                    size_cart = 0;

                                                                    cout << endl << "Mission Completed!" << endl;
                                                                    cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                }

                                                                else {

                                                                    temp = false;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else {

                                                    temp = false;
                                                }
                                            }
                                        }

                                        else if (choice == 4) {

                                            string p;                   //password
                                            string e;                   //email
                                            string eP;                  //email password
                                            string f2;                  //favorite food
                                            string pN;                  //phone number
                                            char ch;
                                            int c = 0;
                                            bool t = true;

                                            for (int i = 0; i < sizeC; i++) {

                                                if (n.compare(customers[i].c_Information.id) == 0) {

                                                    while (t) {

                                                        cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                        cout << "1 : Login Password" << endl;
                                                        cout << "2 : Email" << endl;
                                                        cout << "3 : Email Password" << endl;
                                                        cout << "4 : Phone Number" << endl;
                                                        cout << "5 : Favorite Food" << endl;
                                                        cout << "6 : return" << endl << endl;

                                                        cin >> c;

                                                        if (c == 1) {

                                                            cout << endl << "Tell us the new password : ";
                                                            cin >> p;

                                                            if (p.length() >= 8) {

                                                                customers[i].c_Information.password = p;
                                                            }

                                                            else {

                                                                cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                            }
                                                        }

                                                        else if (c == 2) {

                                                            bool temp = true;

                                                            cout << endl << "Tell us the new email address : ";
                                                            cin >> e;

                                                            for (int j = 0; j < sizeC && temp; j++) {

                                                                if (e.compare(customers[j].c_PersonalInfo.email) == 0) {

                                                                    cout << endl << "Error : This email has been taken!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int j = 0; j < sizeE && temp; j++) {

                                                                if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                                    cout << endl << "Error : This email has been taken!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                customers[i].c_PersonalInfo.email = e;
                                                            }
                                                        }

                                                        else if (c == 3) {

                                                            cout << endl << "Tell us the new email password : ";
                                                            cin >> eP;

                                                            customers[i].c_PersonalInfo.emailPassword = eP;
                                                        }

                                                        else if (c == 4) {

                                                            bool temp = true;

                                                            cout << endl << "Tell us the new phone number : ";
                                                            cin >> pN;

                                                            for (int j = 0; j < sizeC && temp; j++) {

                                                                if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            for (int j = 0; j < sizeE && temp; j++) {

                                                                if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                                    cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                customers[i].c_PersonalInfo.phoneNumber = pN;
                                                            }
                                                        }

                                                        else if (c == 5) {

                                                            cout << endl << "Tell us the favorite food : ";
                                                            cin.get(ch);
                                                            getline (cin , f2);

                                                            customers[i].c_PersonalInfo.favoriteFood = f2;
                                                        }

                                                        else if (c == 6) {

                                                            t = false;
                                                        }

                                                        else {

                                                            cout << endl << "Error : choose one of the options!" << endl << endl;

                                                            t = false;
                                                        }
                                                    }

                                                    cout << endl;
                                                    cout << "------------------------" << endl << endl;
                                                    cout << " Your information are : " << endl << endl;
                                                    cout << "------------------------" << endl << endl;
                                                    cout << "Name : " << customers[i].c_PersonalInfo.fullName << endl << endl;
                                                    cout << "ID : " << customers[i].c_Information.id << endl << endl;
                                                    cout << "Login Password : " << customers[i].c_Information.password << endl << endl;
                                                    cout << "Email Address : " << customers[i].c_PersonalInfo.email << endl << endl;
                                                    cout << "Email Password : " << customers[i].c_PersonalInfo.emailPassword << endl << endl;
                                                    cout << "Phone Number : " << customers[i].c_PersonalInfo.phoneNumber << endl << endl;
                                                    cout << "Favorite Food : " << customers[i].c_PersonalInfo.favoriteFood << endl << endl;
                                                }
                                            }
                                        }

                                        else if (choice == 5) {

                                            long long int deposit;

                                            cout << endl << "Please enter the deposit amount : ";
                                            cin >> deposit;

                                            if (deposit >= 0) {

                                                customers[i].wallet += deposit;

                                                cout << endl << "------------------" << endl;
                                                cout << endl << "Mission Completed!" << endl;
                                                cout << endl << "Now you have " << " ' " << customers[i].wallet << " ' " << " Toman in your wallet" << endl;
                                                cout << endl << "Have a nice day :)" << endl;
                                                cout << endl << "------------------" << endl;
                                            }

                                            else {

                                                cout << endl << "Error!" << endl << endl;
                                            }
                                        }

                                        else if (choice == 6) {

                                            long long int total = 0;

                                            for (int k = 0; k < size_in; k++) {

                                                total += customers[i].invoice_c[k].totalPrice;
                                            }

                                            printInvoices (customers,i,size_in,size_info);

                                            cout << endl << "Total price of your food invoices is : " << total << endl << endl;
                                        }

                                        else if (choice == 7) {

                                            fl = false;
                                        }

                                        else {

                                            cout << endl << "Error : You have to choose one of the options above!" << endl;

                                            fl = false;
                                        }
                                    }

                                    tmp = false;
                                }
                            }

                            if (tmp) {

                                int sure = 0;
                                string pN;
                                string f2;

                                cout << endl << "Invalid Inputs!" << endl << endl;
                                cout << endl << "If you are sure that you have registered enter '1' if not enter '0' : ";
                                cin >> sure;

                                if (sure == 1) {

                                    tmp = true;
                                    cout << endl << "Tell us your phone number : ";
                                    cin >> pN;
                                    cout << endl;
                                    cout << endl << "Now tell us your favorite food : ";
                                    cin >> f2;
                                    cout << endl;

                                    for (int i = 0; i < sizeC && tmp; i++) {

                                        if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0 && f2.compare(customers[i].c_PersonalInfo.favoriteFood) == 0) {

                                            bool fl = true;

                                            while (fl) {

                                                int choice = 0;

                                                cout << endl << endl << "Please choose one of the options : " << endl << endl;

                                                cout << "1 : view the list of foods along with their prices" << endl;
                                                cout << "2 : add and remove food from the cart" << endl;
                                                cout << "3 : final registration of purchase and payment" << endl;
                                                cout << "4 : change your information" << endl;
                                                cout << "5 : charge the wallet" << endl;
                                                cout << "6 : view all your invoices for previous purchases" << endl;
                                                cout << "7 : return to the login page" << endl << endl;

                                                cin >> choice;

                                                if (choice == 1) {

                                                    printmenu (menu , sizeF);
                                                }

                                                else if (choice == 2) {

                                                    bool orderType = true;
                                                    int act = 0;

                                                    while (orderType) {

                                                        cout << endl << "choose one of the actions :" << endl;
                                                        cout << endl << "1 : add" << endl;
                                                        cout << endl << "2 : remove" << endl;
                                                        cout << endl << "3 : return" << endl << endl;

                                                        cin >> act;

                                                        if (act == 1) {

                                                            string order;
                                                            bool temp = true;

                                                            cout << endl << "Please tell us your new order : ";

                                                            char ch;
                                                            cin.get(ch);
                                                            getline (cin,order);

                                                            for (int k = 0; k < sizeF && temp; k++) {

                                                                if (order.compare(menu[k].name) == 0) {

                                                                    size_cart++;
                                                                    customers[i].cart[size_cart-1].name = order;
                                                                    customers[i].cart[size_cart-1].price = menu[k].price;

                                                                    cout << endl << "Mission Completed!" << endl << endl;

                                                                    printCart (customers,i,size_cart);

                                                                    cout << endl << endl;

                                                                    temp = false;
                                                                }
                                                            }

                                                            if (temp) {

                                                                cout << endl << "Sorry the food is not in the menu!" << endl << endl;
                                                            }
                                                        }

                                                        else if (act == 2) {

                                                            if (size_cart != 0) {

                                                                string order;
                                                                bool temp = true;

                                                                printCart (customers,i,size_cart);

                                                                cout << endl << "Please tell us which food do you want to remove : ";
                                                                cin >> order;

                                                                for (int k = 0; k < size_cart && temp; k++) {

                                                                    if (order.compare(customers[i].cart[k].name) == 0) {

                                                                        for (int j = k; j < size_cart-1; j++) {

                                                                            customers[i].cart[j].name = customers[i].cart[j+1].name;
                                                                            customers[i].cart[j].price = customers[i].cart[j+1].price;
                                                                        }

                                                                        k--;
                                                                        size_cart--;

                                                                        cout << endl << "Mission Completed!" << endl << endl;

                                                                        printCart (customers,i,size_cart);

                                                                        temp = false;
                                                                    }
                                                                }

                                                                if (temp) {

                                                                    cout << endl << "This Food is not in your cart!" << endl << endl;
                                                                }
                                                            }

                                                            else {

                                                                cout << endl << "Your cart is empty! :(" << endl << endl;
                                                            }
                                                        }

                                                        else {

                                                            orderType = false;
                                                        }
                                                    }
                                                }

                                                else if (choice == 3) {

                                                    bool temp = true;
                                                    int act = 0;
                                                    long long unsigned int sum = 0;
                                                    long long unsigned int total = 0;

                                                    printCart (customers,i,size_cart);

                                                    for (int k = 0; k < size_cart; k++) {

                                                        sum += customers[i].cart[k].price;
                                                    }

                                                    customers[i].invoice_c[size_in].totalPrice = sum;

                                                    for (int k = 0; k < size_in; k++) {

                                                        total += customers[i].invoice_c[k].totalPrice;
                                                    }

                                                    cout << endl << "Total price of your orders is : " << sum << endl;

                                                    while (temp) {

                                                        cout << endl << "which action would you like to take :" << endl << endl;

                                                        cout << "1 : final registration of purchase and payment" << endl;
                                                        cout << "2 : return" << endl << endl;

                                                        cin >> act;

                                                        if (act == 1) {

                                                            int x = 0;

                                                            cout << endl << "If you have discount code enter '1' if not enter '0' : ";
                                                            cin >> x;

                                                            if (x == 1) {

                                                                string c;
                                                                bool check = true;

                                                                cout << endl << "Enter the discount code : ";
                                                                cin >> c;

                                                                for (int k = 0; k < size_c && check; k++) {

                                                                    if (c.compare(discountCode[k]) == 0) {

                                                                        sum = (sum * 5) / 10;

                                                                        for (int j = k; j < size_c-1; j++) {

                                                                            discountCode[j] = discountCode[j+1];
                                                                        }

                                                                        k--;
                                                                        size_c--;

                                                                        cout << endl << "discount code applied successfully!" << endl << endl;

                                                                        if (sum > customers[i].wallet) {

                                                                            cout << endl << "But unfortunately you still don't have enough money!" << endl;
                                                                            cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                                            sum = (sum * 10) / 5;

                                                                            size_c++;
                                                                            discountCode[size_c-1] = c;
                                                                        }

                                                                        else {

                                                                            int sure = 0;

                                                                            cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                            cin >> sure;

                                                                            if (sure == 1) {

                                                                                customers[i].invoice_c[size_in].totalPrice = sum;
                                                                                customers[i].wallet -= sum;
                                                                                addToFactor(customers,i,size_cart,size_info,size_in);
                                                                                size_in++;
                                                                                sum = 0;
                                                                                size_cart = 0;

                                                                                cout << endl << "Mission Completed!" << endl;
                                                                                cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                            }

                                                                            else {

                                                                                sum = (sum * 10) / 5;

                                                                                size_c++;
                                                                                discountCode[size_c-1] = c;

                                                                                check = false;
                                                                            }
                                                                        }

                                                                        check = false;
                                                                    }
                                                                }

                                                                if (check) {

                                                                    cout << endl << "Sorry this code has been expired!" << endl << endl;

                                                                    if (total >= 150000) {

                                                                        cout << endl << "You still can get 20% discount becouse of your previous purchases :)" << endl << endl;

                                                                        sum = (sum * 8) / 10;

                                                                        cout << endl << "discount applied successfully!" << endl << endl;

                                                                        if (sum > customers[i].wallet) {

                                                                            sum = (sum * 10) / 8;

                                                                            cout << endl << "But unfortunately you still don't have enough money!" << endl;
                                                                            cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;
                                                                        }

                                                                        else {

                                                                            int sure = 0;

                                                                            cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                            cin >> sure;

                                                                            if (sure == 1) {

                                                                                customers[i].invoice_c[size_in].totalPrice = sum;
                                                                                customers[i].wallet -= sum;
                                                                                addToFactor(customers,i,size_cart,size_info,size_in);
                                                                                size_in++;
                                                                                sum = 0;
                                                                                size_cart = 0;

                                                                                cout << endl << "Mission Completed!" << endl;
                                                                                cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                            }

                                                                            else {

                                                                                sum = (sum * 10) / 8;

                                                                                temp = false;
                                                                            }
                                                                        }
                                                                    }

                                                                    else {

                                                                        if (sum > customers[i].wallet) {

                                                                            cout << endl << "And unfortunately you don't have enough money!" << endl;
                                                                            cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;
                                                                        }

                                                                        else {

                                                                            int sure = 0;

                                                                            cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                            cin >> sure;

                                                                            if (sure == 1) {

                                                                                customers[i].invoice_c[size_in].totalPrice = sum;
                                                                                customers[i].wallet -= sum;
                                                                                addToFactor(customers,i,size_cart,size_info,size_in);
                                                                                size_in++;
                                                                                sum = 0;
                                                                                size_cart = 0;

                                                                                cout << endl << "Mission Completed!" << endl;
                                                                                cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                            }

                                                                            else {

                                                                                temp = false;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }

                                                            else if (x == 0) {

                                                                if (total >= 150000) {

                                                                    sum = (sum * 8) / 10;

                                                                    cout << endl << "*** Congratulation! ***" << endl;
                                                                    cout << endl << "Becouse of your previous purchases you got 20% discount!" << endl;
                                                                    cout << endl << "Now total price of your orders is : " << sum << endl << endl;

                                                                    if (sum > customers[i].wallet) {

                                                                        sum = (sum * 10) / 8;

                                                                        cout << endl << "But unfortunately you don't have enough money!" << endl;
                                                                        cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                                        temp = false;
                                                                    }

                                                                    else {

                                                                        int sure = 0;

                                                                        cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                        cin >> sure;

                                                                        if (sure == 1) {

                                                                            customers[i].invoice_c[size_in].totalPrice = sum;
                                                                            customers[i].wallet -= sum;
                                                                            addToFactor(customers,i,size_cart,size_info,size_in);
                                                                            size_in++;
                                                                            sum = 0;
                                                                            size_cart = 0;

                                                                            cout << endl << "Mission Completed!" << endl;
                                                                            cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                        }

                                                                        else {

                                                                            temp = false;
                                                                        }
                                                                    }
                                                                }

                                                                else {

                                                                    if (sum > customers[i].wallet) {

                                                                        cout << endl << "Sorry but you don't have enough money!" << endl;
                                                                        cout << endl << "Please remove some of foods and try again or charge your wallet!" << endl << endl;

                                                                        temp = false;
                                                                    }

                                                                    else {

                                                                        int sure = 0;

                                                                        cout << endl << "If you're sure that you want to pay now enter '1' if not enter '0' : ";

                                                                        cin >> sure;

                                                                        if (sure == 1) {

                                                                            customers[i].invoice_c[size_in].totalPrice = sum;
                                                                            customers[i].wallet -= sum;
                                                                            addToFactor(customers,i,size_cart,size_info,size_in);
                                                                            size_in++;
                                                                            sum = 0;
                                                                            size_cart = 0;

                                                                            cout << endl << "Mission Completed!" << endl;
                                                                            cout << endl << "Now you have " << customers[i].wallet << " Toman in your wallet!" << endl << endl;
                                                                        }

                                                                        else {

                                                                            temp = false;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }

                                                        else {

                                                            temp = false;
                                                        }
                                                    }
                                                }

                                                else if (choice == 4) {

                                                    string p;                   //password
                                                    string e;                   //email
                                                    string eP;                  //email password
                                                    string f2;                  //favorite food
                                                    string pN;                  //phone number
                                                    char ch;
                                                    int c = 0;
                                                    bool t = true;

                                                    for (int i = 0; i < sizeC; i++) {

                                                        if (n.compare(customers[i].c_Information.id) == 0) {

                                                            while (t) {

                                                                cout << endl << "Please tell us which one of these you want to change : " << endl <<  endl;

                                                                cout << "1 : Login Password" << endl;
                                                                cout << "2 : Email" << endl;
                                                                cout << "3 : Email Password" << endl;
                                                                cout << "4 : Phone Number" << endl;
                                                                cout << "5 : Favorite Food" << endl;
                                                                cout << "6 : return" << endl << endl;

                                                                cin >> c;

                                                                if (c == 1) {

                                                                    cout << endl << "Tell us the new password : ";
                                                                    cin >> p;

                                                                    if (p.length() >= 8) {

                                                                        customers[i].c_Information.password = p;
                                                                    }

                                                                    else {

                                                                        cout << endl << "Error : Password must be at least 8 character!" << endl << endl;
                                                                    }
                                                                }

                                                                else if (c == 2) {

                                                                    bool temp = true;

                                                                    cout << endl << "Tell us the new email address : ";
                                                                    cin >> e;

                                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                                        if (e.compare(customers[j].c_PersonalInfo.email) == 0) {

                                                                            cout << endl << "Error : This email has been taken!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                                        if (e.compare(employees[j].e_PersonalInfo.email) == 0) {

                                                                            cout << endl << "Error : This email has been taken!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    if (temp) {

                                                                        customers[i].c_PersonalInfo.email = e;
                                                                    }
                                                                }

                                                                else if (c == 3) {

                                                                    cout << endl << "Tell us the new email password : ";
                                                                    cin >> eP;

                                                                    customers[i].c_PersonalInfo.emailPassword = eP;
                                                                }

                                                                else if (c == 4) {

                                                                    bool temp = true;

                                                                    cout << endl << "Tell us the new phone number : ";
                                                                    cin >> pN;

                                                                    for (int j = 0; j < sizeC && temp; j++) {

                                                                        if (pN.compare(customers[j].c_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    for (int j = 0; j < sizeE && temp; j++) {

                                                                        if (pN.compare(employees[j].e_PersonalInfo.phoneNumber) == 0) {

                                                                            cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                                            temp = false;
                                                                        }
                                                                    }

                                                                    if (temp) {

                                                                        customers[i].c_PersonalInfo.phoneNumber = pN;
                                                                    }
                                                                }

                                                                else if (c == 5) {

                                                                    cout << endl << "Tell us the favorite food : ";
                                                                    cin.get(ch);
                                                                    getline (cin , f2);

                                                                    customers[i].c_PersonalInfo.favoriteFood = f2;
                                                                }

                                                                else if (c == 6) {

                                                                    t = false;
                                                                }

                                                                else {

                                                                    cout << endl << "Error : choose one of the options!" << endl << endl;

                                                                    t = false;
                                                                }
                                                            }

                                                            cout << endl;
                                                            cout << "------------------------" << endl << endl;
                                                            cout << " Your information are : " << endl << endl;
                                                            cout << "------------------------" << endl << endl;
                                                            cout << "Name : " << customers[i].c_PersonalInfo.fullName << endl << endl;
                                                            cout << "ID : " << customers[i].c_Information.id << endl << endl;
                                                            cout << "Login Password : " << customers[i].c_Information.password << endl << endl;
                                                            cout << "Email Address : " << customers[i].c_PersonalInfo.email << endl << endl;
                                                            cout << "Email Password : " << customers[i].c_PersonalInfo.emailPassword << endl << endl;
                                                            cout << "Phone Number : " << customers[i].c_PersonalInfo.phoneNumber << endl << endl;
                                                            cout << "Favorite Food : " << customers[i].c_PersonalInfo.favoriteFood << endl << endl;
                                                        }
                                                    }
                                                }

                                                else if (choice == 5) {

                                                    long long int deposit;

                                                    cout << endl << "Please enter the deposit amount : ";
                                                    cin >> deposit;

                                                    if (deposit >= 0) {

                                                        customers[i].wallet += deposit;

                                                        cout << endl << "------------------" << endl;
                                                        cout << endl << "Mission Completed!" << endl;
                                                        cout << endl << "Now you have " << " ' " << customers[i].wallet << " ' " << " Toman in your wallet" << endl;
                                                        cout << endl << "Have a nice day :)" << endl;
                                                        cout << endl << "------------------" << endl;
                                                    }

                                                    else {

                                                        cout << endl << "Error!" << endl << endl;
                                                    }
                                                }

                                                else if (choice == 6) {

                                                    long long int total = 0;

                                                    for (int k = 0; k < size_in; k++) {

                                                        total += customers[i].invoice_c[k].totalPrice;
                                                    }

                                                    printInvoices (customers,i,size_in,size_info);

                                                    cout << endl << "Total price of your food invoices is : " << total << endl << endl;
                                                }

                                                else if (choice == 7) {

                                                    fl = false;
                                                }

                                                else {

                                                    cout << endl << "Error : You have to choose one of the options above!" << endl;

                                                    fl = false;
                                                }
                                            }

                                            tmp = false;
                                        }
                                    }

                                    if (tmp) {

                                        cout << endl << "It seems like you haven't registered yet!" << endl << endl <<
                                                        "So please register at first then Try Again!" << endl << endl;
                                    }
                                }

                                else {

                                    tmp = false;
                                }
                            }
                        }

                        else {

                            tmp = false;
                        }
                    }
                }

                else if (userType == 4) {

                    flag = false;
                }

                else {

                    cout << endl << "Error : you can access the site only if you are one of us or you are a customer!" << endl << endl;

                    flag = false;
                }

            }
        }

        else if (action == 2) {

            string n;                   //id
            string f;                   //first name
            string l;                   //last name
            string p;                   //password
            string e;                   //email
            string eP;                  //email password
            string f2;                  //favorite food
            string pN;                  //phone number
            char ch;
            bool t = true;

            cout << endl << "Please Fill The Form : " << endl << endl;

            while (t) {

                bool temp = true;

                cout << "ID : ";
                cin >> n;

                if (n.length() >= 5) {

                    for (int i = 0; i < sizeC && temp; i++) {

                        if (n.compare(customers[i].c_Information.id) == 0) {

                            cout << endl << "Sorry but this id has been taken!" << endl << endl;
                            temp = false;
                        }
                    }

                    for (int i = 0; i < sizeE && temp; i++) {

                        if (n.compare(employees[i].e_Information.id) == 0) {

                            cout << endl << "Sorry but this id has been taken!" << endl << endl;
                            temp = false;
                        }
                    }

                    if (n == admin.a_Information.id) {

                        cout << endl << "Sorry but this id has been taken!" << endl << endl;
                        temp = false;
                    }

                    if (temp) {

                        cout << endl;

                        int pass = 0;
                        int choice = 0;

                        pass = rand() % 30000 + 452000;

                        p = to_string(pass) + "FN";

                        cout << endl << "Your random password is : " << p << endl;
                        cout << endl << "If you want to change it enter '1' if not enter '0' : ";
                        cin >> choice;

                        cout << endl << endl;

                        if (choice == 1) {

                            bool a = true;

                            while (a) {

                                cout << "Password : ";
                                cin >> p;

                                if (p.length() >= 8) {

                                    cout << endl << endl;

                                    sizeC++;

                                    customers[sizeC-1].c_Information.id = n;

                                    customers[sizeC-1].c_Information.password = p;

                                    cout << "First Name : ";
                                    cin.get(ch);
                                    getline(cin , f);
                                    customers[sizeC-1].c_PersonalInfo.firstName = f;

                                    cout << endl << endl;

                                    cout << "Last Name : ";
                                    getline(cin , l);
                                    customers[sizeC-1].c_PersonalInfo.lastName = l;

                                    cout << endl << endl;

                                    bool b = true;

                                    while (b) {

                                        cout << "Email : ";
                                        cin >> e;

                                        bool temp = true;

                                        for (int i = 0; i < sizeC && temp; i++) {

                                            if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                                cout << endl << "This email has been used!" << endl << endl;
                                                temp = false;
                                            }
                                        }

                                        for (int i = 0; i < sizeE && temp; i++) {

                                            if (e.compare(employees[i].e_PersonalInfo.email) == 0) {

                                                cout << endl << "This email has been used!" << endl << endl;
                                                temp = false;
                                            }
                                        }

                                        if (temp) {

                                            customers[sizeC-1].c_PersonalInfo.email = e;
                                            b = false;
                                        }
                                    }

                                    cout << endl << endl;

                                    cout << "Email Password : ";
                                    cin >> eP;
                                    customers[sizeC-1].c_PersonalInfo.emailPassword = eP;

                                    cout << endl << endl;

                                    b = true;

                                    while (b) {

                                        cout << "Phone Number : ";
                                        cin >> pN;

                                        temp = true;

                                        for (int i = 0; i < sizeC && temp; i++) {

                                            if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0) {

                                                cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                temp = false;
                                            }
                                        }

                                        for (int i = 0; i < sizeE && temp; i++) {

                                            if (pN.compare(employees[i].e_PersonalInfo.phoneNumber) == 0) {

                                                cout << endl << "Error : This phone number has been used!" << endl << endl;
                                                temp = false;
                                            }
                                        }

                                        if (temp) {

                                            customers[sizeC-1].c_PersonalInfo.phoneNumber = pN;
                                            b = false;
                                        }
                                    }

                                    cout << endl << endl;

                                    cout << "Favorite Food : ";
                                    cin.get(ch);
                                    getline (cin , f2);
                                    customers[sizeC-1].c_PersonalInfo.favoriteFood = f2;

                                    cout << endl << endl;

                                    customers[sizeC-1].c_PersonalInfo.fullName = customers[sizeC-1].c_PersonalInfo.firstName + ' ' + customers[sizeC-1].c_PersonalInfo.lastName;

                                    cout << endl;
                                    cout << "------------------------" << endl << endl;
                                    cout << " Your information are : " << endl << endl;
                                    cout << "------------------------" << endl << endl;
                                    cout << "Name : " << customers[sizeC-1].c_PersonalInfo.fullName << endl << endl;
                                    cout << "ID : " << customers[sizeC-1].c_Information.id << endl << endl;
                                    cout << "Login Password : " << customers[sizeC-1].c_Information.password << endl << endl;
                                    cout << "Email Address : " << customers[sizeC-1].c_PersonalInfo.email << endl << endl;
                                    cout << "Email Password : " << customers[sizeC-1].c_PersonalInfo.emailPassword << endl << endl;
                                    cout << "Phone Number : " << customers[sizeC-1].c_PersonalInfo.phoneNumber << endl << endl;
                                    cout << "Favorite Food : " << customers[sizeC-1].c_PersonalInfo.favoriteFood << endl << endl;

                                    a = false;
                                    t = false;
                                }

                                else {

                                    cout << endl << "Password must be at least 8 character!" << endl << endl;
                                }
                            }
                        }

                        else {

                            sizeC++;

                            customers[sizeC-1].c_Information.id = n;

                            customers[sizeC-1].c_Information.password = p;

                            cout << "First Name : ";
                            cin.get(ch);
                            getline(cin , f);
                            customers[sizeC-1].c_PersonalInfo.firstName = f;

                            cout << endl << endl;

                            cout << "Last Name : ";
                            getline(cin , l);
                            customers[sizeC-1].c_PersonalInfo.lastName = l;

                            cout << endl << endl;

                            bool b = true;

                            while (b) {

                                cout << "Email : ";
                                cin >> e;

                                bool temp = true;

                                for (int i = 0; i < sizeC && temp; i++) {

                                    if (e.compare(customers[i].c_PersonalInfo.email) == 0) {

                                        cout << endl << "This email has been used!" << endl << endl;
                                        temp = false;
                                    }
                                }

                                for (int i = 0; i < sizeE && temp; i++) {

                                    if (e.compare(employees[i].e_PersonalInfo.email) == 0) {

                                        cout << endl << "This email has been used!" << endl << endl;
                                        temp = false;
                                    }
                                }

                                if (temp) {

                                    customers[sizeC-1].c_PersonalInfo.email = e;
                                    b = false;
                                }
                            }

                            cout << endl << endl;

                            cout << "Email Password : ";
                            cin >> eP;
                            customers[sizeC-1].c_PersonalInfo.emailPassword = eP;

                            cout << endl << endl;

                            b = true;

                            while (b) {

                                cout << "Phone Number : ";
                                cin >> pN;

                                temp = true;

                                for (int i = 0; i < sizeC && temp; i++) {

                                    if (pN.compare(customers[i].c_PersonalInfo.phoneNumber) == 0) {

                                        cout << endl << "Error : This phone number has been used!" << endl << endl;
                                        temp = false;
                                    }
                                }

                                for (int i = 0; i < sizeE && temp; i++) {

                                    if (pN.compare(employees[i].e_PersonalInfo.phoneNumber) == 0) {

                                        cout << endl << "Error : This phone number has been used!" << endl << endl;
                                        temp = false;
                                    }
                                }

                                if (temp) {

                                    customers[sizeC-1].c_PersonalInfo.phoneNumber = pN;
                                    b = false;
                                }
                            }

                            cout << endl << endl;

                            cout << "Favorite Food : ";
                            cin.get(ch);
                            getline (cin , f2);
                            customers[sizeC-1].c_PersonalInfo.favoriteFood = f2;

                            cout << endl << endl;

                            customers[sizeC-1].c_PersonalInfo.fullName = customers[sizeC-1].c_PersonalInfo.firstName + ' ' + customers[sizeC-1].c_PersonalInfo.lastName;

                            cout << endl;
                            cout << "------------------------" << endl << endl;
                            cout << " Your information are : " << endl << endl;
                            cout << "------------------------" << endl << endl;
                            cout << "Name : " << customers[sizeC-1].c_PersonalInfo.fullName << endl << endl;
                            cout << "ID : " << customers[sizeC-1].c_Information.id << endl << endl;
                            cout << "Login Password : " << customers[sizeC-1].c_Information.password << endl << endl;
                            cout << "Email Address : " << customers[sizeC-1].c_PersonalInfo.email << endl << endl;
                            cout << "Email Password : " << customers[sizeC-1].c_PersonalInfo.emailPassword << endl << endl;
                            cout << "Phone Number : " << customers[sizeC-1].c_PersonalInfo.phoneNumber << endl << endl;
                            cout << "Favorite Food : " << customers[sizeC-1].c_PersonalInfo.favoriteFood << endl << endl;

                            t = false;
                        }
                    }
                }

                else {

                    cout << endl << "ID must be at least 5 character!" << endl << endl;
                }
            }

        }

        else if (action == 3) {

            return 0;
        }

        else {

            cout << endl << "you have to choose one of the actions above!" << endl << endl;

            return 0;
        }
    }
    return 0;
}

//-----------------------------------------------------------------

template <class T>
void printmenu (T menu[] , int len) {

    cout << endl << "The menu is :" << endl << endl;

    for (int i = 0; i < len; i++) {

        cout << "Name : " << menu[i].name << "          ";
        cout << "Price : " << menu[i].price << endl << endl;
    }
}

//-----------------------------------------------------------------

template<class T>
void printCustomerInfo (T customers[], int len) {

    cout << "-----------------------------------" << endl << endl;
    cout << "The information of customers are : " << endl << endl;
    cout << "---------------------------------- " << endl << endl;

    for (int i = 0; i < len; i++) {

        customers[i].c_PersonalInfo.fullName = customers[i].c_PersonalInfo.firstName + ' ' + customers[i].c_PersonalInfo.lastName;

        cout << "ID : " << customers[i].c_Information.id << endl << endl;
        cout << "Password : " << customers[i].c_Information.password << endl << endl;
        cout << "Name : " << customers[i].c_PersonalInfo.fullName << endl << endl;
        cout << "Email : " << customers[i].c_PersonalInfo.email<< endl << endl;
        cout << "Email Password : " << customers[i].c_PersonalInfo.emailPassword << endl << endl;
        cout << "Phone Number : " << customers[i].c_PersonalInfo.phoneNumber << endl << endl;
        cout << "Favorite Food : " << customers[i].c_PersonalInfo.favoriteFood << endl << endl;
        cout << "-----------------------------------------------" << endl << endl;
    }
}

//-----------------------------------------------------------------

template<class T>
void printCode (T discountCode[], int len) {

    cout << endl << "discount codes are : " << endl << endl;

    for (int i = 0; i < len; i++) {

        cout << discountCode[i] << endl << endl;
    }
}

//-----------------------------------------------------------------

template<class T>
void printEmployeesInfo (T employees[] , int len) {

    cout << "-----------------------------------" << endl << endl;
    cout << "The information of employees are : " << endl << endl;
    cout << "---------------------------------- " << endl << endl;

    for (int i = 0; i < len; i++) {

        employees[i].e_PersonalInfo.fullName = employees[i].e_PersonalInfo.firstName + ' ' + employees[i].e_PersonalInfo.lastName;

        cout << "Name : " << employees[i].e_PersonalInfo.fullName << endl << endl;
        cout << "ID : " << employees[i].e_Information.id << endl << endl;
        cout << "Password : " << employees[i].e_Information.password << endl << endl;
        cout << "Email : " << employees[i].e_PersonalInfo.email<< endl << endl;
        cout << "Email Password : " << employees[i].e_PersonalInfo.emailPassword << endl << endl;
        cout << "Phone Number : " << employees[i].e_PersonalInfo.phoneNumber << endl << endl;
        cout << "Favorite Food : " << employees[i].e_PersonalInfo.favoriteFood << endl << endl;
        cout << "-----------------------------------------------" << endl << endl;
    }
}

//-----------------------------------------------------------------

template<class T>
void printCart (T customers[], int index,int len) {

    cout << endl << "----------------------------------" << endl;
    cout << endl << "Your cart includes the following :" << endl;
    cout << endl << "----------------------------------" << endl;

    for (int  j = 0; j < len; j++) {

        cout << endl << "Name of Food : " << customers[index].cart[j].name;
        cout << "           ";
        cout << "Price : " << customers[index].cart[j].price << endl << endl;
    }
}

//-----------------------------------------------------------------

template<class T>
void printInvoices (T customers[],int index,int len,int len2) {


    for (int k = 0; k < len; k++) {

        cout << endl << "=========================================" << endl;
        cout << endl << "Invoice " << k+1 << " : " << endl;
        cout << endl << "=========================================" << endl;

        for (int j = 0; j < len2 ; j++) {

            if (customers[index].invoice_c[k].info[j].name.empty()) {

                j++;
            }

            else {

                cout << "Food Name : " << customers[index].invoice_c[k].info[j].name;
                cout << "           ";
                cout << "Price : " << customers[index].invoice_c[k].info[j].price << endl;
            }
        }

        cout << endl << "Price Paid : " << customers[index].invoice_c[k].totalPrice << endl << endl;
    }
}

//-----------------------------------------------------------------

template<class T>
void addToFactor (T customers, int index, int len1, int &len2, int size_in) {

    for (int i = 0; i < len1; i++) {

        customers[index].invoice_c[size_in].info[len2].name = customers[index].cart[i].name;
        customers[index].invoice_c[size_in].info[len2].price = customers[index].cart[i].price;

        len2++;
    }
}

//-----------------------------------------------------------------
