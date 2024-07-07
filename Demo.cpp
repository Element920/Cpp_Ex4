#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include "complex.hpp"

int main() {
    // Create a k-ary tree (K = 3)
    ariel::Tree<Complex, 3> tree;

    // Add root node
    tree.add_root(std::make_shared<ariel::Node<Complex>>(Complex(1.1, 0.0)));

    // Get root node
    auto root = tree.get_root();

    // Create and add child nodes
    auto child1 = std::make_shared<ariel::Node<Complex>>(Complex(1.2, 0.0));
    auto child2 = std::make_shared<ariel::Node<Complex>>(Complex(1.3, 0.0));
    auto child3 = std::make_shared<ariel::Node<Complex>>(Complex(1.4, 0.0));
    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(root, child3);

    // Add grandchildren
    auto grandchild1 = std::make_shared<ariel::Node<Complex>>(Complex(1.5, 0.0));
    tree.add_sub_node(child1, grandchild1);

    auto grandchild2 = std::make_shared<ariel::Node<Complex>>(Complex(1.6, 0.0));
    tree.add_sub_node(child2, grandchild2);

    // SFML window setup
    sf::RenderWindow window(sf::VideoMode(800, 600), "K-ary Tree Visualizer");

    // Tree visualizer
    ariel::TreeVisualizer<Complex, 3> visualizer(tree);

    // Main loop for SFML window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        visualizer.draw(window);
        window.display();
    }

    return 0;
}
