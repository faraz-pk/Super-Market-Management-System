#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <set>
#include <windows.h>
using namespace std;

void loginPanel();
void loginAsUser();
void createAccount();
bool checkPasswordAuth(string password);
void userPanel();
bool savingUserAccount(string username, string password);
void displayProducts();
int createId();
void accManagePanel();
void changePassword();
void changeUsername();
void inventoryPanel();
void filterPanel();
void filter1(string s, string filterBy);
void filter2(int min, int max, string filterBy);
string toLowerStr(string s);
void searchProduct();
void addToCart();
void cart();
void viewCart();

struct Accounts {
    int id;
    string username;
    string password;
};

struct Product {
    int id;
    string name;
    double price;
    string brand;
    string category;
    int quantity;
};

struct Cart {
    int productId;
    int quantity;
};

Cart item[20];
int cartItemsCount = 0;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    setColor(1);
    cout << "\n----- Welcome to NextGen Supermarket -----\n" << endl;
    setColor(7);
    //moving to login panel
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
            setColor(4);
            cout << "Wrong Choice! Try Again" << endl;
            setColor(7);
        }
    }
    
    if(choice == 1) {
        cout << "-------------------\n" << endl;
        loginAsUser();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        // loginAsAdmin();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        createAccount();
    } else if(choice == 4) {
        setColor(4);
        cout << "-------------------" << endl;
        cout << "App Closed!" << endl;
        cout << "-------------------" << endl;
        setColor(7);
        return;
    }
}

void createAccount() {
// taking credential for new account
    string username, password;
    Accounts account;
    setColor(3);
    cout << "Note: Password should include atleast one uppercase, lowercase, number, special character and min 8 characters long" << endl;
    setColor(7);
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (!file) {
        setColor(4);
        cout << "File not found!" << endl;
        setColor(7);
        return;
    }

    bool found = false;
    while(file >> account.id >> account.username >> account.password) {
        if(account.username == username) {
            found = true; 
            break;
        } 
    }

    file.close();

    if(found) {
        setColor(4);
        cout << "\n-------------------" << endl;
        cout << "Username already exists! Try different" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
        createAccount();
    }

    // checking validation
    if(checkPasswordAuth(password) && username != "") {
        // storing user account
        if (savingUserAccount(username, password)) {
            setColor(2);
            cout << "\n-------------------" << endl;
            cout << "Account Created Successfully!" << endl;
            cout << "-------------------\n" << endl;
            setColor(7);
            loginPanel();
        } else {
            setColor(4);
            cout << "\n-------------------" << endl;
            cout << "Error Creating Account! Try Again Later" << endl;
            cout << "-------------------\n" << endl;
            setColor(7);
            loginPanel();
        }
    }else {
        setColor(4);
        cout << "\n-------------------" << endl;
        cout << "Invalid credentials! Try Again" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
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
    Accounts account;

    ifstream file("users.txt");
    if (!file) {
        setColor(4);
        cout << "File not found!" << endl;
        setColor(7);
        return;
    }

    bool found = false;
    while(file >> account.id >> account.username >> account.password) {
        if(account.username == username && account.password == password) {
            found = true; 
            break;
        } 
    }

    file.close();

    if(found) {
        setColor(2);
        cout << "\n-------------------" << endl;
        cout << "Login Successfully!" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
        // moving to user-panel pending 
        userPanel();
    } else {
        setColor(4);
        cout << "\n-------------------" << endl;
        cout << "Invalid Credentials! Try Again" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
        loginPanel();
    }
}

void userPanel() {
    int choice;
    cout << "-------------------" << endl;
    cout << "1. Move To Inventory" << endl;
    cout << "2. Account Management" << endl;
    cout << "3. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-3): ";
        cin >> choice;
        if(choice >= 1 && choice <= 3) {
            break;
        } else {
            setColor(4);
            cout << "Wrong Choice! Try Again" << endl;
            setColor(7);
        }
    }

    if (choice == 1){
        cout << "-------------------\n" << endl;
        inventoryPanel();
    }
    else if (choice == 2){
        cout << "-------------------\n" << endl;
        accManagePanel();
    }
    else if (choice == 3){
        setColor(4);
        cout << "\n-------------------" << endl;
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
        loginPanel();
    }
}

