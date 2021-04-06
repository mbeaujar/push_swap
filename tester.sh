#!/bin/bash


if [ -f error.log ]
then
    rm -rf error.log
fi

display_note()
{
    if [ $2 -eq 100 ]
    then
        A=700
        Z=900
        E=1100
        R=1300
        T=1500
    else
        A=5500
        Z=7000
        E=8500
        R=10000
        T=11500
    fi
    if [ $1 -lt $A ]
    then 
        echo "NOTE : \033[1;32m5\033[0m"
    elif [ $1 -lt $Z ]
    then 
        echo "NOTE : \033[1;33m4\033[0m"
    elif [ $1 -lt $E ]
    then 
        echo "NOTE : \033[1;33m3\033[0m"
    elif [ $1 -lt $R ]
    then
        echo "NOTE : \033[1;31m2\033[0m"
    elif [ $1 -lt $T ]
    then
        echo "NOTE : \033[1;31m1\033[0m"
    else
        echo "NOTE : \033[1;31m0\033[0m"
    fi
}

RESULTAT=0
SUM=0
MIN=-1
MAX=0

for i in {1..100}
do
    export ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
    ./push_swap $ARG > file.txt
    if ./checker $ARG < file.txt | grep -q "KO" 
    then 
        echo "/\!\\ TEST FAILED /\!\\" >> error.log
        echo "ARG : " $ARG >> error.log
        echo "test returned : KO" >> error.log
        RESULTAT=$(($RESULTAT - 1))
    fi
    export VALUE=$(cat file.txt | wc -l)
    if [ $MIN -eq -1 ] || [ $VALUE -lt $MIN ]
    then
        MIN=$VALUE
    fi
    if [ $VALUE -gt $MAX ]
    then
        MAX=$VALUE
    fi
    SUM=$(($SUM + $VALUE))
    RESULTAT=$(($RESULTAT + 1))
done

rm -rf file.txt
echo "TEST FOR 100"
echo "TEST VALIDE  :  $RESULTAT/100"
SUM=$(($SUM / 100))
echo "MIN : $MIN"
echo "AVERAGE : $SUM"
echo "MAX : $MAX" 
display_note $SUM 100

RESULTAT=0
SUM=0
MIN=-1
MAX=0
TIME_START=$(date +%s)

for i in {1..100}
do
    export ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
	TIME_START=$(date +%s)
    ./push_swap $ARG > file.txt
	TIME_END=$(date +%s)
    if ./checker $ARG < file.txt | grep -q "KO" 
    then 
        echo "/\!\\ TEST FAILED /\!\\" >> error.log
        echo "ARG : " $ARG >> error.log
        echo "test returned : KO" >> error.log
        RESULTAT=$(($RESULTAT - 1))
    fi
    export VALUE=$(cat file.txt | wc -l)
    if [ $MIN -eq -1 ] || [ $VALUE -lt $MIN ]
    then
        MIN=$VALUE
    fi
    if [ $VALUE -gt $MAX ]
    then
        MAX=$VALUE
    fi
    SUM=$(($SUM + $VALUE))
    RESULTAT=$(($RESULTAT + 1))
done

rm -rf file.txt
echo "TEST FOR 500"
echo "TEST VALIDE : $RESULTAT/100"
SUM=$(($SUM / 100))
echo "MIN : $MIN"
echo "AVERAGE : $SUM"
echo "MAX : $MAX" 
display_note $SUM 500
TIME=$(($TIME_END-$TIME_START))
echo "TIME FOR LAST TEST : $TIME"
