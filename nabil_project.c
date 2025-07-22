#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>   // getch() 


#define MAX_NAME 50
#define MAX_ROLE 20
#define MAX_PLAYERS 100

typedef struct {
    char name[MAX_NAME];
    char role[MAX_ROLE];
    int matches;
    int runs;
    int wickets;
} Player;

Player players[MAX_PLAYERS];
int playerCount = 0;

void gotoxy(int x,int y)
{ 
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
   
}

void setcolor (int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;


    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


void loadingScreen () {
    system("cls");



    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPLEASE WAIT OUR SYSTEM IS LOADING . . .\n\n");
    printf("\t\t\t");
    for(int loading=0; loading<70; loading++)
    {

        Sleep(40);
        setcolor(6);
        printf("%c",219);


    }
    system("cls");
}


void end () {
    system("cls");



    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  PLEASE WAIT . . .\n\n");
    printf("\t\t\t");
    for(int loading=0; loading<70; loading++)
    {

        Sleep(30);
        printf("%c",219);


    }
    system("cls");

    gotoxy(35,10);
    printf("%c",201);
    gotoxy(36,10);
    for(int i=1; i<50; i++)
        printf("%c",205);
    gotoxy(85,10);
    printf("%c",187);

    gotoxy(35,11);
    printf("%c",186);
    gotoxy(35,12);
    printf("%c",186);
    gotoxy(35,13);
    printf("%c",186);

    gotoxy(85,11);
    printf("%c",186);
    gotoxy(85,12);
    printf("%c",186);
    gotoxy(85,13);
    printf("%c",186);

    gotoxy(35,14);
    printf("%c",200);
    gotoxy(36,14);
    for(int i=1; i<50; i++)
        printf("%c",205);
    gotoxy(85,14);
    printf("%c",188);



    gotoxy(40,12);
    printf("THANK YOU FOR USING OUR MANAGEMENT SYSTEM");
    setcolor(6);

    gotoxy(0,0);
    getch();

}

void saveToFile() {
    FILE *fp = fopen("players.txt", "w");
    for(int i=0; i<playerCount; i++) {
        fprintf(fp, "%s,%s,%d,%d,%d\n",
            players[i].name, players[i].role, players[i].matches, players[i].runs, players[i].wickets);
    }
    fclose(fp);
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);
    printf("%c", 201);
    gotoxy(99,5);
    printf("%c", 187);
    gotoxy(39,6);
    printf("%c", 186);
    gotoxy(39,7);
    printf("%c", 186);
    gotoxy(39,8);
    printf("%c", 186);
    gotoxy(39,9);
    printf("%c", 186);
    gotoxy(39,10);
    printf("%c", 186);
    gotoxy(39,11);
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11);
    printf("%c", 188);
    gotoxy(99,6);
    printf("%c", 186);
    gotoxy(99,7);
    printf("%c", 186);
    gotoxy(99,8);
    printf("%c", 186);
    gotoxy(99,9);
    printf("%c", 186);
    gotoxy(99,10);
    printf("%c", 186);
    gotoxy(60,8);
    setcolor(10);
    printf("Data saved to file.\n");
    setcolor(7);
}

void loadFromFile() {
    FILE *fp = fopen("players.txt", "r");
    playerCount = 0;
    if(fp) {
        while(fscanf(fp, " %[^,],%[^,],%d,%d,%d\n",
            players[playerCount].name,
            players[playerCount].role,
            &players[playerCount].matches,
            &players[playerCount].runs,
            &players[playerCount].wickets) == 5) {
            playerCount++;
        }
        fclose(fp);
    }
}

