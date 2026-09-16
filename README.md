# C-Containers : Bibliothèque de structures de données en C

## À propos du projet

Ce dépôt a pour objectif de regrouper une implémentation de différents conteneurs de données développés entièrement en langage **C**. 

Afin de s'adapter à divers cas d'usage (notamment pour les systèmes embarqués où les ressources sont limitées), les structures sont développées selon deux paradigmes distincts :
- **Une version "Classique" (Non-POO)** : Basée sur des appels de fonctions simples, idéale pour limiter l'overhead, maximiser les performances et la légèreté.
- **Une version Orientée Objet (POO)** : Utilisant des structures de données encapsulant des pointeurs de fonctions pour simuler des méthodes d'objets. Cette approche offre une syntaxe plus moderne, modulaire et proche du C++.

##  État d'avancement (Fonctionnalités actuelles)

Actuellement, le projet propose les implémentations suivantes :

### FIFO
- Implémentation **POO** fonctionnelle (utilisation via des pointeurs de fonctions).
- Implémentation **Standard** fonctionnelle (utilisation via des appels de fonctions classiques).

## TODO :

Voici les prochains conteneurs et fonctionnalités prévus :

- [ ] **Vector (Tableau dynamique)**
  - [ ] Version optimisée pour l'embarqué (Embedded)
  - [ ] Version POO
- [ ] **Array (Tableau statique)**
  - [ ] Version optimisée pour l'embarqué (Embedded)
  - [ ] Version POO
- [ ] **List (Liste chaînée)**
- [ ] **FIFO Circulaire** (Implémentation circulaire complète)

## 🛠️ Utilisation

Pour chaque structure de donnée, il suffit de prendre le fichier `.h` et le fichier `.c` correspondant à la structure.
