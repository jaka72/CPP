# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    test_ex00_jaka.sh                                  :+:    :+:             #
#                                                      +:+                     #
#    By: jaka <jaka@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/02 18:29:52 by jaka          #+#    #+#                  #
#    Updated: 2022/11/07 14:14:39 by jaka          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

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

PRINT_YES=1


print_yes()
{
	if [ $PRINT_YES == 1 ] ; then
		echo -en $GRN "YES" $RES
	fi
}



loopOutFile()
{
	str="   in bash [$1]" # !!! NEEDS TO PRESERVE SPACES !!!

	while  read -r line ; do
		# if [[ $line == char:* ]] ; then
		 	if [ "$line" == "char:  '$2'" ] ; then      # CHARS
		 		print_yes
		# 	else    
		# 		 echo -en $RED "NO " $RES
		# 	fi
		# fi
		# if [[ $line == int:* ]] ; then
		 	elif [ "$line" == "int:    $3" ] ; then      # INTS
		 		print_yes
		# 	else    
		# 		echo -en $RED "NO " $RES
		# 	fi
		# fi
		# if [[ $line == float:* ]] ; then
			elif [ "$line" == "float:  $4" ] ; then      # FLOATS
				print_yes
		# 	else    
		# 		echo -en $RED "NO " $RES
		# 	fi
		# fi
		# if [[ $line == double:* ]] ; then
			elif [ "$line" == "double: $5" ] ; then      # DOUBLES
				print_yes
		 	else    
		 		echo -en $RED "Error " $RES
		# 	fi
		fi
	done < outTemp
	if [ $PRINT_YES == 1 ] ; then
		echo "   [$1]"
	fi

}

testChars()
{
	./a.out "$1" > outTemp
	#./a.out "   -   789" > outTemp
	#ret=$(echo $?)
	if [ $PRINT_YES == 1 ] ; then
		echo -e -n test "$i   " 
	fi
	loopOutFile "$1" $2 $3 $4 $5
	((i=i+1))
}


# loopOutFile_NanInf()
# {
# 	str="   in bash [$1]" # !!! NEEDS TO PRESERVE SPACES !!!
# 	# echo $str
# 	# echo "Result: $1"

# 	while  read -r line ; do
# 		if [[ $line == char:* ]] ; then
# 			 echo -n [$line] "$2"
# 			#  echo "        char:  '$2'"
# 			 if [ "$line" == "char:   $2" ] ; then      # CHARS
# 				 echo -en $GRN "YES" $RES
# 			 else    
# 				#  echo -e $line
# 				 echo -en $RED "NO " $RES
# 			fi
# 		fi
# 		if [[ $line == int:* ]] ; then
# 			  echo -n [$line] "$3"
# 			if [ "$line" == "int:    $3" ] ; then      # INTS
# 				echo -en $GRN "YES" $RES
# 			else    
# 				echo -en $RED "NO " $RES
# 			fi
# 		fi
# 		if [[ $line == float:* ]] ; then
# 			if [ "$line" == "float:  $4" ] ; then      # FLOATS
# 				echo -en $GRN "YES" $RES
# 			else    
# 				echo -en $RED "NO " $RES
# 			fi
# 		fi
# 		if [[ $line == double:* ]] ; then
# 			if [ "$line" == "double: $5" ] ; then      # DOUBLES
# 				echo -en $GRN "YES" $RES
# 			else    
# 				echo -en $RED "NO " $RES
# 			fi
# 		fi
# 	done < outTemp
# 	//if [[ TURN_OFF_YES == 0 ]] ; then
# 		echo "   [$1]"
# 	//fi
# }

# test_NanInf()
# {
# 	./a.out "$1" > outTemp
# 	#./a.out "   -   789" > outTemp
# 	ret=$(echo $?)
# 	# echo ret $ret
# 	# if [ $ret == 11 ] ; then
# 		echo -e -n test "$i   " 
# 		loopOutFile_NanInf "$1" "$2" "$3" $4 $5
# 	((i=i+1))
# }

# TEST CHARS #######################
#         input        char     int     float       double
testChars "a"           "a"     "97"    "97.0f"     "97.0"
testChars " b"          "b"     "98"    "98.0f"     "98.0"
testChars "    c"       "c"     "99"    "99.0f"     "99.0"
testChars "    d "      "d"     "100"   "100.0f"    "100.0"
testChars "    e    "   "e"     "101"   "101.0f"    "101.0"
echo ; i=0


