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



    // CONST BEFORE A FUNCTION
        const before a function means that the return parameter is const, 
        which only really makes sense if you return a reference or a pointer


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


// REPEAT THINGS ///////////////////////////

/*
    Allocating an array, with know number of element

    Zombie *horde = new Zombie[33];
    delete []horde





    // OPEN INFILE, OUTFILE
        std::ifstream infile;   std::ofstream outfile;

        infile.open(argv[1]);
        outfile.open(argv1.c_str());

        if (infile.is_open() == 0)      // check if it opened

        outfile << "something\n";

        outfile.close();

        std::cin.getline(strBuffer, 100);  // get line from cin int strBuffer   ? first arg

        getline(inFile, name, ' ');         // get line from file int name      ? second arg


    // USEFUL STRING FUNCTIONS: 
        line.find(someStr)
        line.substr(0, 33)      // returns substr from position 0 to 33
        line.length()
        std::getline(infile, line)

        str.append("something")



    // POINTER TO FUNCTION, OR ARRAY OF POINTERS

        void		      (*pointerToFunction) (void);
        void		(Harl::*pointerToFunction) (void);      // Harl is a Class, so this would be used in case when
                                                            // this pointer is meant to point to a member function 
                                                            // of the class Harl:   pointerTOFunction = &Harl::debug();
        To call this function via pointer:
                    *(pointerToFunction) ();
    
    // STRUCT AND ARRAY OF STRUCT 
        typedef struct s_data
		{
			std::string	level;
			void		(Harl::*pointerToFunction)(void);
		} t_data;
		t_data data[4];


    // SWITCH SYNTAX

    switch (some int or char)
    {
        case 0:
            do something;
            break ;         // pr maybe no break;
        case 1: 
            etc ...
    }

    Switch can be in a loop, then case would be the i++, each time calling the next case - so you get to print
    from certain i to the end of i.

*/




/*  OVERLOADING OPERATORS SYNTAX

    // COMPARISSON

        bool	Fixed::operator== (const Fixed &fixed) const
        {
            return (this->_fpn == fixed._fpn);      // COMPARING THE PRIVATE MEMBERS OF 2 OBJECTS OF THE SAME CLASS
        }                                           //    ie:    if (cat1 == cat2) ...


*/





/*  THE DIAMOND ISSUE

    Default and param. constr.:     
        The grandchild must instantiate the grandparent in the ::init.list.
        Then it must declare both his parents in both constructors (default and param.)
        Then it can inherit specific values from both parents by calling the getters!
                    GrandChild::GrandChild()  :  GrandParent("someName")
                    {
                        ParentA pA;
                        ParentB pB;

                        pA.getName();
                        pB.getTitle();
                    }
                    
    Copy constructor:
        It must instantiate all 3 ancestors in the :init.list.
                    GrandChild::GrandChild(const GrandChild & copy) : GrandParent(), ParenA(), ParentB
                    {
                        *this = copy;
                    }


*/