#!/bin/bash

for num in {01..11}; do
    # Format le numéro pour qu'il ait toujours deux chiffres
    formatted_num=$(printf "%02d" $num)

    echo "Comparaison des fichiers pour le numéro: $formatted_num"

    file1="Examples/Ex${formatted_num}_pcode.c"
    file2="Correction/corr${formatted_num}.c"

    # Création de copies temporaires des fichiers sans les commentaires
    temp1=$(mktemp)
    temp2=$(mktemp)

    grep -o '^[^//]*' "$file1" > "$temp1"
    grep -o '^[^//]*' "$file2" > "$temp2"

    if cmp -s "$temp1" "$temp2"; then
        echo "Les deux fichiers ($file1 et $file2) sont identiques."
    else
        echo "Les fichiers ($file1 et $file2) sont différents. Voici les différences (sans commentaires) :"
        diff "$temp1" "$temp2"
    fi

    # Nettoyage des fichiers temporaires
    rm "$temp1" "$temp2"

    echo ""  # Ligne vide pour une meilleure lisibilité entre les comparaisons
done
