#include"Cdbll.h"
//constructor
template<class T>
Cdbll<T> ::Cdbll()
{
    first = NULL;
    last = NULL;
    count = 0;
}

//function to destroy all the node
template <class T>
void Cdbll<T>::destroy()
{
    Node <T>* temp;
    if (first == NULL)
    {
        return;
    }
    else
    {
        do
        {
            temp = first;
            last = first->next;
            first = first->next;
            delete temp;
            count--;
        } while (last != first);
    }
    first =NULL;// set first ==NULL
    last = NULL;// last == NULL
    count = 0;
}

//destructor
template<class T>
Cdbll<T> :: ~Cdbll()
{
    destroy();
}

//function to insert at the front 
template< class T>
void Cdbll<T>::insertFront(const T& item)
{   
    if (first == NULL)
    {
        Node<T>* newNode;
        newNode = new Node<T>;// allocate memory
        newNode->value = item;//insert value 
        first = last = newNode;
        newNode->prev = last;
        newNode->next = first;
    }
    else
    {
        Node<T>* newNode1;
        newNode1 = new Node<T>;
        
        newNode1->value = item;
        newNode1->next = first;
        first->prev = newNode1;
        newNode1->prev = last;
        last->next = newNode1;
        first = newNode1; 
    }
    count++;
}

// function to insert at the Back
template <class T>
void Cdbll<T>::insertEnd(const T& item)
{
    if (first == NULL)
    {
        Node<T>* newNode;
        newNode = new Node<T>;
        newNode->value = item;
        first = last = newNode;
        newNode->prev = last;
        newNode->next = first;
        
    }
    else
    {
        Node<T>* newNode1;
        newNode1 = new Node<T>;
        newNode1->value = item;
        newNode1->prev = last;
        last->next = newNode1;
        newNode1->next = first;
        first->prev = newNode1;
        last = newNode1;
    }
    count++;
}

//print function 
template< class T>
void Cdbll<T>::print()
{
    Node<T>* current;
    current = first;
    if (first == NULL)
    {
        cout << " The list is empty" << endl;
    }
    else
    {   cout<<"copy: ";
        do
        {   
            cout  << current->value << " ";
            current = current->next;
        } while (current!=first );
    }
}


//copylist function for operator = equal and copy constructor
template<class T>
void Cdbll<T> ::copylist(const Cdbll<T>& otherlist)
{    
    int count1 ;

    count1 = counterlist();
    if (first != NULL) destroy(); //if the list is nonempty, make it empty
        
    if (otherlist.first == NULL) //otherlist is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    { 
        Node<T>* current;
        Node<T>* currentother;
        first = new Node<T>;
        first->value = otherlist.first->value;
        current = first;
        currentother = otherlist.first;
        currentother = currentother->next;
       // cout<<"first copy"<<first->value<<endl;
       while (currentother != otherlist.first)
       {
           current->next = new Node<T>;
           current->next->value = currentother->value;
           current->next->prev = current;
           current = current->next;
           currentother = currentother->next;
           //cout<<"copied"<<current->value<<endl;
       }
       last = current;
       last->next = first;
       first->prev = last;
       count = otherlist.count;
    }//end else   
}

//  Count function 
template<class T>
int Cdbll<T> ::counterlist()
{
    return count;//return the number of element inside the doubly circular linked list 
}

//client side count function
template<class T>
int Cdbll<T> ::length()
{
  int a =  counterlist(); //function that the client call access to knwow the length of his list
  return a;

}

//copy constructor
template<class T>
Cdbll<T> ::Cdbll(const Cdbll<T>& otherlist)
{
    copylist(otherlist); 
}


//operator= overloading 
template<class T>
void Cdbll<T> :: operator=(const Cdbll<T> & otherlist)
{
   // destroy();
    copylist(otherlist);
}
// function to delete Node
template<class T>
void Cdbll<T> ::deleteItem(const T& item)
{   
    int l= counterlist();//variable to stop the loop if the value is not in the list
    Node<T>* p;
    Node<T>* temp;
    Node<T>* q;
    if (first == NULL)
        return;
    p = new Node <T>;
    p = first;
    q = first;
    while (p->value != item && l!=0)
    {
        if (p->next == first)
        {
            cout << " There is no node with value " << item << " to delete" << endl;
         
        }

        q = p;
        p = p->next;
        l--;
    }// end loop

    if (p->next == first && q == NULL) // check only if one node is available
    {
        first = NULL;
        delete p;
        count--;
        
    }

    if (p == first) //check if delete is assign to the first node
    {   
        p = first;
        first = first->next;
        first->prev = last;
        last->next = first;
        delete p;
    }
    else if (p->next ==first) // check if delete is assign to the last node
    {
        q->next = first;
        first->prev = q;
        last = q;
        delete p;   
    }
    else // check if delete is assign to position s different from the one ellicted above
    {
        q = first;
        temp = p->next;
        q->next = temp;
        temp->prev = q;
        delete p;
    }
    count--;
}

//empty the list;
template<class T>
void Cdbll<T> ::emptylist()
{
    destroy();
}

//function to search for item 
template<class T>
bool Cdbll<T> ::searchItem( T item)
{
    bool found = false;
    Node<T>* current;
    current = first;
    if (current == NULL)
    {
        return false;
    }
    else
    {
        do
        {
            if (current->value == item)
                found = true;
            else
                current = current->next;
        } while (!found && current != first);

        return found;
    }
}

//function to check if the list is NULL
template<class T>
bool Cdbll<T> ::isEmpty()
{
    return(first == NULL);
}


//iterate functions

template<class T>
void Cdbll<T> ::iterateFront()
{
    Node<T>* current;
    current = first;
    do
    {
        if (current == NULL)
            cout << "empty list: I cannot Iterate" << endl;
        else
        {
            cout << current->value << " ";
            current = current->next;
        }
    } while (current != first);
}

template<class T>
void Cdbll<T> ::iterateBack()
{
    Node<T>* current;
    current = last;
    do
    {
        if (current == NULL)
            cout << "empty list: I cannot Iterate" << endl;
        else
        {
            cout << current->value << " ";
            current = current->prev;
        }
    } while (current != last);
}

