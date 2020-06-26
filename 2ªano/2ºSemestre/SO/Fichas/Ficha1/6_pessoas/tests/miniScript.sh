#!/bin/bash

. tests/nomes.sh

for i in {1..10000}; do
  nome=$((RANDOM % ${#NOMES[@]}))
  idade=$((RANDOM % ${#IDADES[@]}))
  ./bin/pessoas -i "${NOMES[nome]}" ${IDADES[idade]}
done

