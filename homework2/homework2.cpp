#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::weak_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        std::weak_ptr<node> node1 = std::make_shared<node>(1);
        std::weak_ptr<node> node2 = std::make_shared<node>(2);
        node1.swap(node2);
        node2.swap(node1);
    }

    return EXIT_SUCCESS;
}