- For objects that are declared as const , you can only call constant member functions.
 The compiler ensures that the constant object is never modified. You can call
either constant or non-constant member functions for a non-constant object.
- you cannot declare a non member function with const keyword, even if you are not
  changing any varaible in that function, simply c++ dont allow const keyword with
  non member function (that is function defined in global scope or which is not a
  part of any class)