void addPlayer() {
    system("cls");
    fflush(stdin);
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);
    printf("%c", 201);
    gotoxy(99,5);
    printf("%c", 187);
    gotoxy(39,6);
    printf("%c", 186);
    gotoxy(39,7);
    printf("%c", 186);
    gotoxy(39,8);
    printf("%c", 186);
    gotoxy(39,9);
    printf("%c", 186);
    gotoxy(39,10);
    printf("%c", 186);
    gotoxy(39,11);
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11);
    printf("%c", 188);
    gotoxy(99,6);
    printf("%c", 186);
    gotoxy(99,7);
    printf("%c", 186);
    gotoxy(99,8);
    printf("%c", 186);
    gotoxy(99,9);
    printf("%c", 186);
    gotoxy(99,10);
    printf("%c", 186);
    if(playerCount >= MAX_PLAYERS) {
        setcolor(12);
        gotoxy(60,8);
        printf("Player list full!\n");
        system("cls");
        fflush(stdin);
        setcolor(7);
        return;
    }
    char tempName[MAX_NAME];
    gotoxy(60,8);
    setcolor(7);
    printf("Enter name: ");
    scanf(" %[^\n]", tempName);
    system("cls");
    fflush(stdin);
    // Duplicate check
    for(int i=0; i<playerCount; i++) {
        if(strcmp(players[i].name, tempName) == 0) {
            gotoxy(60,8);
            setcolor(12);
            printf("Player already exists!\n");
            system("cls");
            setcolor(7);

            return;
        }
    }
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);
    printf("%c", 201);
    gotoxy(99,5);
    printf("%c", 187);
    gotoxy(39,6);
    printf("%c", 186);
    gotoxy(39,7);
    printf("%c", 186);
    gotoxy(39,8);
    printf("%c", 186);
    gotoxy(39,9);
    printf("%c", 186);
    gotoxy(39,10);
    printf("%c", 186);
    gotoxy(39,11);
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11);
    printf("%c", 188);
    gotoxy(99,6);
    printf("%c", 186);
    gotoxy(99,7);
    printf("%c", 186);
    gotoxy(99,8);
    printf("%c", 186);
    gotoxy(99,9);
    printf("%c", 186);
    gotoxy(99,10);
    printf("%c", 186);
    strcpy(players[playerCount].name, tempName);
    setcolor(7);
    gotoxy(45,8);
    printf("Enter role (Batsman/Bowler/All-rounder): ");
    scanf(" %[^\n]", players[playerCount].role);
    system("cls");
    fflush(stdin);
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);
    printf("%c", 201);
    gotoxy(99,5);
    printf("%c", 187);
    gotoxy(39,6);
    printf("%c", 186);
    gotoxy(39,7);
    printf("%c", 186);
    gotoxy(39,8);
    printf("%c", 186);
    gotoxy(39,9);
    printf("%c", 186);
    gotoxy(39,10);
    printf("%c", 186);
    gotoxy(39,11);
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11);
    printf("%c", 188);
    gotoxy(99,6);
    printf("%c", 186);
    gotoxy(99,7);
    printf("%c", 186);
    gotoxy(99,8);
    printf("%c", 186);
    gotoxy(99,9);
    printf("%c", 186);
    gotoxy(99,10);
    printf("%c", 186);
    gotoxy(60,8);
    setcolor(7);
    printf("Matches played: ");
    scanf("%d", &players[playerCount].matches);
    system("cls");
    fflush(stdin);
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);
    printf("%c", 201);
    gotoxy(99,5);
    printf("%c", 187);
    gotoxy(39,6);
    printf("%c", 186);
    gotoxy(39,7);
    printf("%c", 186);
    gotoxy(39,8);
    printf("%c", 186);
    gotoxy(39,9);
    printf("%c", 186);
    gotoxy(39,10);
    printf("%c", 186);
    gotoxy(39,11);
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11);
    printf("%c", 188);
    gotoxy(99,6);
    printf("%c", 186);
    gotoxy(99,7);
    printf("%c", 186);
    gotoxy(99,8);
    printf("%c", 186);
    gotoxy(99,9);
    printf("%c", 186);
    gotoxy(99,10);
    printf("%c", 186);
    setcolor(7);
    gotoxy(60,8);
    printf("Runs scored: ");
    scanf("%d", &players[playerCount].runs);
    system("cls");
    fflush(stdin);
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);
    printf("%c", 201);
    gotoxy(99,5);
    printf("%c", 187);
    gotoxy(39,6);
    printf("%c", 186);
    gotoxy(39,7);
    printf("%c", 186);
    gotoxy(39,8);
    printf("%c", 186);
    gotoxy(39,9);
    printf("%c", 186);
    gotoxy(39,10);
    printf("%c", 186);
    gotoxy(39,11);
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11);
    printf("%c", 188);
    gotoxy(99,6);
    printf("%c", 186);
    gotoxy(99,7);
    printf("%c", 186);
    gotoxy(99,8);
    printf("%c", 186);
    gotoxy(99,9);
    printf("%c", 186);
    gotoxy(99,10);
    printf("%c", 186);
    setcolor(7);
    gotoxy(60,8);
    printf("Wickets taken: ");
    scanf("%d", &players[playerCount].wickets);
    system("cls");
    fflush(stdin);
    playerCount++;
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);
    printf("%c", 201);
    gotoxy(99,5);
    printf("%c", 187);
    gotoxy(39,6);
    printf("%c", 186);
    gotoxy(39,7);
    printf("%c", 186);
    gotoxy(39,8);
    printf("%c", 186);
    gotoxy(39,9);
    printf("%c", 186);
    gotoxy(39,10);
    printf("%c", 186);
    gotoxy(39,11);
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11);
    printf("%c", 188);
    gotoxy(99,6);
    printf("%c", 186);
    gotoxy(99,7);
    printf("%c", 186);
    gotoxy(99,8);
    printf("%c", 186);
    gotoxy(99,9);
    printf("%c", 186);
    gotoxy(99,10);
    printf("%c", 186);
    gotoxy(60,8);
    setcolor(10);
    printf("Player added successfully!\n");
    system("cls");
    fflush(stdin);
    setcolor(7);
    saveToFile();

}


