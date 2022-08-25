/*
https://codeforces.com/contest/1499
https://codeforces.com/blog/entry/88812

You have a board represented as a grid with 2×n cells.

The first k1 cells on the first row and first k2 cells on the second row are colored in white. 
All other cells are colored in black.

You have w white dominoes (2×1 tiles, both cells are colored in white) and 
b black dominoes (2×1 tiles, both cells are colored in black).

You can place a white domino on the board if both board's cells are white and not occupied by any other domino. 
In the same way, you can place a black domino if both cells are black and not occupied by any other domino.

Can you place all w+b dominoes on the board if you can place dominoes both horizontally and vertically?

Input
The first line contains a single integer t (1≤t≤3000) — the number of test cases.

The first line of each test case contains three integers n, k1 and k2 (1≤n≤1000; 0≤k1,k2≤n).

The second line of each test case contains two integers w and b (0≤w,b≤n).

Output
For each test case, print YES if it's possible to place all w+b 
dominoes on the board and NO, otherwise.

You may print every letter in any case you want 
(so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
input
5
1 0 1
1 0
1 1 1
0 0
3 0 0
1 3
4 3 1
2 2
5 4 3
3 1

output
NO
YES
NO
YES
YES

Note:
In the first test case, n=1, k1=0 and k2=1. 
It means that 2×1 board has black cell (1,1) and white cell (2,1). 
So, you can't place any white domino, since there is only one white cell.

In the second test case, the board of the same size 2×1, but both cell are white. 
Since w=0 and b=0, so you can place 0+0=0 dominoes on the board.

In the third test case, board 2×3, but fully colored in black (since k1=k2=0), 
so you can't place any white domino.
    
In the fourth test case, cells (1,1), (1,2), (1,3), and (2,1) are white and 
other cells are black. You can place 2 white dominoes at positions ((1,1),(2,1)) and 
((1,2),(1,3)) and 2 black dominoes at positions ((1,4),(2,4)) ((2,2),(2,3)).

/**/

/*
Solution:

We can prove that if we have k1+k2 white cells on the board then we can place any w 
white dominoes as long as 2w≤k1+k2.

The proof is the following: if k1≥k2 let's place one domino at position 
((1,k1−1),(1,k1)), otherwise let's place domino at position ((2,k2−1),(2,k2)). 
Then we can solve the placement of w−1 dominoes in k1−2 cells in the first row and k2 
cells of the second row recursively (or, analogically, k1 and k2−2).

At the end, either all dominoes are placed or k1<2 and k2<2. 
If k1=0 or k2=0 then, since 2w≤k1+k2, then w=0 or we successfully placed all dominoes. 
If k1=1 and k2=1 then we, possibly, need to place one domino more — and we can place it vertically.

We can prove that we can place any b dominoes as long as 2b≤(n−k1)+(n−k2) in the same manner.

As a result, all we need to check is that 2w≤k1+k2 and 2b≤(n−k1)+(n−k2).
*/

/*
fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k1, k2) = readLine()!!.split(' ').map { it.toInt() }
        val (w, b) = readLine()!!.split(' ').map { it.toInt() }

        if (k1 + k2 >= 2 * w && (n - k1) + (n - k2) >= 2 * b)
            println("YES")
        else
            println("NO")
    }
}
*/