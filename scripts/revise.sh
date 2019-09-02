#!/bin/bash

PD=/Applications/Pd-0.48-1.app/Contents/Resources/bin/pd

if [ ! `command -v pd` ]
then
	echo "Could not find 'pd', trying with default location:"
	echo $PD
	if [ ! `command -v $PD` ]
	then
		echo "Pd not found. Update line 3 with correct path."
		exit
	fi
else
	PD=pd
fi

LIST=`cat ./list.txt`


declare -a ARRAY


for i in $LIST
do
	ARRAY+=( "${arr[@]}" "$i" )
done


OFFSET=$1
ARROFFSET=`echo "${ARRAY[@]:$OFFSET}"`

COUNT=$OFFSET

for j in $ARROFFSET
do
	if  [[ $j == *"-help.pd"* ]]
	then
		echo "[$COUNT] [$j]"
		$PD $j
		((COUNT++))
		echo "--------- [$COUNT] [end]"
	fi
done

exit 0