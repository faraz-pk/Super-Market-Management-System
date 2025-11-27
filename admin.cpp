#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void loginPanel();
void adminPanel();
void accManagePanel();
void inventoryPanel();
void salesReportPanel();

void loginAsAdmin();

string adminUsername = "abc";
string adminPassword = "123";

struct Accounts {
    string username;
    string password;
};

struct Product {
    int id;
    string name;
    double price;
    int quantity;
    string category;
    string brand;
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
        // loginAsUser();
    } else if(choice == 2) {
        loginAsAdmin();
    } else if(choice == 3) {
        // createAccount();
    } 
}

void loginAsAdmin() {
    string username;
    string password;

    // taking and verifying credentials
    while(true) {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        if(username == adminUsername && password == adminPassword) {
            cout << "-------------------" << endl;
            cout << "Login Successfully!" << endl;
            cout << "-------------------\n" << endl;
            // moving towards admin panel
            adminPanel();
            break;
        } else {
            cout << "Wrong Credentials! Try Again" << endl;
        }
    }
}

void adminPanel() {
    int choice;
    cout << "1. Inventory Management" << endl;
    cout << "2. Account Management" << endl;
    cout << "3. Sales Report" << endl;
    cout << "4. Logout" << endl;
    while(true) {
        cout << "Enter choice(1-4): ";
        cin >> choice;
        if(choice >= 1 && choice <= 4) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }
    
    if(choice == 1) {
        cout << "-------------------\n" << endl;
        // moving to inventory panel
        inventoryPanel();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        //moving to account management panel
        accManagePanel();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        //moving to sales reports panel
        salesReportPanel();
    } else if(choice == 4) {
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        //moving to login panel
        loginPanel();
    }
}

void inventoryPanel() {
    int choice;
    cout << "1. Add Product" << endl;
    cout << "2. Update Product" << endl;
    cout << "3. Delete Product" << endl;
    cout << "4. Search Product" << endl;
    cout << "5. Show All Products" << endl;
    cout << "6. Low Stock Product" << endl;
    cout << "7. Go Back" << endl;
    cout << "8. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-8): ";
        cin >> choice;
        if(choice >= 1 && choice <= 8) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }
    
    //pending
    if(choice == 1) {

    } else if(choice == 2) {

    } else if(choice == 3) {
        
    } else if(choice == 4) {
        
    } else if(choice == 5) {
        
    } else if(choice == 6) {
        
    } else if(choice == 7) {

    } else if(choice == 8) {

    }
    // pending
}

void salesReportPanel() {
    int choice;
    cout << "1. Total Revenue Report" << endl;
    cout << "2. Monthly Sales Report" << endl;
    cout << "3. Daily Sales Report" << endl;
    cout << "4. Go Back" << endl;
    cout << "5. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-5): ";
        cin >> choice;
        if(choice >= 1 && choice <= 5) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }
    // pending
    // pending
    // pending
}

void accManagePanel() {
    int choice;
    cout << "1. Delete Account" << endl;
    cout << "2. View All Accounts" << endl;
    cout << "3. Go Back" << endl;
    cout << "4. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-4): ";
        cin >> choice;
        if(choice >= 1 && choice <= 4) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }

    if(choice == 1) {
        //pending
        //pending
        //pending
    } else if(choice == 2) {
        //pending
        //pending
        //pending
    } else if(choice == 3) {
        //pending
        //pending
        //pending
    } else if(choice == 4) {
        //pending
        //pending
        //pending
    }
}