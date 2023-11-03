- For objects that are declared as const , you can only call constant member functions.
 The compiler ensures that the constant object is never modified. You can call
either constant or non-constant member functions for a non-constant object.
- you cannot declare a non member function with const keyword, even if you are not
  changing any varaible in that function, simply c++ dont allow const keyword with
  non member function (that is function defined in global scope or which is not a
  part of any class)
  
  - https://www.geeksforgeeks.org/const-member-functions-c/
  - When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
  - Whenever an object is declared as const, it needs to be initialized at the time of declaration. however, the object initialization while declaring is possible only with the help of constructors.
- A function becomes const when the const keyword is used in the function’s declaration. The idea of const functions is not to allow them to modify the object on which they are called.
- It is recommended practice to make as many functions const as possible so that accidental changes to objects are avoided.
