
gcc -Wall -Werror -Wextra infin_mult_vaja00.c
# gcc -Wall -Werror -Wextra infin_mult.c




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


result=$(./a.out 5  3) ; check 15
result=$(./a.out 3  5) ; check 15
# result=$(./a.out 0  0) ; check 0
# result=$(./a.out 0  5) ; check 0
# result=$(./a.out 5  0) ; check 0

result=$(./a.out 10  3) ; check 30
result=$(./a.out 100  3) ; check 300
result=$(./a.out 3  100) ; check 300
result=$(./a.out 2  123) ; check 246
result=$(./a.out 123 456) ; check 56088
result=$(./a.out 123 456789) ; check 56185047


# result=$(./a.out 0  -0) ; check 0
result=$(./a.out 10  -3) ; check -30
result=$(./a.out 100  -3) ; check -300
result=$(./a.out 3  -100) ; check -300
result=$(./a.out 2  -123) ; check -246
result=$(./a.out 123 -456) ; check -56088
result=$(./a.out 123 -456789) ; check -56185047


# result=$(./a.out -0  0) ; check 0
result=$(./a.out -10  3) ; check -30
result=$(./a.out -100  3) ; check -300
result=$(./a.out -3  100) ; check -300
result=$(./a.out -2  123) ; check -246
result=$(./a.out -123 456) ; check -56088
result=$(./a.out -123 456789) ; check -56185047

# result=$(./a.out -0  -0) ; check 0
result=$(./a.out -10  -3) ; check 30
result=$(./a.out -100  -3) ; check 300
result=$(./a.out -3  -100) ; check 300
result=$(./a.out -2  -123) ; check 246
result=$(./a.out -123 -456) ; check 56088
result=$(./a.out -123 -456789) ; check 56185047

result=$(./a.out 23 67) ; check 1541
result=$(./a.out 67 23) ; check 1541


# if first str is longer than second !!!
result=$(./a.out 456789 123) ; check 56185047   # no
result=$(./a.out -456789 123) ; check -56185047
result=$(./a.out 456789 -123) ; check -56185047

result=$(./a.out 123 456) ; check 56088
result=$(./a.out 456 123) ; check 56088     # no ???

result=$(./a.out 234 123) ; check  28782    
result=$(./a.out 345 123) ; check  42435    
result=$(./a.out 445 123) ; check   54735
result=$(./a.out 456 123) ; check   56088



result=$(./a.out 1234567  98765) ; check  121932009755
result=$(./a.out -1234567  98765) ; check  -121932009755
result=$(./a.out 1234567  -98765) ; check  -121932009755
result=$(./a.out -1234567  -98765) ; check  121932009755
