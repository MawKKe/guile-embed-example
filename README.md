# guile-embed-example

GNU Guile Scheme C/C++ embedding example - with CMake integration

# Build

    $ cmake -B build .
    $ cmake --build build

or via Docker:

    $ docker build -t guile-example-build .

# Run

Run the executable, which opens a Guile shell:

    $ ./build/guile-test

or if you built the Docker image:

    $ docker run -it --rm guile-example-build guile-test

...then access the custom subroutines in the repl:

    scheme@(guile-user)> (my-gettime)
    $1 = (1636677878 . 965159349)

    scheme@(guile-user)> (my-pythagoras 10 20)
    $2 = 22.360679774997898


# Features

This example project defines three native funcions in C/C++, then binds them into the
Guile environment as subroutines. The native functions are callable as if they were
defined directly in scheme.

The `my-gettime` subroutine demonstrates how to return simple pair (cons) of integer values from a
function. This function takes no arguments.

The `my-pythagoras` subroutine demonstrates how to pass values into a native function.
Note the different first argument value passed in respective `scm_c_define_gsubr`  call.

The `my-hostname` subroutine demonstrates error generation; if `HOSTNAME` environment variable
is not set at runtime, the native function raises a `misc-error` into the guile session.

# Dependencies

Tested on Ubuntu 20.04. The following packages are needed:

- `guile-3.0-dev`
- `libgmp-dev`
- `cmake` >= 3.10
- `build-essential`
- `pkg-config`

# License

Copyright 2021 Markus Holmström (MawKKe)

The works under this repository are licenced under Apache License 2.0. See file LICENSE for more information.
