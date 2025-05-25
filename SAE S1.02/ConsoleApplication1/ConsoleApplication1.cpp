
#include "fonctions.h"
#include <iostream>
#include <iomanip>

int main()
{
    /*std::vector<int> tab = initTabAleat(150);
    std::cout << triSelection(tab) << "\n";

    verifTri(tab);

    std::vector<int> tab1 = initTabPresqueTri(501);
    std::cout << triSelection(tab1) << "\n";

    verifTri(tab1);
  

    std::vector<int> tab2 = initTabPresqueTriDeb(501);
    std::cout << triSelection(tab2) << "\n";

    verifTri(tab2);

    std::vector<int> tab3 = initTabPresqueTriFin(501);
    std::cout << triSelection(tab3) << "\n";

    verifTri(tab3);

    std::vector<int> tab4 = initTabPresqueTriDebFin(501);
    std::cout << triSelection(tab4) << "\n";

    verifTri(tab4); */

    const std::string csvFilename = "comparaisons.csv";

    // Tableau des tailles
    std::vector<size_t> N = { 99, 200, 250, 300, 350 };  // Ajoutez les tailles nécessaires

    // Vecteur pour stocker les résultats des comparaisons
    std::vector<std::vector<unsigned int>> comparaisons(N.size(), std::vector<unsigned int>(31, 0));

    // Boucle sur chaque taille dans le tableau N
    for (size_t i = 0; i < N.size(); ++i)
    {
        std::vector<int> tab = initTabAleat(N[i]);
        comparaisons[i][1] = triSelection(tab);
        verifTri(tab);

        std::vector<int> tab1 = initTabPresqueTri(N[i]);
        comparaisons[i][2] = triSelection(tab1);
        verifTri(tab1);

        std::vector<int> tab2 = initTabPresqueTriDeb(N[i]);
        comparaisons[i][3] = triSelection(tab2);
        verifTri(tab2);

        std::vector<int> tab3 = initTabPresqueTriFin(N[i]);
        comparaisons[i][4] = triSelection(tab3);
        verifTri(tab3);

        std::vector<int> tab4 = initTabPresqueTriDebFin(N[i]);
        comparaisons[i][5] = triSelection(tab4);
        verifTri(tab4);




        std::vector<int> tab5 = initTabAleat(N[i]);
        comparaisons[i][6] = triBulles(tab5);
        verifTri(tab5);

        std::vector<int> tab6 = initTabPresqueTri(N[i]);
        comparaisons[i][7] = triBulles(tab6);
        verifTri(tab6);

        std::vector<int> tab7 = initTabPresqueTriDeb(N[i]);
        comparaisons[i][8] = triBulles(tab7);
        verifTri(tab7);

        std::vector<int> tab8 = initTabPresqueTriFin(N[i]);
        comparaisons[i][9] = triBulles(tab8);
        verifTri(tab8);

        std::vector<int> tab9 = initTabPresqueTriDebFin(N[i]);
        comparaisons[i][10] = triBulles(tab9);
        verifTri(tab9);




        std::vector<int> tab10 = initTabAleat(N[i]);
        comparaisons[i][11] = triBullesOptimise(tab10);
        verifTri(tab10);

        std::vector<int> tab11 = initTabPresqueTri(N[i]);
        comparaisons[i][12] = triBullesOptimise(tab11);
        verifTri(tab11);

        std::vector<int> tab12 = initTabPresqueTriDeb(N[i]);
        comparaisons[i][13] = triBullesOptimise(tab12);
        verifTri(tab12);

        std::vector<int> tab13 = initTabPresqueTriFin(N[i]);
        comparaisons[i][14] = triBullesOptimise(tab13);
        verifTri(tab13);

        std::vector<int> tab14 = initTabPresqueTriDebFin(N[i]);
        comparaisons[i][15] = triBullesOptimise(tab14);
        verifTri(tab14);




        std::vector<int> tab15 = initTabAleat(N[i]);
        comparaisons[i][16] = triPeigne(tab15);
        verifTri(tab15);

        std::vector<int> tab16 = initTabPresqueTri(N[i]);
        comparaisons[i][17] = triPeigne(tab16);
        verifTri(tab16);

        std::vector<int> tab17 = initTabPresqueTriDeb(N[i]);
        comparaisons[i][18] = triPeigne(tab17);
        verifTri(tab17);

        std::vector<int> tab18 = initTabPresqueTriFin(N[i]);
        comparaisons[i][19] = triPeigne(tab18);
        verifTri(tab18);

        std::vector<int> tab19 = initTabPresqueTriDebFin(N[i]);
        comparaisons[i][20] = triPeigne(tab19);
        verifTri(tab19);




        std::vector<int> tab20 = initTabAleat(N[i]);
        comparaisons[i][21] = triRapideShort(tab20);
        verifTri(tab20);

        std::vector<int> tab21 = initTabPresqueTri(N[i]);
        comparaisons[i][22] = triRapideShort(tab21);
        verifTri(tab21);

        std::vector<int> tab22 = initTabPresqueTriDeb(N[i]);
        comparaisons[i][23] = triRapideShort(tab22);
        verifTri(tab22);

        std::vector<int> tab23 = initTabPresqueTriFin(N[i]);
        comparaisons[i][24] = triRapideShort(tab23);
        verifTri(tab23);

        std::vector<int> tab24 = initTabPresqueTriDebFin(N[i]);
        comparaisons[i][25] = triRapideShort(tab24);
        verifTri(tab24);




        std::vector<int> tab25 = initTabAleat(N[i]);
        comparaisons[i][26] = triParTas(tab25);
        verifTri(tab25);

        std::vector<int> tab26 = initTabAleat(N[i]);
        comparaisons[i][27] = triParTas(tab26);
        verifTri(tab26);

        std::vector<int> tab27 = initTabAleat(N[i]);
        comparaisons[i][28] = triParTas(tab27);
        verifTri(tab27);

        std::vector<int> tab28 = initTabAleat(N[i]);
        comparaisons[i][29] = triParTas(tab28);
        verifTri(tab28);

        std::vector<int> tab29 = initTabAleat(N[i]);
        comparaisons[i][30] = triParTas(tab29);
        verifTri(tab29);

        
    }

    // Écriture des résultats dans le fichier CSV
    writeToCSV(csvFilename, comparaisons, N);

    std::cout << "Le resultat des comparaisons est ecrit dans le fichier : " << csvFilename << std::endl;

    return 0;
}

