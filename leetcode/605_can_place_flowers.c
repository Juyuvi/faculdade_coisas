bool CanPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {

    /*
    ====================
    CanPlaceFlowers
        Exercicio 604 do leetcode. Codigo atual (refeito em casa).
    ====================
    */

    int avaPlots, currPlot, currZeroSequence;
    avaPlots = currZeroSequence = 0;

    for ( int i = -1; i < flowerbedSize + 1; i++ ) {
        if ( i == -1 || i == flowerbedSize ) {
            currPlot = 0;
        } else {
            currPlot = *(flowerbed + i);
        }

        if ( !currPlot ) {
            currZeroSequence++;

            if ( !( currZeroSequence % 2 == 0 ) && ( currZeroSequence > 1 ) ) {
                avaPlots++;
            }
        } else {
            currZeroSequence = 0;
        }
    }

    if ( avaPlots >= n ){
        return true;
    }
    return false;
}