# Invert File Tree in C++

This is like [Inverting Binary Tree](https://twitter.com/mxcl/status/608682016205344768), but instead of the Binary Tree it's File Tree.

This is intended as a simple exercise to learn how to use [std::filesystem](https://en.cppreference.com/w/cpp/filesystem)

The idea is to implement a program that can transform this:

```console
$ tree data/
data/
├── bar
└── foo
    ├── hello
    └── world

1 directory, 3 files
$ cat data/foo/hello
Hello
$ cat data/foo/world
World
```

into this:

```console
$ tree data/
data/
├── foo
└── bar
    ├── hello
    └── world

1 directory, 3 files
$ cat data/foo/hello
World
$ cat data/foo/world
Hello
```

## Quick Start

```console
$ make
$ ./generator ./data/
$ tree ./data/
...
$ ./inverter ./data/
$ tree ./data/
...
```
