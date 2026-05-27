# EX01 MOAR BRAINZ!

-- Dir ex01/
-- Files to submit: `Makefile main.cpp Zombie.cpp Zombie.hpp zombieHorde.cpp`
-

Time to create a horde of Zombies!
Implement the following function in the appropriate file:
`Zombie* zombieHorde( int N, std::string name );`
It must allocate N Zombie objects in a single allocation. 
Then, it must initialize the zombies, giving each of them the name passed as a parameter.


Implement your own tests to ensure that your zombieHorde() function works as expected.
Try calling announce() for each of the zombies.
Do not forget to use delete to deallocate all the zombies and check for memory
leaks.


