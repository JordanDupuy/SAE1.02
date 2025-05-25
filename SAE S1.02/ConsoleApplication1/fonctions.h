/**
 * \file fonctions.h
 *
 * Déclaration des fonctions fournies.
 */
#pragma once
#include <vector>
#include <string>

//!\brief Crée un tableau aléatoire
std::vector<int> initTabAleat(size_t N);

//!\brief Crée un tableau presque trié
std::vector<int> initTabPresqueTri(size_t N);

//!\brief Crée un tableau presque trié au début
std::vector<int> initTabPresqueTriDeb(size_t N);

//!\brief Crée un tableau presque trié à la fin
std::vector<int> initTabPresqueTriFin(size_t N);

//!\brief Crée un tableau presque trié entre le début et la fin
std::vector<int> initTabPresqueTriDebFin(size_t N);

//!\brief Vérifie qu'un tableau est correctement trié
void verifTri(const std::vector<int>& tab, const std::string& algoName = {});

unsigned int triSelection(std::vector<int>& tab);

unsigned int triBulles(std::vector<int>& tab);

unsigned int triBullesOptimise(std::vector<int>& tab);

unsigned int triPeigne(std::vector<int>& tab);

unsigned int triRapideShort(std::vector<int>& tab);

unsigned int triRapide(std::vector<int>& tab, int debut, int fin);

unsigned int tamiser(std::vector<int>& tab, size_t noeur, size_t n);

unsigned int triParTas(std::vector<int>& tab);

void writeToCSV(const std::string& filename, const std::vector<std::vector<unsigned int>>& comparaisons, const std::vector<size_t>& tailles);
