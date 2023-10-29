#include <stdio.h>
#include <stdlib.h>
 
#define MOD 1000000007
 
// Tableau pour la mémoïsation
long long memo[1000001];
 
// Fonction récursive avec mémoïsation
long long countWays(int n) {
    // Si la valeur a déjà été calculée, la retourner
    if (memo[n] != -1) {
        return memo[n];
    }
    // Initialiser le compteur pour n
    long long count = 0;
    // Pour chaque valeur possible du dé (1 à 6),
    // ajouter le nombre de façons de former la somme n - i
    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0) {
            count = (count + countWays(n - i)) % MOD;
        }
    }
    // Stocker le résultat dans le tableau de mémoïsation et le retourner
    return memo[n] = count;
}
 
int main() {
    int n;
    scanf("%d", &n);
    // Initialiser le tableau de mémoïsation avec des valeurs de -1
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    // Cas de base
    memo[0] = 1;
    // Calculer et afficher le résultat
    printf("%lld\n", countWays(n));
    return 0;
}
