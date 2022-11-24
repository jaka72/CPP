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
    If I get this well, the copy constructor is always called at the very start only, when the object doesn't yet exist.
    In this case, it is good to set the address of this object to NULL. In order to be recognized later in the =operator.

    Because the next step is calling the =operator, where the new copy will get new memory allocated.
    So, if the object has just been created, the delete of member _array must not happen.
    But if the object has already existed, then the delete must be done, before allocating new memory.
*/
