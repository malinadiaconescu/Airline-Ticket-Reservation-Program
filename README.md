# Airline-Ticket-Reservation-Program
An airline ticket reservation program using skip lists in C++. My program displays a menu where you can make reservations, cancel them or interact with them.
## Introduction
My program displays a menu where you can make reservations, cancel them or interact with them. To do this, I used skip lists that I will explain below.
## The Implementation
The program is pretty simple. It contains a class SkipList with different methods
that help maintain the reservation system. I also added a class for nodes called
Node that contains a constructor, a variable used for the name of the person
that makes the reservation and an array that holds pointers to node of different
level. For SkipList class, I implemented the following:
### Variables
There is maxlvl that represents the maximum number of levels on skip list, p
that represents the fraction of the nodes with level, lvl that is the current level
of skip list and a pointer to the header node.
### randomLevel() Method
Each element in the skip list is represented by a node that is chosen randomly while insertion in the list. It cannot be greater than maxlvl.
### createNode() Method
It returns the constructor of the Node class.
### insertElement() Method
insertElement() method takes as a parameter a key to insert in the skip list.
It creates then an update array and initialize it. It starts from highest level of
skip list and it moves to while key is greater than key of node. After all that, we reached to level 0, and forward the pointer to right, which is where we want
to insert the key. If current is NULL, it means that it reached to the end of the
level or current's key is not equal to key to insert. So, we have to insert a node
between update[0] and current node.
### searchElement() Method
It starts from the highest level in the skip list and moves further while key is
greater than key of node. Otherwise, it moves one level down and continues the
search. When it reached to the level 0, the element we are looking for might be
in the right, if not, that means the element is not in the skip list.
### deleteElement() Method
The first part of this method is basically the searchElement(). When it finds
the element, it rearranges the pointers just like in a simple linked list. At the
end, it removes the level having no elements.
### display() Method
I chose to display only the level 0. I know my skip list has more levels, but I
thought this is more closer to a real life program. I only displayed all the levels
of the skip list when I tested my code.
## The Menu
When you run my code, you will see 4 options: you can reserve a ticket, cancel
a reservation, check whether you have a reservation and see all the reservations.
To reserve a ticket, my program first searches whether you have a reservation
or not. It only makes you a reservation if you do not have one already.
To cancel a reservation, my program searches again if you have a reservation in
the first place. If you do not have, it shows you a message that you do not have.
Otherwise, it cancels your reservation.
## Encountered Problems
My problems regarding this project were understanding the levels thing in a
skip list. I read a lot before implementing. Like, I knew what was happening
in a skip list but I did not know how to put it in a code. Finally, I succeed in
implementing the skip list and inserting elements in it. The rest of the project
went well.
## What can my program do?
I tried different things with my program before sending it in. I tried adding
a reservation with the same name and my program works fine. It does not
allow you to have more reservations on the same name. I tried canceling a
reservation that does not exist and my program does know what to do in
this case. I tried canceling all the reservations and my program displays
an empty list.
