#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "ST_ADD_NEW.h"
#include "ST_NODE.h"
#include "ST_Rec.h"

                /************ Prototype Of Functions **************/
void Tim_func(Node1 **head1);
void Add_Patient(void);
u8 search(ST_ADD Cpy_Data);
void AddLast(ST_ADD Cpy_Data);
void Edit_Patient_record(void) ;
void Edit_List(ST_ADD Cpy_Data);
void show_func(Node1 **head1);
void Reser_func( Node1 **head1,u16 id,f32 time);
u16 chckid_func(Node1 **head1,u16 id);
void cancel_func(Node1 **head1,u16 id);
void prin_func(ST_ADD Cpy_Data);
void view_record(void);
void prin1_func(Node1 **head1);
void view_res(void);


            /************** global variable ***************/
u8 choose;
f32 time; 
ST_ADD Data_Input ;
u16 id;

               /********* function main begins program execution ***********/
int main()
{
	/************** local variable ***************/
	u8 choice,choose;
	u16 gender,admin,user,x=0,pass,age;
	
	/******************* Calling of Time Function ************************/
	Tim_func(&head1);
	
    while(1)
    {
		printf(" \n \n  ******************* Welcome to Clinic Management System. ********************  \n\n");
	    printf(" Hello,if you write 'A' ,you are in admin mode. \n");
	    printf("\n And,if you write 'U' ,you are in user mode. \n");
		printf("\n Take care,if you write any letter ,you will be exited from the system. \n");
		printf("\n\nYour Choice is: ");
		scanf(" %c",&choice);
            switch(choice)
		    {
	           case 'A':printf("Please enter password: ");
			            scanf("%d",&pass);
			            for(u8 i=0;i<3;i++)
					    {
			                if (pass !=1234)
						    {
						        if(i<2)
							    {
		                          printf("\n Try again...\n");
								  printf("Enter password again: ");
			                      scanf("%d",&pass);
								}
							    else if(i==2)
								{
								   x=0;  
								   break;
								}
					        } // for if (pass)
					        else 
							{
								x=1;
							    while(1)
							    {   printf("\n-------------------------You are in the admin mode--------------------------------\n");
								    printf("\n Select(1)To Add new patient record.\n");
						            printf(" Select(2)To Edit patient record.\n");
									printf(" Select(3)To Reserve a slot with the doctor.\n");
									printf(" Select(4)To Cancel reservation.\n");
									printf(" Select(5)To return to the first list. \n");
									printf(" Your Select: ");
									scanf("%d",&admin);
								    if(admin==5)
									{ 
								      x=2; 
								      printf("You will return to the first list.\n");
							          break;
									}
								    else
									{
						                switch(admin)
									    {
									        case 1:  
												 /******* Calling Of Add Function *************/
													   Add_Patient();
										
										    break; // for case 1  
                                            case 2:    
											      /******* Calling Of Edit Function *************/
											          Edit_Patient_record();
											break;	
                                            case 3: 
											        printf("\n--------------------------------Reserve a slot with the doctor-------------------------------------------\n\n");
											        printf(" The Slots are...");
										 /******* Calling Of Book Function *************/
											        show_func(&head1);
													printf("\nPlease Enter The Patient ID: ");
													scanf("%d",&id);		
												    printf("Choose a suitable time: ");
													scanf("%f",&time);
										 /******* Calling Of Reserve Function *************/
													Reser_func(&head1,id,time);
											break;
                                            case 4:
											        printf("Please Enter The Patient ID: ");
													scanf("%d",&id);
													if(chckid_func(&head1,id)== 1)
													{
														 /******* Calling Of Cancel Function *************/
											             cancel_func(&head1,id);
													}
													else
													{
														printf("Invalid ID..");
													} 
											break;											
									    }  // for switch(op) 
								    }  // for else
								} break; //  for while(1)		
					        }       // for else
					    }      // for for loop
			   break;     // for case'A'
			    case 'U':
                    printf("\n---------------------------You are in the user mode-----------------------------------\n");
			        printf("\n[1]To select View patient record.\n[2]To View todays reservations.\n");
					printf("Your select: ");
					scanf("%d",&user);
					switch(user)
				    {
									        case 1:  
												 /******* Calling Of View_record function *************/
													 view_record();  
										    break; // for case 1  
                                            case 2:    
											     /******* Calling Of  *************/
											          view_res(); 
											break;	
					}
			    break; 	
			   default:        break;
		    }  // for switch(choice)
	    if (x==0)
	    {
			 printf("The system closed. \n");
			 break;
        }
    } // for while(1)after int main 
		
} // for int main
				
 /*************************** Implementation Of Add Function ****************************/
	
	
	    /****************************  Add_Patient  function    *********************************/
