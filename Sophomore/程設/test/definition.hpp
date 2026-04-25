#include <bits/stdc++.h>
#include <windows.h>
#include <winnt.h>
using namespace std;
#pragma once

#define status int
#define OK 1
#define TRUE 1
#define FALSE 0
#define SIZE 9

//文字節點
typedef struct literalNode
{
    int literal;              
    struct literalNode *next; 
} literalNode, *literalList;

//子句節點
typedef struct clauseNode
{
    literalList head;        
    struct clauseNode *next; 
} clauseNode, *clauseList;

//CNF文件
typedef struct cnfNode
{
    clauseList root; 
    int boolCount;   
    int clauseCount; 
} cnfNode, *CNF;

//函式定義
CNF readCNF(const char* filename);
void destroyCNF(CNF cnf);
void printCNF(CNF cnf);
int is_single_word(literalList L);
int find_single(clauseList L);
int DestroyClause(clauseList &cL);
void Simplify(clauseList &cL, int literal);
clauseList CopyCnf(clauseList cL);
int ChooseLiteral_1(CNF cnf);
int ChooseLiteral_2(CNF cnf);
int ChooseLiteral_3(CNF cnf);
int Satisfy(clauseList cL);
int EmptyClause(clauseList cL);
int DPLL(CNF cnf, bool value[], int flag);
int SaveResult(int result, double time, double time_, bool value[], char fileName[], int boolCount);


