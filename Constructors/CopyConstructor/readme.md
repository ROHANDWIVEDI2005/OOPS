- A copy constructor is a special constructor in C++ that is used to create a new object by copying an existing object of the same class.
- The process of initializing members of an object through a copy constructor is known as copy initialization. 

- It is also called member-wise initialization because the copy constructor initializes one object with the existing object, both belonging to the same class on a member-by-member copy basis.

- Even if you didn’t write any constructor, C++ gives you a default copy constructor that copies each member  one by one.This is called implicit copy constructor.

- The user defined constructor is called user defined or explicit copy constructor.

### Syntax Example:
```
className (const ClassName &obj) {
    // Copy logic
    ……
}
```
- The const qualifier is optional but is added so that we do not modify the obj by mistake.

### The copy constructor creates two type of copies :
1. Shallow Copy
2.  Deep Copy
