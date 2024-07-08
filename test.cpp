// israelmor555@gmail.com
// 206508954

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "complex.hpp"

TEST_CASE("Complex number operations") {
    Complex a(1, 1);
    Complex b(2, 3);

    SUBCASE("String representation") {
        CHECK(a.to_string() == "1 + 1i");
        CHECK(b.to_string() == "2 + 3i");
    }
}

TEST_CASE("Tree operations") {
    auto tree = std::make_shared<ariel::Tree<Complex, 2>>();
    auto root = std::make_shared<ariel::Node<Complex>>(Complex(1, 1));
    tree->add_root(root);

    SUBCASE("Add and retrieve root") {
        REQUIRE(tree->get_root() == root);
    }

    SUBCASE("Add sub-nodes") {
        auto child1 = std::make_shared<ariel::Node<Complex>>(Complex(2, 2));
        auto child2 = std::make_shared<ariel::Node<Complex>>(Complex(3, 3));
        tree->add_sub_node(root, child1);
        tree->add_sub_node(root, child2);
        REQUIRE(root->get_children().size() == 2);
        REQUIRE(root->get_children()[0] == child1);
        REQUIRE(root->get_children()[1] == child2);
    }

    SUBCASE("Pre-order traversal") {
        auto child1 = std::make_shared<ariel::Node<Complex>>(Complex(2, 2));
        auto child2 = std::make_shared<ariel::Node<Complex>>(Complex(3, 3));
        auto grandchild = std::make_shared<ariel::Node<Complex>>(Complex(4, 4));
        tree->add_sub_node(root, child1);
        tree->add_sub_node(root, child2);
        tree->add_sub_node(child1, grandchild);

        std::vector<Complex> expected = {Complex(1, 1), Complex(2, 2), Complex(4, 4), Complex(3, 3)};
        auto it = tree->begin_pre_order();
        for (const auto& val : expected) {
            REQUIRE(it != tree->end_pre_order());
            REQUIRE(it->get_value() == val);
            ++it;
        }
        REQUIRE(it == tree->end_pre_order());
    }

    SUBCASE("In-order traversal") {
        auto child1 = std::make_shared<ariel::Node<Complex>>(Complex(2, 2));
        auto child2 = std::make_shared<ariel::Node<Complex>>(Complex(3, 3));
        auto grandchild = std::make_shared<ariel::Node<Complex>>(Complex(4, 4));
        tree->add_sub_node(root, child1);
        tree->add_sub_node(root, child2);
        tree->add_sub_node(child1, grandchild);

        std::vector<Complex> expected = {Complex(4, 4), Complex(2, 2), Complex(1, 1), Complex(3, 3)};
        auto it = tree->begin_in_order();
        for (const auto& val : expected) {
            REQUIRE(it != tree->end_in_order());
            REQUIRE(it->get_value() == val);
            ++it;
        }
        REQUIRE(it == tree->end_in_order());
    }

    SUBCASE("Post-order traversal") {
        auto child1 = std::make_shared<ariel::Node<Complex>>(Complex(2, 2));
        auto child2 = std::make_shared<ariel::Node<Complex>>(Complex(3, 3));
        auto grandchild = std::make_shared<ariel::Node<Complex>>(Complex(4, 4));
        tree->add_sub_node(root, child1);
        tree->add_sub_node(root, child2);
        tree->add_sub_node(child1, grandchild);

        std::vector<Complex> expected = {Complex(4, 4), Complex(2, 2), Complex(3, 3), Complex(1, 1)};
        auto it = tree->begin_post_order();
        for (const auto& val : expected) {
            REQUIRE(it != tree->end_post_order());
            REQUIRE(it->get_value() == val);
            ++it;
        }
        REQUIRE(it == tree->end_post_order());
    }

    SUBCASE("BFS traversal") {
        auto child1 = std::make_shared<ariel::Node<Complex>>(Complex(2, 2));
        auto child2 = std::make_shared<ariel::Node<Complex>>(Complex(3, 3));
        auto grandchild = std::make_shared<ariel::Node<Complex>>(Complex(4, 4));
        tree->add_sub_node(root, child1);
        tree->add_sub_node(root, child2);
        tree->add_sub_node(child1, grandchild);

        std::vector<Complex> expected = {Complex(1, 1), Complex(2, 2), Complex(3, 3), Complex(4, 4)};
        auto it = tree->begin_bfs();
        for (const auto& val : expected) {
            REQUIRE(it != tree->end_bfs());
            REQUIRE(it->get_value() == val);
            ++it;
        }
        REQUIRE(it == tree->end_bfs());
    }

    SUBCASE("DFS traversal") {
        auto child1 = std::make_shared<ariel::Node<Complex>>(Complex(2, 2));
        auto child2 = std::make_shared<ariel::Node<Complex>>(Complex(3, 3));
        auto grandchild = std::make_shared<ariel::Node<Complex>>(Complex(4, 4));
        tree->add_sub_node(root, child1);
        tree->add_sub_node(root, child2);
        tree->add_sub_node(child1, grandchild);

        std::vector<Complex> expected = {Complex(1, 1), Complex(2, 2), Complex(4, 4), Complex(3, 3)};
        auto it = tree->begin_dfs();
        for (const auto& val : expected) {
            REQUIRE(it != tree->end_dfs());
            REQUIRE(it->get_value() == val);
            ++it;
        }
        REQUIRE(it == tree->end_dfs());
    }
}

TEST_CASE("TreeVisualizer draw test") {
    // Since we cannot visually test the GUI rendering in an automated test,
    // we will simply ensure the TreeVisualizer can be created and called without crashing.

    auto tree = std::make_shared<ariel::Tree<Complex, 2>>();
    auto root = std::make_shared<ariel::Node<Complex>>(Complex(1, 1));
    tree->add_root(root);
    tree->add_sub_node(root, std::make_shared<ariel::Node<Complex>>(Complex(2, 2)));
    tree->add_sub_node(root, std::make_shared<ariel::Node<Complex>>(Complex(3, 3)));

    ariel::TreeVisualizer<Complex, 2> visualizer(*tree);
    sf::RenderWindow window(sf::VideoMode(800, 600), "TreeVisualizer Test");

    CHECK_NOTHROW(visualizer.draw(window));
}
