#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    std::cout << "Running tests..." << std::endl;
    int result = RUN_ALL_TESTS();
    std::cout << "Tests completed!" << std::endl;

    return result;
}