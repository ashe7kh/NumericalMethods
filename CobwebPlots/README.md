This is a preliminary program written in C that creates cobweb diagrams, with associated plots, (made in GNU plot).

A small introduction to cobweb diagrams:

Cobweb diagrams are a means of illustrating what happens when we iterate a function repeatedly.

So as in the code, let us start with a 0th value: x_0. Then our first value: x_1 = sin(x_0), our second value: x_2 = sin(x_1) = sin(sin(x_0)).

From this, we can construct the cobweb diagram. If we had the line y = x, and a graph of the function to be observed, the graphical (pen and paper algorithm) starts:

1. plot the point (x_0, 0) //starting point
2. draw a line to (x_0,x_1) from (x_0, 0) // x_1 = f(x_0)
3. draw a line to (x_1, x_1) from (x_0, x_1)

Loop, for i from 1 to n:
1. draw a line to (x_i, x_{i+1}) from (x_i, x_i) //x_{i+1} = f(x_i)
2. draw a line to (x_{i+1}, x_{i+1}) from (x_i, x_{i+1})
