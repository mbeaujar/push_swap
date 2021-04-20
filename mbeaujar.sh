#!/bin/bash

# file error -- error.log
# file used by the tester -- tester_100.txt

##### COLORS #####

GREEN='\033[1;32m'
YELLOW='\033[1;33m'
RED='\033[1;31m'
NC='\033[0m'

##### FILES #####

if [ -f error.log ]; then
	rm -rf error.log
fi

if [ ! -f ./push_swap ]; then
	printf "${RED}File push_swap does not exist${NC}\n"
	exit 1
elif [ ! -f ./checker ]; then
	printf "${RED}File checker does not exist${NC}\n"
	exit 1
fi

display_note()
{
    if [ $2 -eq 100 ] ;then
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
    if [ $1 -lt $A ]; then 
        printf "${GREEN}NOTE : ${GREEN}5${NC}\n"
    elif [ $1 -lt $Z ]; then 
        printf "${GREEN}NOTE : ${YELLOW}4${NC}\n"
    elif [ $1 -lt $E ]; then 
        printf "${GREEN}NOTE : ${YELLOW}3${NC}\n"
    elif [ $1 -lt $R ]; then
        printf "${GREEN}NOTE : ${RED}2${NC}\n"
    elif [ $1 -lt $T ]; then
        printf "${GREEN}NOTE : ${RED}1${NC}\n"
    else
        echo "${GREEN}NOTE : ${RED}0${NC}"
    fi
}

clear

printf ${GREEN}
echo " ______________________________________ "
echo "|                                      |"
echo "|              TEST ERROR              |"
echo "|______________________________________|"
printf ${NC}
printf "\n"
MSG_ERROR=0

printf "${GREEN}Error : ${NC}"
touch endline.txt
error=("-2147483649 1" "2147483648 2" "1000000000000 5" "1 2 4 5 2" "5 4 3 2 one" "pa" "1 p" "p" "10000000000000000000000000000" "0 00")
for error in "${error[@]}"
do
	if ./checker $error < endline.txt | grep -q -E "KO|Error"; then
		printf "${GREEN}[OK]${NC}"
	else
		printf "${RED}[KO]${NC}"
		echo "/!\\ TEST FAILED /!\\" >> error.log
		echo "ARG : '$error'" >> error.log
		echo "test returned : [KO]" >> error.log
		MSG_ERROR=$(($MSG_ERROR + 1))
	fi
	printf " "
done

if ./checker 0 "" < endline.txt | grep -q -E "Error"; then
	printf "${GREEN}[OK]${NC}"
else
	printf "${RED}[KO]${NC}"
	echo "/!\\ TEST FAILED /!\\" >> error.log
	echo "ARG : '0 \"\"'" >> error.log
	echo "test returned : [KO]" >> error.log
	MSG_ERROR=$(($MSG_ERROR + 1))
fi
printf " "

if echo "saa" > endline.txt && ./checker 2 1 3 4 5 < endline.txt | grep -q -E "Error"; then
	printf "${GREEN}[OK]${NC}"
else
	printf "${RED}[KO]${NC}"
	echo "/!\\ TEST FAILED /!\\" >> error.log
	echo "INSTRUCTION : 'saa'" >> error.log
	echo "test returned : [KO]" >> error.log
	MSG_ERROR=$(($MSG_ERROR + 1))
fi
printf " "

if ! ./push_swap 010 | grep -q -E "Error"; then
	printf "${GREEN}[OK]${NC}"
else
	printf "${RED}[KO]${NC}"
	echo "/!\\ TEST FAILED /!\\" >> error.log
	echo "ARG : '010'" >> error.log
	echo "test returned : [KO]" >> error.log
	MSG_ERROR=$(($MSG_ERROR + 1))
fi
printf " "
ARG=-00000000000000000000000000010

if ! ./push_swap $ARG | grep -q -E "Error"; then
	printf "${GREEN}[OK]${NC}"
else
	printf "${RED}[KO]${NC}"
	echo "/!\\ TEST FAILED /!\\" >> error.log
	echo "ARG : '$ARG'" >> error.log
	echo "test returned : [KO]" >> error.log
	MSG_ERROR=$(($MSG_ERROR + 1))
fi
printf " "

rm -rf endline.txt

printf "\n"

if [ $MSG_ERROR -gt 0 ]; then
	echo "Error file : error.log"
fi



printf ${GREEN}
echo " ______________________________________ "
echo "|                                      |"
echo "|              TEST FOR 100            |"
echo "|______________________________________|"
printf "\nTesting ...\n"
printf ${NC}
printf "\n"

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
	export $1=$(($1 + (100 * $(cat tester_$3.txt | grep -i $1 | wc -l) / $2)))
}

for i in {1..100}
do
    export ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
    ./push_swap $ARG > tester_100.txt
    if ./checker $ARG < tester_100.txt | grep -q "KO"; then 
        echo "/!\\ TEST FAILED /!\\" >> error.log
        echo "ARG : " $ARG >> error.log
        echo "test returned : [KO]" >> error.log
        RESULTAT=$(($RESULTAT - 1))
    fi
    export VALUE=$(cat tester_100.txt | wc -l)
    if [ $MIN -eq -1 ] || [ $VALUE -lt $MIN ]; then
        MIN=$VALUE
    fi
    if [ $VALUE -gt $MAX ]; then
        MAX=$VALUE
    fi
    SUM=$(($SUM + $VALUE))
    RESULTAT=$(($RESULTAT + 1))
	LINE=$(cat tester_100.txt | wc -l)
	inst=("PA" "PB" "SA" "SB" "SS" "RA" "RB" "RR" "RRA" "RRB" "RRR")
	for inst in "${inst[@]}"
	do
		calcul_percent $inst $LINE 100
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
	printf "${GREEN}Score : ${GREEN}$RESULTAT${GREEN}/100${NC}\n"
