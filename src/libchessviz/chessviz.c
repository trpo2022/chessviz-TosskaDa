#include <libchessviz/chessviz.h>
#include <stdio.h>
#include <stdlib.h>

void create(char mas[9][9])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 1; j++) {
            mas[i][j] = 56 - i;
        }
    mas[8][0] = 32;
    for (int i = 8; i > 7; i--) {
        for (int j = 1; j < 9; j++)
            mas[i][j] = 96 + j;
    }
    for (int i = 2; i < 6; i++)
        for (int j = 1; j < 9; j++) {
            mas[i][j] = 32;
        }
    for (int i = 1; i < 2; i++)
        for (int j = 1; j < 9; j++) {
            mas[i][j] = 112;
        }
    for (int i = 6; i < 7; i++)
        for (int j = 1; j < 9; j++) {
            mas[i][j] = 80;
        }
    mas[7][1] = 82;
    mas[7][8] = 82;
    mas[7][2] = 78;
    mas[7][7] = 78;
    mas[7][3] = 66;
    mas[7][6] = 66;
    mas[7][4] = 81;
    mas[7][5] = 75;
    mas[0][1] = 114;
    mas[0][8] = 114;
    mas[0][2] = 110;
    mas[0][7] = 110;
    mas[0][3] = 98;
    mas[0][6] = 98;
    mas[0][4] = 113;
    mas[0][5] = 107;
}

void print(char mas[9][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%c ", mas[i][j]);
        printf("\n");
    }
    printf("\n");
}

void BlackMove(int* step_int, char mas[9][9])
{
    if ((step_int[1] == 1) && (step_int[4] == step_int[1] + 2)
        && (mas[step_int[4]][step_int[3]] == ' ')) {
        mas[step_int[4]][step_int[3]]
                = mas[step_int[1]][step_int[0]];
        mas[step_int[1]][step_int[0]] = ' ';
    } else if (
            (mas[step_int[4]][step_int[3]] == ' ')
            && (step_int[4] == step_int[1] + 1)) {
        mas[step_int[4]][step_int[3]]
                = mas[step_int[1]][step_int[0]];
        mas[step_int[1]][step_int[0]] = ' ';
    } else if (
            (mas[step_int[4]][step_int[3]] > 'A')
            && (mas[step_int[4]][step_int[3]] < 'Z')
            && (step_int[4] == step_int[1] + 1)
            && ((step_int[3] == step_int[0] + 1)
                || (step_int[3] == step_int[0] - 1))) {
        mas[step_int[4]][step_int[3]]
                = mas[step_int[1]][step_int[0]];
        mas[step_int[1]][step_int[0]] = ' ';
    }
}
void WhiteMove(int* step_int, char mas[9][9])
{
    if ((step_int[1] == 6) && (step_int[4] == step_int[1] - 2)
        && (mas[step_int[4]][step_int[3]] == ' ')) {
        mas[step_int[4]][step_int[3]]
                = mas[step_int[1]][step_int[0]];
        mas[step_int[1]][step_int[0]] = ' ';
    } else if (
            (mas[step_int[4]][step_int[3]] == ' ')
            && (step_int[4] == step_int[1] - 1)) {
        mas[step_int[4]][step_int[3]]
                = mas[step_int[1]][step_int[0]];
        mas[step_int[1]][step_int[0]] = ' ';
    } else if (
            (mas[step_int[4]][step_int[3]] > 'a')
            && (step_int[4] == step_int[1] - 1)
            && ((step_int[3] == step_int[0] + 1)
                || (step_int[3] == step_int[0] - 1))) {
        mas[step_int[4]][step_int[3]]
                = mas[step_int[1]][step_int[0]];
        mas[step_int[1]][step_int[0]] = ' ';
    }
}
void WhiteTurn(char mas[9][9])
{
    char step[6];
    int flag = 1, step_int[6];
    scanf("%s", step);
    while (flag == 1) {
        flag = 0;
        while ((step[0] < 'a') || (step[0] > 'h') || (step[2] != '-')) {
            printf("This white move is wrong, do another one\n");
            scanf("%s", step);
        }
        step[0] = step[0] - 96;
        step[1] = abs(step[1] - 56);
        step[3] = step[3] - 96;
        step[4] = abs(step[4] - 56);
        step_int[0] = step[0];
        step_int[1] = step[1];
        step_int[3] = step[3];
        step_int[4] = step[4];
        switch (mas[step_int[1]][step_int[0]]) {
        case 'P':
            WhiteMove(step_int, mas);
            if (mas[step_int[1]][step_int[0]] == 'P') {
                flag = 1;
                printf("This white move is wrong, do another one\n");
            }
            break;
        default:
            printf("This white move is wrong, do another one\n");
            flag = 1;
        }
    }
}

void BlackTurn(char mas[9][9])
{
    char step[6];
    int flag = 1, step_int[6];
    printf(" ");
    scanf("%s", step);
    while (flag == 1) {
        flag = 0;
        while ((step[0] < 'a') || (step[0] > 'h') || (step[2] != '-')) {
            printf("This black move is wrong, do another one\n");
            scanf("%s", step);
        }
        step[0] = step[0] - 96;
        step[1] = abs(step[1] - 56);
        step[3] = step[3] - 96;
        step[4] = abs(step[4] - 56);
        step_int[0] = step[0];
        step_int[1] = step[1];
        step_int[3] = step[3];
        step_int[4] = step[4];
        switch (mas[step_int[1]][step_int[0]]) {
        case 'p':
            BlackMove(step_int, mas);
            if (mas[step_int[1]][step_int[0]] == 'p') {
                flag = 1;
                printf("This black move is wrong, do another one\n");
            }
            break;
        default:
            printf("This black move is wrong, do another one\n");
            flag = 1;
        }
    }
}
