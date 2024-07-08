// israelmor555@gmail.com
// 206508954

// node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <vector>

namespace ariel {

    // Example Node class for double values
    class Node {
    public:
        Node(double value) : value(value) {}

        double get_value() const { return value; }

        void add_sub_node(std::shared_ptr<Node> child) {
            children.push_back(child);
        }

        const std::vector<std::shared_ptr<Node>>& get_children() const {
            return children;
        }

    private:
        double value;
        std::vector<std::shared_ptr<Node>> children;
    };

} // namespace ariel

#endif // NODE_HPP
