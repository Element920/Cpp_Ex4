// #define CATCH_CONFIG_MAIN
// #include "doctest.h"
// #include "complex.hpp"  // Include your Complex class header
// #include "tree.hpp"     // Include your Tree class header

// // MockupNode for testing purposes (replace with your actual Node implementation if needed)
// template <typename T>
// class MockupNode : public ariel::Node<T> {
// public:
//     MockupNode(const T& value) : ariel::Node<T>(value) {}
// };

// // Test cases for Tree and Complex classes
// TEST_CASE("Tree and Complex Tests") {
//     SECTION("Complex Operations") {
//         Complex c1(2.0, 3.0);
//         Complex c2(1.0, -2.0);

//         // Test arithmetic operations
//         REQUIRE((c1 + c2) == Complex(3.0, 1.0));
//         REQUIRE((c1 - c2) == Complex(1.0, 5.0));
//         REQUIRE((c1 * c2) == Complex(8.0, -1.0));
        
//         // Test division
//         REQUIRE((c1 / c2) == Complex(0.4, 1.6));

//         // Test equality
//         REQUIRE(c1 == Complex(2.0, 3.0));
//         REQUIRE(c1 != c2);

//         // Test to_string
//         REQUIRE(c1.to_string() == "2 + 3i");
//         REQUIRE(c2.to_string() == "1 - 2i");
//     }

//     SECTION("Tree Structure and Iterators") {
//         using namespace ariel;

//         // Create nodes
//         auto root_node = std::make_shared<MockupNode<double>>(1.1);
//         Tree<double, 2> tree;
//         tree.add_root(root_node);

//         auto n1 = std::make_shared<MockupNode<double>>(1.2);
//         auto n2 = std::make_shared<MockupNode<double>>(1.3);
//         auto n3 = std::make_shared<MockupNode<double>>(1.4);
//         auto n4 = std::make_shared<MockupNode<double>>(1.5);
//         auto n5 = std::make_shared<MockupNode<double>>(1.6);

//         tree.add_sub_node(root_node, n1);
//         tree.add_sub_node(root_node, n2);
//         tree.add_sub_node(n1, n3);
//         tree.add_sub_node(n1, n4);
//         tree.add_sub_node(n2, n5);

//         // Ensure basic structure
//         REQUIRE(tree.get_root() == root_node);
//         REQUIRE(root_node->get_children().size() == 2);
//         REQUIRE(n1->get_children().size() == 2);
//         REQUIRE(n2->get_children().size() == 1);

//         // Test iterators (example: PreOrderIterator)
//         auto pre_order_it = tree.begin_pre_order();
//         REQUIRE(pre_order_it != tree.end_pre_order());
//         REQUIRE((*pre_order_it).get_value() == 1.1);

//         ++pre_order_it;
//         REQUIRE(pre_order_it != tree.end_pre_order());
//         REQUIRE((*pre_order_it).get_value() == 1.2);

//         ++pre_order_it;
//         REQUIRE(pre_order_it != tree.end_pre_order());
//         REQUIRE((*pre_order_it).get_value() == 1.4);

//         ++pre_order_it;
//         REQUIRE(pre_order_it != tree.end_pre_order());
//         REQUIRE((*pre_order_it).get_value() == 1.5);

//         ++pre_order_it;
//         REQUIRE(pre_order_it != tree.end_pre_order());
//         REQUIRE((*pre_order_it).get_value() == 1.3);

//         ++pre_order_it;
//         REQUIRE(pre_order_it != tree.end_pre_order());
//         REQUIRE((*pre_order_it).get_value() == 1.6);

//         ++pre_order_it;
//         REQUIRE(pre_order_it == tree.end_pre_order());
//     }
// }
