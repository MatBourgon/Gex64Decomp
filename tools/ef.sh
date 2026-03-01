#!/bin/sh
if [ $# -eq 1 ]; then
    result=`find asm -name *$1.s`
    if [$result -eq ""]; then
        echo No file found for file named \'$1.s\'
    else
        code $result
    fi
elif [ $# -eq 2 ]; then
    code asm/nonmatchings/$1/$2.s
else
    echo Requires 1 or 2 arguments
fi