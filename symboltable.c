struct Gsymbol *GLookup(char * name)
{
    struct Gsymbol *temp;

    temp  = Ghead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
    	temp = temp -> next;
    }
	return temp;
}

void GInstall(char *name,struct Typetable* type,int size,struct Paramstruct *paramlist)
{
	struct Gsymbol *temp;

    temp = GLookup(name);
    if(temp != NULL)
    {
    	yyerror("Variable re-initialized");
    	printf("\"%s\"\n",name);
    	exit(1);
    }

    temp = (struct Gsymbol *) malloc(sizeof(struct Gsymbol));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> type = type;
    temp -> size = size;
    temp -> paramlist = paramlist;
    temp -> next = NULL;

    if(temp -> size == -1)
    {
        temp -> binding = fbind;
        fbind++;
    }
    else
    {
        temp -> binding = totalCount;
        totalCount = totalCount + temp -> size;        
    }

    if(Ghead != NULL)
    {
    	Gtail -> next = temp;
        Gtail = temp; 
    }
    else
    {
    	Ghead = temp;
    	Gtail = temp;
    }
    return;
}

struct Lsymbol *LLookup(char *name)
{
    struct Lsymbol *temp;
    temp  = Lhead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
    	temp = temp -> next;
    }
	return temp;
}

void LInstall(char *name,struct Typetable* type)
{
	struct Lsymbol *temp;
    temp = (struct Lsymbol *) malloc(sizeof(struct Lsymbol));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> type = type;
    temp -> next = NULL;

    if(Lhead != NULL)
    {
    	Ltail -> next = temp;
        Ltail = temp; 
    }
    else
    {
    	Lhead = temp;
    	Ltail = temp;
    }
    return;
}

struct Paramstruct* PLookup(char* name)
{
   struct Paramstruct *temp;
    temp  = Phead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}

void PInstall(char* name,struct Typetable* type)
{
    struct Paramstruct *temp;
    temp = (struct Paramstruct *) malloc(sizeof(struct Paramstruct));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> type = type;
    temp -> next = NULL;

    if(Phead == NULL)
    {
        Phead = temp;
        Ptail = temp;
    }
    else
    {
        Ptail -> next = temp;
        Ptail = Ptail -> next;
    }
    return;
}

struct Typetable* TLookup(char* name)
{
   struct Typetable *temp;

    temp  = Thead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}

void TInstall(char* name,int size,struct Fieldlist *fields)
{
    struct Typetable *temp;
    struct Fieldlist *ftemp;
    int counter=0;

    temp = (struct Typetable *) malloc(sizeof(struct Typetable));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> next = NULL;

    if(Thead == NULL)
    {
        Thead = temp;
        Ttail = temp;
    }
    else
    {
        Ttail -> next = temp;
        Ttail = Ttail -> next;
    }

    ftemp = fields;

    while(ftemp != NULL)
    {
    	if(ftemp -> type == TLookup("dummy"))
    	{
    		ftemp -> type = TLookup(name);
    	}

    	ftemp -> fieldIndex = counter++;
    	ftemp = ftemp -> next;

    }
    temp -> fields = fields;
    temp -> size = counter;
    Fhead = NULL;
    Ftail = NULL;
    return;
}


struct Fieldlist* FLookup(char* name,struct Fieldlist *list)
{
    struct Fieldlist *temp;
    temp  = list;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}



void FInstall(struct Typetable *type,char* name)
{
    struct Fieldlist *temp;
    struct Typetable *temp1;
    temp = (struct Fieldlist *) malloc(sizeof(struct Fieldlist));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> type = type;
    temp -> next = NULL;

    if(Fhead == NULL)
    {
        Fhead = temp;
        Ftail = temp;
    }
    else
    {
        Ftail -> next = temp;
        Ftail = Ftail -> next;
    }
    return;
}

struct Classtable* CLookup(char* name)
{
   struct Classtable *temp;

    temp  = Chead;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}