void Add_Patient(void)
{                                                                 
                printf("\n------------------------------------Add new patient record-----------------------------------------\n");
                printf("Please Enter Name: ");
				scanf("%s",&Data_Input.name);                                                        
                printf("Please Enter Age: ");
                scanf("%d",&Data_Input.age);                                                               
                printf("Please Enter Gender [M or F]: ");
                scanf(" %c",&Data_Input.gender);                                                            
                printf("Please Enter ID: ");
                scanf("%d",&Data_Input.id);                                                                


                if(search(Data_Input))
				{                                                               
                    printf("\nExisted ID!!\n");
                    printf("Entry has been rejected!!\n "); 
                }
                else
				{                                                                                                                                                                   
                    AddLast(Data_Input);                                                                 
                    printf("\nSucessful\n");
                    printf("Patient Data has been saved.\n\n");
	
	
				}			
}				


	 /****************************  search for id  function    *********************************/

u8 search(ST_ADD Cpy_Data)
{
    Node *ptr = head;                                                                                       
    while(ptr != NULL)
	{                                                                                       
        if(ptr->Data.id == Cpy_Data.id)
		{                                                                 
            return 1;                                                                                    
        }
        ptr= ptr->Next;                                                                                     
    }

        return 0;      
                                                                                 
}







	 /****************************  AddLast function to add another patient    *********************************/

void AddLast(ST_ADD Cpy_Data)
{   
		if(head != NULL)
		{                                                                                      
			Node * last = (Node *) malloc(sizeof(Node));                                                        
			Node * ptr = head;                                                                               
				while(ptr -> Next != NULL)
				{                                                                         
					ptr = ptr -> Next;                                                                             
				}
			last->Data = Cpy_Data;                                                                           
			last->Next = NULL;                                                                                  
			ptr->Next = last;                                                                                   
		}
			else
			{
				Node *ptr = (Node *) malloc(sizeof(Node));                                                              
                ptr->Data = Cpy_Data;                                                                                
                ptr->Next = head;                                                                                       
                head = ptr;                                                                             
			}
}



	 /****************************  Edit_record function to edit patient record    *********************************/

void Edit_Patient_record(void)
{
    printf("\n-------------------------------------------------Edit Patient record-------------------------------------------------\n\n");
		printf("Please Enter The Patient ID: \n");
        scanf("%d",&Data_Input.id);
			if(search(Data_Input))
			{  
				printf("choose the data you want to edit :\n");
				printf("[1] name \n[2] age \n[3] gender :\n");
		        scanf("%d",&choose);
					switch(choose)
							{
								case 1 :
										printf(" new name is :  ") ;
										scanf("%s",&Data_Input.name);                                                        
										printf("\nNew name is edit successfully \n ") ;
										break;
								case 2 :
										printf(" new age is :  ") ;
										scanf("%d",&Data_Input.age);
										printf("\nNew age is edit successfully \n ") ;
										break;
								case 3 :
										printf(" new gender is :  ") ;
										scanf(" %c",&Data_Input.gender);
										printf("\nNew gender is edit successfully \n ") ;
										break;
								default :
										printf(" wrong choice.try again :  ") ;
										scanf("%d",&choose);
							}
								 Edit_List(Data_Input);
			}
			else
			{                                                                                       																																			
				printf("\nThe Patient ID not exist!!\n");

			}				
}

/****************************  Edit_List function to edit patient record    *********************************/
void Edit_List(ST_ADD Cpy_Data)
{
	Node *ptr = head;                                                                                  
	  while(ptr != NULL)
	    {                                                                                     
				if(ptr->Data.id == Cpy_Data.id)
				{   
					ptr->Data = Cpy_Data;			
					break;                                                                                     
				}
				ptr=ptr->Next;                                                                                  
	    }
	
}



  /*******************************   Reservation_function    *********************************/	

