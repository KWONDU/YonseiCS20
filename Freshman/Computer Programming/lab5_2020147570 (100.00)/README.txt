Lab 5 answers by Kwon Donguk, student ID 2020147570

Answer Q1:
(a) True
(b) True
(c) False
(d) False

Answer Q2:
(a) False
(b) True
(c) True
(d) False
(e) True

Answer Q3:
(a) num >= 0 and num < 100
(b) (num < 100 and num >= 0) or num == 200
(c) 'Thompson' in last_names or 'Wu' in last_names
(d) 'Thompson' in last_names and 'Wu' not in last_names

Answer Q4:
First, at line 2, we need to get input as type 'int'.
But at the program, variable 'num' get input as type 'string', so error occurs.
We can fix it as using int(input()), not input().
Second, we need to switch line 4 and line 5.
If we run this program and 'num' is 0, it doesn't stop
We can fix it by switching line 4 and line 5.
Third, at line 6, print function's position isn't correct.
At that position, print function will activate once per one while loop.
We can fix it by changing print function's position at very front.