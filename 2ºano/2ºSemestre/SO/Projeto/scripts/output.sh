#!/bin/bash

# Start sever
./argusd &
sleep 1

# Commands execution
./argus -e "ls"
ls > gol

[ "$(diff log gol)" ] && echo "False" || echo "True"