void displayProducts() {
    Product product;
    ifstream file("products.txt");

    if (!file) {
        setColor(4);
        cout << "File not found!" << endl;
        setColor(7);
        return;
    }

    cout << left; 
    setColor(1);
    cout << setw(15) << "Id"
         << setw(20) << "Name"
         << setw(15) << "Price(Rs)"
         << setw(15) << "Brand"
         << setw(20) << "Category"
         << setw(15) << "Quantity"
         << endl;

    cout << string(100, '-') << endl;
    setColor(7);

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
        setColor(4);
        cout << "No product available in inventory!" << endl;
        setColor(7);
    }
    file.close();
    setColor(2);
    cout << "\nTotal Products = " << counter << endl;
    setColor(7);
}

bool savingUserAccount(string username, string password) {
    Accounts account;
    ofstream file("users.txt", ios::app);

    if (!file) {
        cout << "File not found!" << endl;
        return false;
    }
    
    account.id = createId();
    account.username = username;
    account.password = password;

    file << account.id << " " << account.username << " " << account.password << "\n";
    file.close();
    return true;
}

int createId() {
    srand(time(0));
    int num = rand() % 500 + 1;
    Accounts account;
    ifstream file("users.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return num;
    }

    bool found = false;
    while(file >> account.id >> account.username >> account.password) {
        if(num == account.id) {
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

void accManagePanel() {
    int choice;
    cout << "1. Change Password" << endl;
    cout << "2. Change Username" << endl;
    cout << "3. Go Back" << endl;
    cout << "4. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-4): ";
        cin >> choice;
        if(choice >= 1 && choice <= 4) {
            break;
        } else {
            setColor(4);
            cout << "Wrong Choice! Try Again" << endl;
            setColor(7);
        }
    }

    if(choice == 1) {
        cout << "-------------------\n" << endl;
        changePassword();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        changeUsername();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        userPanel();
    } else if(choice == 4) {
        setColor(4);
        cout << "\n-------------------" << endl;
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
        loginPanel();
    }
}

void changePassword() {
    string password, newpassword, confirmpassword;
    Accounts account;
    cout << "Enter Old password: ";
    cin >> password;
    cout << "Enter New password: ";
    cin >> newpassword;
    cout << "Confirm New password: ";
    cin >> confirmpassword;

    ifstream file("users.txt");
    ofstream temp("temporary.txt");
    if (!file || !temp){
        cout << "File not found!\nPlease contact with admin at admin@gmail.com." << endl;
        return;
    }

    bool found = false;
    while (file >> account.id >> account.username >> account.password){
        if (account.password == password){
            account.password = newpassword;
            found = true;
        }
        temp << account.id << " " << account.username << " " << account.password << endl;
    }
    file.close();
    temp.close();

    if (!found){
        cout << "Please enter the correct old password!" << endl;
        remove("temporary.txt");
        changePassword();
    }
    else {
        if (checkPasswordAuth(newpassword)){
            if (newpassword == confirmpassword){
                savingUserAccount(account.username , account.password);
                cout << "Password Changed Successfullly!" << endl;
                remove("users.txt");
                rename("temporary.txt" , "users.txt");
            }
            else {
                cout << "New passwords doesn't match!\nPlease try again..." << endl;
                remove("temporary.txt");
                changePassword();
            }
        }
        else {
            cout << "Please Write password fulfilling given requirements!" << endl;
        }
    }
    
    accManagePanel();
}

void changeUsername() {
    string username, newusername, confirmusername;
    Accounts account;
    cout << "Enter old username: ";
    cin >> username;
    cout << "Enter new username: ";
    cin >> newusername;
    cout << "Confirm new username: ";
    cin >> confirmusername;

    ifstream into("users.txt");
    ofstream outof("temp.txt");

    if (!into || !outof){
        cout << "Files doesn't exists!\nPlease contact with admin at admin@gmail.com." << endl;
        return;
    }

    bool found = false;
    while (into >> account.id >> account.username >> account.password){
        if (account.username == username){
            account.username = newusername;
            found = true;
        }
        outof << account.id << " " << account.username << " " << account.password << endl;
    }
    into.close();
    outof.close();

    if (!found) {
        cout << "Please Enter the correct old username!" << endl;
        remove("temp.txt");
        changeUsername();
    }
    else {
        if (newusername == confirmusername){
            savingUserAccount(account.username , account.password);
            cout << "Username Changed Successfully!" << endl;
            remove("users.txt");
            rename("temp.txt" , "users.txt");
        }
        else {
            cout << "New usernames doesn't match\nPlease try again..." << endl;
            remove("temp.txt");
            changeUsername();
        }
    }

    accManagePanel();
}

void inventoryPanel() {
    int choice;
    cout << "1. View All Products" << endl;
    cout << "2. Filter Products" << endl;
    cout << "3. Search Product" << endl;
    cout << "4. View Cart" << endl;
    cout << "5. Proceed to Billing" << endl;
    cout << "6. Go Back" << endl;
    cout << "7. Logout" << endl;

    while(true) {
        cout << "Enter choice(1-7): ";
        cin >> choice;
        if(choice >= 1 && choice <= 7) {
            break;
        } else {
            setColor(4);
            cout << "Wrong Choice! Try Again" << endl;
            setColor(7);
        }
    }

    if(choice == 1) {
        cout << "-------------------\n" << endl;
        displayProducts();
        cout << "-------------------\n" << endl;
        cart();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        filterPanel();
        cout << "-------------------\n" << endl;
        cart();
    } else if(choice == 3) {
        cout << "-------------------\n" << endl;
        searchProduct();
        cout << "-------------------\n" << endl;
        cart();
    } else if(choice == 4) {
        cout << "-------------------\n" << endl;
        viewCart();
    } else if(choice == 5) {
        cout << "-------------------\n" << endl;
        // pending
        // pending
        // pending
    } else if(choice == 6) {
        cout << "-------------------\n" << endl;
        userPanel();
    } else if(choice == 7) {
        setColor(4);
        cout << "\n-------------------" << endl;
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
        loginPanel();
    }
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
            setColor(4);
            cout << "Wrong Choice! Try Again" << endl;
            setColor(7);
        }
    }

    if(choice == 1) {
        Product product;
        ifstream file("products.txt");

        setColor(1);
        cout << "\nAvailable Brands Are:\n" << endl;
        setColor(7);
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

        setColor(1);
        cout << "\nAvailable Categories Are:\n" << endl;
        setColor(7);
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
            setColor(4);
            cout << "-------------------" << endl;
            cout << "Invalid Range! Try Again" << endl;
            cout << "-------------------\n" << endl;
            setColor(7);
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
            setColor(4);
            cout << "-------------------" << endl;
            cout << "Invalid Range! Try Again" << endl;
            cout << "-------------------\n" << endl;
            setColor(7);

            filterPanel();
            return;
        }

        filter2(min, max, "Quantity");

    }else if(choice == 5) {
        cout << "-------------------\n" << endl;
        inventoryPanel();
    }else if(choice == 6) {
        setColor(4);
        cout << "\n-------------------" << endl;
        cout << "Logout!" << endl;
        cout << "-------------------\n" << endl;
        setColor(7);
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
    setColor(1);
    cout << setw(15) << "Id"
        << setw(20) << "Name"
        << setw(15) << "Price(Rs)"
        << setw(15) << "Brand"
        << setw(20) << "Category"
        << setw(15) << "Quantity"
        << endl;

    cout << string(100, '-') << endl;
    setColor(7);

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
        setColor(4);
        cout << "No product available in this " << filterBy << "!" << endl;
        setColor(7);
    }

    file.close();
    cout << "-------------------\n" << endl;
    filterPanel();
}

