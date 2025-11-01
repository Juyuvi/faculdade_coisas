bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
    bool SearchForEven = true;
    int firstSequenceN, middleSequenceN, lastSequenceN;
    firstSequenceN = middleSequenceN = lastSequenceN = 0;
    int currSequence = 1; // 1 = First, 2 = Middle; 3 = Last;
    int currReadZeros = 0;
    int currPlot;
    int avaPlots = 0;
    int tempCount;
    int possibleMiddle = 0;



    for(int i = 0; i < flowerbedSize; i++){
        currPlot = *(flowerbed + i);
        if (flowerbedSize == 1 && currPlot == 0)
            return true;


        if ((currSequence == 1) && (currPlot)){
            currSequence = 3;
        }

        if ((currSequence == 3) && (currPlot)){
            avaPlots += possibleMiddle;
            printf("somados %d para avaPlot\n", possibleMiddle);
            printf("AvaPlot atual == %d\n", avaPlots);
            lastSequenceN = 0;
            possibleMiddle = 0;
            currReadZeros = 0;
        }


        if(currPlot == 0){
            currReadZeros++;
            printf("currPlot == %d\n", currPlot);
            printf("cRZ == %d\n", currReadZeros);
            switch (currSequence){
                case 1:

                    if(currReadZeros % 2 == 0){
                        firstSequenceN++;
                        avaPlots++;
                        printf("+1 Avaplot inicial\n");
                        currReadZeros = 0;
                    }
                    break;

                case 2:
                printf("Isso nao deveria ter rodado!!!");
                    if(currReadZeros % 3 == 0){
                        //middleSequenceN++;
                        //avaPlots++;
                    }
                    break;

                case 3:
                    if(currReadZeros % 2 == 0){
                        printf("isso roda?\n");
                        lastSequenceN++;

                    }

                    else if(currReadZeros > 1){
                        possibleMiddle++;
                    }
                        

                    break;
                }


        }
        

    }


    avaPlots += lastSequenceN;
    printf("avaPlots Recebeu + %d\n", lastSequenceN);

    printf("%d", avaPlots);
    if(avaPlots >= n){
        
        return true;
    }
    return false;
}