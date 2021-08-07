# ZENO Embed Demo

Demo project showing on how to use ZENO in a embed environment.

# Setup

First of all, run this command:
```bash
git submodule update --init --recursive
```
To fetch ZENO which is included a submodule.

## Build

```bash
cmake -B build
cmake --build build --parallel
```

## Run

```bash
./run.py
```