string toLowerStr(string s) {
    for(int i = 0; i <= s.length(); i++) {
        s[i] = tolower(s[i]);
    } 
    return s;
}

void filter2(int min, int max, string filterBy) {
    Product product;

    ifstream file("products.txt");
    if(!file) {
        cout << "Error opening file!";
        return;
    }

    cout << left; 
    setColor(1);
    cout << setw(15) << "Id"
        << setw(20) << "Name"
        << setw(15) << "Price(Rs)"
        << setw(15) << "Brand"
        << setw(20) << "Category"
        << setw(15) << "Quantity"
        << endl;

    cout << string(100, '-') << endl;
    setColor(7);

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
        setColor(4);
        cout << "No product available in this Price Range!" << endl;
        setColor(7);
    }

    file.close();
    cout << "-------------------\n" << endl;
    filterPanel();
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
    setColor(1);
    cout << setw(15) << "Id"
        << setw(20) << "Name"
        << setw(15) << "Price(Rs)"
        << setw(15) << "Brand"
        << setw(20) << "Category"
        << setw(15) << "Quantity"
        << endl;

    cout << string(100, '-') << endl;
    setColor(7);

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
        setColor(4);
        cout << "Product not found!" << endl;
        setColor(7);
    }
    cout << "-------------------\n" << endl;
    inventoryPanel();
}

