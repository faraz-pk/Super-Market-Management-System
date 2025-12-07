#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <set>
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
int createId();
void updateProduct();
void deleteAccount();
void deleteProduct();
void searchProduct();
string toLowerStr(string s);
void lowStock();
void filterPanel();
void filter1(string s, string filterBy);
void filter2(int min, int max, string filterBy);
void accountSearch();

string adminUsername = "abc";
string adminPassword = "123";

struct Accounts {
    int id;
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
    loginPanel();
    return 0;
}

void loginPanel() {
    cout << "1. Login as User" << endl;
    cout << "2. Login as Admin" << endl;
    cout << "3. Create an Account" << endl;
    cout << "4. Close App" << endl;
    int choice;
    while(true) {
        cout << "Enter (1-4): ";
        cin >> choice;
        if(choice >= 1 && choice <= 4) {
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
    } else if(choice == 4) {
        cout << "-------------------" << endl;
        cout << "App Closed!" << endl;
        cout << "-------------------" << endl;
        return;
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
    cout << "5. View All Products" << endl;
    cout << "6. Low Stock Product" << endl;
    cout << "7. Filter Products" << endl;
    cout << "8. Go Back" << endl;
    cout << "9. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-9): ";
        cin >> choice;
        if(choice >= 1 && choice <= 9) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }
    
    if(choice == 1) {
        cout << "-------------------\n" << endl;
        addProduct();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        updateProduct();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        deleteProduct();
    } else if(choice == 4) {
        cout << "-------------------\n" << endl;
        searchProduct();
    } else if(choice == 5) {
        cout << "-------------------\n" << endl;
        displayProducts();
        cout << "-------------------\n" << endl;
        inventoryPanel();
    } else if(choice == 6) {
        cout << "-------------------\n" << endl;
        lowStock();
    } else if(choice == 7) {
        cout << "-------------------\n" << endl;
        filterPanel();
    } else if(choice == 8) {
        cout << "-------------------\n" << endl;
        adminPanel();
    } else if(choice == 9) {
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        loginPanel();
    }
}

void salesReportPanel() {
    int choice;
    cout << "1. Total Revenue Report" << endl;
    cout << "2. Daily Sales Report" << endl;
    cout << "3. Weekly Sales Report" << endl;
    cout << "4. Monthly Sales Report" << endl;
    cout << "5. Go Back" << endl;
    cout << "6. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-6): ";
        cin >> choice;
        if(choice >= 1 && choice <= 6) {
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
    cout << "3. Search Account" << endl;
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

    if(choice == 1) {
        cout << "-------------------\n" << endl;
        deleteAccount();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        displayAccounts();
        cout << "-------------------\n" << endl;
        accManagePanel();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        accountSearch();
    } else if(choice == 4) {
        cout << "-------------------\n" << endl;
        adminPanel();
    } else if(choice == 5) {
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        loginPanel();
    }
}

void addProduct() {
    Product product;
    product.id = createId();
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
    
    file << product.id << " " << product.name << " " << product.price << " " << product.brand << " " << product.category << " " << product.quantity << "\n";
    cout << "-------------------" << endl;
    cout << "Product Added Successfully!" << endl;
    cout << "-------------------\n" << endl;
    file.close();
    inventoryPanel();
}

void displayAccounts() {
    Accounts account;
    ifstream file("users.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    cout << left;
    cout << setw(20) << "Id"
         << setw(20) << "Usernames"
         << setw(20) << "Passwords" 
         << endl;
    cout << string(60, '-') << endl;

    int counter = 0;
    while(file >> account.id >> account.username >> account.password) {
        cout << setw(20) << account.id 
            << setw(20) << account.username
            << setw(20) << account.password
            << endl;
        counter++;
    }
    if(counter == 0) {
        cout << "No user found!" << endl;
    }
    file.close();
    cout << "\nTotal Accounts = " << counter << endl;
}

void displayProducts() {
    Product product;
    ifstream file("products.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    cout << left; 
    cout << setw(15) << "Id"
         << setw(20) << "Name"
         << setw(15) << "Price(Rs)"
         << setw(15) << "Brand"
         << setw(20) << "Category"
         << setw(15) << "Quantity"
         << endl;

    cout << string(100, '-') << endl;

    int counter = 0;

    while(file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
        cout << setw(15) << product.id 
            << setw(20) << product.name
            << setw(15) << product.price
            << setw(15) << product.brand
            << setw(20) << product.category
            << setw(15) << product.quantity
            << endl;
        counter++;
    }
    if(counter == 0) {
        cout << "No product available in inventory!" << endl;
    }
    file.close();
    cout << "\nTotal Products = " << counter << endl;
}

int createId() {
    srand(time(0));
    int num = rand() % 500 + 1;
    Product product;
    ifstream file("products.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return num;
    }

    bool found = false;
    while(file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
        if(num == product.id) {
            found = true;
            break;
        }
    }

    file.close();

    if(found) {
        return createId();
    } else {
        return num; 
    }
}

void updateProduct() {
    displayProducts();
    Product product;
    bool found = false;
    int id;
    cout << "Enter Id of product to update: ";
    cin >> id;

    ifstream infile("products.txt");
    ofstream outfile("temp.txt");

    if (!infile || !outfile) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Read each product
    while (infile >> product.id >> product.name >> product.price 
                  >> product.brand >> product.category >> product.quantity) {
        if (product.id == id) {
            found = true;
            product.id = createId();
            cout << "Enter new Name: ";
            cin >> product.name;
            cout << "Enter new Price: ";
            cin >> product.price;
            cout << "Enter new Brand: ";
            cin >> product.brand;
            cout << "Enter new Category: ";
            cin >> product.category;
            cout << "Enter new Quantity: ";
            cin >> product.quantity;
        }

        outfile << product.id << " " << product.name << " " << product.price << " "
                << product.brand << " " << product.category << " " << product.quantity << "\n";
    }

    infile.close();
    outfile.close();

    if (!found) {
        cout << "-------------------" << endl;
        cout << "Product with ID " << id << " not found!" << endl;
        cout << "-------------------\n" << endl;
        remove("temp.txt");
    } else {
        remove("products.txt");
        rename("temp.txt", "products.txt");
        cout << "-------------------" << endl;
        cout << "Product Updated Successfully!" << endl;
        cout << "-------------------\n" << endl;
    }
    inventoryPanel();
}

void deleteAccount() {
    displayAccounts();
    Accounts account;
    bool found = false;
    int id;
    cout << "Enter Id of user to remove: ";
    cin >> id;

    ifstream infile("users.txt");
    ofstream outfile("temp.txt");

    if (!infile || !outfile) {
        cout << "Error opening file!" << endl;
        return;
    }

    while(infile >> account.id >> account.username >> account.password) {
        if(account.id == id) {
            found = true;
            continue;
        }
        outfile << account.id << " " << account.username << " " << account.password << "\n";
    }

    infile.close();
    outfile.close();

    if (!found) {
        cout << "-------------------" << endl;
        cout << "User with ID " << id << " not found!" << endl;
        cout << "-------------------\n" << endl;
        remove("temp.txt");
    } else {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        cout << "-------------------" << endl;
        cout << "User Removed Successfully!" << endl;
        cout << "-------------------\n" << endl;
    }
    
    accManagePanel();
}

void deleteProduct() {
    displayProducts();
    Product product;
    bool found = false;
    int id;
    cout << "Enter Id of product to remove: ";
    cin >> id;

    ifstream infile("products.txt");
    ofstream outfile("temp.txt");

    if (!infile || !outfile) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (infile >> product.id >> product.name >> product.price 
            >> product.brand >> product.category >> product.quantity) {
        if(product.id == id) {
            found = true;
            continue;
        }
        outfile << product.id << " " << product.name << " " << product.price << " "
                << product.brand << " " << product.category << " " << product.quantity << "\n";
    }

    infile.close();
    outfile.close();

    if (!found) {
        cout << "-------------------" << endl;
        cout << "Product with ID " << id << " not found!" << endl;
        cout << "-------------------\n" << endl;
        remove("temp.txt");
    } else {
        remove("products.txt");
        rename("temp.txt", "products.txt");
        cout << "-------------------" << endl;
        cout << "Product Removed Successfully!" << endl;
        cout << "-------------------\n" << endl;
    }
    
    inventoryPanel();
}

void searchProduct() {
    Product product;
    string name;
    cout << "Enter product name: ";
    cin >> name;

    ifstream file("products.txt");
    if(!file) {
        cout << "Error opening file!";
        return;
    }

    cout << left; 
            cout << setw(15) << "Id"
                << setw(20) << "Name"
                << setw(15) << "Price(Rs)"
                << setw(15) << "Brand"
                << setw(20) << "Category"
                << setw(15) << "Quantity"
                << endl;

            cout << string(100, '-') << endl;

    bool found = false;
    while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
        if(toLowerStr(product.name) == toLowerStr(name)) {
            found = true;
            cout << setw(15) << product.id 
                << setw(20) << product.name
                << setw(15) << product.price
                << setw(15) << product.brand
                << setw(20) << product.category
                << setw(15) << product.quantity
                << endl;
        }
    }

    file.close();

    if(!found) {
        cout << "Product not found!" << endl;
    }
    cout << "-------------------\n" << endl;
    inventoryPanel();
}

string toLowerStr(string s) {
    for(int i = 0; i <= s.length(); i++) {
        s[i] = tolower(s[i]);
    } 
    return s;
}

void lowStock() {
    Product product;
    ifstream file("products.txt");
    if(!file) {
        cout << "Error opening file!";
        return;
    }

    cout << left; 
            cout << setw(15) << "Id"
                << setw(20) << "Name"
                << setw(15) << "Price(Rs)"
                << setw(15) << "Brand"
                << setw(20) << "Category"
                << setw(15) << "Quantity"
                << endl;

            cout << string(100, '-') << endl;

    while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
        if(product.quantity <= 10) {
            cout << setw(15) << product.id 
                << setw(20) << product.name
                << setw(15) << product.price
                << setw(15) << product.brand
                << setw(20) << product.category
                << setw(15) << product.quantity
                << endl;
        }
    }

    file.close();
    cout << "-------------------\n" << endl;
    inventoryPanel();
}

void filterPanel() {
    int choice;
    cout << "1. Filter by Brand" << endl;
    cout << "2. Filter by Category" << endl;
    cout << "3. Filter by Price" << endl;
    cout << "4. Filter by Quantity" << endl;
    cout << "5. Go Back" << endl;
    cout << "6. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-6): ";
        cin >> choice;
        if(choice >= 1 && choice <= 6) {
            break;
        } else {
            cout << "Wrong Choice! Try Again" << endl;
        }
    }

    if(choice == 1) {
        Product product;
        ifstream file("products.txt");

        cout << "\nAvailable Brands Are:\n" << endl;
        set<string> brands; 
        while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
            brands.insert(product.brand);
        }
        file.close();
        for (const string &brand : brands) {
            cout << brand << endl;
        }   

        string brand;
        cout << "\nEnter brand name: ";
        cin >> brand;

        filter1(brand, "Brand");
    } else if(choice == 2) {
        Product product;
        ifstream file("products.txt");

        cout << "\nAvailable Categories Are:\n" << endl;
        set<string> categories;
        while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
            categories.insert(product.category);
        }
        file.close();
        for (const string &category : categories) {
            cout << category << endl;
        } 

        string category;
        cout << "\nEnter category: ";
        cin >> category;
        
        filter1(category, "Category");
    }else if(choice == 3) {
        int min, max;
        cout << "-------------------\n" << endl;
        cout << "Filter from Rs: ";
        cin >> min;
        cout << "Filter to Rs: ";
        cin >> max;
        if(min > max || min < 0 || max < 0) {
            cout << "-------------------" << endl;
            cout << "Invalid Range! Try Again" << endl;
            cout << "-------------------\n" << endl;
            filterPanel();
            return;
        }
        filter2(min, max, "Price");
    }else if(choice == 4) {
        int min, max;
        cout << "-------------------\n" << endl;
        cout << "Filter from Quantity: ";
        cin >> min;
        cout << "Filter to Quantity: ";
        cin >> max;
        if(min > max || min < 0 || max < 0) {
            cout << "-------------------" << endl;
            cout << "Invalid Range! Try Again" << endl;
            cout << "-------------------\n" << endl;

            filterPanel();
            return;
        }
        filter2(min, max, "Quantity");
    }else if(choice == 5) {
        cout << "-------------------\n" << endl;
        inventoryPanel();
    }else if(choice == 6) {
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        loginPanel();
    }
}

