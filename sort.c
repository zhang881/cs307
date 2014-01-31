#include <stdio.h>
#include <string.h>
#include "list.h"
#include "sort.h"
/*
 * Compares n1 and n2 based on the words stored in nodes.
 * Return -1 if word in n1 less than word in n2
 * Return  0 if word in n1 is equal to word in n2
 * Return  1 if word in n1 is greater than  word in n2
 */

/*struct lnode {
  char* keyword;
  int lineNum;
  int wordCount;
  struct lnode* next;
};*/


int wordCmp (struct lnode* n1, struct lnode* n2) {
  /* FILL IN HERE */
  if(strcmp(nodeGetWord(n1), nodeGetWord(n2)) > 0)
  {
    return 1;
  }
  else if(strcmp(nodeGetWord(n1), nodeGetWord(n2)) == 0)
  {
    return 0;
  }
  else if(strcmp(nodeGetWord(n1), nodeGetWord(n2)) < 0)
  {
    return -1;
  }
}
/*
 * Compares n1 and n2 based on the lines stored in nodes.
 * Return -1 if line in n1 less than line in n2
 * Return  0 if line in n1 is equal to line in n2
 * Return  1 if line in n1 is greater than  line in n2
 */
int lineCmp (struct lnode* n1, struct lnode* n2) {
  /* FILL IN HERE */
  if(nodeGetLine(n1) < nodeGetLine(n2))
  {
    return -1;
  }
  else if(nodeGetLine(n1) == nodeGetLine(n2))
  {
    return wordCmp(n1, n2);
  }
  else if(nodeGetLine(n1) > nodeGetLine(n2))
  {
    return 1;
  }
}
/*
 * Compares n1 and n2 based on the counts stored in nodes.
 * Return -1 if count in n1 less than count in n2
 * Return  0 if count in n1 is equal to count in n2
 * Return  1 if count in n1 is greater than  count in n2
 */
int countCmp (struct lnode* n1, struct lnode* n2) {
  /* FILL IN HERE */
  if(nodeGetCount(n1) < nodeGetCount(n2))
  {
    return -1;
  }
  else if(nodeGetCount(n1) == nodeGetCount(n2))
  {
    return wordCmp(n1, n2);
  }
  else if(nodeGetCount(n1) > nodeGetCount(n2))
  {
    return 1;
  }
}
/*
 * Swap nodes n1 and n2 in the linked list. For eg, if the
 * list looks like: -- n1 -- n2 -- , then after swapping n1
 * with n2, it should look like this: -- n2 -- n1 --.
 * head is the pointer to the head pointer of the linked list.
 */
void swap (struct lnode** head, struct lnode* n1, struct lnode* n2) {
  struct lnode* temp = *head;
  if(head != NULL && n1 != NULL && n2 != NULL)
  {
    if(strcmp(nodeGetWord(n1), nodeGetWord(n2)) == 0)
    {
      return;
    }
    if (n1 != n2)
    {
      if(nodeGetNext(n1) == n2)
      {
        evictNode(head, n1);
        insertNode(head, n2, n1);
      }
      else if(nodeGetNext(n2) == n1)
      {
        evictNode(head, n2);
        insertNode(head, n1, n2);
      }
      else
      {
        struct lnode* prevn1 = nodeGetPrev(temp, n1);
        struct lnode* prevn2 = nodeGetPrev(temp, n2);
        evictNode(head, n1);
        evictNode(head, n2);
        insertNode(head, prevn1, n2);
        insertNode(head, prevn2, n1);
      }
    }
  }
}
/*
 * Sorts the linked list whose head is (*head).
 * Based on this description, complete the function signature of sort
 */
void sortByWord (struct lnode** head) {
  struct lnode* temp = *head;
  int flag = 0;

  while(nodeGetNext(temp) != NULL)
  {
    if (wordCmp(temp, nodeGetNext(temp)) == 1)
    {
      swap(head, temp, nodeGetNext(temp));
      flag++;
    }
    else
    {
      temp = nodeGetNext(temp);
    }
    if(flag == 0)
    {
      continue;
    }
    else
    {
      flag = 0;
      temp = *head;
    }
  }
}
void sortByCount (struct lnode** head) {
  struct lnode* temp = *head;
  int flag = 0;

  while(nodeGetNext(temp) != NULL)
  {
    if (countCmp(temp, nodeGetNext(temp)) == 1)
    {
      swap(head, temp, nodeGetNext(temp));
      flag++;
    }
    else
    {
      temp = nodeGetNext(temp);
    }
    if(flag == 0)
    {
      continue;
    }
    else
    {
      flag = 0;
      temp = *head;
    }
  }
}
void sortByLine (struct lnode** head) {
  struct lnode* temp = *head;
  int flag = 0;

  while(nodeGetNext(temp) != NULL)
  {
    if (lineCmp(temp, nodeGetNext(temp)) == 1)
    {
      swap(head, temp, nodeGetNext(temp));
      flag++;
    }
    else
    {
      temp = nodeGetNext(temp);
    }
    if(flag == 0)
    {
      continue;
    }
    else
    {
      flag = 0;
      temp = *head;
    }
  }
}