void cart() {
    int choice;
    cout << "1. Add to Cart" << endl;
    cout << "2. Go Back" << endl;

    while(true) {
        cout << "Enter choice(1-2): ";
        cin >> choice;
        if(choice >= 1 && choice <= 2) {
            break;
        } else {
            setColor(4);
            cout << "Wrong Choice! Try Again" << endl;
            setColor(7);
        }
    }

    if(choice == 1) {
        cout << "-------------------\n" << endl;
        addToCart();
    } else if(choice == 2) {
        cout << "-------------------\n" << endl;
        inventoryPanel();
    }
}

void viewCart() {
    Product product;
    ifstream file("products.txt");

    if (!file) {
        cout << "File not found!" << endl;
        return;
    }

    cout << left; 
    setColor(1);
    cout << setw(15) << "Id"
         << setw(20) << "Name"
         << setw(20) << "Price per Unit(Rs)"
         << setw(20) << "Total Price(Rs)"
         << setw(15) << "Brand"
         << setw(20) << "Category"
         << setw(15) << "Quantity"
         << endl;

    cout << string(130, '-') << endl;
    setColor(7);

    if(cartItemsCount == 0) {
        setColor(4);
        cout << "No item added in cart!" << endl;
        setColor(7);
        cout << "-------------------\n" << endl;
        inventoryPanel();
        return;
    }

    while(file >> product.id >> product.name >> product.price >> product.brand >> product.category >> product.quantity) {
        for(int i = 0; i <= cartItemsCount; i++) {
            if(item[i].productId == product.id) {
                cout << setw(15) << product.id 
                << setw(20) << product.name
                << setw(20) << product.price
                << setw(20) << product.price * item[i].quantity
                << setw(15) << product.brand
                << setw(20) << product.category
                << setw(15) << item[i].quantity
                << endl;
            }
        }
    }
    file.close();
    cout << "-------------------\n" << endl;
    inventoryPanel();
}

void addToCart() {
    Product product;
    int choice = 1;

    while(choice != 0) {
        ifstream file("products.txt");
        if(!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        int id, quantity;
        cout << "Enter Product ID to add to cart: ";
        cin >> id;
        cout << "Enter Quantity: ";
        cin >> quantity;

        bool found = false;

        while(file >> product.id >> product.name >> product.price 
                   >> product.brand >> product.category >> product.quantity) {

            if(product.id == id) {
                found = true;

                if(quantity > product.quantity) {
                    setColor(4);
                    cout << "\n-------------------" << endl;
                    cout << "Insufficient stock! Available: " 
                         << product.quantity << endl;
                    cout << "-------------------\n" << endl;
                    setColor(7);
                } else {
                    item[cartItemsCount].productId = id;
                    item[cartItemsCount].quantity = quantity;
                    cartItemsCount++;

                    setColor(2);
                    cout << "\n-------------------" << endl;
                    cout << "Product Added to Cart!" << endl;
                    cout << "-------------------\n" << endl;
                    setColor(7);
                }
                break;
            }
        }

        if(!found) {
            setColor(4);
            cout << "\n-------------------" << endl;
            cout << "Product ID does not exist!" << endl;
            cout << "-------------------\n" << endl;
            setColor(7);
        }

        file.close();

        setColor(1);
        cout << "Add more products? (1 = Yes, 0 = No): ";
        setColor(7);
        cin >> choice;
    }

    cout << "-------------------\n" << endl;
    inventoryPanel();
}
