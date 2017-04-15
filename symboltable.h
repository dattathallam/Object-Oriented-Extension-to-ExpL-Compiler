#include <string.h>
void yyerror(char const *s);
#define SYMBOL_INTEGER 1
#define SYMBOL_STR 2
#define SYMBOL_ARRAY_INT 3
#define SYMBOL_ARRAY_STR 4

struct Fieldlist 
{
	char *name;				//name of the field
	int fieldIndex;			//the position of the field in the field list
	struct Typetable *type;	//pointer to type table entry of the field's type
	struct Fieldlist *next;	//pointer to the next field
};
struct Fieldlist *Fhead,*Ftail;
struct Fieldlist* FLookup(char* name,struct Fieldlist *list);
void FInstall(struct Typetable *type,char* name);

struct Typetable
{
	char *name;					//type name
	int size;					//size of the type
	struct Fieldlist *fields;	//pointer to the head of fields list
	struct Typetable *next;		// pointer to the next type table entry
};
struct Typetable *Thead,*Ttail;
struct Typetable* TLookup(char* name);
void TInstall(char* name,int size,struct Fieldlist *fields);

struct CVarlist 
{
	char *name;				//name of the class variable
	int ClassVarIndex;			//the position of the variable in the list
	struct Typetable *type; //pointer to the type of the variable in class table
	struct CVarlist *next;	//pointer to the next Class variable field
};
struct CVarlist *CVhead,*CVtail;
struct CVarlist* CVLookup(char* name,struct CVarlist *list);
void CVarInstall(char* name, struct Typetable *type);
int class_var_count = 1;

struct CFunclist 
{
	char *name;				//name of the class field (function name)
	int ClassFuncIndex;			//the position of the field in the class func list
	int label;				//label number of function
	struct Paramstruct *paramlist; //pointer to the head of the formal parameter list in the case of functions
	struct CFunclist *next;	//pointer to the next Class function field
};
struct CFunclist *CFhead,*CFtail;
struct CFunclist* CFLookup(char* name,struct CFunclist *list);
void CFuncInstall(int label,char* name, struct Paramstruct *paramlist);

struct Classtable
{
	char *name;					//class name
	int ClassIndex;				//index of class, starts from 0
	int size;					//size of the class
	struct CFunclist *CFuncs;	//pointer to the head of class functions list
	struct CVarlist *CVars;		//pointer to the head of class variables list	
	int binding;				//address of the start of class memory in stack (to store label numbers)
	struct Classtable *next;		// pointer to the next class table entry
};
struct Classtable *Chead,*Ctail;
struct Classtable* CLookup(char* name);
void CInstall(char* name,struct CFunclist *CFuncs,struct CVarlist *CVars);
void extends(char* name1, char* name2);
void extends_var(char* name1, char* name2);
struct CFunclist* CFparamLookup(struct CFunclist* list, struct Paramstruct* paramlist1, char* name);
void CFuncIndex(struct Classtable *ctable);
int class_count = 0;

struct Paramstruct
{
	int amp;
   char *name;
   struct Typetable* type;
   struct Paramstruct *next;
};
struct Paramstruct *Phead = NULL,*Ptail = NULL;
void PInstall(char* name,struct Typetable* type);
struct Paramstruct* PLookup(char* name);

struct Gsymbol 
{
	char *name; //name of the variable or function
	struct Typetable* type;	//pointer to the Typetable entry of variable type/return type of the function
	struct Classtable* ctype;
	int size; //size of an array or a user defined type. (The default types have size 1)
	int binding; // Address of the Identifier in Memory
	struct Paramstruct *paramlist; //pointer to the head of the formal parameter list in the case of functions
	int flabel;	//a label for identifying the starting address of the function's code in the memory
	struct Gsymbol *next; // Pointer to next Symbol Table Entry */
};
struct Gsymbol * GLookup(char* name); // Look up for a global identifier
void GInstall(char* name,struct Typetable* type,int size,struct Paramstruct * paramlist); // Installation
void CGInstall(char *name,struct Classtable* ctype,int size,struct Paramstruct *paramlist);
struct Gsymbol *Ghead, *Gtail;

int totalCount = 4096;
int fbind = 0;

struct Lsymbol 
{
	/* Here only name, type, binding and pointer to next entry needed */
	char *name; //name of the variable
	struct Typetable* type;	//pointer to the Typetable entry of variable type
	/***The TYPE field must be a TypeStruct if user defined types are allowed***/
	struct Lsymbol *next; //points to the next Local Symbol Table entry
};
struct Lsymbol *Lhead, *Ltail;
struct Lsymbol *LLookup(char* name);
void LInstall(char* name,struct Typetable* type);