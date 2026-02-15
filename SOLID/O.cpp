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

class Persistence {
private: 
    ShoppingCart* cart;
public:
    virtual void save(ShoppingCart* cart) = 0;
};

class SQLPersistence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to sql" << endl;
    }
};

class MongoPersistence : public Persistence {
public:    
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to mongo" << endl;
    }
};

class FilePeristence : public Persistence {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to file" << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 999.99));
    cart->addProduct(new Product("Mouse", 49.99));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePeristence();

    db->save(cart);
    mongo->save(cart); 
    file->save(cart);

    return 0;
}