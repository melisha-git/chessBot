cmake_minimum_required(VERSION 3.10)

project(ChessBot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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

# Добавьте файлы заголовков (опционально для IDE)
set(HEADERS
    Controller.hpp
    SMove.hpp

    Pieces/APiece.hpp
    Pieces/Bishop.hpp
    Pieces/King.hpp
    Pieces/Knight.hpp
    Pieces/Pawn.hpp
    Pieces/Queen.hpp
    Pieces/Rook.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# # Укажите путь к заголовочным файлам
# target_include_directories(${PROJECT_NAME} PRIVATE include)