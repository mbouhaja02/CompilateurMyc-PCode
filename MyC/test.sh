#!/bin/bash

if [ ${#num} -eq 1 ]; then
    num="0$num"
fi

for num in {01..11}; do
    echo "Comparaison des fichiers pour le numéro: $num"


    if cmp -s "Examples/Ex${num}_pcode.c" "Correction/corr${num}.c"; then
        echo "Les deux fichiers (Ex${num}_pcode.c et corr${num}.c) sont identiques."
    else
        echo "Les fichiers (Ex${num}_pcode.c et corr${num}.c) sont différents."
    fi

    echo "" 
done

