#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

void loginPanel();
void loginAsUser();
void createAccount();
bool checkPasswordAuth(string password);
void userPanel();
bool savingUserAccount(string username, string password);
void displayAllProducts();

struct Accounts {
    string username;
    string password;
};

struct Products {
    int id;
    string name;
    double price;
    string brand;
    string category;
    int quantity;
};

int main() {
    cout << "\n----- Welcome to NextGen Supermarket -----\n" << endl;
    //moving to login panel
    loginPanel();
    return 0;
}

void loginPanel() {
    //taking login type
    cout << "1. Login as User" << endl;
    cout << "2. Login as Admin" << endl;
    cout << "3. Create an Account" << endl;
    int choice;
    while(true) {
        cout << "Enter (1-3): ";
        cin >> choice;
        if(choice >= 1 && choice <= 3) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }
    cout << "-------------------\n" << endl;

    // managing login type
    if(choice == 1) {
        loginAsUser();
    } else if(choice == 2) {
        // loginAsAdmin();
    } else if(choice == 3) {
        createAccount();
    } 
}

void createAccount() {
// taking credential for new account
    string username, password;
    Accounts account;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password(atleast one uppercase, lowercase, number, special character and min 8 characters long): ";
    cin >> password;

    ifstream file("users.txt");
    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    bool found = false;
    while(file >> account.username >> account.password) {
        if(account.username == username) {
            found = true; 
            break;
        } 
    }

    file.close();

    if(found) {
        cout << "Username already exists! Try different" << endl;
        createAccount();
    }

    // checking validation
    if(checkPasswordAuth(password) && username != "") {
        // storing user account
        if (savingUserAccount(username, password)) {
            cout << "-------------------" << endl;
            cout << "Account Created Successfully!" << endl;
            cout << "-------------------" << endl;
            loginPanel();
        } else {
            cout << "-------------------\n" << endl;
            loginPanel();
        }
    }else {
        cout << "Invalid credentials! Try Again" << endl;
        createAccount();
    }
}

bool checkPasswordAuth(string password) {
    bool upper = false, lower = false, digit = false, special = false;
    for(int i = 0; i <= password.length(); i++){
        if(isupper(password[i])){
            upper = true;
        }else if(islower(password[i])){
            lower = true;
        }else if(ispunct(password[i])){
            special = true;
        }else if(isdigit(password[i])){
            digit = true;
        }
    }

    if(upper && lower && digit && special && password.length() >= 8) {
        return true;
    } else {
        return false;
    }
}

void loginAsUser() {
    // taking credentials
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // validating account existence
    Accounts user;

    ifstream file("users.txt");
    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    bool found = false;
    while(file >> user.username >> user.password) {
        if(user.username == username && user.password == password) {
            found = true; 
            break;
        } 
    }

    file.close();

    if(found) {
        cout << "\n-------------------" << endl;
        cout << "Login Successfully!" << endl;
        cout << "-------------------" << endl;
        // moving to user-panel pending 
        userPanel();
    } else {
        cout << "Invalid Credentials! Try Again" << endl;
        cout << "-------------------\n" << endl;
        loginPanel();
    }
}

void userPanel() {
    int choice;
    cout << "-------------------\n" << endl;
    cout << "1. Show All Products" << endl;
    cout << "2. Search Product" << endl;
    cout << "3. Go Back" << endl;
    cout << "4. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-3): ";
        cin >> choice;
        if(choice >= 1 && choice <= 3) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }
    if (choice == 1){
        cout << "Following products are available in the store:" << endl;
        displayAllProducts();
    }
    else if (choice == 2){
        //pending
        //pending
        //pending
    }
    else if (choice == 3){
        userPanel();
    }
    else if (choice == 4){
        loginPanel();
    }
}

void displayAllProducts(){
    Products products;
    ifstream Products("products.txt");
    string line;
    cout << "id" << setw(20) << "Product Name" << setw(20) << "Price" << setw(20) << "brand" << setw(20) << "Category" << setw(20) << "Quantity" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    while (Products >> products.id >> products.name >> products.price >> products.brand >> products.category >> products.quantity){
        cout << products.id << setw(20) << products.name << setw(20) << products.price << setw(20) << products.brand << setw(20) << products.category << setw(20) << products.quantity << endl;
    }
}

bool savingUserAccount(string username, string password) {
    Accounts account;
    ofstream file("users.txt", ios::app);

    if (!file) {
        cout << "File not found!" << endl;
        return false;
    }
    
    account.username = username;
    account.password = password;

    file << account.username << " " << account.password << "\n";
    file.close();
    return true;
}