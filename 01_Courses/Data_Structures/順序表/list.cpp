#include<stdio.h>
#include<stdlib.h>
struct nodelist
{
	int data;
	struct nodelist *next;
	struct nodelist *prev;
};
int main()
{
	nodelist *head=NULL;
	nodelist *tail=head;
	nodelist *pre=head;
	nodelist *p=NULL;
	int num;
	
	printf("input the num");
	scanf("%d",&num);
	while(num!=-1)
	{
		p=(nodelist *)malloc(sizeof(nodelist));
		p->data=num;
		tail->next=p;
		tail=p;
		p->next=pre;
		pre=p;
		scanf("%d",&num);
	}
	
	
	return 0;
}
