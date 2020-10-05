/* non_empty_test.c --- 
 * 
 * 
 * Author: Marguerite Genereux
 * Created: Sat Oct  3 12:08:55 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include "list.h"                                                               
#include <math.h>                                                               
                                                                                
void doublePrice(car_t *cp) {                                                   
  cp->price *= 2;                                                               
}                                                                               
                                                                                
int main(void) {                                                                
                                                                                
  car_t *car0, *car1, *car2;                                                    
                                                                                
  car0=malloc(sizeof(car_t));                                                   
  strcpy(car0->plate,"hello12");                                                
  car0->price = 8000.3;                                                         
  car0->year = 2014;                                                            
  car0->next = NULL;                                                           \
                                                                                
  car1=malloc(sizeof(car_t));                                                   
  strcpy(car1->plate,"hiya34");                                                 
  car1->price = 6000.3;                                                         
  car1->year = 2012;                                                            
  car1->next = NULL;                                                            
                                                                                
  car2=malloc(sizeof(car_t));                                                   
  strcpy(car2->plate,"hola67");                                                 
  car2->price = 1234;                                                           
  car2->year = 2016;                                                            
  car1->next = NULL;                                                            
                                                                                
  int num_cars=3;                                                               
  car_t *cars[num_cars];                                                        
  cars[0]=car0;                                                                 
  cars[1]=car1;                                                                 
  cars[2]=car2;                                                                 
                                                                                
  // testing the lput function that places car at front of list                 
  lput(car2);                                                                   
  lput(car1);                                                                   
  if (lput(car0) != 0)                                                          
    printf("FAILURE: lput did not work for nonempty list\n");                   
  else                                                                          
    printf("SUCCESS: lput worked for nonempty list\n");                         
                                                                                
  // testing lget function that returns the first car in list                   
  car_t *cp = lget();                                                           
  if (cp!=car0)                                                                 
    printf("FAILURE: lget did not get the first car in nonempty list\n");       
  else {                                                                        
    printf("SUCCESS: lget returned the first car in nonempty list\n");          
    lput(car0);                                                                 
  }                                                                             
                                                                                
  // testing lapply function that applied function to all cars in list          
  double orig_prices[num_cars];                                                 
  for (int i=0;i<num_cars;i++)  // keeps track of original prices               
    orig_prices[i]=cars[i]->price;                                              
                                                                                
  lapply(&doublePrice);                                                         
                                                                                
  int incorrect=0;                                                              
  for (int j=0;j<num_cars;j++) { // checks each new price for function impact   
    if (fabs(cars[j]->price-(orig_prices[j])*2)>0.000001) {                     
      printf("FAILURE: lapply did not correctly apply function to all cars in nonempty list\n");
      incorrect++;                                                              
    }                                                                           
  }                                                                             
  if (incorrect==0)                                                             
    printf("SUCCESS: lapply correctly applied function all cars in nonempty list\n");
                                                                                
  // testing lremove function that finds, removes, and returns car from front o\
f list                                                                          
  if (lremove(car0->plate)==car0) {                                             
    printf("SUCCESS: lremove found, removed, and returned the first car in nonempty list\n");
    //lput(car0);                                                               
  } else {                                                                      
    printf("FAILURE: lremove did not find, remove, and return first car in nonempty list\n");
  }                                                                             
  // testing lremove function for middle of list                                
  if (lremove(car1->plate)==car1) {                                             
    printf("SUCCESS: lremove found, removed, and returned the middle car in nonempty list\n");
  } else {                                                                      
    printf("FAILURE: lremove did not find, remove, and return middle car in nonempty list\n");
  }                                                                             
                                                                                
  // testing lremove function for end of list                                   
  if (lremove(car2->plate)==car2) {                                             
    printf("SUCCESS: lremove found, removed, and returned the last car in nonempty list\n"); 
  } else {                                                                      
    printf("FAILURE: lremove did not find, remove, and return the last car in nonempty list\n");                  
  }                                                                             
                                                                                
  free(car0);                                                                   
  free(car1);                                                                   
  free(car2);                                                                   
  return 0;
}

