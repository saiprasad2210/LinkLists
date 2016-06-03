/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: saitanne
 *
 * Created on May 14, 2016, 11:31 AM
 */

#include<stdlib.h>
#include<stdio.h>

using namespace std;
/*
 * Kadanes algo to finf max contig sum
 * Finds max contig sum in array
 */
int max_contig_sum(int *ar, int size) {
    int max_over_all = 0 ;
    int max_till_now = 0 ;
    int i = 0;
    
    for(i=0;i< size; i++) {   
        max_till_now += ar[i];
        if(max_till_now < 0) {
            max_till_now = 0;
        }
        if(max_over_all < max_till_now) {
            max_over_all = max_till_now;
        }
        
    }
    
    return(max_over_all);
}


int max_ones_after_flip(int *a, int n) {
    
    int i, count=0,sum;
    
    // find number of ones in original array
    
    for(i=0; i<n; i++) {
        if(a[i] == 1) {
            count++;
            a[i] = -1;
        } else if (a[i] == 0) {
            a[i] = 1; 
        }
    }
    
    sum = max_contig_sum(a,n);
    
    return(count+sum);
    
}

void swap(int *a, int *b) {
    int tmp;
  
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void printarray(int *a,int n) {
    int i = 0;
    
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
// segregates an array into even/odd
void seg_even_odd(int *a , int n) {
    int right,left,i=0;
    
    right = n-1;
    left  = 0;
    
  while(left < right) {
    while((a[left] % 2 == 0) && left < right) {
        left++;
    }
    
    while((a[right] % 2 == 1) && left < right) {
        right--;
    }
    
    if(left < right) {
        swap(&a[left],&a[right]);
        left++;
        right--;
    }
  }
}

void seg_even_odd_positions(int *a, int n) {
    int odd =1, even =0;
    
    while(odd < n && even < n ) {
        
        while(even < n && (a[even] % 2 ==0)) {
            even = even + 2;
        }
        
        while(odd < n && (a[odd] % 2 == 1)) {
            odd = odd + 2;
        }
        
        if(odd < n && even < n) {
            swap(&a[even], &a[odd]);
            even +=2;
            odd +=2;
        }
    }    
}

int partion(int *a,int lo,int hi) {
    int i=0,piv,j=0;
    i=lo;
    piv = a[hi];
    
    
    for(j=lo;j<=hi-1;j++) {
        if(a[j] <= piv) {
           swap(&a[j],&a[i]);
           i++;
        }
    }
    swap(&a[i],&a[hi]);
    
    return(i);
}

void sub_array_with_given_sum(int *a,int n,int val) {
    int start = 0,sum =0,cur_sum =0,i;
    
    start = 0;
    for(i=0;i < n;) {
        sum += a[i];
        if(sum < val) {
            cur_sum = sum;
            i++;
        } else if (sum > val) {
            cur_sum = cur_sum - a[start];
            sum = cur_sum;
            start++;
        } else {
            while(start <= i) {
                printf("%d ",a[start]);
                start++;
            }
            return;
        }
    }
}

// hash based Implementation o(n) time
void find_pair_with_given_sum(int *a,int n,int sum){
    
    //create a hash with size equals to max element in array.
   int i,max = 150,val=0;
   int hash[max];
   
   for(i=0;i<n;i++)
       hash[i] = -1;
   
   for(i=0;i<n;i++) {
       val = sum - a[i];   
       if(val <= sum) {
          if(hash[a[i]] != -1){
             printf("%d %d",val,a[i]);
             return;
          }     
          hash[val] = a[i];
       }
   }
}

void find_duplicates(int *arr,int size) {
    int hash[10],i,j;
    
    for(i=0; i <= 10;i++) {
        hash[i] = 0;
    }
    
    for(i=0;i<size;i++){
        hash[arr[i]]++;
    }
    
    for(i=0;i<= 10;i++){
        if(hash[i] > 1)
            printf("%d  ", i);
    }    
}

struct Point
{
    int x, y;
};
 
// Returns true if two rectangles (l1, r1) and (l2, r2) overlap
bool doOverlap(Point l1, Point r1, Point l2, Point r2)
{
    // If one rectangle is on left side of other
    if (l1.x > r2.x || l2.x > r1.x)
        return false;
 
    // If one rectangle is above other
    if (l1.y < r2.y || l2.y < r1.y)
        return false;
 
    return true;
}
 
/* Driver program to test above function */
int main()
{
    Point l1 = {0, 10}, r1 = {10, 0};
    Point l2 = {5, 5}, r2 = {15, 0};
    if (doOverlap(l1, r1, l2, r2))
        printf("Rectangles Overlap");
    else
        printf("Rectangles Don't Overlap");
    return 0;
}
/*
 * 
 */

int binary_search(int *arr,int start,int end,int key) {
    
    int mid,i;
    if(start <= end ) {
        mid = (start + end) / 2;
        if(arr[mid] == key)
            return mid;
        if(key < arr[mid]) {
            return binary_search(arr,start,mid-1,key);
        } else {
            return binary_search(arr,mid+1,end,key);
        }
    }  
    return -1;
}