# # TEST SINGLE SIGN + OR - #######################
testChars "-"           "-"     "45"    "45.0f"     "45.0"
testChars " +"          " +"    "43"    "43.0f"     "43.0"
testChars "    -"       "-"     "45"    "45.0f"     "45.0"
testChars "    + "      "+"     "43"    "43.0f"     "43.0"
testChars "    -    "   "-"     "45"    "45.0f"     "45.0"
echo ; i=0



# # TEST SINGLE INT #######################
testChars "1"               "non-printable"     "1"     "1.0f"      "1.0"
testChars " 2"              "non-printable"     "2"     "2.0f"      "2.0"
testChars "   3"            "non-printable"     "3"     "3.0f"      "3.0"
testChars "   4 "           "non-printable"     "4"     "4.0f"      "4.0"
testChars "   5    "        "non-printable"     "5"     "5.0f"      "5.0"
testChars "    0    "       "non-printable"     "0"     "0.0f"      "0.0"
testChars "           9"    "non-printable"     "9"     "9.0f"      "9.0"
echo ; i=0


testChars "-1"          "not-possible"   "-1"    "-1.0f"    "-1.0"     
testChars " -1"         "not-possible"   "-1"    "-1.0f"    "-1.0"
testChars "   -1   "    "not-possible"   "-1"    "-1.0f"    "-1.0"
testChars "- 2"         "not-possible"   "-2"    "-2.0f"    "-2.0"
testChars "-   2 "      "not-possible"   "-2"    "-2.0f"    "-2.0"
testChars " -   2 "     "not-possible"   "-2"    "-2.0f"    "-2.0"
testChars "   -   2  "  "not-possible"   "-2"    "-2.0f"    "-2.0"
testChars "+3"          "non-printable"   "3"    "3.0f"    "3.0"
testChars " +3"         "non-printable"   "3"    "3.0f"    "3.0"
testChars "   +3   "    "non-printable"   "3"    "3.0f"    "3.0"
testChars "+ 4"         "non-printable"   "4"    "4.0f"    "4.0"
testChars "+   4 "      "non-printable"   "4"    "4.0f"    "4.0"
testChars " +   4 "     "non-printable"   "4"    "4.0f"    "4.0"
testChars "   +   4  "  "non-printable"   "4"    "4.0f"    "4.0"
echo ; i=0


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
echo ; i=0



# echo "- - - TEST INTEGERS - - - - - - - - - - -"
testChars "12"                  "non-printable"		"12"	"12.0f"		"12.0"   
testChars "123"                 "{"					"123"	"123.0f"	"123.0"
testChars "+1"                  "non-printable"		"1"		"1.0f"		"1.0"
testChars "+12"                 "non-printable"		"12"	"12.0f"		"12.0"
testChars "+   12"              "non-printable"		"12"	"12.0f"		"12.0"
testChars " +12 "               "non-printable"		"12"	"12.0f"		"12.0"
testChars "   +    12 "         "non-printable"		"12"	"12.0f"		"12.0"
testChars "            +12 "    "non-printable"		"12"	"12.0f"		"12.0"

testChars " -12 "               "not-possible"		"-12"	"-12.0f"	"-12.0"
testChars "   -    12 "         "not-possible"		"-12"	"-12.0f"	"-12.0"
testChars "            -12 "    "not-possible"		"-12"	"-12.0f"	"-12.0"

testChars "+ 345"               "not-possible"		"345"	"345.0f"	"345.0"
testChars "+    345"            "not-possible"		"345"	"345.0f"	"345.0"
testChars "   +    345"         "not-possible"		"345"	"345.0f"	"345.0"
testChars "      +345"          "not-possible"		"345"	"345.0f"	"345.0"

testChars "-3"                  "not-possible"		"-3"	"-3.0f"		"-3.0"
testChars "-345"                "not-possible"		"-345"	"-345.0f"	"-345.0"
testChars " -345"               "not-possible"		"-345"	"-345.0f"	"-345.0"
testChars "  -345"              "not-possible"		"-345"	"-345.0f"	"-345.0"
testChars "- 345"               "not-possible"		"-345"	"-345.0f"	"-345.0"
testChars "-    345"            "not-possible"		"-345"	"-345.0f"	"-345.0"
testChars "   -    345"         "not-possible"		"-345"	"-345.0f"	"-345.0"
testChars "      -345"          "not-possible"		"-345"	"-345.0f"	"-345.0"
echo ; i=0




