

/*
    TYPE unitptr_t

    uintptr_t is an unsigned integer type that is capable of storing a data pointer
    (whether it can hold a function pointer is unspecified).
    Which typically means that it's the same size as a pointer.

    A common reason to want an integer type that can hold an architecture's pointer type 
    is to perform integer-specific operations on a pointer, or to obscure the type of
    a pointer by providing it as an integer "handle".
    
    In C99, it is defined as "an unsigned integer type with the property that 
    any valid pointer to void can be converted to this type, then converted back 
    to pointer to void, and the result will compare equal to the original pointer".
*/




/*
    REINTERPRET CAST
    
    The C++ standard guarantees the following:

    static_casting a pointer to and from void* preserves the address. 
    That is, in the following, a, b and c all point to the same address:

            int* a = new int();
            void* b = static_cast<void*>(a);
            int* c = static_cast<int*>(b);

    reinterpret_cast only guarantees that if you cast a pointer to a different type, 
    and then reinterpret_cast it back to the original type, you get the original value. 
    So in the following:

            int* a = new int();
            void* b = reinterpret_cast<void*>(a);
            int* c = reinterpret_cast<int*>(b);

    a and c contain the same value, but the value of b is unspecified. 
    (in practice it will typically contain the same address as a and c, but that's 
    not specified in the standard, and it may not be true on machines with more complex memory systems.)

    For casting to and from void*, static_cast should be preferred.
*/