
#include<stdio.h>
#include<malloc.h>
int n,s;
struct T{
	int x;
	struct T*next;
}*head,*tail;
void creatlist(){
	head=NULL;
	tail=NULL;
    int c=1;
	for(int i=1;i<=n;i++){
		struct T*p=(struct T*)malloc(sizeof(struct T));
		p->x=i;
		if(head==NULL){
			head=p;
		}
		else{
			tail->next=p;
		}
		tail=p;
	} 
	tail->next=head;
	struct T*move=head;
	struct T*h=NULL;
	while(move->next!=move){
		for(int i=2;i<=s;i++){
			h=move;
			move=move->next;
		}        
		if(c!=n-1)
		{
		//printf("%8d 1 ",move->x);  
        	
		}
        else
        {
      //  printf("%8d 2",move->x);  
		
		}
		h->next=move->next;
        move=move->next;
        c++;
	
	}
	printf("%d",move->x);
} 
 
int main()
{
    scanf("%d %d",&n,&s);	
	creatlist();
	return 0;
}

