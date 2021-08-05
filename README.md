# ZENO Addon Wizard

Demo project showing on how to add custom nodes to ZENO.

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

Then open `graphs/MyPrimitiveOps.zsg` and click `Run`.

# Coding

The `YourProject/` is a demo project for showing how to add custom nodes in ZENO with its C++ API.

See [MyPrimitiveOps.cpp](YourProject/MyPrimitiveOps.cpp) for custom primitive operation.
See [CustomNumber.cpp](YourProject/CustomNumber.cpp) for defining custom object.

Let me know if you need more demos here by opening an [issue](https://github.com/zenustech/zeno_addon_wizard/issues).
