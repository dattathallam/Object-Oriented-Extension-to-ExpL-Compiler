FILE *intermediate;
int res,counter = -1,label = 3,temporary = 0,offset= 0 ,offset1 = 0,Loffset = 0,isamp = 0,i,j,fld = 0,w1,w2,st=1,arg_count=0;
//w1 & w2 stores the start and end of while loop (label numbers) which are used by break and continue to transfer control.
//arg_count is to count the number of arguments in exposcall function.
int class_addr; //pointer to the class in the data structure created for classes i.e 4096 + (8*ClassIndex)
struct Lsymbol* Ltemp;																							
int tree_iter = 0,flditer = 0;
int exprcounter = 0; // to get the count of arguments passed so that we can find function binding using name and paramcount
struct Gsymbol *Gtemp;
struct Paramstruct *Argtemp,*Arg_callee;
struct Fieldlist *fldtemp1,*fldtemp2;
struct CVarlist *cvfldtemp1,*cvfldtemp2;
struct Classtable *ctemp = NULL;
struct CFunclist *cftemp;

int getlabel()
{
	return ++label;
}
void freereg()
{
	if(counter >= 0)
		counter--;
}
void freeallreg()
{
	counter = -1;
}
int getreg()
{
	if(counter < 16)
		return ++counter;
	else
	{
		printf("Running out of registers\n");
		exit(1);
	}
}
void class_setmem()
{
    struct Classtable *temp;
    struct CFunclist *head;
    int l1,l2,l3,l4,size;

    temp = Chead;
   
    fprintf(intermediate, "F%d:\n",fbind);
    fbind++;
    fprintf(intermediate, "PUSH BP\n");
    fprintf(intermediate, "MOV BP,SP\n");

    fprintf(intermediate, "MOV R0, 4096\n");

    while(temp != NULL)
    {
    	fprintf(intermediate, "MOV R1,R0\n");
    	head = temp -> CFuncs;
    	while(head != NULL)
    	{
    		fprintf(intermediate, "MOV [R1], \"#F%d\n",head -> label);
    		fprintf(intermediate, "ADD R1, 1\n");
    		head = head -> next;
    	}
    	fprintf(intermediate, "ADD R0, 8\n");
    	temp = temp -> next;
    }
    fprintf(intermediate, "MOV BP,[SP]\n");

    fprintf(intermediate, "POP R0\n");
    fprintf(intermediate, "RET\n");

}
int codegen(struct ASTNode* root)
{
	int number,a,r1,r2,r3,l1,l2,i,status = 0;
	struct  ASTNode *temp ,*temp1;
	struct ASTNode *Ttemp;
	if(intermediate == NULL)
	{
		printf("Error while generating assemblycode\n");
		exit(1);
	}

	if(root == NULL)
	{
		return 0;
	}
	
	if(root -> nodetype == NODE_EXPR )
	{
		tree_iter = 0;
		Arg_callee = root -> ptr3;
		Argtemp = Arg_callee;
		while(Argtemp != NULL)
		{
			++tree_iter;
			Argtemp = Argtemp -> next;
		}
		Ttemp = root;
		while( tree_iter != 1 )
		{
			if(Ttemp -> ptr1 -> nodetype == NODE_ID)
			{
				Argtemp = Arg_callee;
				for (i = 1 ; i < tree_iter; i++)
				{
					Argtemp = Argtemp -> next;
				}
			}
			if(Ttemp -> ptr1 -> nodetype == NODE_FIELD)
			{
				Argtemp = Arg_callee;
				for (i = 1 ; i < tree_iter; i++)
				{
					Argtemp = Argtemp -> next;
				}
			}	
			a = codegen(Ttemp -> ptr1);
			fprintf(intermediate, "PUSH R%d\n", a);
			freereg();	
			Ttemp =  Ttemp -> ptr2;
			tree_iter--;
		}
			if(Ttemp -> nodetype == NODE_ID)
			{
				Argtemp = Arg_callee;
				for (i = 1 ; i < tree_iter; i++)
				{
					Argtemp = Argtemp -> next;
				}
			}
			if(Ttemp -> nodetype == NODE_FIELD)
			{
				Argtemp = Arg_callee;
				for (i = 1 ; i < tree_iter; i++)
				{
					Argtemp = Argtemp -> next;
				}
			}
			a = codegen(Ttemp);
			fprintf(intermediate, "PUSH R%d\n", a);
			freereg();	
	}
	else if(root -> nodetype == DEFAULT)
	{
		codegen(root -> ptr1);
		codegen(root -> ptr2);
	}
	else
	{
	    temp = root;

		switch(temp -> nodetype)
		{				
			case NODE_LE  :
								r1 = codegen(temp -> ptr1);
								r2 = codegen(temp -> ptr2);
								fprintf(intermediate, "LE R%d,R%d\n",r1,r2);
								freereg();
								return r1;		
								break;
			case NODE_GE  :
								r1 = codegen(temp -> ptr1);
								r2 = codegen(temp -> ptr2);
								fprintf(intermediate, "GE R%d,R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_LT  :
								r1 = codegen(temp -> ptr1);
								r2 = codegen(temp -> ptr2);
								fprintf(intermediate, "LT R%d,R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_GT  :
								r1 = codegen(temp -> ptr1);
								r2 = codegen(temp -> ptr2);
								fprintf(intermediate, "GT R%d,R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_DEQ  :
								r1 = codegen(temp -> ptr1);
								r2 = codegen(temp -> ptr2);
								fprintf(intermediate, "EQ R%d,R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_NEQ  :
								r1 = codegen(temp -> ptr1);
								r2 = codegen(temp -> ptr2);
								fprintf(intermediate, "NE R%d,R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_AND  :
								r1 = codegen(temp -> ptr1);
								r2 = getreg();
								fprintf(intermediate,"MOV R%d,1\n",r2);
								l1 = getlabel();
								fprintf(intermediate, "JZ R%d,L%d\n",r1,l1);
								r3 = codegen(temp -> ptr2);
								fprintf(intermediate, "MOV R%d,R%d\n",r2,r3);
								freereg();
								fprintf(intermediate, "L%d:\n",l1);
								fprintf(intermediate, "MUL R%d,R%d\n",r1,r2);
								freereg();
								return r1;
								break;
            case NODE_OR  :
								r1 = codegen(temp -> ptr1);
								r2 = getreg();
								fprintf(intermediate,"MOV R%d,1\n",r2);
								l1 = getlabel();
								fprintf(intermediate, "JNZ R%d,L%d\n",r1,l1);
								r3 = codegen(temp -> ptr2);
								fprintf(intermediate, "MOV R%d,R%d\n",r2,r3);
								freereg();
								fprintf(intermediate, "L%d:\n",l1);
								fprintf(intermediate, "ADD R%d,R%d\n",r1,r2);
								freereg();
								return r1;
								break;
			case NODE_NOT  :
								r1 = codegen(temp -> ptr2);
								l1 = getlabel();
								fprintf(intermediate, "JNZ R%d,L%d\n",r1,l1);
								fprintf(intermediate, "MOV R%d,1\n",r1);
								l2 = getlabel();
								fprintf(intermediate, "JMP L%d\n",l2);
								fprintf(intermediate, "L%d:\n",l1);
								fprintf(intermediate, "MOV R%d,0\n",r1);										
								fprintf(intermediate, "L%d:\n",l2);
								return r1;
			case NODE_ID   :
								r1 = getreg();
								Ltemp = LLookup(temp -> name);
								if(Ltemp != NULL)
								{
									Ltemp = Lhead;
									Loffset = 0;
									while(strcmp(temp -> name , Ltemp -> name) != 0)
									{
										Loffset = Loffset + 1;
										Ltemp = Ltemp -> next;
									}
									
									r2 = getreg();
									fprintf(intermediate, "MOV R%d,BP\n",r2);
									fprintf(intermediate, "MOV R%d,%d\n",r1,Loffset+1);
									fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
									if(isamp)
									{
										fprintf(intermediate, "MOV R%d,R%d\n",r1,r2);
										isamp = 0; 
									}
									else
									{
										fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
										if(fld)
										{
											fprintf(intermediate, "MOV R%d,R%d\n",r1,r2);
											fld = 0;
										}
									}
									freereg();
								}
								else
								{
									Argtemp = PLookup(temp -> name);
	// BRING THIGS FROM STACK
									if(Argtemp != NULL)
									{
										Argtemp = Phead;
										offset = 0;

										while(strcmp(Argtemp -> name,temp -> name) != 0)
										{
											offset = offset + 1;
											Argtemp = Argtemp -> next;
										}
									
										r2 = getreg();
										fprintf(intermediate, "MOV R%d,BP\n",r2);
			 							r3 = getreg();
			 							fprintf(intermediate, "MOV R%d,2\n",r3);
			 							fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
			 							fprintf(intermediate, "MOV R%d,%d\n",r3,(offset+1));
										fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
										freereg();
										if( isamp || fld )
										{
											fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2); //BP-2-(offset+1)
											isamp = 0;
											fld = 0;
										}
				
										else
										{
											fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2); //BP-2-(offset+1)
										}
										
										freereg();
									}
									else
									{
										if(isamp)
										{
											fprintf(intermediate, "MOV R%d,%d\n",r1,(temp -> Gentry -> binding));
											isamp = 0;
										}
										else
										{
											fprintf(intermediate, "MOV R%d,[%d]\n",r1,(temp -> Gentry -> binding));
											if(fld)
											{
												fprintf(intermediate, "MOV R%d,%d\n",r1,(temp -> Gentry -> binding));
												fld = 0;
											}
										}
									}
								}
								return r1;
								break;


			case NODE_FIELD :		
								r1 = getreg();
								Ltemp = LLookup(temp -> name);
								if(Ltemp != NULL)
								{
									Ltemp = Lhead;
									Loffset = 0;
									while(strcmp(temp -> name , Ltemp -> name) != 0)
									{
										Loffset = Loffset + 1;
										Ltemp = Ltemp -> next;
									}
									
									r2 = getreg();
									fprintf(intermediate, "MOV R%d,BP\n",r2);
									fprintf(intermediate, "MOV R%d,%d\n",r1,Loffset+1);
									fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
									fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
									freereg();

									fldtemp2 = fldtemp1 = Ltemp -> type -> fields;
									flditer = 0;
									temp1 = temp;
									while(temp1 -> ptr2 != NULL)
									{
										flditer = 1;
										fldtemp2 = fldtemp1;
										while(fldtemp2 != NULL)
										{
											if(strcmp(fldtemp2 -> name,temp1 -> ptr2 -> name) == 0)
											{
												r2 = getreg();
												fprintf(intermediate, "MOV R%d,%d\n",r2,flditer);
												fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
												fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
												freereg();
												break;
											}
											flditer++;
											fldtemp2 = fldtemp2 -> next;
										}
										temp1 = temp1 -> ptr2;
									}
									if(fld == 1)
									{
										fprintf(intermediate, "MOV R%d,R%d\n",r1,r2);

										fld = 0;
									}
								}
								else
								{
									Argtemp = PLookup(temp -> name);
	
									if(Argtemp != NULL)
									{
										Argtemp = Phead;
										offset = 0;

										while(strcmp(Argtemp -> name,temp -> name) != 0)
										{
											offset = offset + 1;
											Argtemp = Argtemp -> next;
										}
									
										r2 = getreg();
										fprintf(intermediate, "MOV R%d,BP\n",r2);
			 							r3 = getreg();
			 							fprintf(intermediate, "MOV R%d,2\n",r3);
			 							fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
			 							fprintf(intermediate, "MOV R%d,%d\n",r3,(offset+1));
										fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
										freereg();

										fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2); //BP-2-(offset+1)
										freereg();
										fldtemp2 = fldtemp1 = Argtemp -> type -> fields;
										flditer = 0;
										temp1 = temp;
										while(temp1 -> ptr2 != NULL)
										{
											flditer = 1;
											fldtemp2 = fldtemp1;
											while(fldtemp2 != NULL)
											{
												if(strcmp(fldtemp2 -> name,temp1 -> ptr2 -> name) == 0)
												{
													r2 = getreg();
													fprintf(intermediate, "MOV R%d,%d\n",r2,flditer);
													fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
													fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
													freereg();

													break;
												}
												flditer++;
												fldtemp2 = fldtemp2 -> next;
											}
											temp1 = temp1 -> ptr2;
										}

										if(fld == 1)
										{
											fprintf(intermediate, "MOV R%d,R%d\n",r1,r2);
											fld = 0;
										}
									}
									else
									{
										fprintf(intermediate, "MOV R%d,[%d]\n",r1,(temp -> Gentry -> binding));

										if(temp -> Gentry -> type == NULL)
										{
											cvfldtemp2 = cvfldtemp1 = temp -> Gentry -> ctype -> CVars;
											flditer = 0;
											temp1 = temp;
											while(temp1 -> ptr2 != NULL)
											{
												flditer = 1;
												cvfldtemp2 = cvfldtemp1;
												while(cvfldtemp2 != NULL)
												{
													if(strcmp(cvfldtemp2 -> name,temp1 -> ptr2 -> name) == 0)
													{
														r2 = getreg();
														fprintf(intermediate, "MOV R%d,%d\n",r2,flditer);
														fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
														fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
														freereg();
														break;
													}
													flditer++;
													cvfldtemp2 = cvfldtemp2 -> next;
												}
												temp1 = temp1 -> ptr2;
											}
										}
										else
										{
											fldtemp2 = fldtemp1 = temp -> Gentry -> type -> fields;
											flditer = 0;
											temp1 = temp;
											while(temp1 -> ptr2 != NULL)
											{
												flditer = 1;
												fldtemp2 = fldtemp1;
												while(fldtemp2 != NULL)
												{
													if(strcmp(fldtemp2 -> name,temp1 -> ptr2 -> name) == 0)
													{
														r2 = getreg();
														fprintf(intermediate, "MOV R%d,%d\n",r2,flditer);
														fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
														fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
														freereg();
														break;
													}
													flditer++;
													fldtemp2 = fldtemp2 -> next;
												}
												temp1 = temp1 -> ptr2;
											}
										}	

										if(fld == 1)
										{
											fprintf(intermediate, "MOV R%d,R%d\n",r1,r2);

											fld = 0;
										}
									}
								}
	                            return r1;
								break;
			case NODE_ARRAY :
									offset = codegen(temp -> ptr2);
									r1 = getreg();
									fprintf(intermediate, "MOV R%d,%d\n",r1,(temp -> ptr1 -> Gentry -> binding));
									fprintf(intermediate, "ADD R%d,R%d\n",r1,offset);
									fprintf(intermediate, "MOV R%d,[R%d]\n",offset,r1);
									if(fld)
									{
										fprintf(intermediate, "MOV R%d,R%d\n",offset,r1);
										fld = 0;	
									}
									freereg();
									return offset;
									break;

			case NODE_NUM :
									r1 = getreg();
									fprintf(intermediate, "MOV R%d,%d\n",r1,(root -> value));
									return r1;
									break;
			case NODE_STRVAL :
									r1 = getreg();
									fprintf(intermediate, "MOV R%d,\"%s\"\n",r1,(root -> value));
									return r1;
									break;
			case NODE_PLUS :
									r1 = codegen(temp -> ptr1);
									r2 = codegen(temp -> ptr2);
									fprintf(intermediate, "ADD R%d,R%d\n",r1,r2);
									freereg();
									return r1;
									break;
 			case NODE_MINUS :
 									r1 = codegen(temp -> ptr1);
									r2 = codegen(temp -> ptr2);
									fprintf(intermediate, "SUB R%d,R%d\n",r1,r2);
									freereg();
									return r1;
									break;
 			case NODE_MUL :
 									r1 = codegen(temp -> ptr1);
									r2 = codegen(temp -> ptr2);
									fprintf(intermediate, "MUL R%d,R%d\n",r1,r2);
									freereg();
									return r1;
									break;
			case NODE_DIV :
 									r1 = codegen(temp -> ptr1);
									r2 = codegen(temp -> ptr2);
									l1 = getlabel();
									fprintf(intermediate, "JZ R%d,L%d\n",r2,l1);
									fprintf(intermediate, "DIV R%d,R%d\n",r1,r2);
									freereg();
									fprintf(intermediate, "JMP L%d\n",l2);
									fprintf(intermediate, "L%d:\n",l1);
									fprintf(intermediate, "INT 10\n");
									fprintf(intermediate, "L%d:\n",l2);
									
									return r1;
									break;
			case NODE_MOD :
 									r1 = codegen(temp -> ptr1);
									r2 = codegen(temp -> ptr2);
									fprintf(intermediate, "MOD R%d,R%d\n",r1,r2);
									freereg();
									return r1;
									break;
			case NODE_ASGN :
								number = codegen(temp -> ptr2);
								if(temp -> ptr1 -> nodetype == NODE_THIS)
								{
									fld = 1;
									r1 = codegen(temp -> ptr1);
									fprintf(intermediate, "MOV [R%d],R%d\n",r1,number);
									freereg();
								}
								else if(temp -> ptr1 -> nodetype == NODE_FIELD)
								{
									fld = 1;
									r1 = codegen(temp -> ptr1);
									fprintf(intermediate, "MOV [R%d],R%d\n",r1,number);
									freereg();
								}
								else
								{
									Ltemp = LLookup(temp -> ptr1 -> name);
									if(Ltemp != NULL)
									{
										Ltemp = Lhead;
										Loffset = 0;

										while(strcmp(temp -> ptr1 -> name , Ltemp -> name) != 0)
										{
											Loffset = Loffset + 1;
											Ltemp = Ltemp -> next;
										}
										r1 = getreg();
										r2 = getreg();
										fprintf(intermediate, "MOV R%d,BP\n",r2);
										fprintf(intermediate, "MOV R%d,%d\n",r1,Loffset+1);
										fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
										fprintf(intermediate, "MOV [R%d],R%d\n",r2,number);
										freereg();
										freereg();
									}
									else
									{
										Argtemp = PLookup(temp -> ptr1 -> name);
		// BRING THIGS FROM STACK
										if(Argtemp != NULL)
										{
											Argtemp = Phead;
											offset = 0;

											while(strcmp(Argtemp -> name,temp -> ptr1 -> name) != 0)
											{
												offset = offset + 1;
												Argtemp = Argtemp -> next;
											}

											r1 = getreg();
											fprintf(intermediate, "MOV R%d,BP\n",r1);
				 							r2 = getreg();
				 							fprintf(intermediate, "MOV R%d,2\n",r2);
				 							fprintf(intermediate, "SUB R%d,R%d\n",r1,r2);
				 							
				 							fprintf(intermediate, "MOV R%d,%d\n",r2,(offset+1));
											fprintf(intermediate, "SUB R%d,R%d\n",r1,r2);
											freereg();
											fprintf(intermediate, "MOV [R%d],R%d\n",r1,number); //BP-2-(offset+1)
											freereg();
										}
										else
										{
											fprintf(intermediate, "MOV [%d],R%d\n",(temp -> ptr1 -> Gentry -> binding),number);
											if(ctemp != NULL)
											{
												r1 = getreg();
												fprintf(intermediate, "MOV R%d,%d\n",r1,(temp -> ptr1 -> Gentry -> binding));
												fprintf(intermediate, "ADD R%d,1\n",r1);
												fprintf(intermediate, "MOV [R%d],%d\n",r1,ctemp -> binding);
												freereg();
												ctemp = NULL;
											}

										}
									}
								}
									freereg();
									break;

			case NODE_ARRAY_ASGN :
										offset1 = codegen(temp -> ptr2);
										r1 = getreg();
										fprintf(intermediate, "MOV R%d,%d\n",r1,(temp -> ptr1 -> Gentry -> binding));
										fprintf(intermediate, "ADD R%d,R%d\n",offset1,r1);
										freereg();
										r1 = codegen(temp -> ptr3);
										fprintf(intermediate, "MOV [R%d],R%d\n",offset1,r1);
										freereg();
										freereg();
										break;
			case NODE_READ :
									temporary = 0;
									if(temp -> ptr2 -> nodetype == NODE_THIS)
									{
										fld = 1;
										r2 = codegen(temp -> ptr2);

										for(i = 0; i <= counter; i++)
		 									fprintf(intermediate, "PUSH R%d\n",i);

			 							fprintf(intermediate, "MOV R1,\"Read\"\n");
			 							fprintf(intermediate, "PUSH R1\n"); // function code "Read"

			 							fprintf(intermediate, "MOV R1,-1\n");
			 							fprintf(intermediate, "PUSH R1\n"); //Argument 1
			 							fprintf(intermediate, "PUSH R%d\n",r2); //Argument 2
										freereg();
										temporary++;
			 							status = counter;											
									}
									else if(temp -> ptr2 -> nodetype == NODE_FIELD)
									{
										fld = 1;
										r2 = codegen(temp -> ptr2);

										for(i = 0; i <= counter; i++)
		 									fprintf(intermediate, "PUSH R%d\n",i);

			 							fprintf(intermediate, "MOV R1,\"Read\"\n");
			 							fprintf(intermediate, "PUSH R1\n"); // function code "Read"

			 							fprintf(intermediate, "MOV R1,-1\n");
			 							fprintf(intermediate, "PUSH R1\n"); //Argument 1
			 							fprintf(intermediate, "PUSH R%d\n",r2); //Argument 2
										freereg();
										temporary++;
			 							status = counter;
									}
									else
									{
										Ltemp = LLookup(temp -> ptr2 -> name);
										if(Ltemp != NULL)
										{
											Ltemp = Lhead;
											Loffset = 0;

											while(strcmp(temp -> ptr2 -> name , Ltemp -> name) != 0)
											{
												Loffset = Loffset + 1;
												Ltemp = Ltemp -> next;
											}
											r2 = getreg();
											r3 = getreg();
											fprintf(intermediate, "MOV R%d,BP\n",r3);
											fprintf(intermediate, "MOV R%d,%d\n",r2,Loffset+1);
											fprintf(intermediate, "ADD R%d,R%d\n",r3,r2);

											for(i = 0; i <= counter; i++)
		 										fprintf(intermediate, "PUSH R%d\n",i);

				 							fprintf(intermediate, "MOV R0,\"Read\"\n");
			 								fprintf(intermediate, "PUSH R0\n"); // function code "Read"
				 							fprintf(intermediate, "MOV R0,-1\n");
				 							fprintf(intermediate, "PUSH R0\n"); //Argument 1
				 							fprintf(intermediate, "PUSH R%d\n",r3); //Argument 2
											freereg();
											temporary++;
											freereg();
											temporary++;
				 							status = counter;
										}
										else
										{
											Argtemp = PLookup(temp -> ptr2 -> name);
											if(Argtemp != NULL)
											{
												Argtemp = Phead;
												offset = 0;

												while(strcmp(Argtemp -> name,temp -> ptr2 -> name) != 0)
												{
													offset = offset + 1;
													Argtemp = Argtemp -> next;
												}
												r2 = getreg();
												fprintf(intermediate, "MOV R%d,BP\n",r2);
					 							r3 = getreg();
					 							fprintf(intermediate, "MOV R%d,2\n",r3);
					 							fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
					 							fprintf(intermediate, "MOV R%d,%d\n",r3,(offset+1));
												fprintf(intermediate, "SUB R%d,R%d\n",r2,r3);
												freereg();
												for(i = 0; i <= counter; i++)
			 										fprintf(intermediate, "PUSH R%d\n",i);

					 							fprintf(intermediate, "MOV R0,\"Read\"\n");
			 									fprintf(intermediate, "PUSH R0\n"); // function code "Read"
					 							fprintf(intermediate, "MOV R0,-1\n");
					 							fprintf(intermediate, "PUSH R0\n"); //Argument 1
					 							fprintf(intermediate, "PUSH R%d\n",r2); //Argument 2
												freereg();
												temporary++;
						 						status = counter;
											}
											else
											{
												for(i = 0; i <= counter; i++)
			 										fprintf(intermediate, "PUSH R%d\n",i);

					 							fprintf(intermediate, "MOV R0,\"Read\"\n");
			 									fprintf(intermediate, "PUSH R0\n"); // function code "Read"
					 							fprintf(intermediate, "MOV R0,-1\n");
					 							fprintf(intermediate, "PUSH R0\n"); //Argument 1
					 							fprintf(intermediate, "MOV R0,%d\n",(temp -> ptr2 -> Gentry -> binding));
					 							fprintf(intermediate, "PUSH R0\n"); //Argument 2
					 							status = counter;
											}
										}
									}
		 							fprintf(intermediate, "ADD SP,2\n");
		 							freeallreg();
		 							fprintf(intermediate, "CALL 0\n");
		 							fprintf(intermediate, "SUB SP,5\n");

									for (i = temporary; i > 0; i--)
		 							{
		 								fprintf(intermediate, "POP R0\n");
		 							}
									for(i = status; i >= 0; i--)
		                            {
		 								fprintf(intermediate, "POP R%d\n",i);
		                            }
		 							counter = status;
									break;
			case NODE_ARRAY_READ :
									temporary = 0;
									offset = codegen(temp -> ptr3);

		    						r1 = getreg();
									fprintf(intermediate, "MOV R%d,%d\n",r1,(temp -> ptr2 -> Gentry -> binding));
									r2 = getreg();
									fprintf(intermediate, "MOV R%d,%d\n",r2,(temp -> ptr2 -> Gentry -> size));
									fprintf(intermediate, "GT R%d,R%d\n",r2,offset);
									l1 = getlabel();
									fprintf(intermediate, "JNZ R%d,L%d\n",r2,l1);
									fprintf(intermediate, "INT 10\n");
									fprintf(intermediate, "L%d:\n",l1);
									freereg();
									fprintf(intermediate, "ADD R%d,R%d\n",offset,r1);
									freereg();
									fprintf(intermediate, "MOV [2044],R%d\n",offset); // The address of the reg to be read is stored
																						// in 2044 and this passed as an argument to
																						// read system call
									for(i = 0; i <= counter; i++)
	 									fprintf(intermediate, "PUSH R%d\n",i);

		 							fprintf(intermediate, "MOV R0,\"Read\"\n");
			 						fprintf(intermediate, "PUSH R0\n"); // function code "Read"
		 							fprintf(intermediate, "MOV R0,-1\n");
		 							fprintf(intermediate, "PUSH R0\n"); //Argument 1
		 							fprintf(intermediate, "MOV R0,[2044]\n");
		 							fprintf(intermediate, "PUSH R0\n"); //Argument 2
									freereg();
									temporary++;	
									status = counter;
		 							fprintf(intermediate, "ADD SP,2\n");
		 							freeallreg();
		 							fprintf(intermediate, "CALL 0\n");
		 							fprintf(intermediate, "SUB SP,5\n");

									for (int i = temporary; i > 0; i--)
		 							{
		 								fprintf(intermediate, "POP R0\n");
		 							}
									for(i = status; i >= 0; i--)
		                            {
		 								fprintf(intermediate, "POP R%d\n",i);
		                            }
		 							counter = status;
		 							temporary = 0;
									break;
			case NODE_WRITE :
									number = codegen(temp -> ptr2);

									fprintf(intermediate, "MOV [2042],R%d\n",number); // we are writing the value to the dummy loc 2042
																					// sending this loc to write sys call to print value
									
									for(i = 0; i <= counter; i++)
	 									fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;

		 							fprintf(intermediate, "MOV R0,\"Write\"\n");
			 						fprintf(intermediate, "PUSH R0\n"); // function code "Write"
		 							fprintf(intermediate, "MOV R0,-2\n");
		 							fprintf(intermediate, "PUSH R0\n"); //Argument 1
									fprintf(intermediate, "MOV R0,2042\n");
		 							fprintf(intermediate, "PUSH R0\n"); //Argument 2
		 							fprintf(intermediate, "ADD SP,2\n");
		 							freeallreg();
		 							fprintf(intermediate, "CALL 0\n");
		 							fprintf(intermediate, "SUB SP,5\n");
									
									for(i = status; i >= 0; i--)
		                            {
		 								fprintf(intermediate, "POP R%d\n",i);
		                            }
		 							counter = status;
									freereg();
									break;
			case NODE_IF  :
									l1 = getlabel();
									number = codegen(temp -> ptr1);
									fprintf(intermediate, "JZ R%d,L%d\n",number,l1);
									number = codegen(temp -> ptr2);
									fprintf(intermediate, "L%d:\n",l1);
									freereg();
									break;
			case NODE_IF_ELSE:
									number = codegen(temp -> ptr1);
									l1 = getlabel();
									l2 = getlabel();
									fprintf(intermediate, "JZ R%d,L%d\n",number,l1);
									freereg();
									number = codegen(temp -> ptr2);
									fprintf(intermediate, "JMP L%d\n",l2);
									fprintf(intermediate, "L%d:\n",l1);
									freereg();
									number = codegen(temp -> ptr3);
									fprintf(intermediate, "L%d:\n",l2);
									break;
		 	case NODE_WHILE :
		 							l1 = getlabel();
		 							l2 = getlabel();
		 							w1 = l1;
		 							w2 = l2;
		 							fprintf(intermediate, "L%d:\n",l1);
		 							number = codegen(temp -> ptr1);
		 							fprintf(intermediate, "JZ R%d,L%d\n",number,l2);
		 							freereg();
									number = codegen(temp -> ptr2);
		 							fprintf(intermediate, "JMP L%d\n",l1);
		 							fprintf(intermediate, "L%d:\n",l2);
		 							freereg();

		 							break;

		 	case NODE_FUNC :
		 							for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;

		 							freeallreg();
		 							if(temp -> ptr3 == NULL && temp -> ptr2 == NULL)
		 							{
		 							}
		 							else if(temp -> ptr2 != NULL)
		 							{
		 								codegen(temp -> ptr2); //more than 1 argument
		 							}
		 							else
		 							{
		 								if((temp -> ptr3 -> nodetype == NODE_ID) || (temp -> ptr3 -> nodetype == NODE_FIELD) || (temp -> ptr3 -> nodetype == NODE_ARRAY))
										{
											Argtemp = temp -> ptr3 -> ptr3;
										}
		 								a = codegen(temp -> ptr3);
		 								fprintf(intermediate, "PUSH R%d\n",a);
		 								freereg();
		 							}
		 							fprintf(intermediate, "PUSH R0\n"); //space for return value
		 							Gtemp = GLookup(temp -> name);
		 							if(Gtemp == NULL)
		 								fprintf(intermediate, "CALL #F%d\n",temp -> value);
		 							else
		 								fprintf(intermediate, "CALL F%d\n",Gtemp -> binding);
		 							r1 = getreg();
                                    fprintf(intermediate, "POP R%d\n",r1);	// for return value
                                    freereg();
                                    r2 = getreg();
                                    if(Gtemp == NULL)
                                    	Argtemp = temp -> arglist;
                                    else
                                    	Argtemp = Gtemp -> paramlist;
                                    temporary = 0;
                                    while(Argtemp != NULL)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",r2);
		 								Argtemp = Argtemp -> next;
                                    }

                                    freereg();

                                    for(i = status; i >= 0; i--)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",i);
                                    }
		 							counter = status;
		 							r1 = getreg();
		 							r2 = getreg();
		 							fprintf(intermediate, "MOV R%d,%d\n",r1,(temporary+1));
		 							fprintf(intermediate, "MOV R%d,SP\n",r2);
		 							fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
		 							fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
		 							freereg();
		 							return r1;
		 							break;
		 	case NODE_RET : 
	 								res = codegen(temp -> ptr2);
		 							r1 = getreg();
		 							fprintf(intermediate, "MOV R%d,BP\n",r1);
		 							r2 = getreg();
		 							fprintf(intermediate, "MOV R%d,2\n",r2);
		 							fprintf(intermediate, "SUB R%d,R%d\n",r1,r2);
		 							freereg();
		 							fprintf(intermediate, "MOV [R%d],R%d\n",r1,res);
		 							freereg();
		 							freereg();
		 							Ltemp = Lhead;
		 							while(Ltemp != NULL)
		 							{                                                                
                                        fprintf(intermediate, "POP R0\n");
                                        Ltemp = Ltemp -> next;
                                    }

		 							fprintf(intermediate, "MOV BP,[SP]\n");
		 							fprintf(intermediate, "POP R0\n");
                                    fprintf(intermediate, "RET\n");
                                    break;

            case NODE_BRK :
		 							fprintf(intermediate, "JMP L%d\n",w2);
            						break;
            case NODE_CONTINUE :
		 							fprintf(intermediate, "JMP L%d\n",w1);
            						break;
            case NODE_BRKP :
		 							fprintf(intermediate, "BRKP\n");
            						break;
            case NODE_ALLOC :	
            						for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;

		 							freeallreg();
		 							fprintf(intermediate, "MOV R0,\"Alloc\"\n");
		 							fprintf(intermediate, "PUSH R0\n"); // function code "Alloc"

		 							fprintf(intermediate, "MOV R0,8\n");
		 							fprintf(intermediate, "PUSH R0\n");	// Argument 1
		 							fprintf(intermediate, "ADD SP,2\n");

		 							fprintf(intermediate, "PUSH R0\n"); //return value
		 							fprintf(intermediate, "CALL 0\n");
		 							fprintf(intermediate, "SUB SP,5\n"); //pop values

									temporary = 0;
									for(i = status; i >= 0; i--)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",i);
                                    }
		 							counter = status;
		 							r1 = getreg();
		 							r2 = getreg();
		 							fprintf(intermediate, "MOV R%d,%d\n",r1,(temporary+5));
		 							fprintf(intermediate, "MOV R%d,SP\n",r2);
		 							fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
		 							fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
		 							freereg();
		 							return r1;
		 							break;

		 	case NODE_FREE :
		 							r1 = getreg();
		 							r1 = codegen(temp -> ptr2);
		 							for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;
		 							freeallreg();
		 							fprintf(intermediate, "MOV R0,\"Free\"\n");
		 							fprintf(intermediate, "PUSH R0\n"); // function code "Free"

		 							fprintf(intermediate, "PUSH R%d\n",r1); // Argument 1
		 							fprintf(intermediate, "ADD SP,2\n");
		 							fprintf(intermediate, "PUSH R0\n");	// return value
		 							fprintf(intermediate, "CALL 0\n");
		 							fprintf(intermediate, "SUB SP,5\n");

									for(i = status; i >= 0; i--)
                                    {
		 								fprintf(intermediate, "POP R%d\n",i);
                                    }
		 							counter = status;
		 							return;
		 							break;
		 	case NODE_NILL :
				 					r1 = getreg();
			 						fprintf(intermediate, "MOV R%d,-1\n",r1);
				 					return r1;
				 					break;
		 	case NODE_INIT : 
				 					for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);

		 							status = counter;
		 							freeallreg();

		 							fprintf(intermediate, "MOV R0,\"Heapset\"\n");
		 							fprintf(intermediate, "PUSH R0\n");	// function code "Initialize"
		 							fprintf(intermediate, "ADD SP,3\n");

		 							fprintf(intermediate, "PUSH R0\n");	// return value
		 							fprintf(intermediate, "CALL 0\n");
		 							fprintf(intermediate, "SUB SP,5\n");

									for(i = status; i >= 0; i--)
		                            {
		 								fprintf(intermediate, "POP R%d\n",i);
		                            }
		 							counter = status;
		 							return 0;
		 							break;
		 	case NODE_NEW : 
		 							res = codegen(temp -> ptr1);
		 							ctemp = CLookup(temp -> ptr2 -> name);
		 							return res;
		 							break;
		 	case NODE_THIS :
		 							r1 = getreg();
		 							if(fld)
		 							{
			 							fprintf(intermediate, "MOV R%d,[2046]\n",r1 );
			 							fprintf(intermediate, "ADD R%d,%d\n",r1,temp -> ptr1 -> value);
			 							fld = 0;
		 							}
		 							else
		 							{
		 								fprintf(intermediate, "MOV R%d,[2046]\n",r1 );
			 							fprintf(intermediate, "ADD R%d,%d\n",r1,temp -> ptr1 -> value);
			 							fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r1);
		 							}
		 							return r1;
		 							break;

		 	case NODE_CLASS_FUNC :
		 							for(i = 0; i <= counter; i++)
		 								fprintf(intermediate, "PUSH R%d\n",i);
		 							status = counter;

		 							freeallreg();

		 							if(temp -> ptr3 == NULL)
		 							{
		 							}
		 							else if(temp -> value.intval == 1)
		 							{
		 								codegen(temp -> ptr3); //more than 1 argument
		 							}
		 							else
		 							{
		 								if(temp -> ptr3 -> nodetype == NODE_ID)
										{
											Argtemp = temp -> ptr3 -> ptr3;
										}
		 								a = codegen(temp -> ptr3);
		 								fprintf(intermediate, "PUSH R%d\n",a);
		 								freereg();
		 							}

		 							fprintf(intermediate, "PUSH R0\n"); //space for return value
		 							Gtemp = GLookup(temp -> ptr1 -> name);
		 							
		 							// for accessing using this
		 							fprintf(intermediate, "MOV R0,[%d]\n", Gtemp -> binding);
		 							fprintf(intermediate, "MOV [2046],R0\n");
		 							fprintf(intermediate, "MOV R0,[%d]\n", (Gtemp -> binding)+1);
		 							fprintf(intermediate, "MOV [2047],R0\n");

		 							fprintf(intermediate, "MOV R0,[%d]\n",(Gtemp -> binding)+1);
		 							// cftemp = CFLookup(temp -> ptr2 -> name, Gtemp -> ctype -> CFuncs);
		 							exprcounter = 0;
		 							if(temp -> ptr3 != NULL)
		 							{
			 							Argtemp = temp -> ptr3 -> ptr3;
			 							while(Argtemp != NULL)
			 							{
			 								exprcounter++;
			 								Argtemp = Argtemp -> next;
			 							}		 								
		 							}

		 							cftemp = CFPcountLookup(temp -> ptr2 -> name, Gtemp -> ctype -> CFuncs,exprcounter);
		 							if(cftemp == NULL)
		 							{
		 								printf("The function %s can not be found in the class %s with %d arguments \n",temp -> ptr2 -> name,Gtemp -> ctype -> name,exprcounter);
		 								exit(0);
		 							}
		 							exprcounter = 0;
		 							fprintf(intermediate, "ADD R0,%d\n",cftemp -> ClassFuncIndex);
		 							fprintf(intermediate, "MOV R0,[R0]\n");
		 							
		 							fprintf(intermediate, "CALL \"#R0\n");

		 							r1 = getreg();
                                    fprintf(intermediate, "POP R%d\n",r1);	// for return value
                                    freereg();
                                    
                                    r2 = getreg();
                                    // printf("%s\n",cftemp -> name);
                                    // printf("%s\n",cftemp -> paramlist -> name);

                                    Argtemp = cftemp -> paramlist;
                                    temporary = 0;
                                    while(Argtemp != NULL)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",r2);
		 								Argtemp = Argtemp -> next;
                                    }

                                    freereg();

                                    for(i = status; i >= 0; i--)
                                    {
                                    	temporary = temporary + 1;
		 								fprintf(intermediate, "POP R%d\n",i);
                                    }
		 							counter = status;
		 							r1 = getreg();
		 							r2 = getreg();
		 							fprintf(intermediate, "MOV R%d,%d\n",r1,(temporary+1));
		 							fprintf(intermediate, "MOV R%d,SP\n",r2);
		 							fprintf(intermediate, "ADD R%d,R%d\n",r2,r1);
		 							fprintf(intermediate, "MOV R%d,[R%d]\n",r1,r2);
		 							freereg();
		 							return r1;
		 							break;

					default:
									printf("NODETYPE is %d\n",temp -> nodetype);
									printf("Error : Unknown node Type\n");
									exit(1);	
		}														
	}
	return 0;
}