void searchPlayer() {
    loadFromFile();  // Load player data from file
    char searchName[MAX_NAME];
    system("cls");

    // Input Box Frame
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);  
    printf("%c", 201);
    gotoxy(99,5);  
    printf("%c", 187);
    for (int i = 6; i <= 8; i++) {
        gotoxy(39,i); 
        printf("%c", 186);
        gotoxy(99,i); 
        printf("%c", 186);
    }
    gotoxy(39,9); 
    printf("%c", 200);
    gotoxy(40,9);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,9); 
    printf("%c", 188);

    // Input prompt
    setcolor(7);
    gotoxy(55,7);
    printf("Enter player name to search: ");
    scanf(" %[^\n]", searchName);

    system("cls");

    // Result Box Frame
    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);  
    printf("%c", 201);
    gotoxy(99,5);  
    printf("%c", 187);
    for (int i = 6; i <= 10; i++) {
        gotoxy(39,i); 
        printf("%c", 186);
        gotoxy(99,i); 
        printf("%c", 186);
    }
    gotoxy(39,11); 
    printf("%c", 200);
    gotoxy(40,11);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,11); 
    printf("%c", 188);

    // Search result
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, searchName) == 0) {
            setcolor(10);
            gotoxy(45,7);
            printf("Player Found!");
            setcolor(7);
            gotoxy(45,8);
            printf("Name   : %s", players[i].name);
            gotoxy(45,9);
            printf("Role   : %s", players[i].role);
            gotoxy(45,10);
            printf("Matches: %d, Runs: %d, Wickets: %d",
                   players[i].matches, players[i].runs, players[i].wickets);
            gotoxy(45,12);
            printf("Press any key to return...");
            getch();
            return;
        }
    }

    // If not found
    setcolor(12);
    gotoxy(50,8); 
    printf("Player not found!");
    setcolor(7);
    gotoxy(50,10); 
    printf("Press any key to return...");
    getch();
}



