#!/bin/bash

for num in {01..11}; do
    # Format le numéro pour qu'il ait toujours deux chiffres
    formatted_num=$(printf "%02d" $num)

    echo "Comparaison des fichiers pour le numéro: $formatted_num"

    file1="Examples/Ex${formatted_num}_pcode.c"
    file2="Correction/corr${formatted_num}.c"

    if cmp -s "$file1" "$file2"; then
        echo "Les deux fichiers ($file1 et $file2) sont identiques."
    else
        echo "Les fichiers ($file1 et $file2) sont différents. Voici les différences :"
        diff "$file1" "$file2"
    fi

    echo ""  # Ligne vide pour une meilleure lisibilité entre les comparaisons
done
