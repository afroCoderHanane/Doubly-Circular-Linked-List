#include <iostream>
#include "Cdbll.cpp"
#include "Cdbll.h"
using namespace std;
int main() 
{
    Cdbll<int> list;
    Cdbll<int> listcopy;
    //listcopy,listcopy1(list);
    int choice;
    int item;
    cout << "Make your selection using 1..11 or press -1 to quit" << endl;
    cout << "1:  insert an item from the front" << endl;
    cout << "2:  insert an item from the end" << endl;
    cout << "3:  delete an item " << endl;
    cout << "4:  search for an item" << endl;
    cout << "5:  check if the list is empty" << endl;
    cout << "6:  copy the list in another list using = " << endl;
    cout << "7:  Know the length of the list" << endl;
    cout << "8:  Make the list empty" << endl;
    cout << "9:  view the item in your list printer in increasing ordered form" << endl;
    cout <<"10: view the item in your list printer in decreasing ordered form" << endl;
    cout <<"11: view the item in your copied list printer in decreasing ordered form" << endl;
    cout <<"-1: to Quit" << endl;
    cout<<"---------------------------------"<<endl;
    //cout<<"Enter your selection"<<endl;
    //11cin >> choice;

    while (choice!=-1)
    {   
        cout << "What is your selection" << endl;
        cin >> choice;
        switch (choice)
        { 
          case 1:
              cout << "What to insert at the front" << endl;
              cin >> item;
              list.insertFront(item);
              break;
          case 2 :
              cout << "What to insert at the Back?" << endl;
              cin >> item;
              list.insertEnd(item);
              break;
          case 3:
              cout << "What to delete" << endl;
              cin >> item;
              list.deleteItem(item);
              break;
          case 4:
              cout << "What to search for" << endl;
              cin >> item;
              if (list.searchItem(item))
              {
                  cout<<"your item is in the list"<<endl;
              }
              else
              {
                  cout << "Item not present in the list/Empty list" << endl;
              }
              break;
          case 5:
              if (list.isEmpty())
              {
                  cout << "list is EMpty" << endl;
              }
              else 
                  cout<< "List is not empty"<<endl;
              break;
          case 6:
              listcopy = list;
              listcopy.print();
              cout<<endl;
              break;
          case 7:
              cout << "length is: " << list.length()<<endl;
              break;
          case 8:
              list.emptylist();
              break;
          case 9:
              cout << "Iteration towards the front" << endl;
              list.iterateFront();
              cout<<endl;
              break;
          case 10:
               
              cout << "Iteration towards the Back" << endl;
              list.iterateBack();
              cout<<endl;
              break;
          case 11:
               
              cout << "Iteration towards the Back of the copied list" << endl;
              listcopy.iterateBack();
              cout<< endl;
              break;
          case -1:
               exit(0);
               break;
          default:
              cout << "No selection" << endl;
              break;
        }

    }
}