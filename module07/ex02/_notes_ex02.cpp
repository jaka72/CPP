/*
    INSTANTIATING THE CLASS AS POINTER VS NON-POIUNTER

        Why int needs square brakets???
		    int* mirror = new int[ 10 ];    // a way to create a pointer to array of ints with 10 elements

        But object Array constructor needs round brackets:
            Array <int> numbers( 10 );      // create the object Array, which has a member array of size 10

        Pointer needs square brackets [ ] 

            Non-pointer:
            Array <int> arr( 5 );

            Pointer:
            Array * <int> arr = new Arr[ 5 ]

*/


/*
    Hoi, let me try to explain this,
    In the copy constructor it is necessary to set the member _array to NULL, so that in the next step, when the =overload is called,
    the =overload will recognize that the copy is fresh (it does not have any new memory allocated yet).
    In this case, the _array must not be deleted, but just allocate new memory to it.
    In the other case, the _array already had memory allocated before (was created in the default constructor), so it must first be deleted,
    and only then can get new memory allocated.
    Something like this : )
*/
