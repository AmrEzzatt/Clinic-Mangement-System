#include <stdio.h>
#include <stdlib.h>

void Add_new_patient ();
void Edit_patient_record();
void Display_Reserved_slot();
void Reservation ();
void cancel_Reservation ();
void View_patient_record();
void user_View_todays_reservations();
void user_Display_Reserved_slot();

typedef struct
{
   int id ;
   char name[10];
   int age;
   int date;
   char gender[5];
}Patient;

Patient patient_list[100]   ;
int time_slot_arr[5] = {0,0,0,0,0};
int i = 0 ;

int main()
{
 int type ,flag ,password,features;
 int program_flag = 1;


  while(program_flag == 1)
  {

     printf ("if you are admin please enter : 1\n");
     printf ("if you are user please  enter : 2\n");
     printf ("Number is : ");
     scanf("%d",&type);
      if(type==1)
      {
         printf("enter you password please : ");
         scanf("%d",&password);
         if(password==1234)
         {
             flag=1;

         }
         else
         {
            for(int i=0;i<2;i++)
            {
              printf("try again : ");
              scanf("%d",&password);
              if(password==1234)
             {
                         flag = 1;
                         break;
             }
            }

        }
        if(flag==1)
        {
            int cont = 1;
            while(cont == 1)
            {
                printf("enter  1 to Add new patient record \n");
                printf("enter  2 to Edit patient record \n");
                printf("enter  3 to Reserve a slot with the doctor \n");
                printf("enter  4 to Cancel reservation \n");
                scanf("%d",&features);
                if (features<5)
                {
                    switch (features)
                    {
                        case 1 :

                           printf("Please enter ID , NAME , AGE , GENDER\n");
                            Add_new_patient ();

                          break ;

                        case 2 :

                            Edit_patient_record();

                          break ;

                        case 3 :

                             Reservation ();

                          break ;

                        case 4 :

                             cancel_Reservation ();

                          break ;

                    }
                }

                printf("if you want to continue press 1 \n");
                printf("if you want to exist press any button \n");
                scanf("%d",&cont);
                printf("\n");
            }

        }
        else
        {
                printf("#wrong password try agian later#");
        }
      }
      else if(type==2)
      {
           int Logout = 1;
            while(Logout == 1)
            {
                View_patient_record();
                printf("if you want to logout press 2 \n");
                printf("if you want to enter id again press 1 \n");
                scanf("%d",&Logout);
                printf("\n");
            }


      }
      else
      {
          printf ("please enter 1 or 2 to login");
      }

    printf("Do you want to login again press: 1 \n");
    printf("if you don't want to exit press any other key\n");
    scanf("%d",&program_flag);
  }


  return 0;

}

 void Add_new_patient ()
{
  Patient p;

  scanf("%d",&p.id);
  for(int i=0;i<101;i++)
  {
	if (p.id==patient_list[i].id)
	{
	    printf("#Error :the id is already reserved#\n");

	  return ;
	}
  }
  scanf("%s",p.name);
  scanf("%d",&p.age);
  scanf("%s",p.gender);

  patient_list[i]=p;
  i++;

}

void Edit_patient_record()
{
	  Patient p;
  printf("enter the id please : ");
  scanf("%d",&p.id);
  for(int i=0;i<101;i++)
  {
	if (p.id==patient_list[i].id)
	{
      printf("then edit NAME , AGE , GENDER\n");
	  scanf("%s",&p.name);
	  scanf("%d",&p.age);
	  scanf("%s",&p.gender);
	  patient_list[i]=p;
      return;
	}
  }
  printf("#you can't edit a new id \n#");
}

void Reservation ()
{
	  int id ,choice;
  printf("enter the id please : ");
  scanf("%d",&id);
  for(int i=0;i<101;i++)
  {
	if (id==patient_list[i].id)
	{

      printf("choose slot please \n");
      Display_Reserved_slot();
      scanf("%d",&choice);
      if(time_slot_arr[choice-1] == 0)
      {
        time_slot_arr[choice-1] = 1;
        // the date is the time slot number
        patient_list[i].date = choice;
      }
      else
      {
        printf("#this slot is already reserved#\n");
      }

      return;
	}
  }
	printf("#this id doesn't exist#\n");
}


void Display_Reserved_slot()
{
    if(time_slot_arr[0] == 0)
    {
        printf("For appointment from 2pm to 2:30pm => choose 1 \n");
    }
        if(time_slot_arr[1] == 0)
    {
        printf("for appointment from 2:30pm to 3pm => choose 2 \n");
    }
        if(time_slot_arr[2] == 0)
    {
        printf("for appointment from 3pm to 3:30pm => choose 3 \n");
    }
        if(time_slot_arr[3] == 0)
    {
        printf("for appointment from 3:30pm to 4pm => choose 4 \n");
    }
        if(time_slot_arr[4] == 0)
    {
        printf("for appointment from 4pm to 4:30pm => choose 5 \n");
    }
}

void cancel_Reservation ()
{
    	  int id ,choice;
  printf("enter the id please : ");
  scanf("%d",&id);
  for(int i=0;i<101;i++)
  {
	if (id==patient_list[i].id)
	{

      choice = patient_list[i].date;
      time_slot_arr[choice-1] = 0;
      patient_list[i].date = 0;
      return;
	}
  }
}

void View_patient_record()
{
    	  Patient p;
  printf("enter your id please : ");
  scanf("%d",&p.id);
    for(int i=0;i<100;i++)
  {
	if (p.id==patient_list[i].id)
	{
   printf("patient id is : %d \n", i);
      printf("patient name is : %s \n", patient_list[i].name);
      printf("patient age is : %d \n" ,patient_list[i].age);
      printf("patient gender is : %s \n", patient_list[i].gender);
      user_Display_Reserved_slot(i);
      return;
	}
  }
  printf("you haven't registered your data before \n");

}

void user_Display_Reserved_slot(int i)
{
    if( patient_list[i].date == 1)
    {
        printf("your appointment is from 2pm to 2:30pm  \n");
    }
        if(patient_list[i].date == 2)
    {
        printf("your appointment is from2:30pm to 3pm  \n");
    }
        if(patient_list[i].date == 3)
    {
        printf("your appointment is from 3pm to 3:30pm \n");
    }
        if(patient_list[i].date == 4)
    {
        printf("your appointment is from 3:30pm to 4pm  \n");
    }
        if(patient_list[i].date == 5)
    {
        printf("your appointment is from 4pm to 4:30pm \n");
    }
}
