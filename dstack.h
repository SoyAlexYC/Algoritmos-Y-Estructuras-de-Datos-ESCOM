#ifndef _DSTACK
   #define _DSTACK

      typedef int element; 

      typedef struct nodeDS{
         element e;
         struct nodeDS *next;
      } NodeDS;

      int isEmptyDS(NodeDS *ds);
      void createDS(NodeDS **ds);
      void push(NodeDS **ds,element ele);
      element pop (NodeDS **ds);
      void deleteDS(NodeDS **ds);
      void printDS(NodeDS *ds);
	  void replaceDS(NodeDS **ds, element nuevo, element viejo);
   
   #include "dstack.c"
#endif   



