/************************************************
   
   Following is the linkedList class structure:

   class List {
    public:
        int data;
        List *next;
        List() {};
        List(int v){
            data = v;
            next = NULL;
        };
   };

*************************************************/

/*
    Time Complexity : O( N )
    Space Complexity : O( 1 )
    
    where 'N' are the number of nodes in LinkedList.
*/

int findCaptian(List *head) {

   // If 'HEAD->NEXT' is 'NULL' return 'HEAD->DATA'.
   if(!head->next) {
      return head->data;
   }

   // Creating two pointer 'SLOW' and 'FAST' pointer.
   List *slow = head , *fast = head->next;

   // Iterating over 'FAST' twice than 'SLOW'.
   while(fast != NULL) {
      fast = fast->next->next;
      slow = slow->next;
   }

   // Return 'SLOW->DATA'.
   return slow->data;
}
