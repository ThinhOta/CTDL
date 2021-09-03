#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#define MAX_INPUT_SIZE 64
#include "main.h"

class SymbolTable
{
public:
    class Symbol
    {
    public:
        string identifier, type;
        int block;
        Symbol* next;
    public:
        Symbol();
        Symbol(string key, int block, string type);
        ~Symbol();
    };

public:
    Symbol* head;
    SymbolTable();
    void processInsertion(string identifier, string type);
    void processAssignment();
    void processBegin();
    void processEnd();
    int processLookUp(string identifier);
    void processPrint();
    void processRprint();
    void scopeEntry();
    void declare();
    void scopeExit();
    bool isEmpty();
    int searchIdentifierInBlock(string identifier, int block);
    void run(string filename);
};
#endif