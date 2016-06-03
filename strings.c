/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: saitanne
 *
 * Created on May 22, 2016, 8:19 PM
 */

#include <stdio.h>
#include <string.h>

strncmp_cust(char *src, char *dest, int n){
    while(n--) {
        if(*src != *dest )
            return(*src - *dest);
        else {
            src++;
            dest++;
        }
    }
}

char* my_strncpy (char* dst_str, const char* src_str, int length) {
  if (src_str) { 
      int i = 0; 
      int src_length = strlen(src_str); 
      int n = (length < src_length)? length : src_length; 
     for (i = 0; i < n; i++) 
     { 
         dst_str[i] = src_str[i]; 
     } 
     if (n < length) {
       //fill with the null char until length 
       for (i = n; i < length; i++) 
            dst_str[i] = '\0'; 
     } else {
         dst_str[i] = '\0';
     }
  }
  return dst_str;
}

//converts string to int
int my_atoi(char *s) {
    int n=0,i=0;
    
    while(*s != '\0') {
        if(n==0) {
            n = (int) *s - '0';
        } else {
            n = n*10 + ((int) *s - '0');
        }
        
        s++;
    }
    
    return (n);
}


int is_ana_palindrome(char *s) {
    
    int sum =0,i=0,t;
    int hash[256];
    
    for(i=0; i< 256; i++){
        hash[i] = 0;
    }
    
    while(*s != '\0') {
        t = (int) *s;
        
        if(hash[t] == 0)
            hash[t]++;
        else 
            hash[t]--;
        
        s++;
    }
     
     
      for(i=0; i< 256; i++){
        sum = sum + hash[i];
      }
    return (sum <= 1);
}
/*
 * 
 */
int main(int argc, char** argv) {

    char *str = "aacbb$$%%";
    int i;

    printf("palindrome is %d", is_ana_palindrome(str));
    return 0;
}

