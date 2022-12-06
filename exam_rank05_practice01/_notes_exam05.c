/*
    How to use pragma correctly? Is it allowed insead of define header?


    Exam needs to be in -std=c++98 ???
    Because in this case, how can you instantiate parent Spell inside the child Spell?
        If the members in Parent must be private, not protected?



    Default constructor for ASpell, does it need to initialize both strings with nothing,
    name and effects?
            like,      : name(),  effects()     ???
            try both cases, to see if there is a difference?


    Dont forget to have VIRTUAL destructor and also the pure clone() VIRTUAL


    In parent, the members can be private, not protected, because
    children dont initialize private members in the default constructors, but they do 
    use init. list to call the param. construcotr of the parent


    Abstract parent Target and Spell also have copy and overload constructor defined with code
    content. Also children Dummy and Fireball do have these constructors defined,
    including with the init. list!


    In child, the default, param. and copy constructors, all need to have :init list with the parent!
    SO, if the child does not have a private member, this private member will still get value in the parent,
    and the child can use that member and its value.
            ie:    Dummy::Dummy() : ATarget("some type name")

    Similarly, the copy constr in children also needs the :init.list with the parent,
    the parent will be instantiated via copy constr!
            ie:    Dummy::Dummy(Dummy const &other) : ATarget(other)

    In the overload constr in children, no need to copy any private members. 

    Check what is the correct protection in the overload ???
            // self-assignment check  -- is it the same address?
	            if (this == &str)
		        return *this;


    Clone() function in the child returnes a "new" child ---> this new child is
    created with the copy constructor, using the current *this
	// NOT SURE IF IT HAS TO BE ALSO VIRTUAL IN CHILD, OR ONLY IN PARENT ???



    When pushing a spell to the vector in the Warlock, do I need to push and clone?
    Because, when I erase the spell from the vector, does it erase the whole pointer,
    or it erases it just from the list, but the pointer should still exist in the main??? 



    Error squiggles: ctrl comma, error , enable error squiggles


    // random:      srand(time(NULL));
                    int r = rand() % 10


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
