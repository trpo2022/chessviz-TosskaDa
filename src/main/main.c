#include <libchessviz/chessviz.h>

#include <stdio.h>
int main()
{
    char mas[9][9];
    int MoveNum = 1;
    int flag = 1;
    create(mas);
    print(mas);
    while (flag == 1) {
        printf("%d. ", MoveNum);
        WhiteTurn(mas);
        BlackTurn(mas);
        print(mas);
        MoveNum += 1;
    }
    return 0;
}
