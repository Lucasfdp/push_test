#!/bin/bash

__nc()      { echo -e "\033[0m"; }
_yellow()   { echo -ne "\033[1;33m$1"$(__nc); }
_blue()     { echo -e "\033[34m$1"$(__nc); }

if ! [[ "$1" = "--silent" || "$1" = "--lite" || "$1" = "--log" || -z "$1" ]]; then
	exit 1
fi
clear
tput civis
trap 'tput cnorm; exit 42;' INT TERM 
echo -e "\n"$(_blue "  EVALUATION TEST - PUSH_SWAP")"\n"
if [ ! -r ../push_swap ]; then
	if [ ! -r ../Makefile ]; then
		echo -e " your Makefile is missing...\n"
		exit 1
	fi
	echo -e "  executing your Makefile..."
	echo -e "\033[1A\033[1A"
	make -C ../ re > /dev/null
	echo -e "          ready!!               "
	sleep 1
	echo -e "\033[1A\033[1A"
fi
if [ "$1" = "--lite" ]; then
	echo -e $(_yellow "-------------  3  -------------")
	./guilletester_ps.sh 3 30
	echo -e $(_yellow "-------------  5  -------------")
	./guilletester_ps.sh 5 30  
	echo -e $(_yellow "------------  100  ------------")
	./guilletester_ps.sh 100 30
	echo -e $(_yellow "------------  500  ------------")
	./guilletester_ps.sh 500 5
	echo -e $(_yellow "---------  500 strict  --------")
	./guilletester_ps.sh --strict
elif [ "$1" = "--silent" ]; then
	echo -e $(_yellow "-------------  3  -------------")
	./guilletester_ps.sh 3 100 --silent
	echo -e $(_yellow "-------------  5  -------------")
	./guilletester_ps.sh 5 100 --silent 
	echo -e $(_yellow "------------  100  ------------")
	./guilletester_ps.sh 100 300 --silent
	echo -e $(_yellow "------------  500  ------------")
	./guilletester_ps.sh 500 50 --silent
	echo -e $(_yellow "---------  500 strict  --------")
	./guilletester_ps.sh --strict --silent
elif [ "$1" = "--log" ]; then
	echo -e $(_yellow "-------------  3  -------------")
	./guilletester_ps.sh 3 100 --log
	echo -e $(_yellow "-------------  5  -------------")
	./guilletester_ps.sh 5 100 --log
	echo -e $(_yellow "------------  100  ------------")
	./guilletester_ps.sh 100 300 --log
	echo -e $(_yellow "------------  500  ------------")
	./guilletester_ps.sh 500 50 --log
	echo -e $(_yellow "---------  500 strict  --------")
	./guilletester_ps.sh --strict --log
else
	echo -e $(_yellow "-------------  3  -------------")
	./guilletester_ps.sh 3 100 
	echo -e $(_yellow "-------------  5  -------------")
	./guilletester_ps.sh 5 100  
	echo -e $(_yellow "------------  100  ------------")
	./guilletester_ps.sh 100 300
	echo -e $(_yellow "------------  500  ------------")
	./guilletester_ps.sh 500 50
	echo -e $(_yellow "---------  500 strict  --------")
	./guilletester_ps.sh --strict
fi
exit 0