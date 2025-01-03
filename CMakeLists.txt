cmake_minimum_required(VERSION 3.10)

project(ChessBot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Настройка vcpkg
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
endif()

set(CMAKE_PREFIX_PATH "/home/melisha/code/cppCode/chessBot/vcpkg/installed/x64-linux")

find_package(GTest CONFIG REQUIRED)

# Основные исходники
set(SOURCES
    Controller.cpp

    Pieces/APiece.cpp
    Pieces/Bishop.cpp
    Pieces/King.cpp
    Pieces/Knight.cpp
    Pieces/Pawn.cpp
    Pieces/Queen.cpp
    Pieces/Rook.cpp
)

# Тестовые исходники
set(TESTS_SOURCES
    unittests/unit_example.cpp
    unittests/PiecesTests/BishopTests.cpp
    unittests/SMoveTests.cpp
)

# Основной исполняемый файл
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

# Тесты
add_executable(unittests unittests/main.cpp ${TESTS_SOURCES} ${SOURCES})
target_link_libraries(unittests PRIVATE GTest::gtest GTest::gtest_main)

# Регистрация тестов
enable_testing()
add_test(NAME AllTests COMMAND unittests)
