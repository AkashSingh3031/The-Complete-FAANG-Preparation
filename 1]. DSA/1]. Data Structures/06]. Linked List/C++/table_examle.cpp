#include "table.h"

int main()
{
    // ptr_node phead = LIST_(4,
    //     DATA_TYPE,1,
    //     DATA_TYPE,2,
    //     DATA_TYPE,3,
    //     PTR_TYPE,
    //     (LIST_(2,
    //     DATA_TYPE,12,
    //     PTR_TYPE,(LIST_(2,
    //         DATA_TYPE,3,
    //         DATA_TYPE,4))))
    // );
    ptr_node phead = CONS(1,CONS(CONS(1,CONS(2,NULL)),CONS(3,CONS(3,NULL))));
    displaylist(phead);
    free_cons(&phead);
    if(phead==NULL){
        printf("\nFree successful!!!\n");
    }
    return 0;
}