void Reser_func(Node1 **head1,u16 id,f32 time)
{	
	Node1 *last1= *head1;
	
	while((last1 != NULL)&&(last1->time != time))
	{
		last1=last1->next;	
	}
	
	if(last1 != NULL)
	{
		last1->id=id;
	}
  printf("\nReservation Done..\n"); 
}




  /*******************************  Time_function    *********************************/
void Tim_func(Node1 **head1)
{
	*head1      =(Node1 *) malloc(sizeof(Node1));
	Node1 *time2=(Node1 *) malloc(sizeof(Node1));
	Node1 *time3=(Node1 *) malloc(sizeof(Node1));
	Node1 *time4=(Node1 *) malloc(sizeof(Node1));
	Node1 *time5=(Node1 *) malloc(sizeof(Node1));
	(*head1)->time=2;
	(*head1)->id=0;
	(*head1)->next=time2;
	time2->time=2.30;
	time2->id=0;
	time2->next=time3;
	time3->time=3;
	time3->id=0;
	time3->next=time4;
	time4->time=4;
	time4->id=0;
	time4->next=time5;
	time5->time=4.30;
	time5->id=0;
	time5->next=NULL;	
}



  /*******************************  Showslots_function    *********************************/
void  show_func(Node1 **head1) 
{
  Node1 *last1= *head1;
  
	while(last1 != NULL)
	{
	   if (last1->id == 0)	
	    {
		  printf("\n %.2f",last1->time);
	    }
	   last1=last1->next;
	}
		
}



/*******************************   Cancelation Function   *********************************/

void cancel_func(Node1 **head1,u16 id)
{
	printf("\n--------------------------------Cancel reservation-------------------------------------------\n\n");
	Node1 *last1=*head1;
	
	while((last1 != NULL)&&(last1->id != id))
	{
		last1=last1->next;
	}
	
	if (last1 != NULL)
	{
		last1->id=0;
	}
	
	else
	{
		printf("Invalid ID..");
	}
	
	
}


/*******************************   Check ID Function   *********************************/

u16 chckid_func(Node1 **head1,u16 id)
{
	Node1 *last1=*head1;
	
	while((last1 != NULL)&&(last1->id != id))
	{
		last1=last1->next;
	}
	
	if (last1 != NULL)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}


/*******************************   View_record Function   *********************************/
 void view_record(void)
{
    printf("Please Enter ID:");	
	scanf("%d",&Data_Input.id);
	
		if(search(Data_Input))
		{                                                               
           prin_func(Data_Input);
		}
		else
		{                                                                                                                                                                                                                                 
			printf("Invalid ID");
		}		
} 


/*******************************   Print Function   *********************************/
void prin_func(ST_ADD Cpy_Data)
{
	if (head != NULL)
	{
		Node *ptr=head;
	    while(ptr != NULL)
		{
		  printf("Name is: %s\n",ptr->Data.name);
		  printf("Age is: %d\n",ptr->Data.age);
		  printf("Gender is: %c\n",ptr->Data.gender);
		  break;
		}
	}
	else
	{
	   printf("There is no patient record..");	
	}
}


/*******************************   View_Res Function   *********************************/
void view_res(void)
{
    printf("Please Enter ID:");	
	scanf("%d",&id);
	
		if(chckid_func(&head1,id)==1)
		{                                                               
           prin1_func(&head1);
		}
		else
		{                                                                                                                                                                                                                                 
			printf("Invalid ID");
		}		
} 

/*******************************   Print1 Function   *********************************/
void prin1_func(Node1 **head1)
{
	if (head1 != NULL)
	{
		Node1 *ptr=*head1;
	    while(ptr != NULL)
		{
		  if(ptr->id != 0)
		    {
			  printf("Reservation is: %f\n",ptr->time);  
			  printf("ID is : %d \n",ptr->id);
		    }
		  ptr=ptr->next;
		}
	}
	else
	{
	   printf("There is no patient rec..");	
	}
}





