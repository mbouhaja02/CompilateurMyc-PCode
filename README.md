#Projet de Compilation MyC-PCode

Description du Projet

Ce projet vise à développer un compilateur pour un mini langage impératif nommé MyC, lequel est traduit en P-Code. Le compilateur actuellement implémenté gère les six premières phases de compilation, couvrant ainsi jusqu'à l'exemple 17.

#Structure du Projet

    Répertoire de Correction : Un dossier correction a été créé pour contenir les solutions correctes de tous les fichiers. Un script shell (./test) est utilisé pour comparer automatiquement les résultats obtenus avec les fichiers de correction.

    Modifications apportées : Dans le dossier Pcode, tous les exemples se compilent sans problème. Il est important de noter que nous avons modifié les références stack[bp]+1 en stack[bp].int_value+1 pour corriger certains problèmes identifiés dans les fichiers Examples.tar fournis.

#Instructions de Compilation

Compilation de MyC vers P-Code

Pour compiler un fichier MyC en P-Code, suivez ces étapes :

    Exécutez make pour construire le compilateur.
    Utilisez ./run ExX pour compiler un exemple spécifique, où X est le numéro de l'exemple (par exemple, 01, 02, ..., 17).

Compilation des fichiers P-Code avec GCC

Pour compiler les fichiers P-Code :

    Naviguez vers le répertoire PCode.
    Exécutez make ExX pour compiler un fichier spécifique ou makeall pour compiler tous les fichiers
