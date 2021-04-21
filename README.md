# Invert File Tree in C++

This is like [Inverting Binary Tree](https://twitter.com/mxcl/status/608682016205344768), but instead of the Binary Tree it's a File Tree.

This is intended as a simple exercise to learn how to use [std::filesystem](https://en.cppreference.com/w/cpp/filesystem)

The idea is to implement a program that can transform this:

```console
tree ./data/
./data/
├── bar
└── foo
    ├── baz
    └── test
        ├── hello
        └── world
```

into this:

```console
tree ./data/
./data/
├── bar
│   ├── baz
│   │   ├── hello
│   │   └── world
│   └── test
└── foo
```

## Quick Start

```console
$ make
$ ./generator ./data/
$ tree ./data/
./data/
├── bar
└── foo
    ├── baz
    └── test
        ├── hello
        └── world
$ ./inverter ./data/
$ tree ./data/
./data/
├── bar
│   ├── baz
│   │   ├── hello
│   │   └── world
│   └── test
└── foo
```

## Screencast

[![thumbnail](http://i3.ytimg.com/vi/weRRlkbw0FE/hqdefault.jpg)](https://www.youtube.com/watch?v=weRRlkbw0FE)
