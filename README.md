AdvProgPA2
==========

Advanced Programming Assignment 2
 CSCI 3320
Program Assignment 2
Spring 2013
Due Date:
Monday, February 25, 2013
Delivery
This is a multiple file program that must be archived using the tar command. Deliver
a single file named pa2.tar (all lowercase) as an attachment to an email that you send
to the class account 3320@orion.ucdenver.edu. Put PA2 in the subject field, and your
name in the body of the email. I prefer you use your email account on the Ouray
server to deliver the program. Here is a tar command for this assignment.
tar –cvf pa2.tar pa2.cpp pa2functions.h pa2functions.cpp matrix.h matrix.tem
Program objectives
The objectives of this assignment are as follows.
An ability to use current techniques, skills, and tools necessary for computing practice
(ABET i).
Value
This program is worth 15 points. The distribution of points will be as follows.
Criterion
Templates
Matrix
Operators new and delete
Program style (see below)
Correct output with annotation
Error checking
Greeting
Value
1
4
1
2
5
1
1
Problem (A graph theoretic problem using a matrix class)
Given a graph, G=(V,E) where V is a set of vertices and E is a set of edges, we have the
concepts of paths and connectivity. Intuitively, a path is a sequence of edges that connect
two arbitrary vertices, u and v in the graph. The length of the path is then the number of
edges that are crossed on the journey from u to v. A path is simple if no edge is crossed
more than once. Furthermore, a graph is connected if there is a path between every pair
of vertices.
From graph theory, we can determine the number of different paths of some length, say
n, between two arbitrary vertices in a graph. This can be done from its adjacency matrix
representation. The theorem states that the number of different paths of length n between
vertices vi and vj is the (i, j)th entry of An, where A is the adjacency matrix representation

 n 

n
of G and A is the matrix product A • A • ... • A .
1CSCI 3320
Program Assignment 2
Spring 2013
Using this, we can solve many interesting graph theoretic problems. For example,
suppose we are given a route map of an airline that services various cities in the U.S. We
can determine the number of n-step connections between any pair of cities. Let’s say we
have cities, ci and cj and we are interested in determining the length of the shortest path
between the two, we can apply the theorem to find this answer. We determine the
shortest path, say s, by successively computing A1, A2,... until we find the first s such that
the (i, j)th entry of As is not 0. Now, let’s take a simple example to demonstrate how this
is done.
Example 1
Given the following route map, what is the shortest path between cities, 1 and 6?
1 2 3
4 5 6
Solution
First, we create the adjacency matrix that represents the graph. This is as follows:
A
1 2 3 4 5 6
1⎛0
⎜
2 ⎜1
3⎜0
⎜
4 ⎜1
5⎜
⎜1
6⎜
⎝0
1 0 1 1 0⎞
⎟
0 1 0 1 1⎟
1 0 1 0 1⎟
⎟
0 1 0 1 0⎟
1 0 1 0 1⎟
⎟
1 1 0 1 0⎟
⎠
Next, we compute As until we find the first non-zero entry in cell (1,6). After successive
computations, we find that A2 (see below) has a non-zero entry in cell (1,6). Therefore,
we conclude that the shortest path from 1 to 6 in the route map is 2
2CSCI 3320
Program Assignment 2
Spring 2013
1 2 3 4 5 6
2
A
1⎛3
⎜
2 ⎜1
3⎜2
⎜
4 ⎜1
5⎜
⎜2
6⎜
⎝2
1 2 1 2
4 1 3 2
1 3 0 3
3 0
3 1
2 3 1 4
2 1 2 1
2⎞
⎟
2⎟
1⎟
⎟
2⎟
1⎟
⎟
3⎟
⎠
Notice that the value of the (1,2) entry is 2, which means that there are 2 such paths.
Input
A vertex set V and an edge set E that represent a graph G = (V, E), and vertices u, v ∈ V.
Output
The adjacency matrix representation of graph G and the length of a shortest path p
between vertices u and v.
Class requirements
Write a general template and a specialization for a matrix class. Your matrix classes must
be based on dynamic arrays that are allocated using operator new. In addition, your
classes must include the following members.
1. Constant members to return the matrix dimensions.
2. Overloaded operator [ ] to return a matrix cell. Notice that the syntax for returning a
cell is m[i][j], where m is a matrix, and i and j are the row-column indices
respectively.
3. T** data member that represents a pointer to a dynamically allocated matrix.
4. Overloaded operator << to display a matrix in a formatted tabular form.
5. The specialization will be for the type int.
Program requirements
1. Present the user with a greeting.
2. Read the data (V and E) from a file passed to the program in argv[1].
3. Instantiate the matrix class with the data.
4. Display the matrix.
5. Prompt for and get vertices u and v.
6. Compute a shortest path p between u and v
7. Display the value of the shortest path that your program computed.
3CSCI 3320
Program Assignment 2
Spring 2013
Notes
1. The input data will be in the following format within the file.
6
// The number of vertices in the vertex set V.
123456
// The vertex set, V, space delimited.
12
// The number of edges in th edge set E.
13
// Edge (u, v), one per line, u and v space delimited
14
......
2. If a shortest path does not exist between the selected vertices u and v, report this.
3. The graph display must be properly formatted. That is, use std::setw to separate the
columns, and be sure to use row and column headings.
4. Here is an algorithm for multiplication of compatible matrices.
Given matrices A=(aij) with dimensions m×n and B=(bjk) with dimensions n×p, the
product C = AB is computed by,
n
c ik = ∑ aij b jk
j =1
€
4
