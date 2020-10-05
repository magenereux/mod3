/* list.c --- 
 * 
 * 
 * Author: Marguerite Genereux
 * Created: Fri Oct  2 00:08:33 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include <stdint.h>             
#include <string.h>
#include "list.h"

#define MAXREG 10
static car_t *front=NULL;

/* put(): place a car at the beginning of the list
 * returns 0 if successful; nonzero otherwise
 */       
int32_t lput(car_t *cp) {
  if (cp==NULL)
    return -1;
  cp->next=front;
  front=cp;
  return 0;
}

/* get(): remove and return the first car in the list;
 * return NULL if the list is empty
 */                 
car_t *lget() {
  if (front==NULL)
    return NULL;
  car_t *p=front;
  front=front->next;
  return p;                                
}

/* apply a function to every car in the list */
void lapply(void (*fn)(car_t *cp)) {
  car_t *p;
  for (p=front;p!=NULL;p=p->next)
    fn(p);
}

/* remove(): find, remove, and return any car with
* the designated plate; return NULL if not present
 */
car_t *lremove(char *platep) {
  if (front==NULL)
    return NULL;
  car_t *p;
  car_t *f=front;
  for (p=front;p!=NULL;p=p->next) {
    if (strcmp(p->plate,platep)==0) {
      f->next=p->next;
      return p;
    }
		f=p;
  }
  return NULL;
}
