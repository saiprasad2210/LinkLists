#include<stdlib.h>
#include<stdio.h>
 
typedef struct node{
    int data;
    struct node *next;
} Node;
 
Node * mergeSort(Node *a, Node *b){
    Node *result = NULL;
    if(a ==  NULL)
        return b;
    else if(b == NULL)
        return a;

    /* For the first node, we would set the result to either a or b */
      if(a->data <= b->data){
         result = a;
        /* Result's next will point to smaller one in lists 
           starting at a->next  and b */
         result->next = mergeSort(a->next,b);
      }
      else {
        result = b;
       /*Result's next will point to smaller one in lists 
         starting at a and b->next */
        result->next = mergeSort(a,b->next);
      }
      return result;
}

Node * createNode(int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  if(temp){
    temp->data = val;
    temp->next = NULL;
  }
  return temp;
}
/* This function inserts node at the head of linked list */
void push(Node **headRef, int data){
	Node * newNode  = createNode(data);
	newNode->next = *headRef;
	*headRef  = newNode;
}

void printList(Node * head){
    while(head){
        printf("%d->" , head->data );
        head = head->next;
    }

    printf("NULL");
    printf("\n");
}

void reversePrint(Node * head) {
    if(head == NULL)
        return;
    reversePrint(head->next);
    printf("%d->",head->data);
}

Node * reverse(Node *head) {
    Node *cur = NULL;
    Node *nxt = NULL;
    Node *prev = NULL;
    Node *tmp = NULL;
    
   
    if(!head || !head->next) {
       
        return (head);
    }
    
    cur = head;
    nxt = cur->next;
 
    while (cur != NULL) {
      nxt = cur->next;  
      cur->next = prev;
      //nxt->next = cur;
    
      prev = cur;
      cur = nxt;
      
    }
    
    return (prev);
    
}

Node * mergesorted(Node* h1, Node* h2) {
    Node * result=NULL;
    Node * tmp;
    if(h1==NULL) {
        return h2;
    }else if (h2==NULL){
        return h1;
    }
    if(h1->data < h2-> data) {
        result = h1;
        result->next = mergesorted(h1->next,h2);
    } else {
        result = h2;
        result->next = mergesorted(h1,h2->next);        

    }
    return result;
}

Node * mergesorted_iter(Node *h1, Node* h2) {
    Node * h3 = NULL,head;
    
    while(h1!= NULL || h2 != NULL) {
        if(h1->data < h2->data) {
            if(!h3) {
                head = h1;
                h3 = h1;
               
            } else {
                 h3->next = h1;
                 h1 = h1 -> next;
            }
        } else {
            if(!h3) {
                head = h2;
                h3 = h2;
               
            } else {
                 h3->next = h2;
                 h2 = h2->next;
            }
        }
    }
    
    if(h1) {
        h3->next = h1;
    } else if(h2) {
        h3->next = h2;
    }
    
    return(head);
    
}
void rearrange(Node *head) {
    static Node *res = head;
    Node *tmp = NULL;
    
    if(!head || !(head->next)) {
        return;
    }
    
    rearrange(head->next);
    tmp = res->next;
    res->next = head->next;
    head->next->next = tmp;
    //head->next= NULL;
    res = tmp;
}

Node * mergereverse(Node *a, Node *b) {
    Node *res = NULL;
    Node *tmp = NULL;
    
    while(a && b) {
        //add to the front   
        if(a->data < b->data) {
           tmp = a->next;
           a->next = res;
           res = a;
           a= tmp;
            
        } else {
            tmp = b->next;
            b->next = res;
            
            res = b;
            b = tmp;
        }
    }
    
    while(a != NULL) {
        tmp = a->next;
           a->next = res;
           res = a;
           a= tmp;
    }
    
    while(b!= NULL) {
        tmp = b->next;
        b->next = res;
            
        res = b;
        b = tmp;
    }
    
    return res;
}
Node* delete_val(Node* head,int val) {
    Node *curr = head;
    Node *prev = NULL;
    
    while(curr) {
        if(curr->data == val) {
           if(curr == head){
               head = head->next;
               free(curr);
               curr = head;
           } else {
               prev->next = curr->next;
               free(curr);
               curr = prev->next;
           }
        } else {
            prev = curr;
            curr = curr-> next;
        }
        
    }
    
    return(head);
}
 
