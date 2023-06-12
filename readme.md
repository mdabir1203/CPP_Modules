#Difference Stack and Heap Memory in C++

- Stack allocation is faster than heap allocation.
- S.A is more efficient than H.A.
- S.A has a fixed size and scope whereas H.A. has dynamic size and scope
- S.A. has an automated lifetime , while heap allocation has a manual lifetime(More control and flexibility to the programmer)

S.A. -> preferred for fast and efficient memory allocation for small and short-lived objects having a local scope
H.A. -> Dynamic and persistent memory allocation for large and long lived objects having global scope.


** Real life analogy :

## Stack Allocation
It is like putting toys on top of each other in a pile. You can only take the toy that is on the top of the pile. You can also put a new toy on the top of the pile, but you have to take it off when you are done playing with it. This way, you can play with toys very quickly and easily, but you can’t play with many toys at the same time. You also can’t play with toys that are too big or too heavy for the pile. You should use this method when you want to play with small and simple toys for a short time, and then put them back in the box.

## Heap Allocation
Heap allocation is like putting toys in different places around the room. You can take any toy you want from anywhere in the room. You can also put a new toy anywhere in the room, but you have to remember where you put it and clean it up when you are done playing with it. This way, you can play with many toys at the same time, and you can play with toys that are big or complex. You should use this method when you want to play with large and fancy toys for a long time, and keep them outside the box.
