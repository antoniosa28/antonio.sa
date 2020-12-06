int list_erase_even(List *li){

    if(li == NULL || li->size == 0){
        return -1;
    }

    dlnode *node;
    int cont = 0;

    while(cont != li->size){ // pq dois while??
        node = li->begin;
        cont = 0;
        while(cont != li->size){ // pq dois while??
            if((node->data)%2 == 0){
                list_erase(li,cont+1);
                break;
            }
            cont++;
            node = node->next;
        }
    }
    return 0;
}

ex b) os desenhos estão errados