Node* merge_alternate(Node * a, Node* b) {
    Node * t1 = a;
    Node * t2 = b;
    Node * head = a;
    Node * prev = NULL;
    while(t1 && t2 ) {
        prev = a;
        a= a->next;
        b= b->next;
        t1->next =t2;
        t2->next =a; 
        
        t1 = a;
        t2 = b;
    }
    
    if(!t1 && t2){
        prev->next->next  = t2;
    }
    
    return head;
}


void splitListAlternate(Node * h, Node ** a, Node **b) {
    Node * p1=NULL;
    Node * p2=NULL;
    
    *a = h;
    *b = h->next;
    
    p1=*a;
    p2=*b;
    
    while(p2 && p2->next) {
        p1->next = p2->next;
        p2->next= p2->next->next;
        
        printf("%d<->%d\n",p1->data,p2->data);
             
        p1 = p1->next;
        p2 = p2->next;                
    }
    p1->next = NULL;
}
Node* findNodePrev(Node *h,int x,int * is_head);

Node* findNodePrev(Node *h,int x,int * is_head) {
    Node * a = NULL;
    Node * tmp = NULL ;
    
    
    for(tmp =h;tmp->next!=NULL;tmp = tmp->next) {
        if(h->data == x) {
            a = h;
            *is_head = 1;
            printf ("found node with value %d at Head\n",x);
            return(a);

        } else {
            if(tmp->next ->data == x) {
                a = tmp;
                printf ("found node with value %d\n",x);
                return(a);
            }
        }
    }
    
    
}

Node * swapNodes(Node * h,int x,int y) {
    Node * a;
    Node * b;
    Node * p1;
    Node * p2;
    Node *tmp;
    
    int is_head1 = 0,is_head2 =0;
    p1 = findNodePrev (h,x,&is_head1);
    p2 = findNodePrev (h,y,&is_head2);
    
    
    if(is_head1){
        b = p2->next;
        a = p1;
        
        tmp = a->next;
        a->next = b->next;
        p2->next = a;
        
        b->next =tmp;
        h = b;
        
        
    } else if (is_head2) {
        a = p1->next;
        b = p2;
        
        tmp = b->next;
        b->next = a->next;
        p1->next = b;
        
        a->next =tmp;
        h = a;
    } else {
        a = p1->next;
        b = p2->next;
        
        p1->next = b;
        p2->next = a;
        tmp = a->next;
        
        a->next = b->next;
        b->next = tmp;
    }
return(h); 
}


/* Driver program to run above code */
int main(){
        Node * L1 = NULL;
        Node * L2 = NULL;
        Node * L3 = NULL;
        Node * result = NULL;
        int carry = 0 ;
        /* creating list 1 */
        
        push(&L1,6);
        push(&L1,4);
        push(&L1,3);
        /* creating list 2 */
        push(&L2,12);
        push(&L2,11);
        push(&L2,10);
        push(&L2,8);
        push(&L2,1);
      
        //L1 = mergeSort(L1,L2);
        //L3 = delete_val(L1,6);
        // printList(L1);
        //printList(L2);
        L3 = merge_alternate(L1,L2);
        
        printList(L3);
        result = reverse(L3);
        //rearrange(L3);
        printList(result);
        //reversePrint(L3);
        //result = swapNodes(L3,11,3); 
        
        //printList(result);
        
        //L1= NULL;
        //L2 = NULL;
        //splitListAlternate(L3, &L1, &L2);
        //printList(L1);
        //printList(L2);
        
        
        return 0;
}
