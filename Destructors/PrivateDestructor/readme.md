- Destructors with the access modifier as private are known as Private Destructors. 
- Whenever we want to prevent the destruction of an object, we can make the destructor private.

- For dynamically created objects, it may happen that you pass a pointer to the object to a function and the function deletes the object. 
- If the object is referred after the function call, the reference will become dangling.