void filter1(string s, string filterBy) {
    Product product;

    ifstream file("products.txt");
    if(!file) {
        cout << "Error opening file!";
        return;
    }

    cout << left; 
    cout << setw(15) << "Id"
        << setw(20) << "Name"
        << setw(15) << "Price(Rs)"
        << setw(15) << "Brand"
        << setw(20) << "Category"
        << setw(15) << "Quantity"
        << endl;

    cout << string(100, '-') << endl;

    int counter = 0;
    if(filterBy == "Brand") {
        while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
            if(toLowerStr(product.brand) == toLowerStr(s)) {
                counter++;
                cout << setw(15) << product.id 
                    << setw(20) << product.name
                    << setw(15) << product.price
                    << setw(15) << product.brand
                    << setw(20) << product.category
                    << setw(15) << product.quantity
                    << endl;
            }
        }
    } else if(filterBy == "Category") {
        while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
            if(toLowerStr(product.category) == toLowerStr(s)) {
                counter++;
                cout << setw(15) << product.id 
                    << setw(20) << product.name
                    << setw(15) << product.price
                    << setw(15) << product.brand
                    << setw(20) << product.category
                    << setw(15) << product.quantity
                    << endl;
            }
        }
    }
    
    if(counter == 0) {
        cout << "No product available in this " << filterBy << "!" << endl;
    }

    file.close();
    cout << "-------------------\n" << endl;
    filterPanel();
}

