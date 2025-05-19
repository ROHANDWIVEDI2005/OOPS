- A default constructor is a constructor that either takes no arguments or has default values for all its parameters. 
- It is also referred to as a zero-argument constructor when it explicitly accepts no arguments.

### Compiler‑supplied vs. User‑defined:
1. Compiler‑supplied: If you write no constructors at all, the compiler silently provides one that does nothing.

2. User‑defined: As soon as you write any constructor—whether it takes parameters or not—the compiler stops generating its own.

- In cases where a class is derived from a base class with a default constructor, or a class contains an object of another class with a default constructor, the compiler must insert code to ensure these default constructors are invoked appropriately for the base class or the embedded objects.
