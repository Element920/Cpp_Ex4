#ifndef TREE_HPP
#define TREE_HPP
#include "complex.hpp"
#include "node.hpp"
#include <memory>
#include <stdexcept>
#include <stack>
#include <queue>
#include <SFML/Graphics.hpp>

namespace ariel {

template <typename T, size_t K>
class Tree {
public:
    using NodePtr = std::shared_ptr<Node<T>>;

    Tree() : root(nullptr) {}
    ~Tree() {}

    void add_root(NodePtr root_node);
    void add_sub_node(NodePtr parent, NodePtr child);

    NodePtr get_root() const { return root; }

    // Iterator classes
    class PreOrderIterator;
    class PostOrderIterator;
    class InOrderIterator;
    class BFSIterator;
    class DFSIterator;

    // Iterators
    PreOrderIterator begin_pre_order() const;
    PreOrderIterator end_pre_order() const;

    PostOrderIterator begin_post_order() const;
    PostOrderIterator end_post_order() const;

    InOrderIterator begin_in_order() const;
    InOrderIterator end_in_order() const;

    BFSIterator begin_bfs() const;
    BFSIterator end_bfs() const;

    DFSIterator begin_dfs() const;
    DFSIterator end_dfs() const;

private:
    NodePtr root;
};

// PreOrderIterator class
template <typename T, size_t K>
class Tree<T, K>::PreOrderIterator {
private:
    std::stack<NodePtr> nodes;

public:
    PreOrderIterator(NodePtr root) {
        if (root) {
            nodes.push(root);
        }
    }

    bool operator!=(const PreOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const PreOrderIterator& other) const {
        return nodes.empty() == other.nodes.empty();
    }

    PreOrderIterator& operator++() {
        if (!nodes.empty()) {
            NodePtr current = nodes.top();
            nodes.pop();
            for (auto it = current->get_children().rbegin(); it != current->get_children().rend(); ++it) {
                nodes.push(*it);
            }
        }
        return *this;
    }

    Node<T>& operator*() { return *nodes.top(); }
    Node<T>* operator->() { return nodes.top().get(); }
};

// PostOrderIterator class
template <typename T, size_t K>
class Tree<T, K>::PostOrderIterator {
private:
    std::stack<NodePtr> nodes;
    NodePtr last_visited = nullptr;

    void push_left(NodePtr node) {
        while (node) {
            nodes.push(node);
            if (!node->get_children().empty()) {
                node = node->get_children().front();
            } else {
                break;
            }
        }
    }

public:
    PostOrderIterator(NodePtr root) {
        if (root) {
            push_left(root);
        }
    }

    bool operator!=(const PostOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const PostOrderIterator& other) const {
        return nodes.empty() == other.nodes.empty();
    }

    PostOrderIterator& operator++() {
        if (!nodes.empty()) {
            NodePtr top = nodes.top();
            nodes.pop();

            if (!nodes.empty() && !nodes.top()->get_children().empty()) {
                auto& siblings = nodes.top()->get_children();
                auto it = std::find(siblings.begin(), siblings.end(), top);
                if (it != siblings.end() && ++it != siblings.end()) {
                    push_left(*it);
                }
            }

            last_visited = top;
        }
        return *this;
    }

    Node<T>& operator*() { return *nodes.top(); }
    Node<T>* operator->() { return nodes.top().get(); }
};


// InOrderIterator class
template <typename T, size_t K>
class Tree<T, K>::InOrderIterator {
private:
    std::stack<NodePtr> nodes;

    void push_left(NodePtr node) {
        while (node) {
            nodes.push(node);
            node = node->get_children().empty() ? nullptr : node->get_children().front();
        }
    }

public:
    InOrderIterator(NodePtr root) {
        push_left(root);
    }

    bool operator!=(const InOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const InOrderIterator& other) const {
        return nodes.empty() == other.nodes.empty();
    }

    InOrderIterator& operator++() {
        if (!nodes.empty()) {
            NodePtr node = nodes.top();
            nodes.pop();
            if (!node->get_children().empty()) {
                push_left(node->get_children().back());
            }
        }
        return *this;
    }

    Node<T>& operator*() { return *nodes.top(); }
    Node<T>* operator->() { return nodes.top().get(); }
};

// BFSIterator class
template <typename T, size_t K>
class Tree<T, K>::BFSIterator {
private:
    std::queue<NodePtr> nodes;

public:
    BFSIterator(NodePtr root) {
        if (root) {
            nodes.push(root);
        }
    }

    bool operator!=(const BFSIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const BFSIterator& other) const {
        return nodes.empty() == other.nodes.empty();
    }

    BFSIterator& operator++() {
        if (!nodes.empty()) {
            NodePtr current = nodes.front();
            nodes.pop();
            for (const auto& child : current->get_children()) {
                nodes.push(child);
            }
        }
        return *this;
    }

