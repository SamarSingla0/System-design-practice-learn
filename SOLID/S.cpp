#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
private:
    vector<Product*>products;
public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts() {
        return products;
    }

    double calculateTotal() {
        double total = 0;
        for(auto p : products) {
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter {
private:
    ShoppingCart* cart;
public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void printInvoice() {
        cout << "shopping Cart Invoice:\n";
        for(auto it : cart->getProducts()) {
            cout << it->name << ": $" << it->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};

class ShoppingCartStorage {
private:
    ShoppingCart* cart;
public:
    ShoppingCartStorage(ShoppingCart* cart) {
        this->cart = cart;
    }

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 999.99));
    cart->addProduct(new Product("Mouse", 49.99));

    ShoppingCartPrinter* db = new ShoppingCartPrinter(cart);
    db->printInvoice();

    return 0;
}