echo "- - - TEST DOUBLES - NON PRINTABLE CHARS - - - - - - - - - -"
testChars "12.34"                  "non-printable"	"12"	"12.34f"	"12.34"
testChars " 12.34"                 "non-printable"	"12"	"12.34f"	"12.34"
testChars "   12.34"               "non-printable"	"12"	"12.34f"	"12.34"
testChars "   12.34   "            "non-printable"	"12"	"12.34f"	"12.34"
testChars "-12.34"                 "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars " -12.34"                "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars "   -12.34"              "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars "   -12.34   "           "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars "- 12.34"                "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars "-   12.34"              "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars " -   12.34"             "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars "   -   12.34"           "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars "   -   12.34   "        "not-possible"	"-12"	"-12.34f"	"-12.34"
testChars "+12.34"                 "non-printable"	"12"	"12.34f"	"12.34"
testChars " +12.34"                "non-printable"	"12"	"12.34f"	"12.34"
testChars "   +12.34"              "non-printable"	"12"	"12.34f"	"12.34"
testChars "   +12.34   "           "non-printable"	"12"	"12.34f"	"12.34"
testChars "+ 12.34"                "non-printable"	"12"	"12.34f"	"12.34"
testChars "+   12.34"              "non-printable"	"12"	"12.34f"	"12.34"
testChars " +   12.34"             "non-printable"	"12"	"12.34f"	"12.34"
testChars "   +   12.34"           "non-printable"	"12"	"12.34f"	"12.34"
testChars "   +   12.34   "        "non-printable"	"12"	"12.34f"	"12.34"
echo ; i=0



echo "- - - TEST DOUBLES - 3 DIGITS - - - - - - - - - -"
testChars "120.34"                  "x"				"120"		"120.34f"	"120.34"
testChars " 121.34"                 "y"				"121"		"121.34f"	"121.34"
testChars "   122.34"               "z"				"122"		"122.34f"	"122.34"
testChars "   123.34   "            "{"				"123"		"123.34f"	"123.34"
testChars "-120.34"                 "not-possible"	"-120"		"-120.34f"	"-120.34"	# IMPOSSIBLE
testChars " -121.34"                "not-possible"	"-121"		"-121.34f"	"-121.34"
testChars "   -122.34"              "not-possible"	"-122"		"-122.34f"	"-122.34"
testChars "   -123.34   "           "not-possible"	"-123"		"-123.34f"	"-123.34"
testChars "- 124.34"                "not-possible"	"-124"		"-124.34f"	"-124.34"
testChars "-   125.34"              "not-possible"	"-125"		"-125.34f"	"-125.34"
testChars " -   126.34"             "not-possible"	"-126"		"-126.34f"	"-126.34"
testChars "   -   127.34"           "not-possible"	"-127"		"-127.34f"	"-127.34"
testChars "   -   128.34   "        "not-possible"	"-128"		"-128.34f"	"-128.34"
testChars "+120.34"                 "x"				"120"		"120.34f"	"120.34"
testChars " +121.34"                "y"				"121"		"121.34f"	"121.34"
testChars "   +122.34"              "z"				"122"		"122.34f"	"122.34"
testChars "   +123.34   "           "{"				"123"		"123.34f"	"123.34"
testChars "+ 124.34"                "|"				"124"		"124.34f"	"124.34"
testChars "+   125.34"              "}"				"125"		"125.34f"	"125.34"
testChars " +   126.34"             "~"				"126"		"126.34f"	"126.34"
testChars "   +   127.34"           "non-printable"	"127"		"127.34f"	"127.34"
testChars "   +   128.34   "        "non-printable"	"128"		"128.34f"	"128.34"
echo ; i=0



echo "- - - TEST FLOATS - PRINTABLE CHARS - - - - - - - - - -"
testChars "120.34f"                  "x"				"120"		"120.34f"	"120.34"
testChars " 121.34f"                 "y"				"121"		"121.34f"	"121.34"
testChars "   122.34f"               "z"				"122"		"122.34f"	"122.34"
testChars "   123.34f   "            "{"				"123"		"123.34f"	"123.34"
testChars "-120.34f"                 "not-possible"		"-120"		"-120.34f"	"-120.34"	# IMPOSSIBLE
testChars " -121.34f"                "not-possible"		"-121"		"-121.34f"	"-121.34"
testChars "   -122.34f"              "not-possible"		"-122"		"-122.34f"	"-122.34"
testChars "   -123.34f   "           "not-possible"		"-123"		"-123.34f"	"-123.34"
testChars "- 124.34f"                "not-possible"		"-124"		"-124.34f"	"-124.34"
testChars "-   125.34f"              "not-possible"		"-125"		"-125.34f"	"-125.34"
testChars " -   126.34f"             "not-possible"		"-126"		"-126.34f"	"-126.34"
testChars "   -   127.34f"           "not-possible"		"-127"		"-127.34f"	"-127.34"
testChars "   -   128.34f   "        "not-possible"		"-128"		"-128.34f"	"-128.34"
testChars "+120.34f"                 "x"				"120"		"120.34f"	"120.34"
testChars " +121.34f"                "y"				"121"		"121.34f"	"121.34"
testChars "   +122.34f"              "z"				"122"		"122.34f"	"122.34"
testChars "   +123.34f   "           "{"				"123"		"123.34f"	"123.34"
testChars "+ 124.34f"                "|"				"124"		"124.34f"	"124.34"
testChars "+   125.34"f              "}"				"125"		"125.34f"	"125.34"
testChars " +   126.34f"             "~"				"126"		"126.34f"	"126.34"
testChars "   +   127.34f"           "non-printable"	"127"		"127.34f"	"127.34"
testChars "   +   128.34f   "        "non-printable"	"128"		"128.34f"	"128.34"
echo ; i=0



