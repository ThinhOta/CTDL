#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
    this->head = NULL;
}

SymbolTable::Symbol::Symbol()
{
	next =NULL;
}

SymbolTable::Symbol::Symbol(string key, int block, string type)
{
    this->identifier = key;
    this->block = block;
    this->type = type;
    this->next = NULL;
}

std::vector<std::string> tokenize(const std::string str,
                                    const std::regex re)
{
    std::sregex_token_iterator it{ str.begin(), 
                             str.end(), re, -1 };
    std::vector<std::string> tokenized{ it, {} };
  
    // Additional check to remove empty strings
    tokenized.erase(
        std::remove_if(tokenized.begin(), 
                            tokenized.end(),
                       [](std::string const& s) {
                           return s.size() == 0;
                       }),
        tokenized.end());
  
    return tokenized;
}

int SymbolTable::processLookUp(string identifier)
{
    if(this->isEmpty())
        throw std::out_of_range ("Undeclared");
    else{
        Symbol* curSymbol = head;
        while (curSymbol != NULL)
        {
            if(curSymbol->identifier == identifier)
                return curSymbol->block;
            curSymbol = curSymbol->next;
        }
        throw std::out_of_range ("Undeclared");
    } 
}

void SymbolTable::processInsertion(string identifier, string type)
{
    if(this->isEmpty())
    {
        Symbol* newSymbol = new Symbol(identifier, 0, type);
        this->head = newSymbol;
    }
    else
    {
        if(this->searchIdentifierInBlock(identifier, head->block) != -1 )
            throw std::out_of_range("Redeclared");
        Symbol* newSymbol = new Symbol(identifier, head->block, type);
        newSymbol->next = this->head;
        this->head = newSymbol;
    }
}

bool SymbolTable::isEmpty()
{
    if (this->head == NULL)
        return true;
    return false;
}

int SymbolTable::searchIdentifierInBlock(string identifier, int block)
{
    if(this->isEmpty())
        return -1;
    else{
        Symbol* curSymbol = head;
        while (curSymbol != NULL)
        {
            if(curSymbol->identifier == identifier)
                return curSymbol->block;
            curSymbol = curSymbol->next;
        }
        return -1;
    } 
}

void SymbolTable::scopeEntry()
{

}

void SymbolTable::run(string filename)
{
    ifstream infile(filename);
    char** tokens;
    if (infile.fail())
	{
		throw std::out_of_range("Failed to open this file!");
	}
	while (!infile.eof())
	{
		string line;
		getline(infile, line);
		const std::regex re(R"([\s|,]+)");
		
		const std::vector<std::string> tokenized = 
							tokenize(line, re);
		
		if (tokenized[0] == "INSERT")
        {
            this->processInsertion(tokenized[1], tokenized[2]);
            std::cout << "success" << endl;
        }
        else if (tokenized[0] == "ASSIGN")
        {

        }
        else if (tokenized[0] == "BEGIN")
        {

        }
        else if (tokenized[0] == "END")
        {

        } 
        else if (tokenized[0] == "LOOKUP")
        {
            std::cout << this->processLookUp(tokenized[1]) << endl;

        } 
        else if (tokenized[0] == "PRINT")
        {
            
        } 
        else if (tokenized[0] == "RPRINT")
        {
            
        } 
        else
            throw std::out_of_range("");
	}
    infile.close();
}
