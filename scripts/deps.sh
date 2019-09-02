#!/bin/bash
#
# This script loads a pd patch (argument 1) and puts all dependencies in the 
# directory specified with argument 2
#

# WHICHPD="Pd-0.48-1"
# MYPD="/Applications/$WHICHPD.app/Contents/Resources/bin/pd"

MYPD=/usr/local/bin/pd

#get pdfile name from argument 1
if [ "$1" ]
then
	PDFILE="$1"
else
	echo "Please provide a pd patch in argument 1"
	exit 1
fi

#get libdir name from argument 2
if [ "$2" ]
then
	LIBDIR="$2"
else
	echo "Please provide a library directory name in argument 2"
	exit 1
fi

#get logfile name from pd file
LOGFILE=$(basename $PDFILE .pd)-log

#load pd file and output console printout to logfile
echo "
waiting 5 seconds...
"

`$MYPD -stderr -verbose -open $PDFILE -nogui  2> "$LOGFILE"` & sleep 5 ; kill $!; wait 2>/dev/null

SORTED=$(basename "$LOGFILE" .txt)
SORTED="$SORTED-sort.txt"

grep -e "succeeded" "$LOGFILE" | sort -u > "$SORTED"
sed -i -e 's/tried //g' "$SORTED"
sed -i -e 's/and succeeded//g' "$SORTED"

# remove unwanted sorted text

if [ -e "$SORTED-e" ]
then
  rm "$SORTED-e"
fi

# make the lib directory

if [ ! -d "$LIBDIR" ]
then
  mkdir "$LIBDIR"
fi

# read the text and copy all files into the lib directory

while read line
do
  cp -r "$line" "$LIBDIR/"
done < "$SORTED"

rm "$SORTED"
rm "$LOGFILE"

exit