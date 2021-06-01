#include <stdio.h>
#include <stdlib.h>

struct Artist {
    char *name;
    int timesPlayed;
};

void displayList(struct Artist *ArtistList) {
    for (int i = 0; i < 5; ++i) {
        printf("%s - %d\n", ArtistList[i].name, ArtistList[i].timesPlayed);
    }
}

int findLeast(struct Artist *ArtistList) {
    int least = ArtistList[0].timesPlayed;
    int leastIndex = 0;
    for (int i = 0; i < 5; ++i) {
        if (least > ArtistList[i].timesPlayed) { 
            least = ArtistList[i].timesPlayed;
            leastIndex = i;
        }
    }
    return leastIndex;
}

void removeElement(struct Artist *ArtistList, int index, int lenght) {
    for(int i = index; i < lenght - 1; i++) 
        ArtistList[i] = ArtistList[i + 1];
    struct Artist *ArtistListTemp = realloc(ArtistList, (lenght-1) * sizeof(struct Artist));
    if (ArtistListTemp == NULL && lenght > 1)
        exit(EXIT_FAILURE);
    lenght = lenght - 1;
    ArtistList = ArtistListTemp;
}

void selectionSort(struct Artist *ArtistList, struct Artist *ArtistsNewList) {
    for (int i = 0; i < 5; ++i) {
        int smallest = findLeast(ArtistList);
        ArtistsNewList[i] = ArtistList[smallest];
        removeElement(ArtistList, smallest, 5);
    }
}

int binarySearch(struct Artist *ArtistsNewList, int requested_num) {
    int min = 0; int max = 5;
    while (min <= max) {
        int mid = max + min;
        int guess = ArtistsNewList[mid].timesPlayed;
        if (guess == requested_num)
            return mid;
        if (guess > requested_num) 
            max = mid - 1;
        else
            min = mid +1;
    }
    return -1;
}


int main(void) {
    struct Artist *ArtistsList = (struct Artist*)malloc(sizeof(struct Artist)*5);  

    for (int i = 0; i < 5; ++i) {
        ArtistsList[i].name=malloc(10);
    }

    ArtistsList[0].name = "Billie";
    ArtistsList[0].timesPlayed = 126;

    ArtistsList[1].name = "Amber";
    ArtistsList[1].timesPlayed = 86;

    ArtistsList[2].name = "DUNNO";
    ArtistsList[2].timesPlayed = 15;

    ArtistsList[3].name = "HAVOC";
    ArtistsList[3].timesPlayed = 326;

    ArtistsList[4].name = "Avocado";
    ArtistsList[4].timesPlayed = 576;

    printf("Before Sort: \n");
    displayList(ArtistsList);
    struct Artist *ArtistsNewList = (struct Artist*)malloc(sizeof(struct Artist)*5);  

    for (int i = 0; i < 5; ++i) {
        ArtistsNewList[i].name=malloc(10);
    }

    printf("\nAfter Sort: \n");
    printf("--------------\n");
    selectionSort(ArtistsList, ArtistsNewList);
    displayList(ArtistsNewList);

    printf("Enter playtime you wanna search: ");
    int playTime = 0;
    scanf("%d", &playTime);
    printf("Index is %d\n", binarySearch(ArtistsNewList, playTime));
    system("pause");
    return 0;
}