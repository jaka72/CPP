

/*
    ISSUES:
         12345f wrong message: Error: Invalid input, last char is not f and not digit!
            (apparently this is invalid input, float always needs a dot: 123.45f )


        In case 999999999999999999999999999999999999999.9     OK without f
        In case 999999999999999999999999999999999999999.9f 
                If f is present and when the float turns to inff,
                then also the double turns to inf, but double should continue as 1e+39.0 ... etc

        Change cout to cerr if printing errors!
*/

