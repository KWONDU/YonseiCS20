Lab 8 answers by Kwon Donguk, student ID 2020147570

Answer Q1:
(a) 11 20
Line 2, variable n: frame of foo
Line 5, variable n: frame of foo1
Line 8, variable n: global frame
Line 9, variable x: global frame
Line 10, variable y: global frame
At foo() and foo1(n), the values of n are both 10
So foo() return 10 * 2 = 20, foo1(n) return 10 + 1 = 11
x = 11, y = 20
(b) 2
Line 3, variable y: frame of bar
Line 5, variable x: frame of foo
Line 8, variable x: global frame
At foo(), the value of local variable x is newly defined as 1 
So at bar(), x = 1, y = x + 1 = 2
(c) 1
Line 3, variable y: frame of bar
Line 8, variable x: global frame
Unlike (b), the value of x isn't newly defined at (c)
So at bar(), x = 0, y = x + 1 = 1
