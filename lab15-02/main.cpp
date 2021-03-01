#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Bank{
public:
    int amount;
    virtual int card();
    virtual int vip_card();
};