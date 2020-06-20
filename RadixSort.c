#include<stdio.h>
#include<stdlib.h>
struct Rad{
    int data;
    struct Rad *next;
};
void Insert(struct Rad **p,int data){
    struct Rad *node=(struct Rad *)malloc(sizeof(struct Rad));
    node->data=data;
    node->next=NULL;
    if(*p==NULL)
        *p=node;
    else{
        struct Rad *t=*p;
        while(t->next!=NULL)
            t=t->next;
        t->next=node;
    }
}
int Delete(struct Rad **p){
    int key;
    struct Rad *temp=*p;
    *p=temp->next;
    key=temp->data;
    free(temp);
    return key;
}
void Display(int A[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
}
int findMax(int A[],int n){
    int i,max=A[0];
    for(i=1;i<n;i++)
        if(A[i]>max)
            max=A[i];
    return max;
}
int num_digits(int val){
    int ans=0;
    while(val!=0){
        ans+=1;
        val=val/10;
    }
    return ans;
}
void RadixSort(int A[],int n){
    int max,sumd,p=0,i,j,k=1,val;
    max=findMax(A,n);
    sumd=num_digits(max);
    struct Rad **aux=(struct Rad **)calloc(10,sizeof(struct Rad));
    while(p<sumd){
        for(i=0;i<n;i++){
            val=(A[i]/k)%10;
            Insert(&aux[val],A[i]);
        }
        i=j=0;
        while(j<10){
            while(aux[j]!=NULL)
                A[i++]=Delete(&aux[j]);
            j+=1;
        }
        k*=10;
        p+=1;
    }
    free(aux);
}
int main(){
    int A[]={9,8,7,6,5,4,3,2,1,-999};
    int n=sizeof(A)/sizeof(int);
    RadixSort(A,n);
    Display(A,n);
    return 0;
}
