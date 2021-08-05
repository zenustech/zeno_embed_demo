# ZENO Private Repository

Holding private ZENO projects that aren't open-source.

# Setup (important)

First of all, please add this to your `~/.bashrc`:
```bash
[ -f .bash_localrc ] && . .bash_localrc
```
Then quit, and restart the shell.
(This is to add `external/zeno` to `PYTHONPATH` every time you enter this folder)

## Build

```bash
git submodule update --init --recursive
make all
```

## Run

```bash
make run
```

## Windows

"自生自灭", we could ensure Linux-only across the company in our private repo, ain't we?
aye!
