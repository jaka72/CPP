
################################################################
#
#	TESTER TO COMPARE MY replace() WITH THE ORIGINAL replace()
#
################################################################

INFILE = "infile"
OUT_TEMP = "outfile"
OUTFILE = $OUT_TEMP".replace_orig"


compare_outcome()
{
	DIFF=$(diff $INFILE $OUTFILE)
	if [ "$DIFF" == "" ] 
	then
		echo -e "[ OK ] " 
	else
		echo -e "[ KO ] " 
	fi
}

c++ main.cpp -o main.exe ; ./main.exe infile "a" "###"
c++ orig.cpp -o orig.exe ; ./orig.exe infile "a" "###"
compare_outcome

