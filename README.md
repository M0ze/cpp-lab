# cpp-lab

C++ from console apps upward. RAII and the STL are the point — not raw
pointers.

## Projects

| # | Project | What it teaches |
|---|---------|-----------------|
| 1 | `bank-menu` — console banking | classes, iostream, STL containers |
| 2 | `snake` — raylib game loop | OOP, RAII, references |
| 3 | `json-parser` — recursive descent parser | smart pointers, templates |
| 4 | `http-server` — sockets + threads | concurrency, move semantics |

Ship them in order. Project 2 is the fun one; project 4 is the resume one.

## How to run

    cd bank-menu
    cmake -B build && cmake --build build
    ./build/bank-menu

## Toolchain (this machine)

    g++ 16.2.1   (clang 23.1.3 also available)
    cmake        (installing)

Standard: C++20 minimum.

## Rules

- `-Wall -Wextra -Werror -pedantic` on from day one.
- No raw `new`/`delete` in project 2 onward — use smart pointers or containers.
- Prefer `std::` over hand-rolled. If you write a linked list here, you have
  a bug in your thinking.
