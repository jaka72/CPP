
################################################################
#
#	TESTER TO COMPARE MY replace() WITH THE ORIGINAL replace()
#
################################################################

INFILE="infile"
# OUT_TEMP="outfile"
# OUTFILE=$OUT_TEMP".replace_orig"
OUT_MINE=$INFILE".replace"
OUT_ORIG=$INFILE".replace_orig"


compare_outcome()
{
	DIFF=$(diff $OUT_MINE $OUT_ORIG)
	if [ "$DIFF" == "" ] 
	then
		echo -e "[ OK ] " 
	else
		echo -e "[ KO ] " 
	fi
}

c++ main.cpp utils.cpp -o main.out ; ./main.out infile "..." "^^^"
c++ orig.cpp 		   -o orig.out ; ./orig.out infile "..." "^^^"
compare_outcome