    Node<T>& operator*() { return *nodes.front(); }
    Node<T>* operator->() { return nodes.front().get(); }
};

// DFSIterator class
template <typename T, size_t K>
class Tree<T, K>::DFSIterator {
private:
    std::stack<NodePtr> nodes;

public:
    DFSIterator(NodePtr root) {
        if (root) {
            nodes.push(root);
        }
    }

    bool operator!=(const DFSIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const DFSIterator& other) const {
        return nodes.empty() == other.nodes.empty();
    }

    DFSIterator& operator++() {
        if (!nodes.empty()) {
            NodePtr current = nodes.top();
            nodes.pop();
            for (auto it = current->get_children().rbegin(); it != current->get_children().rend(); ++it) {
                nodes.push(*it);
            }
        }
        return *this;
    }

    Node<T>& operator*() { return *nodes.top(); }
    Node<T>* operator->() { return nodes.top().get(); }
};

template<typename T, size_t K>
void Tree<T, K>::add_root(NodePtr root_node) {
    root = root_node;
}

template<typename T, size_t K>
void Tree<T, K>::add_sub_node(NodePtr parent, NodePtr child) {
    if (parent->get_children().size() < K) {
        parent->get_children().push_back(child);
    } else {
        throw std::invalid_argument("Number of children exceeds limit for this node");
    }
}

template<typename T, size_t K>
typename Tree<T, K>::PreOrderIterator Tree<T, K>::begin_pre_order() const {
    return PreOrderIterator(root);
}

template<typename T, size_t K>
typename Tree<T, K>::PreOrderIterator Tree<T, K>::end_pre_order() const {
    return PreOrderIterator(nullptr);
}

template<typename T, size_t K>
typename Tree<T, K>::PostOrderIterator Tree<T, K>::begin_post_order() const {
    return PostOrderIterator(root);
}

template<typename T, size_t K>
typename Tree<T, K>::PostOrderIterator Tree<T, K>::end_post_order() const {
    return PostOrderIterator(nullptr);
}

template<typename T, size_t K>
typename Tree<T, K>::InOrderIterator Tree<T, K>::begin_in_order() const {
    return InOrderIterator(root);
}

template<typename T, size_t K>
typename Tree<T, K>::InOrderIterator Tree<T, K>::end_in_order() const {
    return InOrderIterator(nullptr);
}

template<typename T, size_t K>
typename Tree<T, K>::BFSIterator Tree<T, K>::begin_bfs() const {
    return BFSIterator(root);
}

template<typename T, size_t K>
typename Tree<T, K>::BFSIterator Tree<T, K>::end_bfs() const {
    return BFSIterator(nullptr);
}

template<typename T, size_t K>
typename Tree<T, K>::DFSIterator Tree<T, K>::begin_dfs() const {
    return DFSIterator(root);
}

template<typename T, size_t K>
typename Tree<T, K>::DFSIterator Tree<T, K>::end_dfs() const {
    return DFSIterator(nullptr);
}


template <typename T, size_t K>
class TreeVisualizer {
public:
    TreeVisualizer(const Tree<T, K>& tree) : tree(tree) {}

    void draw(sf::RenderWindow& window) {
        auto root = tree.get_root();
        if (root) {
            float x = window.getSize().x / 2.0f;
            float y = 50.0f;
            drawNode(window, root, x, y, window.getSize().x / 4.0f);
        }
    }

private:
    const Tree<T, K>& tree;

    void drawNode(sf::RenderWindow& window, typename Tree<T, K>::NodePtr node, float x, float y, float xOffset) {
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(x - circle.getRadius(), y - circle.getRadius());
        window.draw(circle);

        sf::Text text;
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            // Handle error
        }
        text.setFont(font);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White);

        // Convert node value to string
        std::string valueString;
        if constexpr (std::is_same_v<T, Complex>) {
            valueString = node->get_value().to_string();
        } else {
            valueString = std::to_string(node->get_value());
        }
        
        text.setString(valueString);
        text.setPosition(x - circle.getRadius() + 10, y - circle.getRadius() + 10);
        window.draw(text);

        auto children = node->get_children();
        float childY = y + 100.0f;
        for (size_t i = 0; i < children.size(); ++i) {
            float childX = x + (i - (children.size() - 1) / 2.0f) * xOffset;
            if (children[i]) {
                sf::Vertex line[] = {
                    sf::Vertex(sf::Vector2f(x, y)),
                    sf::Vertex(sf::Vector2f(childX, childY))
                };
                window.draw(line, 2, sf::Lines);
                drawNode(window, children[i], childX, childY, xOffset / 2.0f);
            }
        }
    }
};

} // namespace ariel

#endif // TREE_HPP
