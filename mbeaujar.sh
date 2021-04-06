#!/bin/bash

clear

# file error -- error.log
# file used by the tester -- tester_100.txt

##### COLORS #####

GREEN='\033[1;32m'
YELLOW='\033[1;33m'
RED='\033[1;31m'
NC='\033[0m'

echo ${GREEN}
echo " ______________________________________ "
echo "|                                      |"
echo "|              TEST FOR 100            |"
echo "|______________________________________|"
echo ${NC}


##### DEFINES VARIABLES #####

# percent instructions
PA=0
PB=0
SA=0
SB=0
SS=0
RA=0
RB=0
RR=0
RRA=0
RRB=0
RRR=0

# init variables
RESULTAT=0
SUM=0
MIN=-1
MAX=0

calcul_percent()
{
	export $1=$(($1 + (100 * $(cat tester_100.txt | grep -i $1 | wc -l) / $2)))
}

for i in {1..100}
do
    export ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
    ./push_swap $ARG > tester_100.txt
    if ./checker $ARG < tester_100.txt | grep -q "KO" 
    then 
        echo "/\!\\ TEST FAILED /\!\\" >> error.log
        echo "ARG : " $ARG >> error.log
        echo "test returned : KO" >> error.log
        RESULTAT=$(($RESULTAT - 1))
    fi
    export VALUE=$(cat tester_100.txt | wc -l)
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
	LINE=$(cat tester_100.txt | wc -l)
	inst=("PA" "PB" "SA" "SB" "SS" "RA" "RB" "RR" "RRA" "RRB" "RRR")
	for inst in "${inst[@]}"
	do
		calcul_percent $inst $LINE
	done
done

finish_percent()
{
	export $1=$(($1 / 100))
}
inst=("PA" "PB" "SA" "SB" "SS" "RA" "RB" "RR" "RRA" "RRB" "RRR")
for inst in "${inst[@]}"
do
	finish_percent $inst 
done

SUM=$(($SUM / 100))

##### DISPLAY #####

if [ $RESULTAT -eq 100 ]
then
	echo "${GREEN}Score : ${GREEN}$RESULTAT${GREEN}/100${NC}"
else
	echo "${GREEN}Score : ${RED}$RESULTAT${GREEN}/100${NC}"
	echo "Failed test > error.log"
fi

echo ""
echo "${GREEN}Stats : ${NC}"
echo "${YELLOW}MIN : ${NC}$MIN"
echo "${YELLOW}AVERAGE : ${NC}$SUM"
echo "${YELLOW}MAX : ${NC}$MAX"
echo ""
echo "${GREEN}percentage of instructions : ${NC}"
echo "${YELLOW}PA : ${NC}$PA%"
echo "${YELLOW}PB : ${NC}$PB%"
echo "${YELLOW}SA : ${NC}$SA%"
echo "${YELLOW}SB : ${NC}$SB%"
echo "${YELLOW}SS : ${NC}$SS%"
echo "${YELLOW}RA : ${NC}$RA%"
echo "${YELLOW}RB : ${NC}$RB%"
echo "${YELLOW}RR : ${NC}$RR%"
echo "${YELLOW}RRA : ${NC}$RRA%"
echo "${YELLOW}RRB : ${NC}$RRB%"
echo "${YELLOW}RRR : ${NC}$RRR%"

rm -rf tester_100.txt


echo ${GREEN}
echo " ______________________________________ "
echo "|                                      |"
echo "|              TEST FOR 500            |"
echo "|______________________________________|"
echo ${NC}


##### DEFINE VARIABLES #####
RESULTAT=0
SUM=0
MIN=-1
MAX=0

calcul_percent()
{
	export $1=$(($1 + (100 * $(cat tester_500.txt | grep -i $1 | wc -l) / $2)))
}

for i in {1..100}
do
    export ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
    ./push_swap $ARG > tester_500.txt
    if ./checker $ARG < tester_500.txt | grep -q "KO" 
    then 
        echo "/\!\\ TEST FAILED /\!\\" >> error.log
        echo "ARG : " $ARG >> error.log
        echo "test returned : KO" >> error.log
        RESULTAT=$(($RESULTAT - 1))
    fi
    export VALUE=$(cat tester_500.txt | wc -l)
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
	LINE=$(cat tester_500.txt | wc -l)
	inst=("PA" "PB" "SA" "SB" "SS" "RA" "RB" "RR" "RRA" "RRB" "RRR")
	for inst in "${inst[@]}"
	do
		calcul_percent $inst $LINE
	done
done

finish_percent()
{
	export $1=$(($1 / 100))
}

instr=("PA" "PB" "SA" "SB" "SS" "RA" "RB" "RR" "RRA" "RRB" "RRR")
for instr in "${instr[@]}"
do
	finish_percent $instr 
done

SUM=$(($SUM / 100))

##### DISPLAY #####

if [ $RESULTAT -eq 100 ]
then
	echo "${GREEN}Score : ${GREEN}$RESULTAT${GREEN}/100${NC}"
else
	echo "${GREEN}Score : ${RED}$RESULTAT${GREEN}/100${NC}"
	echo "Failed test > error.log"
fi

echo ""
echo "${GREEN}Stats : ${NC}"
echo "${YELLOW}MIN : ${NC}$MIN"
echo "${YELLOW}AVERAGE : ${NC}$SUM"
echo "${YELLOW}MAX : ${NC}$MAX"
echo ""
echo "${GREEN}percentage of instructions : ${NC}"
echo "${YELLOW}PA : ${NC}$PA%"
echo "${YELLOW}PB : ${NC}$PB%"
echo "${YELLOW}SA : ${NC}$SA%"
echo "${YELLOW}SB : ${NC}$SB%"
echo "${YELLOW}SS : ${NC}$SS%"
echo "${YELLOW}RA : ${NC}$RA%"
echo "${YELLOW}RB : ${NC}$RB%"
echo "${YELLOW}RR : ${NC}$RR%"
echo "${YELLOW}RRA : ${NC}$RRA%"
echo "${YELLOW}RRB : ${NC}$RRB%"
echo "${YELLOW}RRR : ${NC}$RRR%"

rm -rf tester_500.txt
