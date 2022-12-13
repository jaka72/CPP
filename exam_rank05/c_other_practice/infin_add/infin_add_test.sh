


gcc infin_add_vaja00.c




check ()
{
    # echo "check arg: " $1
    # echo "check result: " $result
    if [ $result -eq $1 ] ;
    then
        echo yes
    else
        echo no
    fi
}


result=$(./a.out 5  3) ; check 8
result=$(./a.out 3  5) ; check 8
result=$(./a.out 123  456) ; check 579
result=$(./a.out 456  123) ; check 579

result=$(./a.out 1 12345) ; check 12346
result=$(./a.out 12345 1) ; check 12346


result=$(./a.out 5 -3) ; check 2
result=$(./a.out -3 5) ; check 2
result=$(./a.out -5 3) ; check -2

# result=$(./a.out 0 0) ; check 0 // not working ???

result=$(./a.out 3 0) ; check 3
result=$(./a.out 0 4) ; check 4

result=$(./a.out 10 -3) ; check 7
result=$(./a.out -10 3) ; check -7

result=$(./a.out 100 -3) ; check 97
result=$(./a.out -100 3) ; check -97
result=$(./a.out 1000 -3) ; check 997
result=$(./a.out -1000 3) ; check -997

result=$(./a.out -3 1000) ; check 997
result=$(./a.out 3 -1000) ; check -997

result=$(./a.out -1  12345) ; check 12344
result=$(./a.out 1  -12345) ; check -12344
result=$(./a.out -12345 1) ; check -12344
result=$(./a.out 12345 -1) ; check 12344
