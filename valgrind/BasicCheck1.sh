#!/bin/bash

# everything works=0, helgrind faild=1, valgrind faild=2, valgrind and helgrind faild=3, Compilation failed=7
dir=$1
program=$2
#trash = "/dev/null"
cd $dir
output="7"
FILE=./makefile



if [ -e "$dir/$FILE"  ];
then
make
if [ $? -eq 0 ];then

valgrind --leak-check=full --error-exitcode=1 ./$program  > valgrind.txt  2>&1
#grep -q "no leaks are possible" valgrind.txt
if [ $? -ne 1 ];then
echo "valgrind pass"

valgrind --tool=helgrind --error-exitcode=1 $dir/$program > helgrind.txt  2>&1
#grep -q "ERROR SUMMARY: 0 errors" helgrind.txt
if [ $? -ne 1 ];then
echo "helgrind pass"	
output=0

else
echo "helgrind not pass"	
output="2"
fi

else
echo "valgrind not pass"
valgrind --tool=helgrind $dir/$program > helgrind.txt  2>&1
#grep -q "ERROR SUMMARY: 0 errors" helgrind.txt

if [ $? -eq 0 ];then
output="1"

else
output="3"
fi
fi
fi
fi

#$output > result.txt
echo "$output"
#return 0

