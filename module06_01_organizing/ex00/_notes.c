/* QUESTIONS

    - stoi nhas issue on linux, works after disableing makefile: -std=c++98

    - stoi throws exception 'stoi' if int overflows and exists. I dont want this.
        I want to print 'impossible' and also print value of float and double
        Therefore I dont want to use stoi()



    - Now I treat " " as a valid printable char, but
                  "   " I treat as invalid string, just empty spaces
                            Shall I say it is valid, like 1 space?


    - In what situation would you use a struct inside a class?


    - Shall I use getters and setters always for all private vars??
    
    SUBJECT SAYS, YOU NEED TO ACQUIRE THE STRING INTO THE RIGHT TYPE, SO IT IS NOT 
    A STRING ANYMORE. SO THIS PROBABLY MEANS, FIRST INTO DOUBLE, THEN INTO 
    EVERYTHING ELSE.
    
    Can you put class member functions definitions in more other files, how do you then name those files?


*/


/*
    TYPE CASTING (TYPE CONVERSION)

    A) Implicit (automatic by compiler)
    
    B) Explicit (manual by programmer)

            b1) With () cast operator (used in C, no compile time checking)

            b2) With <> cast operator (used in C++, has compile time checking)

                - Static_cast           static_cast < new_data_type > (expression); 
                                        x = static_cast < int > (y); 

                - dynamic_cast          To handle polimorphism. Only used when casting from base to derived class
                                        (at runtime, only for class pointers)
                - const_cast
                
                - reinterpret_cast      To store a pointer ???

                - regular cast

        (Difference between C-cast() and C++cast <> is, that <> is more strict.
        Will not allow casting pointers of types with different size (like char and int)
                    char c   = 65;          // 1-byte data. ASCII of ‘A’
                    int *ptr = (int*)&c;    // 4-byte

                    char c   = 65;
                    int *ptr = static_cast<int>(&c);    // Error
*/