void accountSearch() {
    Accounts account;
    string name;
    cout << "Enter username: ";
    cin >> name;

    ifstream file("users.txt");
    if(!file) {
        cout << "Error opening file!";
        return;
    }

    cout << left;
    cout << setw(20) << "Id"
         << setw(20) << "Usernames"
         << setw(20) << "Passwords" 
         << endl;
    cout << string(60, '-') << endl;

    bool found = false;
    while (file >> account.id >> account.username >> account.password) {
        if(account.username == name) {
            found = true;
            cout << setw(20) << account.id 
            << setw(20) << account.username
            << setw(20) << account.password
            << endl;
        }
    }

    file.close();

    if(!found) {
        cout << "Account not found!" << endl;
    }
    cout << "-------------------\n" << endl;
    accManagePanel();
}

void filter2(int min, int max, string filterBy) {
    Product product;

    ifstream file("products.txt");
    if(!file) {
        cout << "Error opening file!";
        return;
    }

    cout << left; 
    cout << setw(15) << "Id"
        << setw(20) << "Name"
        << setw(15) << "Price(Rs)"
        << setw(15) << "Brand"
        << setw(20) << "Category"
        << setw(15) << "Quantity"
        << endl;

    cout << string(100, '-') << endl;

    int counter = 0;
    if(filterBy == "Price") {
        while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
            if(product.price >= min && product.price <= max) {
                counter++;
                cout << setw(15) << product.id 
                    << setw(20) << product.name
                    << setw(15) << product.price
                    << setw(15) << product.brand
                    << setw(20) << product.category
                    << setw(15) << product.quantity
                    << endl;
            }
        }
    } else if(filterBy == "Quantity") {
        while (file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
            if(product.quantity >= min && product.quantity <= max) {
                counter++;
                cout << setw(15) << product.id 
                    << setw(20) << product.name
                    << setw(15) << product.price
                    << setw(15) << product.brand
                    << setw(20) << product.category
                    << setw(15) << product.quantity
                    << endl;
            }
        }
    }

    if(counter == 0) {
        cout << "No product available in this Price Range!" << endl;
    }

    file.close();
    cout << "-------------------\n" << endl;
    filterPanel();
}