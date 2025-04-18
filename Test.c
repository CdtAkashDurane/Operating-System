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
}

void FCFS(struct ProcessQueue *P,int n){
float Time=0;
float AvgTime=0;
struct Process *p=NULL;
while(P->front!=NULL){
printf("At Time:- %f",Time);
AvgTime=AvgTime+Time;
p=P->front;
printf("\n----------------------------------------------------------\n");
printf("Process ID:- %s\nArrival Time:- %f\nBurst Time:- %f\n",p->PId,p->AT,p->BT);
printf("Wating Time:- %f\n",Time);
printf("\n----------------------------------------------------------\n");
Time=Time+p->BT;
P->front=P->front->Next;
free(p);
}
printf("Average Waiting Time:- %f\n",AvgTime/n);
}

int main(){
char pid[4];
float at;
float  bt;
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
FCFS(&Pro,n);
return 0;
}
/*
Output:-
──(kali㉿kali)-[~/Desktop/Testing Program]
└─$ ./a.out     
Enter The Number Of Process:- 3
----------------------------------------------------------
Enter The Process Id:- P1
Enter The Arrival time:- 0
Enter The Burst Time:- 4
----------------------------------------------------------
----------------------------------------------------------
Enter The Process Id:- P2
Enter The Arrival time:- 0
Enter The Burst Time:- 3
----------------------------------------------------------
----------------------------------------------------------
Enter The Process Id:- P3
Enter The Arrival time:- 0
Enter The Burst Time:- 5
----------------------------------------------------------
At Time:- 0.000000
----------------------------------------------------------
Process ID:- P1
Arrival Time:- 0.000000
Burst Time:- 4.000000
Wating Time:- 0.000000

----------------------------------------------------------
At Time:- 4.000000
----------------------------------------------------------
Process ID:- P2
Arrival Time:- 0.000000
Burst Time:- 3.000000
Wating Time:- 4.000000

----------------------------------------------------------
At Time:- 7.000000
----------------------------------------------------------
Process ID:- P3
Arrival Time:- 0.000000
Burst Time:- 5.000000
Wating Time:- 7.000000

----------------------------------------------------------
Average Waiting Time:- 3.666667
*/