else
	printf "${GREEN}Score : ${RED}$RESULTAT${GREEN}/100${NC}\n"
	printf "Failed test > error.log\n"
fi

display_note $MAX 100
echo ""
printf "${GREEN}Stats : ${NC}\n"
printf "${YELLOW}MIN : ${NC}$MIN\n"
printf "${YELLOW}AVERAGE : ${NC}$SUM\n"
printf "${YELLOW}MAX : ${NC}$MAX\n"
echo ""
printf "${GREEN}percentage of instructions : ${NC}\n"
printf "${YELLOW}PA : ${NC}$PA\n"
printf "${YELLOW}PB : ${NC}$PB\n"
printf "${YELLOW}SA : ${NC}$SA\n"
printf "${YELLOW}SB : ${NC}$SB\n"
printf "${YELLOW}SS : ${NC}$SS\n"
printf "${YELLOW}RA : ${NC}$RA\n"
printf "${YELLOW}RB : ${NC}$RB\n"
printf "${YELLOW}RR : ${NC}$RR\n"
printf "${YELLOW}RRA : ${NC}$RRA\n"
printf "${YELLOW}RRB : ${NC}$RRB\n"
printf "${YELLOW}RRR : ${NC}$RRR\n"

rm -rf tester_100.txt

printf ${GREEN}
echo " ______________________________________ "
echo "|                                      |"
echo "|              TEST FOR 500            |"
echo "|______________________________________|"
printf "\nTesting ...\n"
printf ${NC}
printf "\n"
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
TIME=0

for i in {1..100}
do
    export ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
	TIME_START=$(date +%s)
    ./push_swap $ARG > tester_500.txt
	TIME_END=$(date +%s)
	if [ $(($TIME_END-$TIME_START)) -gt $TIME ]; then
		TIME=$(($TIME_END-$TIME_START))
	fi
    if ./checker $ARG < tester_500.txt | grep -q "KO"; then 
        echo "/!\\ TEST FAILED /!\\" >> error.log
        echo "ARG : " $ARG >> error.log
        echo "test returned : [KO]" >> error.log
        RESULTAT=$(($RESULTAT - 1))
    fi
    export VALUE=$(cat tester_500.txt | wc -l)
    if [ $MIN -eq -1 ] || [ $VALUE -lt $MIN ]; then
        MIN=$VALUE
    fi
    if [ $VALUE -gt $MAX ]; then
        MAX=$VALUE
    fi
    SUM=$(($SUM + $VALUE))
    RESULTAT=$(($RESULTAT + 1))
	LINE=$(cat tester_500.txt | wc -l)
	inst=("PA" "PB" "SA" "SB" "SS" "RA" "RB" "RR" "RRA" "RRB" "RRR")
	for inst in "${inst[@]}"
	do
		calcul_percent $inst $LINE 500
	done
done

instr=("PA" "PB" "SA" "SB" "SS" "RA" "RB" "RR" "RRA" "RRB" "RRR")
for instr in "${instr[@]}"
do
	finish_percent $instr 
done

SUM=$(($SUM / 100))

##### DISPLAY #####

if [ $RESULTAT -eq 100 ]
then
	printf "${GREEN}Score : ${GREEN}$RESULTAT${GREEN}/100${NC}\n"
else
	printf "${GREEN}Score : ${RED}$RESULTAT${GREEN}/100${NC}\n"
	printf "Failed test > error.log\n"
fi

display_note $MAX 500
echo ""
printf "${GREEN}Stats : ${NC}\n"
printf "${YELLOW}MIN : ${NC}$MIN\n"
printf "${YELLOW}AVERAGE : ${NC}$SUM\n"
printf "${YELLOW}MAX : ${NC}$MAX\n"
printf "${YELLOW}LONGEST TIME : ${NC}$TIME "
if [ $TIME -gt 1 ]; then
	printf "seconds \n"
else
	printf "second \n"
fi
echo ""
printf "${GREEN}percentage of instructions : ${NC}\n"
printf "${YELLOW}PA : ${NC}$PA\n"
printf "${YELLOW}PB : ${NC}$PB\n"
printf "${YELLOW}SA : ${NC}$SA\n"
printf "${YELLOW}SB : ${NC}$SB\n"
printf "${YELLOW}SS : ${NC}$SS\n"
printf "${YELLOW}RA : ${NC}$RA\n"
printf "${YELLOW}RB : ${NC}$RB\n"
printf "${YELLOW}RR : ${NC}$RR\n"
printf "${YELLOW}RRA : ${NC}$RRA\n"
printf "${YELLOW}RRB : ${NC}$RRB\n"
printf "${YELLOW}RRR : ${NC}$RRR\n"

rm -rf tester_500.txt
