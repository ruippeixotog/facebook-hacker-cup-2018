# Facebook Hacker Cup 2018

This repository contains my solutions to the problems from [Facebook Hacker Cup 2018][1]. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [25: Tourist][qual1] (`tourist`)
* ✓ [30: Interception][qual2] (`interception`)
* ✓ [45: Ethan Searches for a String][qual3] (`ethan-searches-for-a-string`)

### Round 1

* ✓ [15: Let It Flow][round11] (`let-it-flow`)
* ✓ [20: Ethan Traverses a Tree][round12] (`ethan-traverses-a-tree`)
* ✓ [28: Platform Parkour][round13] (`platform-parkour`)

### Round 2

* ✓ [8: Ethan Finds the Shortest Path][round21] (`ethan-finds-the-shortest-path`)
* ✓ [20: Jack's Candy Shop][round22] (`jacks-candy-shop`)

[1]: https://www.facebook.com/hackercup
[qual1]: https://www.facebook.com/hackercup/problem/1632703893518337/
[qual2]: https://www.facebook.com/hackercup/problem/175329729852444/
[qual3]: https://www.facebook.com/hackercup/problem/1153996538071503/
[round11]: https://www.facebook.com/hackercup/problem/180494849326631/
[round12]: https://www.facebook.com/hackercup/problem/232395994158286/
[round13]: https://www.facebook.com/hackercup/problem/1892930427431211/
[round21]: https://www.facebook.com/hackercup/problem/988017871357549/
[round22]: https://www.facebook.com/hackercup/problem/638251746380051/
