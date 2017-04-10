#!/bin/bash

######################
#
# Simple shell script to run tests
#
#
# Author: Kevin Midkiff
#
######################

buildDir="build"
bin="$buildDir/tetro_solve"

if [ ! -d "$buildDir" ] ; then
    echo "ERROR: The build directory does not exist, please build the solver first"
    exit -1
fi

if [ ! -x "$bin" ] ; then
    echo "ERROR: Compiled binary at $bin does not exist, please compile the code"
    exit -1
fi

cd tests/

for f in `ls *-in.txt`
do
    echo "Running test: $f"
    ../${bin} < $f
done
