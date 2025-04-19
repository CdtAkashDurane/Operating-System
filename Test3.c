#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Newnode (struct Process *)malloc(sizeof(struct Process))

struct Process{
char PId[4];
float AT;
float BT;
struct Process *Next;
};

struct ProcessQueue{
struct Process *front;
struct Process *rear;
};

void AddInProcessQueue(struct ProcessQueue *P,char pid[4],float at,float bt){
struct Process *temp=Newnode;
strcpy(temp->PId,pid);
temp->AT=at;
temp->BT=bt;
temp->Next=NULL;
if(P->front==NULL){
P->front=temp;
P->rear=temp;
return;
}
P->rear->Next=temp;
P->rear=temp;
P->rear->Next=P->front;
}

void RR(struct ProcessQueue *P,int TimeSlice){
struct Process *p=NULL;
struct Process *temp=NULL;
do{
printf("Process Id:- %s,Burst Time:- %f,Status:- Running\n",P->front->PId,P->front->BT);
if(P->front->BT>TimeSlice){
P->front->BT=P->front->BT-TimeSlice;
p=P->front;
P->front=P->front->Next;
}
else if(P->front->BT<=TimeSlice){
if(p!=P->front){
temp=P->front;
P->front=P->front->Next;
p->Next=P->front;
free(temp);
}
else return;
}
}
while(P->front!=NULL);
}

int main(){
char pid[4];
float at;
float  bt;
int TimeSlice;
int n;
struct ProcessQueue Pro;
Pro.front=NULL;
Pro.rear=NULL;
printf("Enter The Number Of Process:- ");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("----------------------------------------------------------\n");
printf("Enter The Process Id:- ");
scanf("%s",pid);
printf("Enter The Arrival time:- ");
scanf("%f",&at);
printf("Enter The Burst Time:- ");
scanf("%f",&bt);
printf("----------------------------------------------------------\n");
AddInProcessQueue(&Pro,pid,at,bt);
}
printf("----------------------------------------------------------\n");
printf("Enter The Time Quantum Or Time Slice:- ");
scanf("%d",&TimeSlice);
printf("----------------------------------------------------------\n");
RR(&Pro,TimeSlice);
return 0;
}
/*
Output:-
┌──(kali㉿kali)-[~/Desktop/Testing Program]
└─$ ./a.out                                  
Enter The Number Of Process:- 3
----------------------------------------------------------
Enter The Process Id:- P1
Enter The Arrival time:- 0
Enter The Burst Time:- 5
----------------------------------------------------------
----------------------------------------------------------
Enter The Process Id:- P2
Enter The Arrival time:- 0
Enter The Burst Time:- 8
----------------------------------------------------------
----------------------------------------------------------
Enter The Process Id:- P3
Enter The Arrival time:- 0
Enter The Burst Time:- 2
----------------------------------------------------------
----------------------------------------------------------
Enter The Time Quantum Or Time Slice:- 4
----------------------------------------------------------
Process Id:- P1,Burst Time:- 5.000000,Status:- Running
Process Id:- P2,Burst Time:- 8.000000,Status:- Running
Process Id:- P3,Burst Time:- 2.000000,Status:- Running
Process Id:- P1,Burst Time:- 1.000000,Status:- Running
Process Id:- P2,Burst Time:- 4.000000,Status:- Running
*/
