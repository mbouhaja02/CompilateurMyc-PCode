#!/bin/bash
cd src
make
cd ..

for num in {01..17}; do
    echo "Comparaison des fichiers pour le numéro: $num"
    ./run "Ex${num}"

    file1="test/Ex${num}_pcode.c"
    file2="Correction/corr${num}.c"

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
cd src
make clean
cd ..
