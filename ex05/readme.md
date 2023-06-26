


   +-- Special cases of pointer declarations
|   +-- Point to nonstatic members of class objects
|   +-- Have type information for both the member and the class
|   +-- Use .* or ->* operators to dereference
|
+-- How to declare them?
|   |
|   +-- Use type-specifier qualified-name::* identifier syntax
|   +-- Example: int (Window::* pfnwGC)() = &Window::GetCaption;
|
+-- How to use them?
|   |
|   +-- Need an object or a pointer to object of the class
|   +-- Use (object.*ptr)() or (ptr->*ptr)() syntax to call member functions
|   +-- Use object.*ptr or ptr->*ptr syntax to access member data
|   +-- Example: (win.*pfnwGC)() or (pwin->*pfnwGC)()
|
+-- Why use them?
    |
    +-- Typesafe alternative to offsetof() macro
    +-- Allow dynamic binding of member functions
    +-- Enable generic programming with templates