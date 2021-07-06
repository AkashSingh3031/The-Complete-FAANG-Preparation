<h1 align='center'>OBJECT ORIENTED PROGRAMMING</h1><br>


## Object-Oriented Programming
- **Object-Oriented Programming** is a methodology or paradigm to design a program using classes and objects. It simplifies the software development and maintenance by providing some concepts defined below :

## Class
- **Class** is a user-defined data type which defines its properties and its functions. Class is the only logical representation of the data. For example, Human being is a class. The body parts of a human being are its properties, and the actions performed by the body parts are known as functions. The class does not occupy any memory space till the time an object is instantiated.

**`C++ Syntax (for class):`**
```c++
class student {
   public: 
     int id; // data member 
     int mobile; 
     string name; 
     
     int add(int x, int y) { // member functions 
       return x + y; 
   } 
};
```

## Object
- **Object** is a run-time entity. It is an instance of the class. An object can represent a person, place or any other item. An object can operate on both data members and member functions.

**`C++ Syntax (for object):`**
```c++
student s = new student();
```

**Note:** When an object is created using a new keyword, then space is allocated for the variable in a heap, and the starting address is stored in the stack memory. When an object is created without a new keyword, then space is not allocated in the heap memory, and the object contains the null value in the stack.

## Inheritance
- **Inheritance** is a process in which one object acquires all the properties and behaviors ofits parent object automatically. In such a way, you can reuse, extend or modify the attributes and behaviors which are defined in other classes. 
- In C++, the class which inherits the members of another class is called derived class and the class whose members are inherited is called base class. The derived class is the specialized class for the base class.

**`C++ Syntax :`**
```c++
class derived_class :: visibility-mode base_class; 
visibility-modes = {private, protected, public}
```

**Types of Inheritance :**
1. Single inheritance :
   - When one class inherits another class, it is known as single level inheritance.
2. Multiple inheritance :
   - Multiple inheritance is the process of deriving a new class that inherits the attributes from two or more classes.
3. Multilevel inheritance :
   - Multilevel inheritance is a process of deriving a class from another derived class.
4. Hierarchical inheritance :
   - Hierarchical inheritance is defined as the process of deriving more than one class from a base class.
5. Hybrid inheritance : 
   - Hybrid inheritance is a combination of simple, multiple inheritance and hierarchical inheritance.

## Encapsulation
- **Encapsulation** is the process of combining data and functions into a single unit called class. In Encapsulation, the data is not accessed directly; it is accessed through the functions present inside the class. In simpler words, attributes of the class are kept private and public getter and setter methods are provided to manipulate these attributes. Thus, encapsulation makes the concept of data hiding possible.(**Data hiding:** a language feature to restrict access to members of an object, reducing the negative effect due to dependencies. e.g. "protected", "private" feature in C++).

## Abstraction
- We try to obtain an **abstract view**, model or structure of a real life problem, and reduce its unnecessary details. With definition of properties of problems, including the data which are affected and the operations which are identified, the model abstracted from problems can be a standard solution to this type of problems. It is an efficient way since there are nebulous real-life problems that have similar properties.

***Data binding :*** Data binding is a process of binding the application UI and business logic. Any change made in the business logic will reflect directly to the application UI.

## Polymorphism
- **Polymorphism** is the ability to present the same interface for differing underlying forms (data types). With polymorphism, each of these classes will have different underlying data. Apoint shape needs only two coordinates (assuming it's in a two-dimensional space of course). Acircle needs a center and radius. Asquare or rectangle needs two coordinates for the top left and bottom right corners and (possibly) a rotation. An irregular polygon needs a series oflines. Precisely, Poly means ‘many’ and morphism means ‘forms’.

**Types of Polymorphism**
1. Compile Time Polymorphism (Static)
2. Runtime Polymorphism (Dynamic)

### Compile Time Polymorphism :
- The polymorphism which is implemented at the compile time is known as compile-time polymorphism.
**Example:-** 

   - ***Method Overloading :***
      - Method overloading is a technique which allows you to have more than one function with the same function name but with different functionality. Method overloading can be possible on the following basis:
        
        1. The return type of the overloaded function. 
        2. The type of the parameters passed to the function.
        3. The number of parameters passed to the function.
        
        **`C++ Sample Code :`** 
        ```c++
        #include<bits/stdc++.h> 
        using namespace std; 
        
        class Add { 
            public:
                int add(int a,int b){ 
                    return (a + b); 
                }
                int add(int a,int b,int c){ 
                    return (a + b + c);
                } 
            }; 
        int main(){ 
            Add obj; 
            int res1,res2; 
            res1 = obj.add(2,3); 
            res2 = obj.add(2,3,4); 
            cout << res1 << " " << res2 << endl; 
            return 0; 
        }
        
        /*Output : 5 9 add()is an overloaded function with a different number of parameters. */
        ```
      
### Runtime Polymorphism :
- Runtime polymorphism is also known as dynamic polymorphism. Function overriding is an example of runtime polymorphism. Function overriding means when the child class contains the method which is already present in the parent class. Hence, the child class overrides the method of the parent class. In case offunction overriding, parent and child classes both contain the same function with a different definition. The call to the function is determined at runtime is known as runtime polymorphism.

**`C++ Sample Code :`** 
```c++
#include <bits/stdc++.h> 
using namespace std; 

class Base_class{ 
    public: 
        virtual void show(){ 
            cout << "FAANG Preparation base" << endl; 
        }
};
class Derived_class : public Base_class{ 
    public: 
        void show(){
            cout << "FAANG Preparation derived" << endl; 
        }
};

int main(){ 
    Base_class* b; 
    Derived_class d; b = &d; 
    b->show(); // prints the content of show() declared in derived 
    class return 0;
    }
    
// Output : FAANG Preparation derived
```

##  Constructor :
- **Constructor** is a special method which is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as class or structure.
- There can be **three types** of constructors in C++.
   1. **Default constructor :** 
      - Aconstructor which has no argument is known as default constructor. It is invoked at the time of creating an object. 
   2. **Parameterized constructor :**
      - Constructor which has parameters is called a parameterized constructor. It is used to provide different values to distinct objects. 
   3. **Copy Constructor :** 
      - A Copy constructor is an overloaded constructor used to declare and initialize an object from another object. 
      - It is of two types :
          1.  default copy constructor 
          2.  user defined copy constructor 

**`C++ Sample Code :`** 
```c++
#include <bits/stdc++.h> 
using namespace std; 

class go { 
    public:
        int x; 
        go(int a){ // parameterized constructor.
        x=a; 
    }
    go(go &i){ // copy constructor 
        x = i.x; 
    } 
};
int main(){ 
    go a1(20); // Calling the parameterized constructor.
    go a2(a1); // Calling the copy constructor. 
    cout << a2.x << endl; 
    return 0; 
}

// Output : 20
```

## Destructor : 
- Adestructor works opposite to constructor; it destructs the objects of classes. It can be defined **only once** in a class. Like constructors, it is invoked automatically. Adestructor is defined like a constructor. It must have the same name as class, prefixed with a **tilde sign (~)**.

**`C++ Sample Code :`** 
```c++
#include<bits/stdc++.h>
using namespace std;

class A{ 
    public: // constructor and destructor are called automatically, once the object is instantiated 
        A(){ 
            cout << "Constructor in use" << endl; 
        }
        ~A(){
            cout << "Destructor in use" << endl; 
        }
}; 
    
int main(){
    Aa; Ab; 
    return 0;
}

/*Output: Constructor in use Constructor in use Destructor in use Destructor in use */
```
