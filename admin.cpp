#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

void loginPanel();
void adminPanel();
void accManagePanel();
void inventoryPanel();
void salesReportPanel();
void addProduct();
void displayAccounts();
void loginAsAdmin();
void displayProducts();

string adminUsername = "abc";
string adminPassword = "123";

struct Accounts {
    string username;
    string password;
};

struct Product {
    string name;
    double price;
    int quantity;
    string category;
    string brand;
};

int main() {
    cout << "\n----- Welcome to NextGen Supermarket -----\n" << endl;
    loginPanel();
    return 0;
}

void loginPanel() {
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
    
    if(choice == 1) {
        // loginAsUser();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        loginAsAdmin();
    } else if(choice == 3) {
        // createAccount();
    } 
}

void loginAsAdmin() {
    string username;
    string password;

    while(true) {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        if(username == adminUsername && password == adminPassword) {
            cout << "-------------------" << endl;
            cout << "Login Successfully!" << endl;
            cout << "-------------------\n" << endl;
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
        inventoryPanel();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        accManagePanel();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        salesReportPanel();
    } else if(choice == 4) {
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
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
    
    if(choice == 1) {
        cout << "-------------------\n" << endl;
        addProduct();
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
    } else if(choice == 5) {
        cout << "-------------------\n" << endl;
        displayProducts();
    } else if(choice == 6) {
        //pending
        //pending
        //pending
    } else if(choice == 7) {
        cout << "-------------------\n" << endl;
        adminPanel();
    } else if(choice == 8) {
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        loginPanel();
    }
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
        cout << "-------------------\n" << endl;
        displayAccounts();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        adminPanel();
    } else if(choice == 4) {
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        loginPanel();
    }
}

void addProduct() {
    Product product;
    cout << "Enter Name: ";
    cin >>  product.name;
    cout << "Enter Price: ";
    cin >> product.price;
    cout << "Enter Brand: ";
    cin >> product.brand;
    cout << "Enter Category: ";
    cin >> product.category;
    cout << "Enter Quantity: ";
    cin >> product.quantity;

    ofstream file("products.txt", ios::app);
    if (!file) {
        cout << "File not found!" << endl;
        return;
    }
    
    file << product.name << " " << product.price << " " << product.brand << " " << product.category << " " << product.quantity << "\n";
    cout << "-------------------" << endl;
    cout << "Product Added Successfully!" << endl;
    cout << "-------------------\n" << endl;
    file.close();
    inventoryPanel();
}

void displayAccounts() {
    Accounts account;
    ifstream file("users.txt", ios::app);

    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    cout << left;
    cout << setw(20) << "Usernames"
         << setw(20) << "Passwords" 
         << endl;
    cout << string(40, '-') << endl;

    int counter = 0;
    while(file >> account.username >> account.password) {
        cout << setw(20) << account.username
            << setw(20) << account.password
            << endl;
        counter++;
    }
    file.close();
    cout << "\nTotal Accounts = " << counter << endl;
    cout << "-------------------\n" << endl;
    accManagePanel();
}

void displayProducts() {
    Product product;
    ifstream file("products.txt", ios::app);

    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    cout << left; 
    cout << setw(20) << "Name"
         << setw(15) << "Price(Rs)"
         << setw(15) << "Brand"
         << setw(20) << "Category"
         << setw(15) << "Quantity"
         << endl;

    cout << string(85, '-') << endl;

    int counter = 0;

    while(file >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
        cout << setw(20) << product.name
            << setw(15) << product.price
            << setw(15) << product.brand
            << setw(20) << product.category
            << setw(15) << product.quantity
            << endl;
        counter++;
    }
    file.close();
    cout << "\nTotal Products = " << counter << endl;
    cout << "-------------------\n" << endl;
    inventoryPanel();
}