void displayPlayers() {
    loadFromFile(); // Load from file before display
    system("cls");

    if (playerCount == 0) {
        setcolor(12);
        gotoxy(50,10);
        printf("No players to display!");
        setcolor(7);
        gotoxy(50,12);
        printf("Press any key to return...");
        getch();
        return;
    }

    setcolor(6);
    gotoxy(40,3);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,3);  
    printf("%c", 201);
    gotoxy(99,3);  
    printf("%c", 187);
    gotoxy(39,4);  
    printf("%c", 186);
    gotoxy(99,4);  
    printf("%c", 186);
    gotoxy(39,5);  
    printf("%c", 200);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,5);  
    printf("%c", 188);

    setcolor(11);
    gotoxy(50,4);
    printf("All Player Records");

    // Table headers
    setcolor(14);
    gotoxy(10,7);
    printf("%-3s %-20s %-15s %-10s %-10s %-10s", "No", "Name", "Role", "Matches", "Runs", "Wickets");
    setcolor(7);

    // Print players
    for (int i = 0; i < playerCount; i++) {
        gotoxy(10,8 + i);
        printf("%-3d %-20s %-15s %-10d %-10d %-10d",
               i + 1,
               players[i].name,
               players[i].role,
               players[i].matches,
               players[i].runs,
               players[i].wickets);
    }

    gotoxy(50, playerCount + 10);
    printf("Press any key to return...");
    getch();
}



void updatePlayer() {
    loadFromFile();
    char updateName[MAX_NAME];
    system("cls");

    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5);  
    printf("%c", 201);
    gotoxy(99,5);  
    printf("%c", 187);
    for (int i = 6; i <= 8; i++) {
        gotoxy(39,i); 
        printf("%c", 186);
        gotoxy(99,i); 
        printf("%c", 186);
    }
    gotoxy(39,9); 
    printf("%c", 200);
    gotoxy(40,9);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,9); 
    printf("%c", 188);

    setcolor(7);
    gotoxy(55,7);
    printf("Enter player name to update: ");
    scanf(" %[^\n]", updateName);

    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, updateName) == 0) {
            system("cls");
            setcolor(6);
            gotoxy(40,5);
            for (int i=1; i<60; i++) 
            printf("%c", 205);
            gotoxy(39,5);  
            printf("%c", 201);
            gotoxy(99,5);  
            printf("%c", 187);
            for (int i = 6; i <= 12; i++) {
                gotoxy(39,i); 
                printf("%c", 186);
                gotoxy(99,i); 
                printf("%c", 186);
            }
            gotoxy(39,13); 
            printf("%c", 200);
            gotoxy(40,13);
            for (int i=1; i<60; i++) 
            printf("%c", 205);
            gotoxy(99,13); printf("%c", 188);

            gotoxy(50,6); setcolor(7); 
            printf("Enter new name: ");
            scanf(" %[^\n]", players[i].name);
            gotoxy(50,7); 
            printf("Enter new role: ");
            scanf(" %[^\n]", players[i].role);
            gotoxy(50,8); 
            printf("Enter new matches: ");
            scanf("%d", &players[i].matches);
            gotoxy(50,9); 
            printf("Enter new runs: ");
            scanf("%d", &players[i].runs);
            gotoxy(50,10); 
            printf("Enter new wickets: ");
            scanf("%d", &players[i].wickets);

            saveToFile();
            system("cls");
            setcolor(10);
            gotoxy(55,11); 
            printf("Updated successfully!");
            setcolor(7);
            gotoxy(50,12); 
            printf("Press any key to return...");
            getch();
            return;
        }
    }

    setcolor(12);
    gotoxy(60,8); 
    printf("Player not found!");
    setcolor(7);
    gotoxy(60,9); 
    printf("Press any key to return...");
    getch();
}


