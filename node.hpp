#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

namespace ariel {

    template <typename T>
    class Node {
    public:
        T value;
        std::vector<std::shared_ptr<Node<T>>> children;

        Node(const T& val) : value(val) {}

        T& get_value() { return value; }
        const T& get_value() const { return value; }

        std::vector<std::shared_ptr<Node<T>>>& get_children() { return children; }
        const std::vector<std::shared_ptr<Node<T>>>& get_children() const { return children; }
    };

}

#endif // NODE_HPP
