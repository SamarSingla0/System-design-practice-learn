#include <iostream>
#include <vector>
using namespace std;

class Parent {
    public:
        virtual void print(string msg) {
            cout << "Parent: " << msg << endl;
        }
};

class Child : public Parent {
    public:
        void print(string msg) override {
            cout << "Child: " << msg << endl;
        }
};

class Client {
private:
    Parent* p;
public:
    Client(Parent* p) {
        this->p = p;
    }

    void printMsg() {
        p->print("Hello, World!");
    }
};

int main() {
    Parent* parent = new Parent();
    Parent* child = new Child();

    Client* client1 = new Client(child);
    client1->printMsg();

    return 0;
}