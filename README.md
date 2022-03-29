# ConnectN (C)
A ConnectN program in C. This game is based off of the connect4 game. But instead of 4 pieces lined up to win, you need a line of N pieces. Hence the naming connectN. The program expects 3 arguments. The number of rows, the number of columns, and the number N.

**Full Game Example**
----------------------------------
```
connectN.exe  7 7 3

6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * * * * * * *
0 * * * * * * *
  0 1 2 3 4 5 6
Enter a column between 0 and 6 to play in: 1
6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * * * * * * *
0 * X * * * * *
  0 1 2 3 4 5 6
Enter a column between 0 and 6 to play in: 2
6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * * * * * * *
0 * X O * * * *
  0 1 2 3 4 5 6
Enter a column between 0 and 6 to play in: 2
6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * * X * * * *
0 * X O * * * *
  0 1 2 3 4 5 6
Enter a column between 0 and 6 to play in: 3
6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * * X * * * *
0 * X O O * * *
  0 1 2 3 4 5 6
Enter a column between 0 and 6 to play in: 3
6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * * X X * * *
0 * X O O * * *
  0 1 2 3 4 5 6
Enter a column between 0 and 6 to play in: 0
6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * * X X * * *
0 O X O O * * *
  0 1 2 3 4 5 6
Enter a column between 0 and 6 to play in: 1
6 * * * * * * *
5 * * * * * * *
4 * * * * * * *
3 * * * * * * *
2 * * * * * * *
1 * X X X * * *
0 O X O O * * *
  0 1 2 3 4 5 6
Player 1 Won!
```