void deletePlayer() {
    loadFromFile();
    char delName[MAX_NAME];
    system("cls");

    setcolor(6);
    gotoxy(40,5);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(39,5); 
    printf("%c", 201);
    gotoxy(99,5); 
    printf("%c", 187);
    for (int i=6; i<=8; i++) {
        gotoxy(39,i); 
        printf("%c", 186);
        gotoxy(99,i); 
        printf("%c", 186);
    }
    gotoxy(39,9); 
    printf("%c", 200);
    gotoxy(40,9);
    for (int i=1; i<60; i++) 
    printf("%c", 205);
    gotoxy(99,9); 
    printf("%c", 188);

    setcolor(7);
    gotoxy(55,7);
    printf("Enter player name to delete: ");
    scanf(" %[^\n]", delName);

    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, delName) == 0) {
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            saveToFile();
            setcolor(10);
            system("cls");
    setcolor(10);
    gotoxy(45,8); 
    printf("Player deleted successfully!");
            setcolor(7);
            gotoxy(60,9); 
            printf("Press any key to return...");
            getch();
            return;
        }
    }

    setcolor(12);
    gotoxy(60,8); 
    printf("Player not found!");
    setcolor(7);
    gotoxy(60,9); 
    printf("Press any key to return...");
    getch();
}


void sortPlayersByRuns() {
    loadFromFile();
    Player temp;

    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = 0; j < playerCount - i - 1; j++) {
            if (players[j].runs < players[j + 1].runs) {
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    system("cls");
    setcolor(11);
    gotoxy(45,4);
    printf("Players Sorted by Runs (Descending)");
    setcolor(7);
    gotoxy(20,6);
    printf("%-3s %-20s %-15s %-8s %-8s %-8s", "No", "Name", "Role", "Matches", "Runs", "Wickets");

    for (int i = 0; i < playerCount; i++) {
        gotoxy(20,7+i);
        printf("%-3d %-20s %-15s %-8d %-8d %-8d",
               i + 1,
               players[i].name,
               players[i].role,
               players[i].matches,
               players[i].runs,
               players[i].wickets);
    }

    gotoxy(50, playerCount + 9);
    printf("Press any key to return...");
    getch();
}


void showStatistics() {
    loadFromFile();
    system("cls");

    if (playerCount == 0) {
        setcolor(12);
        gotoxy(55,10);
        printf("No players available!");
        setcolor(7);
        getch();
        return;
    }

    int totalRuns = 0, totalWickets = 0, maxRuns = 0, maxWickets = 0;
    char maxRunPlayer[MAX_NAME], maxWicketPlayer[MAX_NAME];

    for (int i = 0; i < playerCount; i++) {
        totalRuns += players[i].runs;
        totalWickets += players[i].wickets;

        if (players[i].runs > maxRuns) {
            maxRuns = players[i].runs;
            strcpy(maxRunPlayer, players[i].name);
        }

        if (players[i].wickets > maxWickets) {
            maxWickets = players[i].wickets;
            strcpy(maxWicketPlayer, players[i].name);
        }
    }

    setcolor(11);
    gotoxy(50,5); 
    printf("----- Player Statistics -----");
    setcolor(7);
    gotoxy(50,7); 
    printf("Total Players      : %d", playerCount);
    gotoxy(50,8); 
    printf("Average Runs       : %.2f", (float)totalRuns / playerCount);
    gotoxy(50,9); 
    printf("Average Wickets    : %.2f", (float)totalWickets / playerCount);
    gotoxy(50,10); 
    printf("Top Run Scorer     : %s (%d)", maxRunPlayer, maxRuns);
    gotoxy(50,11); 
    printf("Top Wicket Taker   : %s (%d)", maxWicketPlayer, maxWickets);

    gotoxy(50,13); 
    printf("Press any key to return...");
    getch();
}


void filterPlayersByRuns() {
    loadFromFile();
    int minRuns;
    system("cls");

    gotoxy(50,6);
    printf("Show players with minimum runs: ");
    scanf("%d", &minRuns);

    system("cls");
    setcolor(11);
    gotoxy(20,4);
    printf("%-3s %-20s %-15s %-8s %-8s %-8s", "No", "Name", "Role", "Matches", "Runs", "Wickets");
    setcolor(7);

    int found = 0;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].runs >= minRuns) {
            gotoxy(20,6 + found);
            printf("%-3d %-20s %-15s %-8d %-8d %-8d",
                   i + 1, players[i].name, players[i].role,
                   players[i].matches, players[i].runs, players[i].wickets);
            found++;
        }
    }

    if (found == 0) {
        setcolor(12);
        gotoxy(50,8); 
        printf("No players found with runs >= %d", minRuns);
        setcolor(7);
    }

    gotoxy(50, found + 8);
    printf("Press any key to return...");
    getch();
}


