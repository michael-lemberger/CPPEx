#!/bin/bash

# everything works=0, helgrind faild=1, valgrind faild=2, valgrind and helgrind faild=3, Compilation failed=7
DIR_PATH=${1?Error: no path given}
PROGRAM=${2?Error: no program name}
cd $DIR_PATH
output="7"
table=" Compilation     Memory leaks     thread race"

make > "/dev/null"
if [ $? -gt 0 ];then
echo $table
echo "   Fail     FAIL	      FAIL"
exit 7
fi

valgrind --leak-check=full --error-exitcode=2 ./${PROGRAM} ${ARGUMANTS} > valgrind.txt  2>&1

if [ $? -ne 2 ];then
output="0"
else
output="2"
fi

valgrind --tool=helgrind --error-exitcode=1 $dir/$program > helgrind.txt  2>&1
if [ $? -eq 1 ];then
output=output+"1"
fi

echo $table
echo "   PASS      FAIL	      FAIL"

rm valgrind.txt
rm helgrind.txt

cd - > "/dev/null"

exit $output