echo "- - - WEIRD FLOATS - - - - - - - - - - - - - - - -"
testChars "0.f"        "non-printable"	"0"		"0.0f"	"0.0"
testChars "3.f"        "non-printable"	"3"		"3.0f"	"3.0"
testChars "31.f"       "non-printable"	"31"	"31.0f"	"31.0"
testChars ".0f"        "non-printable"	"0"		"0.0f"	"0.0"
testChars ".4f"        "non-printable"	"0"		"0.4f"	"0.4"
testChars ".41f"       "non-printable"	"0"		"0.41f"	"0.41"
echo ; i=0




echo "- - - TEST INT - OVEFLOWS - - - - - - - - - - - -"


#														!!! should be without 0.
testChars "214748364"	"not-possible"	"214748364"		"2.14748e+08f"	"2.14748e+08"

#										XXX: int says imposs.,  should be normal int
#												float and double, should be without 0f
testChars "2147483646"	"not-possible"	"2147483646"	"2.14748e+09f"	"2.14748e+09"
testChars "2147483647"	"not-possible"	"2147483647"	"2.14748e+09f"	"2.14748e+09"


testChars "2147483648"	"not-possible"	"not-possible"	"2.14748e+09f"	"2.14748e+09"


testChars "999999999999999999999999999999999999999"	"not-possible"	"not-possible" "inff"	"1e+39" #  Float wrong: inf.0f, should be inff 


testChars "999999999999999999999999999999999999999.9"	"not-possible"	"not-possible" "inff"	"1e+39" #  double wrong, missing '.0'
echo ; i=0





echo "- - - TEST FLOAT - OVEFLOWS - - - - - - - - - -"
testChars "99999999999999999999999999999999999999.9f"	"not-possible"	"not-possible" "1e+38f"	"1e+38"	# OK
testChars "999999999999999999999999999999999999999.9f"	"not-possible"	"not-possible" "inff"	"1e+39"	#double wrong: inf, should be 1e+39
echo ; i=0




echo "- - - TEST DOUBLES - OVEFLOWS - - - - - - - - - -"
testChars "999.0"		"not-possible"	"999" "999.0f"	"999.0" 	# OK
testChars "999.9"		"not-possible"	"999" "999.9f"	"999.9"		# OK
testChars "999999.9"	"not-possible"	"999999" "1e+06f"	"1e+06"	# OK	WHY HERE NO .0   ???

testChars "999999999999999999999999999999999999999.9"	"not-possible"	"not-possible" "inff"	"1e+39"	#double wrong:  1e+39.0   ,missing .0

testChars "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999990000000000000000000000000000000999990999.9"	"not-possible"	"not-possible" "inff"	"1e+308" # missing .0

testChars "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999900000000000000000000000000000009999909999.9"	"not-possible"	"not-possible" "inff"	"inf"
echo ; i=0



echo "- - - NAN and INF - - - - - - - - - - - - - - - - - -"
# test_NanInf "nan"	"char:   not-possible"	"int:    not-possible" "float:  nanf"	"double: nan"
# test_NanInf "nan"	"char:   not-possible"	"int:    not-possible" "float:  nanf"	"nan"
# test_NanInf "+inf"	"char:   not-possible"	"int:    not-possible" "float:  +inff"	"+inf"
# test_NanInf "-inf"	"char:   not-possible"	"int:    not-possible" "float:  -inff"	"-inf"
# test_NanInf "+inff"	"char:   not-possible"	"int:    not-possible" "float:  +inff"	"+inf"
# test_NanInf "-inff"	"char: not-possible"	"int: not-possible" "float:  -inff"	"-inf"
# 											 #int:    not-possible


echo




