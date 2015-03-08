A computer problem
==================

See
---

1. UVA 10202
2. HDU 1270 (There are some differences but nearly same)

Compile
-------

I like llvm, but gcc is also allowed.

```

    clang++ table_of_number

```

Run
---

Just run the binary.
The input should look like:
```

    3 1269 1160 1663
    3 1 1 1
    5 226 223 225 224 227 229 228 226 225 227
    5 216 210 204 212 220 214 222 208 216 210
    5 -1 0 -1 -2 1 0 -1 1 0 -1
    5 79950 79936 79942 79962 79954 79972 79960 79968 79924 79932

```

And the output shall look like:
```

    383 777 886
    Impossible
    111 112 113 114 115
    101 103 107 109 113
    -1 -1 0 0 1
    39953 39971 39979 39983 39989

```

Generate sample
---------------

I have written a little program to generate sample input and 
sample output.

Compile it:
```

    clang++ table_of_number_test.cpp

```

Run it like this:
```

    ./a.out > table_of_number.input 2> table_of_number.output

```

Then, you could check our program with: (binary file below is not which is run to generate
sample input and sample output)
```

    ./a.out < ./table_of_number.input | diff table_of_number.output -

```
