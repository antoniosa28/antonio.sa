
// Correção!
// código não está de acordo com o .h do TAD passado
int splice(*List dest,*List source,int pos){

DlNode *begin_source,*end_source,*current;
current = *dest;

for(int n=0;n!=pos-1;n++){
	current= *current.next;
}

DlNode back_node = *current.prev;

	back_node.next = *source;
DlNode last_element_source = *source;
	last_element_source.prev = *back_node;

while(last_element_source.next != null){

	last_element_source= last_element.next;
}

last_element_source.next = *current;
current_prev = *last_element;

}