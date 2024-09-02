# SUBNETTING-NETWORK-WITH-LANGUAGE-C
# IP Subnetting Tool

## Description

Ce programme Python permet de découper un réseau IP en sous-réseaux plus petits et d'afficher les informations essentielles sur chacun d'eux. Il prend une adresse IP avec un masque de sous-réseau en entrée et fournit des détails sur l'adresse réseau, l'adresse de broadcast, le nombre d'hôtes, et les sous-réseaux découpés.

## Fonctionnalités

- **Calcul des informations de base** : Adresse réseau, adresse de broadcast, et nombre d'hôtes disponibles.
- **Découpage du réseau** : Permet de diviser le réseau en sous-réseaux plus petits selon le nombre spécifié par l'utilisateur.
- **Affichage des sous-réseaux** : Affiche les adresses de réseau et de broadcast pour chaque sous-réseau découpé.

## Installation

1. Clone le dépôt :
    ```bash
    git clone https://github.com/ton-utilisateur/ton-repository.git
    ```
2. Accède au répertoire du projet :
    ```bash
    cd ton-repository
    ```
    ```

## Utilisation

1. compiler :
    ```bash
    gcc *.c -o subnet
    ```
    ```bash
    ./subnet
2. Suis les instructions affichées :
    - **Entrer l'adresse IP (X.X.X.X/netmask)** : Saisis l'adresse IP et le masque de sous-réseau, par exemple, `110.41.32.51/20`.
    - **Combien de découpages souhaitez-vous ?** : Indique le nombre de sous-réseaux que tu souhaites créer.

## Exemple d'Exécution

```text
Entrer l'adresse IP (X.X.X.X/netmask): 110.41.32.51/20

=========================================
=>ADRESSE IP : 110.41.32.51/20
=>Adresse reseau      : 110.41.32.0
=>Adresse broadcast   : 110.41.47.255
=>Nombre de machine   : 4094
=========================================
Combien de découpages souhaitez-vous ? 3

===================================================
[          Reseau |        Broadcast]
===================================================
1)          110.41.32.0 |          110.41.33.255
2)          110.41.34.0 |          110.41.35.255
3)          110.41.36.0 |          110.41.37.255
4)          110.41.38.0 |          110.41.39.255
5)          110.41.40.0 |          110.41.41.255
6)          110.41.42.0 |          110.41.43.255
7)          110.41.44.0 |          110.41.45.255
8)          110.41.46.0 |          110.41.47.255
