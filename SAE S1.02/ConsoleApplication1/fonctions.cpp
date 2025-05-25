/**
 * \file fonctions.cpp
 *
 * Définition des fonctions fournies.
 */
#include "fonctions.h"
#include <iostream>
#include <fstream>
#include <algorithm>



 /**
  * Crée un tableau d'entiers dont tous les éléments sont choisis aléatoirement.
  *
  * Un tel tableau peut par exemple être 30968 28073 31177 2882 6140 17999 13828 20039 2310 24865.
  *
  * \param[in] N taille du tableau
  * \return le tableau initialisé
  */
std::vector<int> initTabAleat(size_t N)
{
    std::vector<int> tab(N);
    for (auto& val : tab)
        val = rand();
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Chaque élément est quasiment à sa place définitive, échangé éventuellement d'une place.
 *
 * Un tel tableau peut par exemple être 1 3 2 4 6 5 8 7 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTri(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    for (int i = 0; i < N - 1; i++)
    {
        if (rand() % 2 == 0)
        {
            std::swap(tab[i], tab[i + 1]);
            ++i;
        }
    }
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le deuxième élément sont échangés.
 *
 * Un tel tableau peut par exemple être 2 1 3 4 5 6 7 8 9 10.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDeb(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[0], tab[1]);
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le dernier et l'avant dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 1 2 3 4 5 6 7 8 10 9.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriFin(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[N - 1], tab[N - 2]);
    return tab;
}

/**
 * Crée un tableau d'entiers presque triés. Seuls le premier et le dernier élément sont échangés.
 *
 * Un tel tableau peut par exemple être 10 2 3 4 5 6 7 8 9 1.
 *
 * \param[in] N taille du tableau
 * \return le tableau initialisé
 */
std::vector<int> initTabPresqueTriDebFin(size_t N)
{
    std::vector<int> tab(N);
    for (int i = 0; i < N; i++)
        tab[i] = i;
    std::swap(tab[N - 1], tab[0]);
    return tab;
}

/**
 * Vérifie qu'un tableau est correctement trié. Si le tableau est mal trié, un message d'erreur est
 * affiché sur le flux d'erreur et le programme est terminé.
 *
 * \param[in] tab Le tableau à vérifier
 * \param[in] algoName Le nom de l'algorithme de tri qui a été utilisé. Ce paramètre est optionnel.
 */
void verifTri(const std::vector<int>& tab, const std::string& algoName)
{
    const size_t taille = tab.size();
    for (size_t i = 1; i < taille; i++)
    {
        if (tab[i - 1] > tab[i])
        {
            std::cerr << "Erreur dans le tri " << algoName << (algoName.empty() ? "!" : " !") << '\n';
            exit(EXIT_FAILURE);
        }
    }
}

unsigned int triSelection(std::vector<int>& tab)
{
    size_t n = tab.size();
    unsigned int N = 0;

    for (size_t i = 0; i < n - 1; ++i)
    {
        size_t mini = i;

        for (size_t j = i + 1; j < n; ++j)
        {
            N++;
            if (tab[j] < tab[mini])
            {
                mini = j;
            }
        }
        
        if (mini != i)
        {
            std::swap(tab[i], tab[mini]);
        }
    }

    return N;
}


unsigned int triBulles(std::vector<int>& tab)
{
    size_t n = tab.size();
    unsigned int N = 0;

    for (size_t i = n - 1; i > 0; --i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            N++;
            if (tab[j + 1] < tab[j])
            {
                std::swap(tab[j], tab[j + 1]);
            }
        }
    }

    return N;
}



unsigned int triBullesOptimise(std::vector<int>& tab)
{
    size_t n = tab.size();
    unsigned int N = 0;

    for (size_t i = n - 1; i > 0; --i)
    {
        bool tableauTriee = true;

        for (size_t j = 0; j < i; ++j)
        {
            N++;
            if (tab[j + 1] < tab[j])
            {
                std::swap(tab[j], tab[j + 1]);
                tableauTriee = false;
            }
        }

        if (tableauTriee)
            break;
    }

    return N;
}



