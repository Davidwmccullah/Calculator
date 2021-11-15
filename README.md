Bobby's Calculator

Author: lovebobbyandrew
Version: 1.0
Updated: September 4, 2021

Project completed, as plans for functions other than addition and subtraction scrapped. Starting over in order to build a lighter base with more modular functions.

<h1>

Calculator
</h1>

<h2>

David McCullah - Forked from lovebobbyandrew
</h2>

<h3>

Purpose
</h3>

<p>

This program serves as a general purpose calculator with a CLI GUI.

</p>

<h3>

Dependencies
</h3>

<p>

```
cmake version 3.21.3

gcc version 11.1.0 (GCC)
```

</p>

<h3>

Syntax
</h3>

<p>

Make a build directory in:
```
Calculator/build
```

In the build directory, run CMake:
```
cmake ..
```

Then build the executable:
```
make
```

Now the Program is ready:
```
./Calculator
```
</p>

<h3>

Output
</h3>

<p>

The program will return errors for multiple conditions. These error codes should be considered [DEPRICATED].

Return Code | Definition | Description
---|---|---
0 | Success | No error occured.
1 | Syntax Error | The executable did not recieve two arguments. (```./[EXECUTABLE_NAME] [NUMBER]```)
2 | Argument Error | The argument passed was not a whole number.

On a success, the program will output the nth number in the Fibonacci sequence as:
```
Fibonacci #[N]:
        [VALUE]
```

Example:
```
Fibonacci #67:
        44945570212853
```
</p>
