#include<stdio.h>
#include<stdlib.h>
int hasharr[100];
struct node{
	int data;
	struct node *next;
}*first = NULL , *second = NULL;

void create1(int arr[], int n)
{
	struct node *t, *last;
	first = (struct node*)malloc(sizeof(struct node));
	first->data = arr[0];
	first->next = NULL;
	last = first;
	for(int i = 1;i< n ;i++)
	{
	   t = (struct node*)malloc(sizeof(struct node));
	   t->data = arr[i];
	   t->next = NULL;
	   last->next = t;
	   last= t;
	}
}
void create2(int arr[], int n)
{
       struct node *t, *last;
       second = (struct node*)malloc(sizeof(struct node));
       second->data = arr[0];
       second->next = NULL;
       last = second;
       for(int i = 1;i< n ;i++)
       {
          t = (struct node*)malloc(sizeof(struct node));
          t->data = arr[i];
          t->next = NULL;
          last->next = t;
          last= t;
       }
}

 void display(struct node * p)
 {
 	if(p==NULL)
 	{
 		return;
 	}
 	else{
 		while(p)
 		{
 			printf("%d " , p->data);
 			p = p->next;
 		}
 	}
 }
 void rdisplay(struct node *p)
 {
 	if(p==NULL)
 	{
 		return;
 	}
 	else{
 		printf("%d ",p->data);
 		rdisplay(p->next);
 	}
 }
 bool check_last_node(struct node *p , int n)
 {

        int x = 1;
 	while(p->next!=NULL){
        x++;
 		p=p->next;
 	}
 	if(n==x)
 	{
 		return true;
 	}

 	return(false);
 }
 int count_nodes(struct node *p)
 {
 	int cnt = 0;
 	while(p)
 	{
 		cnt++;
 		p=p->next;
 	}
 	return(cnt);
 }
 
 int rcount_nodes(struct node* p)
 {
 	if(p==NULL)
 	{
 		return 0;
 	}
 	return rcount_nodes(p->next)+1;
 }

 int add_nodes(struct node *p)
 {
 	int sum =0;
 	while(p)
 	{
 		sum = sum+p->data;
 		p=p->next;

 	}
 	return(sum);
 }

 int radd_nodes(struct node*p)
 {
 	if(p==NULL)
 	{
 		return 0;
 	}

    return radd_nodes(p->next)+p->data;
 }

 int max_element(struct node *p)
 {
 	int max = -9999;

      while(p)
      {
      	if(p->data>max)
      	{
      		max=p->data;
      	}
      	p=p->next;
      }
      return(max);
 }

 int rmax_element(struct node *p)
 {
 	
 	if(p==0)
 	{
 		return (-9999);
 	}

 	int x = rmax_element(p->next);

 	if(x>p->data)
  		return(x);
 	
 	else
 		return (p->data);
 
 }

 void insert(int pos , int x)
 {
 	struct node * p , *t;
 	if(pos==0)
 	{
 		t = (struct node*)malloc(sizeof(struct node));
 		t->data = x;
 		t->next = first;
 		first = t;
 	}
 	else if(pos>0){
 		p=first;
 		for(int i =0;i< pos-1 && p; i++)
 		{
 			p=p->next;
 		}
 		t = (struct node*)malloc(sizeof(struct node));
 		t->data = x;
        t->next = p->next;
        p->next = t;


 	}
 }

 struct node* search(struct node *p , int value)
 {
 	   while(p)
 	   {
 	   	  if(value == p->data)
 	   	  {
 	   	  	return(p);
 	   	  }
 	   }
 	   return NULL;
 }

 int Delete(struct node* p , int index)
 {
      struct node* q;
      int x =-1;
       if(index<1||index>count_nodes(p))
       {
              return -1;
       }

       if(index==1)
       {
          q = first;
          x = q->data;
          first = first->next;
          free(q);
          return x;
       }
       else{
              for(int i =0;i<index-1;i++)
              {
                     q=p;
                     p=p->next;
              }
              if(p)
              {
                 q->next = p->next;
                 x = p->data;
                  free(p);
                 return x;
              }
       }
 }


 bool IsSorted(struct node* p)
 {
       int x = -32421;
       while(p)
       {
              if(x > p->data)
              { 
                   return false;

              }
              x = p->data;
              p= p->next;
       }
       return true;
 }

 void Remduplicates(struct node* p)
 {
       struct node* q = first;
       p= p->next;
       while(p)
       {
              if(q->data!=p->data)
              {
                     q=p;
                     p=p->next;
              }
              else{
              q->next = p->next;
              free(p);
              p=q->next;
               }
       }


 }
void reverse_using_data(struct node * p )
{
       
       struct node *q = p;
       int *arr;
       arr = (int *)malloc(sizeof(int)*count_nodes(first));
       int i =0;
       while(q!=NULL)
       { 
              arr[i] = q->data;
              q=q->next;
              i++;
       }
       i--;
       q=p;
       while(q)
       {
          q->data = arr[i];
          q= q->next;
          i--;
       }
}



void reverse_using_links(struct node* p)
{
       // Concept of Sliding Pointers
       struct node* q  , *r;
       r = NULL;
       q = NULL;
       while(p)
       {
          r = q;
          q = p;
          p=p->next;
          q->next = r;

       }
          first =q;
}

void reverse_using_recursion(struct node*q , struct node *p)
{      

       
      if(p)
      {
         reverse_using_recursion(p, p->next);
         p->next = q;
      }
      else{
          first = q;
      }

}

void concatination(struct node * q , struct node * p)
{
       while(q->next)
      {
         q= q->next;

      }
      q->next = p;
      p = NULL;

}
int main()
{
	int arr1[]={2,4,3,3,3,10};
       int arr2[]={0,5,7,9,9,11};
	int n =6;
	create1(arr1, n);
       create2(arr2, n);
       // display(first);
       printf("\n");
       // display(second);
       
    // rdisplay(first);

    // int index = 6 ;
    // printf("%s", check_last_node(first , index)?"true":"false");

    // printf("%d ", count_nodes(first));
    
    // printf("%d ", rcount_nodes(first));

    // printf("The sum is %d", add_nodes(first));

    // printf("The sum is %d", radd_nodes(first));

    // printf("The max element is %d", max_element(first));

    // printf("The max element is %d", rmax_element(first));

    // printf("The max element is %d", search(first , 8)->data);...........
     
     // insert(2 , 88888);
      // display(first);
  
      // printf("\nThe delete element is %d\n", Delete(first , 6));
      // display(first);

     // if(IsSorted(first))
     //   printf("IT IS SORTED ");
     // else{
     //   printf("IT IS NOT SORTED");
     // }
         // printf("\n\n");
       // Remduplicates(first);
       // display(first);

       //   printf("\n\n");
       // reverse_using_data(first);
       // display(first);

           //    printf("\n\n");
           // reverse_using_links(first);
           // display(first);

           //  printf("\n\n");
           // reverse_using_recursion(NULL , first);
           // display(first);

           // printf("\n\n");
           // concatination(first , second);
           // display(first);

}