int main () {
    char option;
    int op;
    int i;
    loadingScreen();
    
  do {
    system("cls");
    fflush(stdin);
    setcolor(6);
        gotoxy(11,4);
        printf("%c", 201);
        gotoxy(12,4);
        for(i=1; i<100; i++)
            printf("%c",205);
        gotoxy(111,4);
        printf("%c",187);
        gotoxy(12,6);
        for(i=1; i<100; i++)
        printf("%c",205);
        gotoxy(11,5);
        printf("%c",186);
        gotoxy(11,6);
        printf("%c",204);
        gotoxy(11,7);
        printf("%c",186);
        gotoxy(11,8);
        printf("%c",186);
        gotoxy(11,9);
        printf("%c",186);
        gotoxy(11,10);
        printf("%c",186);
        gotoxy(11,11);
        printf("%c",186);
        gotoxy(11,12);
        printf("%c",200);
        gotoxy(12,12);
        for(i=1; i<100; i++)
            printf("%c",205);
        gotoxy(111,5);
        printf("%c",186);  
        gotoxy(111,6);
        printf("%c",185);
        gotoxy(111,7);
        printf("%c",186);
        gotoxy(111,8);
        printf("%c",186);
        gotoxy(111,9);
        printf("%c",186); 
        gotoxy(111,10);
        printf("%c",186);
        gotoxy(111,11);
        printf("%c",186); 
        gotoxy(111,12);
        printf("%c",188);

        gotoxy(40,5);
        setcolor(4);
        printf("Cricket Players Performance Record System");
       
        setcolor(1);
        gotoxy(30,7);
        printf("1. Add Player");
        gotoxy(30,8);
        printf("2. Display All Players");
        gotoxy(30,9);
        printf("3. Search Player");
        gotoxy(30,10);
        printf("4. Update Player");
        gotoxy(70,7);
        printf("5. Delete Player");
        gotoxy(70,8);
        printf("6. Sort Players by Runs");
        gotoxy(70,9);
        printf("7. Show Statistics");
        gotoxy(70,10);
        printf("8. Filter Players by Runs");
        gotoxy(50,11);
        printf("9. Save & Exit");

        printf("\n\n\n");
        setcolor(7);
        printf("\t\t\tEnter Your Choice: ");
        scanf("%d", &op);
        printf("\n\n\n");
        system("cls");
        
    
    switch (op)
    {
    case 1:
        addPlayer();
        break;

    case 2:
        displayPlayers();
       break;

    case 3:
        searchPlayer();
        break;

    case 4:
        updatePlayer();
        break;

    case 5:
        deletePlayer();
        break;

    case 6:
        sortPlayersByRuns();
        break;

    case 7:
        showStatistics();
        break;

    case 8:
        filterPlayersByRuns();
        break;  

    case 9:
    saveToFile();
    break;
    
    default:
     system("cls");

    // Error Box Frame
    setcolor(6);
    gotoxy(40,5);
    for (int i = 1; i < 60; i++) 
    printf("%c", 205);
    gotoxy(39,5);  
    printf("%c", 201);
    gotoxy(99,5);  
    printf("%c", 187);
    for (int i = 6; i <= 8; i++) {
        gotoxy(39, i); 
        printf("%c", 186);
        gotoxy(99, i); 
        printf("%c", 186);
    }
    gotoxy(39,9);  
    printf("%c", 200);
    gotoxy(40,9);
    for (int i = 1; i < 60; i++) 
    printf("%c", 205);
    gotoxy(99,9);  
    printf("%c", 188);

    // Error Message
    setcolor(12);  // Red
    gotoxy(55,7);
    printf("Invalid choice! Try again.");
    setcolor(7);
    gotoxy(55,8);
    printf("Press any key to return...");
    getch();
    break;
    }

    } while(op != 9);
    
    end();

    return 0;
}