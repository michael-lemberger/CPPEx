#!/bin/bash

# everything works=0, helgrind faild=1, valgrind faild=2, valgrind and helgrind faild=3, Compilation failed=7
dir=$1
program=$2
cd $dir
output="7"
FILE=./makefile
table=" Compilation     Memory leaks     thread race"

if [ -e "$dir/$FILE"  ];
then
make > "/dev/null"
if [ $? -eq 0 ];then

valgrind --leak-check=full --error-exitcode=2 ./$program  > valgrind.txt  2>&1

if [ $? -ne 2 ];then


valgrind --tool=helgrind --error-exitcode=1 $dir/$program > helgrind.txt  2>&1

if [ $? -ne 1 ];then

output="0"
echo $table
echo "   PASS     PASS       PASS"

else
echo $table
echo "   PASS     PASS       FAIL"
output="1"
fi

else
valgrind --tool=helgrind --error-exitcode=3 $dir/$program > helgrind.txt  2>&1

if [ $? -ne 3 ];then
echo $table
echo "   PASS      FAIL	      PASS"
output="2"

else
echo $table
echo "   PASS      FAIL	      FAIL"
output="3"
fi
fi
else
echo $table
echo "   FAIL      FAIL	      FAIL"
fi
fi

if [ $output -ne 7 ];then
rm valgrind.txt
rm helgrind.txt
fi
cd - > "/dev/null"

exit $output

