/*
    How to use pragma correctly? Is it allowed insead of define header?


    Where and how to put headers? Because I don't have the main()!
        <iostream> is in every header, needed for string, etc

        Warlock has included headers <Target> and <Spell>, no class define needed.
        In Spell and Target headers, each needs to define the other class:   class ASpell;   and then 
        at the bottom included that header: #include <ASpell>

        Children of Spell (the Woosh) needs its parend, but no other headers.
        The same for children of Target (Dummmy).


        When an item is erased from Spellbook or TarGen, it must check the size of vector after erasing.
        If size == 0, then it must exit the loop, return from function.
        Otherwise it is in the next loop checking for getName() in an empty vector --> segfault!



    *** PSEUDO CODE EX02 *****************************************

    

*/