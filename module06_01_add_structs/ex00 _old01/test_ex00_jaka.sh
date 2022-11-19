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

Result: -

loopOutFile()
{
            str="   in bash [$1]" # !!! NEEDS TO PRESERVE SPACES !!!
            # echo $str
            # echo "Result: $1"

    while read -r line; do
        if [[ $line == Result* ]] ; then
            echo -n [$line]
            if [ "$line" == "Result: $2" ] ; then #!!!! HERE THE $1 ONLY GIVES THE FIRST WORD, MINUS "  -  123"
                echo -e $GRN YES $RES
            else    
                echo -e $RED NO $RES
            fi
        fi
    done < outTemp
}

testChars()
{
    ./a.out "$1" > outTemp
    #./a.out "   -   789" > outTemp
    ret=$(echo $?)
    # echo ret $ret
    if [ $ret == 11 ] ; then
        echo -e -n test $i: $GRN found char OK $RES
        loopOutFile "$1" $2
    elif [ $ret == 22 ] ; then
        echo -e -n test $i: $GRN found int OK $RES
        loopOutFile "$1" $2
    elif [ $ret == 33 ] ; then
        echo -e -n test $i: $GRN found double OK $RES
        loopOutFile "$1" $2
    elif [ $ret == 44 ] ; then
        echo -e -n test $i: $GRN found float OK $RES
        loopOutFile "$1" $2
    else
        echo -e  test $i: $RED error .... $RES
    fi
    ((i=i+1))
}


# TEST CHARS #######################
testChars "a"           "a"
testChars " b"          "b"
testChars "    c"       "c"
testChars "    d "      "d"
testChars "    e    "   "e"
echo


# TEST SINGLE SIGN + OR - #######################
testChars "-"           "-"
testChars " +"          " +"
testChars "    -"       "-"
testChars "    + "      "+"
testChars "    -    "   "-"
echo


# TEST SINGLE INT #######################
testChars "1"               "1"
testChars " 2"              "2"
testChars "   3"            "3"
testChars "   4 "           "4"
testChars "   5    "        "5"
testChars "    0    "       "0"
testChars "           9"    "9"
echo

testChars "-1"          "-1"
testChars " -1"         "-1"
testChars "   -1   "    "-1"
testChars "- 2"         "-2"
testChars "-   2 "      "-2"
testChars " -   2 "     "-2"
testChars "   -   2  "  "-2"
testChars "+3"          "3"
testChars " +3"         "3"
testChars "   +3   "    "3"
testChars "+ 4"         "4"
testChars "+   4 "      "4"
testChars " +   4 "     "4"
testChars "   +   4  "  "4"
echo

echo "--- SHOULD BE ERROR --- "
testChars "+a "             "error"
testChars "-a "             "error"
testChars "   +   a  "      "error"
testChars "   -   b  "      "error"
testChars "   ++  3  "      "error"
testChars "   --  4    "    "error"
testChars "   ++  123  "    "error"
testChars "   --  456  "    "error"
testChars "--12.34"         "error"

echo



echo "- - - TEST INTEGERS - - - - - - - - - - -"
testChars "12"                  "12"
testChars "123"                 "123"
testChars "+1"                  "1"
testChars "+12"                 "12"
testChars "+   12"              "12"
testChars " +12 "               "12"
testChars "   +    12 "         "12"
testChars "            +12 "    "12"
testChars "-3"                  "-3"
testChars "-345"                "-345"
testChars " -345"               "-345"
testChars "  -345"              "-345"
testChars "- 345"               "-345"
testChars "-    345"            "-345"
testChars "   -    345"         "-345"
testChars "      -345"          "-345"
echo



echo "- - - TEST DOUBLES - - - - - - - - - - -"
testChars "12.34"                  "12.34"
testChars " 12.34"                 "12.34"
testChars "   12.34"               "12.34"
testChars "   12.34   "            "12.34"
testChars "-12.34"                 "-12.34"
testChars " -12.34"                "-12.34"
testChars "   -12.34"              "-12.34"
testChars "   -12.34   "           "-12.34"
testChars "- 12.34"                "-12.34"
testChars "-   12.34"              "-12.34"
testChars " -   12.34"             "-12.34"
testChars "   -   12.34"           "-12.34"
testChars "   -   12.34   "        "-12.34"
testChars "+12.34"                 "12.34"
testChars " +12.34"                "12.34"
testChars "   +12.34"              "12.34"
testChars "   +12.34   "           "12.34"
testChars "+ 12.34"                "12.34"
testChars "+   12.34"              "12.34"
testChars " +   12.34"             "12.34"
testChars "   +   12.34"           "12.34"
testChars "   +   12.34   "        "12.34"



echo -e "\n- - - TEST FLOATS - - - - - - - - - - -"
testChars "12.34f"                  "12.34"
testChars " 12.34"                 "12.34"
testChars "   12.34"               "12.34"
testChars "   12.34   "            "12.34"
testChars "-12.34"                 "-12.34"
testChars " -12.34"                "-12.34"
testChars "   -12.34"              "-12.34"
testChars "   -12.34   "           "-12.34"
testChars "- 12.34"                "-12.34"
testChars "-   12.34"              "-12.34"
testChars " -   12.34"             "-12.34"
testChars "   -   12.34"           "-12.34"
testChars "   -   12.34   "        "-12.34"
testChars "+12.34"                 "12.34"
testChars " +12.34"                "12.34"
testChars "   +12.34"              "12.34"
testChars "   +12.34   "           "12.34"
testChars "+ 12.34"                "12.34"
testChars "+   12.34"              "12.34"
testChars " +   12.34"             "12.34"
testChars "   +   12.34"           "12.34"
testChars "   +   12.34   "        "12.34"


# testChars "   -"    "-"
echo

# inputlines=(
#     "    +   345"
# )
# input=${inputlines[0]}
# testChars "$input"
# testChars "   -   777"