void CInstall(char* name,struct CFunclist *CFuncs,struct CVarlist *CVars)
{
    struct Classtable *temp;

    temp = (struct Classtable *) malloc(sizeof(struct Classtable));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> next = NULL;

    if(Chead == NULL)
    {
        Chead = temp;
        Ctail = temp;
    }
    else
    {
        Ctail -> next = temp;
        Ctail = Ctail -> next;
    }

    temp -> CFuncs = CFuncs;
    temp -> CVars = CVars;
    temp -> binding = totalCount;
    temp -> ClassIndex = class_count++;
    totalCount = totalCount + 8;    //each class uses 8 words of stack memory
    class_var_count = 1;
    return;
}

struct CFunclist* CFparamLookup(struct CFunclist* list, struct Paramstruct* paramlist1, char* name)
{
    struct CFunclist* temphead;
    temphead = list;
    struct Paramstruct *paramlist,*tempparamlist;
    paramlist = paramlist1;

    while(temphead != NULL)
    {
        if(strcmp(temphead -> name,name) == 0)
        {
            tempparamlist = temphead -> paramlist;
            while(tempparamlist != NULL && paramlist != NULL)
            {
                if(tempparamlist -> type == paramlist -> type)
                {
                    tempparamlist = tempparamlist -> next;   
                    paramlist = paramlist -> next;   
                }
                else
                {
                    break;
                }
            }
            if(tempparamlist == NULL && paramlist == NULL)
            {
                return temphead;
            }
        }
        temphead = temphead -> next;
    }
    return NULL;
} 

struct CFunclist* CFPcountLookup(char* name,struct CFunclist *list,int count)
{
    struct CFunclist *temp;
    struct Paramstruct *paramlist;
    temp  = list;
    int countcopy = count;
    while(temp != NULL)
    {
        if(strcmp(temp -> name,name) == 0)
        {
            paramlist = temp -> paramlist;
            while(paramlist != NULL)
            {
                countcopy --;
                paramlist = paramlist -> next;
            }
            if(countcopy == 0)
            {
                return temp;
            }
        }
        temp = temp -> next;
        countcopy = count;
    }
    return NULL;
}
struct CFunclist* CFLookup(char* name,struct CFunclist *list)
{
    struct CFunclist *temp;
    temp  = list;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}

void CFuncInstall(int label,char* name,struct Paramstruct *paramlist)
{
    struct CFunclist *temp;
    struct Classtable *temp1;
    temp = (struct CFunclist *) malloc(sizeof(struct CFunclist));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> label = label;
    temp -> paramlist = paramlist;
    temp -> next = NULL;

    if(CFhead == NULL)
    {
        CFhead = temp;
        CFtail = temp;
    }
    else
    {
        CFtail -> next = temp;
        CFtail = CFtail -> next;
    }       
    return;
}

void CFuncIndex(struct Classtable *ctable)
{
    int counter=0;
    struct CFunclist *cftemp;

    cftemp = ctable -> CFuncs;

    while(cftemp != NULL)
    {
     cftemp -> ClassFuncIndex = counter++;
     cftemp = cftemp -> next;
    }

    ctable -> size = counter;
    return;
}

struct CVarlist* CVLookup(char* name,struct CVarlist *list)
{
    struct CVarlist *temp;
    temp  = list;
    while(temp != NULL && (strcmp(temp -> name,name) != 0))
    {
        temp = temp -> next;
    }
    return temp;
}

