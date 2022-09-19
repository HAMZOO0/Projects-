#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

void Encryption(string &name, string &Password) // this function can encrypt all data which we send to files
{

    for (int i = 0; i < name.size(); i++)
    {
        name[i]++;
        Password[i]--;
    }
}

void decryption(string &name, string &Password) // this function can decrypt all data which we send to files
{

    for (int i = 0; i < name.size(); i++)
    {
        name[i]--;
        Password[i]++;
    }
}
/////////////////////////////////////////////////////class _sign_up_log_in_ /////////////////////////////////////////////////////
class _sign_up_log_in_ // this class have sign in and login functionality
{
    friend class Data;

public:
    void gui_signup();
    void gui_login();
    void sign_up();      // this function can check new / old user
    void sign_up_data(); // new user dara entry
    void log_in();       // login 😂
    void _ADD_New_Data_();
    void _See_All_Data();
    void _Delete_All_Data();
};
//------------------------------------------------- gui_signup()--------------------------------------------------------------------------
void _sign_up_log_in_::gui_signup()
{
    cout << "\n\t     MK PASSWORD MANAGER v1.9" << endl;
    cout << "\n\t * Your Security Is Our Priority ";
    cout << "\n\t * Your Data is Encrypted  ";
    cout << "\n\t * Your Data is Secured Physically   ";
    cout << "\n\n PRESS ANY BUTTON ON KEYBOARD ..... \n";
    getch();
}
// ------------------------------------------------- gui_login()------------------------------------------------------------------------
void _sign_up_log_in_ ::gui_login()
{
A:
    system("CLS");
    cout << "\n\t1 : ADD New Password";
    cout << "\n\t2 : See All Password";
    cout << "\n\t3 : Delete All  Password";
    cout << "\n\t4 : Exit" << endl;

    int chooice;
    cin >> chooice;
    switch (chooice)
    {
    case 1:
        _ADD_New_Data_();
        break;

    case 2:
        _See_All_Data();
        break;
    case 3:
        _Delete_All_Data();
        break;

    case 4:
        exit(1);
        break;

    default:
        cout << "Wrong Input ";
        goto A;
        break;
    }
}
//-----------------------------------------------------------log_in()---------------------------------------------------------------------

void _sign_up_log_in_ ::log_in()
{
    // 1st we get user data and comapir with signup data
    gui_signup();

p:

    string name, password;
    cout << "Enter Name :: ";
    cin >> name;
    cout << "Enter Password :: ";
    cin >> password;

    // here i receiving Eecrypt data form file
    fstream data;
    data.open("signup.txt");
    string _file_name, _file_password;
    data >> _file_name >> _file_password;

    // now we decrypt the file data and then compair
    decryption(_file_name, _file_password);

    // here i compare the login  data with signup data

    if (_file_name == name && _file_password == password) // is password and name mathch then give asscess

        gui_login();

    else
    {
        cout << "Try Again ...\n"
                "Press Any Button ... \n ";
        getch();
        goto p;
    }
    data.close();
}

// ---------------------------------------------------------------sign_up_data()------------------------------------------------------
void _sign_up_log_in_ ::sign_up_data()
{
    // Here i am geting data
    gui_signup();
    system("CLS");
    string name, Password;
    cout << "Enter Your Name  :: ";
    cin >> name;
    cout << "Enter Your Password :: ";
    cin >> Password;
    cout << "\n\t Welcome  " << name << " " << char(3) << " " << char(3) << " " << char(3) << " " << endl;

    // Here i send data to incrption function to incrypt all data
    Encryption(name, Password);

    // here i am sending data towards file
    fstream SignUpData;
    SignUpData.open("signup.txt", ios::app);
    SignUpData << name << endl;
    SignUpData << Password << endl;

    SignUpData.close();
}

// ---------------------------------------------------------------sign_up()----------------------------------------------------------

void _sign_up_log_in_::sign_up()
{
    fstream sign_file;
    sign_file.open("signup.txt");
    string get;
    sign_file >> get;

    if (sign_file.tellp() == -1)
    {
        sign_up_data();
    }
    else
        log_in();

    sign_file.close();
}

void _sign_up_log_in_ ::_ADD_New_Data_()
{
    // Getting data
    string NM, PSS;
    cout << "\nWarning !!! When You Enter Data Don't Press Space !! " << endl;
    cout << "Enter Name :: ";
    cin >> NM;
    cout << "Enter Password :: ";
    cin >> PSS;

    // Encryption before ent er in data base
    Encryption(NM, PSS);

    // Enter in data base
    fstream Data_Entry;
    Data_Entry.open("Data_Base.txt", ios::app);
    Data_Entry << NM << endl;
    Data_Entry << PSS << endl;
    Data_Entry.close();
}

//---------------------------------------------------- _See_All_Data()------------------------------------------------------
void _sign_up_log_in_ ::_See_All_Data()
{

    // Here i receiving Eecrypt data form file
    fstream Data;
    Data.open("Data_Base.txt");

    while (Data.eof() == 0) // Gab file empty na ho to eof 0 da ga bcz 0 = no gab ,, end go gy ge tb 1 = yes
    {
        string _Data_name, _Data_password;

        Data >> _Data_name >> _Data_password;
        // now we decrypt the file data and then compair
        decryption(_Data_name, _Data_password);
        cout << _Data_name << endl
             << _Data_password << endl;
    }

    Data.close();
}
//----------------------------------------------------------_Delete_All_Data()---------------------------------------------------------
void _sign_up_log_in_ ::_Delete_All_Data()
{
    // 223 to 227 is code of my LMS project 😊
    system("cls");

    cout << "\n\t\t\t DELETED ..";
    ofstream file("Data_Base.txt");
    file << "";
}

////////////////////////////////////////////////////// MAIN           () ////////////////////////////////////////////////////////////////////////////////////
int main()
{
    _sign_up_log_in_ user;
    user.sign_up();

    return 0;
}
