#!/usr/bin/env python3

import sys
import runpy

sys.path.insert(0, 'external/zeno')
try:
    from zenqt.main import main
    sys.exit(main())
except ImportError as e:
    raise ImportError('please run `git submodule update --init --recursive`') from e