unsigned int triPeigne(std::vector<int>& tab)
{
    size_t n = tab.size();
    unsigned int N = 0;

    size_t gap = n;
    bool swapped = true;

    while (gap > 1 || swapped)
    {
        gap = (gap * 10) / 13;

        if (gap < 1)
            gap = 1;

        swapped = false;

        for (size_t i = 0; i < n - gap; ++i)
        {
            size_t j = i + gap;
            N++;

            if (tab[i] > tab[j])
            {
                std::swap(tab[i], tab[j]);
                swapped = true;
            }
        }
    }

    return N;
}



unsigned int triRapideShort(std::vector<int>& tab) {
    int N = triRapide(tab, 0, tab.size()-1);
    return N;
}

unsigned int triRapide(std::vector<int>& tab, int debut, int fin) {
    unsigned int N = 0;

    if (debut < fin) {
        int pivotIndex = debut + (fin - debut) / 2;
        int pivot = tab[pivotIndex];
        int i = debut;
        int j = fin;
        while (i <= j) {
            while (tab[i] < pivot) {
                i++;
                N++;
            }
            while (tab[j] > pivot) {
                j--;
                N++;
            }

            if (i <= j) {
                std::swap(tab[i], tab[j]);
                i++;
                j--;
            }
        }
        N += triRapide(tab, debut, j);
        N += triRapide(tab, i, fin);
    }
    return N;
}


unsigned int tamiser(std::vector<int>& tab, size_t noeur, size_t n) {
    size_t k = noeur;
    size_t j = 2 * k;

    unsigned int N = 0;  // Variable pour compter le nombre de comparaisons

    while (j <= n) {
        if (j < n && tab[j - 1] < tab[j]) { 
            j = j + 1;
        }

        if (tab[k - 1] < tab[j - 1]) {  
            std::swap(tab[k - 1], tab[j - 1]); 
            k = j;
            j = 2 * k;
            N++;  // Incrémente le compteur de comparaisons
        }
        else {
            j = n + 1;
        }
    }

    return N;
}

unsigned int triParTas(std::vector<int>& tab) {
    size_t longueur = tab.size();

    unsigned int N = 0;  // Variable pour compter le nombre de comparaisons

    // Construction du tas initial
    for (size_t i = longueur / 2; i >= 1; --i) {
        N += tamiser(tab, i, longueur);
    }

    // Extraction successive des éléments du tas
    for (size_t i = longueur; i >= 2; --i) {
        std::swap(tab[0], tab[i - 1]); 
        N += tamiser(tab, 1, i - 1);
    }

    return N;
}


void writeToCSV(const std::string& filename, const std::vector<std::vector<unsigned int>>& comparaisons, const std::vector<size_t>& tailles)
{
    std::ofstream csvFile(filename);
    if (csvFile.is_open())
    {
        // Write header
        csvFile << "N;Aleat Select;PresqueTri Select;PresqueTriDeb Select;PresqueTriFin Select;PresqueTriDebFin Select;Aleat Bulle;PresqueTri Bulle;PresqueTriDeb Bulle;PresqueTriFin Bulle;PresqueTriDebFin Bulle;Aleat BulleOptimise;PresqueTri BulleOptimise;PresqueTriDeb BulleOptimise;PresqueTriFin BulleOptimise;PresqueTriDebFin BulleOptimise;Aleat Peigne;PresqueTri Peigne;PresqueTriDeb Peigne;PresqueTriFin Peigne;PresqueTriDebFin Peigne;Aleat Rapide;PresqueTri Rapide;PresqueTriDeb Rapide;PresqueTriFin Rapide;PresqueTriDebFin Rapide;Aleat ParTas;PresqueTri ParTas;PresqueTriDeb ParTas;PresqueTriFin ParTas;PresqueTriDebFin ParTas\n";

        // Write data
        for (size_t i = 0; i < comparaisons.size(); ++i)
        {
            csvFile << tailles[i] << ";";
            for (size_t j = 1; j < comparaisons[i].size(); ++j)
            {
                csvFile << comparaisons[i][j] << ";";
            }
            csvFile << "\n";
        }

        csvFile.close();
    }
    else
    {
        std::cerr << "Le fichier ne s'ouvre pas.\n";
    }
}


