#pragma once


//É¨À×
#define ROW 11
#define COL 11
#define a 9
#define b 9
int menu();
void init_g(char g[ROW][COL], int r, int c);
void init_g(char g[a][b], int r, int c);
void p_g(char g[a][b], int r, int c);
void p_g(char g[ROW][COL], int r, int c);
void SetMine(char g[ROW][COL], int r, int  c);
#define count 10
void FindMine(char showing[a][b], char hidden[ROW][COL], int r, int c);
