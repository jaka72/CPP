#!/bin/bash

RED="\033[0;31m"
CYN="\033[0;36m"
GRN="\033[0;32m"
BLU="\033[0;34m"
YEL="\033[0;33m"
GRE="\033[0;38m"
RES="\033[0m"

make
i=0
outTemp="outTemp"

loopOutFile()
{
    while read -r line; do
        if [[ $line == Result* ]] ; then
            echo -n [$line]
            if [ "$line" == "Result: $1" ] ; then
                echo -e $GRN YES $RES
            else    
                echo -e $RED NO $RES
            fi
        fi
    done < outTemp
}

testChars()
{
    ./a.out $1 > outTemp
    ret=$(echo $?)
    if [ $ret == 11 ] ; then 
        echo -e -n test $i: $GRN found char OK $RES
        loopOutFile $1
    else
        echo -e  test $i: $RED error finding char $RES
    fi
    ((i=i+1))
}


# TEST CHARS #######################
testChars "a"
testChars " b"
testChars "    c"
testChars "    d "
testChars "    e    "
echo

# TEST SINGLE INT #######################
testChars "1"
testChars " 2"
testChars "   3"
testChars "   4 "
testChars "   5    "
testChars "    0    "
testChars "           9"
echo


# TEST SINGLE SIGN + OR - #######################
testChars "-"
testChars " +"
testChars "    -"
testChars "    + "
testChars "    -    "
echo


# TEST INTEGERS #######################
testChars "12"
testChars "123"
testChars "+1"
testChars "+12"
testChars "+   12"
testChars " +12 "
testChars "   +    12 "
testChars "            +12 "
testChars "-3"
testChars "-345"
testChars " -345"
testChars "  -345"
testChars "- 345"
testChars "-    345"
testChars "   -    345"
# testChars "      -345"
echo