void CVarInstall(char* name, struct Typetable *type)
{
    struct CVarlist *temp;
    temp = (struct CVarlist *) malloc(sizeof(struct CVarlist));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> type = type;
    temp -> ClassVarIndex = class_var_count++;
    temp -> next = NULL;

    if(CVhead == NULL)
    {
        CVhead = temp;
        CVtail = temp;
    }
    else
    {
        CVtail -> next = temp;
        CVtail = CVtail -> next;
    }       
    return;
}
void extends(char* name1, char* name2)
{
    struct Classtable *temp1, *temp2;
    struct CFunclist *head1, *head2,*temphead,*temptail,*temphead2,*temp;

    temp1 = CLookup(name1);
    temp2 = CLookup(name2);
    head1 = temp1 -> CFuncs;
    head2 = temp2 -> CFuncs;

    temphead2 = head2;
    temphead = NULL;
    while(temphead2 != NULL)
    {
    	temp = (struct CFunclist *) malloc(sizeof(struct CFunclist));
	    temp -> name = (char *) malloc(sizeof(temphead2 -> name));
	    strcpy(temp -> name , temphead2 -> name);
	    temp -> label = temphead2 -> label;
	    temp -> paramlist = temphead2 -> paramlist;
	    temp -> next = NULL;

	    if(temphead == NULL)
	    {
	        temphead = temp;
	        temptail = temp;
	    }
	    else
	    {
	        temptail -> next = temp;
	        temptail = temptail -> next;
	    }
	    temphead2 = temphead2 -> next;
    }

    CFhead = temphead;
    CFtail = temptail;

    temp = head1; 
    while(temp != NULL)
    {
        // temphead2 = CFLookup(temp -> name,temphead);
    	temphead2 = CFparamLookup(temphead,temp -> paramlist,temp -> name);
    	if(temphead2 != NULL)
    	{
    		temphead2 -> label = temp -> label;
    		temphead2 -> name = temp -> name;
    		temphead2 -> paramlist = temp -> paramlist;
    	}
    	temp = temp -> next;
    }


    while(head1 != NULL)
    {
        if(CFparamLookup(temphead,head1 -> paramlist, head1 -> name) == NULL)
        {
            CFuncInstall(head1 -> label, head1 -> name, head1 -> paramlist);
        }

        head1 = head1 -> next;
    }
    
    temp1 -> CFuncs = CFhead;
    return;
}

void extends_var(char* name1, char* name2)
{
    struct Classtable *temp1, *temp2;
    struct CVarlist *head1, *head2,*temphead,*temptail,*temphead2,*temp;

    temp1 = CLookup(name1);
    temp2 = CLookup(name2);
    head1 = temp1 -> CVars;
    head2 = temp2 -> CVars;

    temphead2 = head2;
    temphead = NULL;
    while(temphead2 != NULL)
    {
        temp = (struct CVarlist *) malloc(sizeof(struct CVarlist));
        temp -> name = (char *) malloc(sizeof(temphead2 -> name));
        strcpy(temp -> name , temphead2 -> name);
        temp -> type = temphead2 -> type;
        temp -> next = NULL;

        if(temphead == NULL)
        {
            temphead = temp;
            temptail = temp;
        }
        else
        {
            temptail -> next = temp;
            temptail = temptail -> next;
        }
        temphead2 = temphead2 -> next;
    }

    CVhead = temphead;
    CVtail = temptail;

    while(head1 != NULL)
    {
        if(CVLookup(head1 -> name, temphead) == NULL)
        {
            CVarInstall(head1 -> name, head1 -> type);
        }

        head1 = head1 -> next;
    }
    
    temp1 -> CVars = CVhead;
    return;
}

void CGInstall(char *name,struct Classtable* ctype,int size,struct Paramstruct *paramlist)
{
    struct Gsymbol *temp;

    temp = GLookup(name);
    if(temp != NULL)
    {
        yyerror("Variable re-initialized");
        printf("\"%s\"\n",name);
        exit(1);
    }

    temp = (struct Gsymbol *) malloc(sizeof(struct Gsymbol));
    temp -> name = (char *) malloc(sizeof(name));
    strcpy(temp -> name , name);
    temp -> ctype = ctype;
    temp -> size = size;
    temp -> paramlist = paramlist;
    temp -> next = NULL;

    if(temp -> size == -1)
    {
        temp -> binding = fbind;
        fbind++;
    }
    else
    {
        temp -> binding = totalCount;
        totalCount = totalCount + 2;        //two words for class variable
    }

    if(Ghead != NULL)
    {
        Gtail -> next = temp;
        Gtail = temp; 
    }
    else
    {
        Ghead = temp;
        Gtail = temp;
    }
    return;
}

void printSymbolTable()
{
    struct Gsymbol *temp;
    temp = Ghead;
    while(temp != NULL)
    {
        printf("%s----%s-----%d\n",temp -> name,temp -> type -> name,temp -> binding);
        temp = temp -> next;
    }
}