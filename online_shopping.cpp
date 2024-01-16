#include <iostream>
#include <map>

using namespace std;

class User {
public:
    string Uemail;
    string UAddress;
    string userName;
    string password;
    int UphoneNumber;
};

class Product {
public:
    int Pid;
    string Pname;
    string Ptype;
    int Pquantity;
    int Pprice;
    Product(int id, const string& name, const string& type, int quantity,int price)
        : Pid(id), Pname(name), Ptype(type), Pprice(price), Pquantity(quantity) {}
};
map<int, Product> mp;
map<int, int> storecart;
double totalPrice = 0.0;
int totalItems;
void changeProductQuantity();
void deleteProduct();
void takeProductId() {
    int pId;
    int qty;
    cout << "Enter the product Id" << endl;
    cin >> pId;

    // Check if the product with the given ID exists
    auto it = mp.find(pId);
    if (it != mp.end()) {
        cout << "Enter the Quantity" << endl;
        cin >> qty;
        totalItems += 1;
        Product& abc = it->second;
        totalPrice += (abc.Pprice * qty);
        storecart[pId] = qty;
    } else {
        cout << "Product with ID " << pId << " does not exist." << endl;
    }
}
 
void displayProduct() {

    cout << "Total Quantity: " << totalItems << endl;
    cout << "Total Price: " << totalPrice << endl;
}

void displayProductList() {
    cout << "Product List:" << endl;
    for (const auto& entry : mp) {
        const Product& product = entry.second;
        cout << "ID: " << product.Pid << ", Name: " << product.Pname << ", Type: " << product.Ptype
             << ", Quantity: " << product.Pquantity << endl;
    }
}

void addToCart() {
   int choice;
    cout<<"Enter 1 for add to cart"<<endl;
    cout<<"Enter 2 for toal quantity and amount"<<endl;
    cout<<"Enter -1 for exit";
    cin>>choice;
    while(choice!=-1){
        if(choice==1){
           takeProductId();
        }else if(choice==2){
            displayProduct();
        }
        cout<<"Enter 1 for add to cart"<<endl;
        cout<<"Enter 2 for toal quantity and amount"<<endl;
        cout<<"Enter -1 for exit";
        cin>>choice;
    }
}

void addProduct() {
    int id;
    string name, type;
    int quantity;
    int price;

    cout << "Enter product ID: ";
    cin >> id;

    // Check if the product ID already exists
    if (mp.find(id) == mp.end()) {
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter product type: ";
        getline(cin, type);

        cout << "Enter product quantity: ";
        cin >> quantity;

        cout<< "Enter product price: ";
        cin>> price;

        mp.insert({id, Product(id, name, type, price , quantity)});
        cout << "Product added successfully!" << endl;
    } else {
        cout << "Product with ID " << id << " already exists. Please choose a different ID." << endl;
    }
}

void changeProductQuantity() {
    int id, newQuantity;

    cout << "Enter product ID to change quantity: ";
    cin >> id;

    auto it = mp.find(id);
    if (it != mp.end()) {
        cout << "Enter new quantity: ";
        cin >> newQuantity;

        // Update the product quantity
        it->second.Pquantity = newQuantity;
        cout << "Quantity updated successfully!" << endl;
    } else {
        cout << "Product with ID " << id << " not found." << endl;
    }
}

void deleteProduct() {
    int id;

    cout << "Enter product ID to delete: ";
    cin >> id;

    auto it = mp.find(id);
    if (it != mp.end()) {
        // Erase the product from the map
        mp.erase(it);
        cout << "Product deleted successfully!" << endl;
    } else {
        cout << "Product with ID " << id << " not found." << endl;
    }
}

int main() {
    cout << "************************************" << endl;
    cout << "*                                                                                                    *" << endl;
    cout << "*                                Welcome to MicroShopes                                              *" << endl;
    cout << "*                            we bring everything you need                                            *" << endl;
    cout << "*                                                                                                    *" << endl;
    cout << "************************************" << endl;

    int choice = 0;

    while (choice != -1) {
        cout << "Please select to proceed" << endl;
        cout << "Enter 1 for creating a profile to order" << endl;
        cout << "Enter 2 for Admin Mode" << endl;
        cout << "Enter -1 to exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                // User profile creation logic here
                User newUser;

                cout << "Enter your email: ";
                cin >> newUser.Uemail;

                cout << "Enter your username: ";
                cin >> newUser.userName;

                cout << "Enter your phone number: ";
                cin >> newUser.UphoneNumber;

                cout << "Enter your address: ";
                cin >> newUser.UAddress;

                cout << "Set a password: ";
                cin >> newUser.password;

                int userAction;
                cout << "Enter 1 for product List" << endl;
                cout << "Enter 2 for Order" << endl;
                cout << "Enter -1 for exit" << endl;
                cin >> userAction;

                switch (userAction) {
                    case 1:
                        displayProductList();
                        break;

                    case 2:
                        // Add logic for ordering products by the user
                        addToCart();
                        break;

                    default:
                        // Handle other choices if needed
                        break;
                }

                break;
            }

            case 2: {
                string name;
                string password;
                cout << "Enter username: ";
                cin >> name;
                cout << "Enter password: ";
                cin >> password;

                if (name == "aman" and password == "aman0603") {
                    int adminAction = 0;

                    while (adminAction != -1) {
                        cout << "Welcome Aman" << endl;
                        cout << "Enter 1 for Product list" << endl;
                        cout << "Enter 2 to change the quantity of the product" << endl;
                        cout << "Enter 3 to delete a product" << endl;
                        cout << "Enter 4 to add a product" << endl;
                        cout << "Enter -1 to exit Admin Mode" << endl;

                        cin >> adminAction;

                        switch (adminAction) {
                            case 1:
                                displayProductList();
                                break;

                            case 2:
                                changeProductQuantity();
                                break;

                            case 3:
                                deleteProduct();
                                break;

                            case 4:
                                addProduct();
                                break;

                            default:
                                // Handle other choices if needed
                                break;
                        }
                    }
                } else {
                    cout << "Invalid credentials." << endl;
                }

                break;
            }

            default:
                // Handle other choices if needed
                break;
        }
    }

    return 0;
}