#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace ariel;

int main() {
    // Create a binary tree of Complex numbers
    auto binaryTree = std::make_shared<Tree<Complex, 2>>();
    binaryTree->add_root(std::make_shared<Node<Complex>>(Complex(1, 1)));

    auto root = binaryTree->get_root();
    binaryTree->add_sub_node(root, std::make_shared<Node<Complex>>(Complex(2, 2)));
    binaryTree->add_sub_node(root, std::make_shared<Node<Complex>>(Complex(3, 3)));

    auto child1 = root->get_children()[0];
    binaryTree->add_sub_node(child1, std::make_shared<Node<Complex>>(Complex(4, 4)));
    binaryTree->add_sub_node(child1, std::make_shared<Node<Complex>>(Complex(5, 5)));

    auto child2 = root->get_children()[1];
    binaryTree->add_sub_node(child2, std::make_shared<Node<Complex>>(Complex(6, 6)));
    binaryTree->add_sub_node(child2, std::make_shared<Node<Complex>>(Complex(7, 7)));

    // Display the tree and BFS traversal
    std::cout << "Binary Tree (BFS Traversal):" << std::endl;
    for (auto it = binaryTree->begin_bfs(); it != binaryTree->end_bfs(); ++it) {
        std::cout << it->get_value().to_string() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Binary Tree (DFS Traversal):" << std::endl;
    for (auto it = binaryTree->begin_dfs(); it != binaryTree->end_dfs(); ++it) {
        std::cout << it->get_value().to_string() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal:" << std::endl;
    for (auto it = binaryTree->begin_pre_order(); it != binaryTree->end_pre_order(); ++it) {
        std::cout << it->get_value().to_string() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "In-Order Traversal:" << std::endl;
    for (auto it = binaryTree->begin_in_order(); it != binaryTree->end_in_order(); ++it) {
        std::cout << it->get_value().to_string() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Post-Order Traversal:" << std::endl;
    for (auto it = binaryTree->begin_post_order(); it != binaryTree->end_post_order(); ++it) {
        std::cout << it->get_value().to_string() << std::endl;
    }
    std::cout << std::endl;

    std::cout << std::endl;
    auto treeK = std::make_shared<Tree<int, 3>>();
    treeK->add_root(std::make_shared<Node<int>>(1));
    treeK->add_sub_node(treeK->get_root(), std::make_shared<Node<int>>(2));
    treeK->add_sub_node(treeK->get_root(), std::make_shared<Node<int>>(3));
    treeK->add_sub_node(treeK->get_root(), std::make_shared<Node<int>>(4));
    treeK->add_sub_node(treeK->get_root()->get_children()[0], std::make_shared<Node<int>>(5));
    treeK->add_sub_node(treeK->get_root()->get_children()[1], std::make_shared<Node<int>>(6));
    treeK->add_sub_node(treeK->get_root()->get_children()[1], std::make_shared<Node<int>>(7));
    treeK->add_sub_node(treeK->get_root()->get_children()[2], std::make_shared<Node<int>>(8));
    treeK->add_sub_node(treeK->get_root()->get_children()[2], std::make_shared<Node<int>>(9));
    treeK->add_sub_node(treeK->get_root()->get_children()[2], std::make_shared<Node<int>>(10));

    std::cout << "Tree K=3 DFS - Expected Output from Orders on K != 2" << std::endl;
    for (auto it = treeK->begin_dfs(); it != treeK->end_dfs(); ++it) {
        std::cout << it->get_value() << " ";
    }
    std::cout << std::endl;

    // All printing should be in the same order as the DFS iterator
    std::cout << "Tree K=3 In-Order:" << std::endl;
    for (auto it = treeK->begin_in_order(); it != treeK->end_in_order(); ++it) {
        std::cout << it->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "Tree K=3 Pre-Order:" << std::endl;
    for (auto it = treeK->begin_pre_order(); it != treeK->end_pre_order(); ++it) {
        std::cout << it->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "Tree K=3 Post-Order:" << std::endl;
    for (auto it = treeK->begin_post_order(); it != treeK->end_post_order(); ++it) {
        std::cout << it->get_value() << " ";
    }
    std::cout << std::endl;

    // Create a window to draw the binary tree
    sf::RenderWindow window(sf::VideoMode(800, 600), "Complex Binary-Tree Drawing");

    // Create the visualizer
    TreeVisualizer<Complex, 2> visualizer(*binaryTree);

    // Main loop to keep the window open and handle events
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close the window if the close event is triggered
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black); // Clear the window with a black color
        visualizer.draw(window); // Draw the binary tree on the window
        window.display(); // Display the contents of the window
    }

    // Create another window to draw the tree of type Tree<int, 3>
    sf::RenderWindow window2(sf::VideoMode(800, 600), "Tree<int, 3> Drawing");

    // Create the visualizer for Tree<int, 3>
    TreeVisualizer<int, 3> visualizer2(*treeK);

    // Main loop to keep the second window open and handle events
    while (window2.isOpen()) {
        sf::Event event;
        while (window2.pollEvent(event)) {
            // Close the window if the close event is triggered
            if (event.type == sf::Event::Closed) {
                window2.close();
            }
        }

        window2.clear(sf::Color::Black); // Clear the window with a black color
        visualizer2.draw(window2); // Draw the Tree<int, 3> on the window
        window2.display(); // Display the contents of the window
    }

    return 0;
}
