#!/bin/bash

a="NO"
b="NO"

# Functions
function choose {
	while true; do
	if [ "$a" = "OK" ] && [ "$b" = "OK" ]; then
		./main $portServer
	fi
	echo -e """
	\033[0;32m 
	 ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
	  $a - Directory 4 static server
	  $b - Port of instance         
	
	 ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
	\033[0;0m""";
	
	  read -r -p "Server -> " action
	
		if [ -d "$action" ]; then
			a="OK"
			rootServer="$action"
			continue
		elif [[ "$action" =~ ^[0-9]+$ ]]; then
			b="OK"
			portServer="$action"
			continue
		else
			a="OFF"
			b="OFF"
			echo "ONLY DIRECTORY OR PORT!"
		fi
	done
}

if [ -f main ]; then
	choose
else
	gcc include/main.c -o main
	if [ $? != 0 ]; then
		echo "ERROR IN COMPILATION!"
		exit 1;
	fi
	
	choose
fi
