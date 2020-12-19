Lab 13_final answers by Kwon Donguk, student ID 2020147570

Answer Q1:
(a) Escape sequence is used to display a character which cannot be displayed directly or display special cahracter such as new line, quotation mark, Hangul.
(b) 3 bytes. When using encode method, 'HANGUL SYLLABLE TAEG' looks like b'\xed\x83\x9d', and it means 'HANGUL SYLLABLE TAEG' takes up for 3 bytes. In general, Hangul occupy for 3 bytes at UTF-8.
(c) UTF-8 character's length vary because it can reduce the waste of capacity.

Answer Q2:
(a) 'i' increases until it reaches 4. But because of code 'del x[i]', its length is less than 5. So IndexError occurs.
(b) This program can be fixed by using other list, del_list. Init 'del_list' as 'del_list = []' and replace 'del x[i]' with 'del_list.append(x[i])'. Then remove del_list's item from x using remove method. Code can be written as 'for item in del_list: x.remove(item)'.

Answer Q3:
Function can be called by writing its name. But when calling method, we should use 'object.method' or 'class name.method' instead of 'method'. At Python methods, self parameter is used to pass the object as the first argument to a method.

Answer Q4:
(a) none
(b) Line 3, Line 14
(c) Line 7, Line 16
(d) Line 12, Line 14

Answer Q5:
S3

Answer Q6:
encapsulation
(1) Encapsulation is used to hide information which protects code from wrong approach.
(2)
class Super:
    def __init__(self, x):
        self.__x = x

    def get_x(self):
        return self.__x

    def set_x(self, x):
        self.__x = x

inheritance
(1) Inheritance uses to extend a class with new functionality by re-using code.
(2)
class Super:
    name = 'Computer Programming'

    def write(self):
        print('Yonsei')

class Sub(Super):
    def __init__(self, name):
        self.name = name

    def write_name(self):
        print(self.name)

polymorphism
(1) Polymorphism makes maintenance easier by storing instances of its own class and its subclasses.
(2)
class Super:
    name = 'Computer Programming'

    def write(self):
        print('Yonsei :', self.name)

class Sub(Super):
    def __init__(self, name):
        self.name = name

    def write(self):
        print('Yonsei 20:', self.name)

Answer Q7:
(a) When we define each function, we have to call every variable as parameter.
(b) At turtle graphics, one turtle instance, which declared as 'Turtle()' or 'getturtle()',is used to as a factor for many functions. So if global keyword is eliminated, problems will be occur. It appears at Lab9_p5.

Answer Q8:
Python uses a new frame for each recursive function call to get completely new copy of the function's data such as fresh set of local variables and own set of function arguments.
