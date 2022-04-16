#include <iostream>
using namespace std;

int ID = 0;

// Feel free to add any useful variables that you might need
struct store {
    int id;
    int ssize;
    int *storedata;
    store *next;
};
store *head = nullptr;


int total = 0;

// Question 1
int newstore(int size)
{
    store *s = new (nothrow) store;
    store *curr = head;
    int *data = new int[size];      //initializing the new store
    s->id = ID;
    s->ssize = size;
    s->storedata = data;
    s->next = nullptr;

    curr = head;
    if (curr != nullptr) {              //if it's not the first store append to the list
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = s;
    }
    else {              //otherwise make it the head
        head = s;
    }
    ID++;
    int x = s->id;
    return x;
}




// Question 2
int add_element_to_store(int idt, int val, int idx=-1)
{
    // provide your implementation
    store *curr = head;
    curr = head;
    while(curr->id != idt) {       //find store
        curr = curr->next;
    }
    
    if(idx==-1) {       //if index not given find the first spot
        idx = 0;
        while ((curr->storedata[idx] != 0 ) && idx<curr->ssize ) {
            idx++;
        }

    }
    if (idx >= curr->ssize) return -1;      //does not work if store is full or index out of bounds
    if (curr->storedata[idx] == 0) total ++;
    curr->storedata[idx] = val;
    
   return 0;
}

// Question 3
void print_debug()
{
    cout << "total used store elements: "; cout << total; cout << endl;
    cout << endl;
    cout << "datastore: "; 
    store *curr = head;
    curr = head;
    while(curr != nullptr) {
        for(int i=0; i<curr->ssize; i++) {
            cout << curr->storedata[i]; cout << " ";
        }
        curr = curr->next;
    }
    cout << endl;
    cout << endl;
    curr = head;
    
    while(curr != nullptr) {
        cout << "store "; cout << curr->id; cout << ": ";
        for(int i=0; i<curr->ssize; i++) {
            
            cout << curr->storedata[i]; cout << " ";
        }
        cout << endl;
        cout << endl;
        curr = curr->next;
        
    }

    cout << endl;
    cout << endl;
    cout << "####################################";
    cout << endl;
    cout << endl;
    
}

// Question 4
void delete_element_from_store_by_value(int idt, int val)
{
    // provide your implementation
    store *curr = head;
    
    while(curr->id != idt) {
        curr = curr->next;
    }
    int x = 0;
    while((curr->storedata[x] != val) && (x<curr->ssize)){ //go through the elements of the store until you find val
        x++;
    }
    if (x<curr->ssize) {
        curr->storedata[x] = 0;
        total--;
    }

}

void delete_element_from_store_by_index(int idt, int idx)
{
    store *curr = head;
    
    while(curr->id != idt) {
        curr = curr->next;
    }
    if (idx<curr->ssize) {      //delete element at index idx
        curr->storedata[idx] = 0;
        total -=1;
    }
}

// Question 5
void which_stores_have_element(int val)
{
    // provide your implementation
    store *curr = head;
   
    int e;
    bool instore = false; //this variable checks if we found the value in a store already
    while(curr != nullptr) {
        for(int i=0; i<curr->ssize; i++) {
            e = curr->storedata[i];
            if(e == val) {
                if (instore == false) {
                    cout << "Element "; 
                    cout << val; 
                    cout << " is in store IDs: ";
                    cout << curr->id;
                    instore = true;
                }
                else {
                    cout << ", "; 
                    cout << curr->id;
                }
                break;
            }
        }
        curr = curr->next;
        
    }
    if (instore == false) {     //if not found
        cout << "Element "; 
        cout << val;
        cout << " is not available in any store";
    }
    cout << endl;
    cout << endl;
    
}

// Question 6
void delete_store(int idt)
{
    // provide your implementation
    store *curr = head;
    store *prev = head;
    while(curr->id != idt) {
        prev = curr;
        curr = curr->next;
    }
    if(prev == head) {  //remove first element and move head
        curr = head->next;
        int x=0;
        for(int i=0; i<prev->ssize; i++) {  //update available items
            if (prev->storedata[i] != 0) x++;
        }
        total -= x;
        
        head = curr;    
        
        delete [] prev->storedata;
        prev->id = -1;
        delete prev;
    }
    else {      //make previous element point to the next after curr
        prev->next = curr->next;
        int x=0;
        for(int i=0; i<curr->ssize; i++) {
            if (curr->storedata[i] != 0) x++;
        }
        total -= x;
        
        delete [] curr->storedata;
        curr->id = -1;
        delete curr;
        
        
    }
    
}

// Question 7
int resize_store(int idt, int newsize)
{ 
store *curr = head;

while((curr->id != idt) && (curr!=nullptr)) {
    curr = curr->next;
}
int *x = new int[newsize];  
for(int i=0; i<curr->ssize; i++) {  //copy in the new array
    x[i] = curr->storedata[i];
}
delete[] curr->storedata;
                                    //update the element 
curr->storedata = x;
curr->ssize = newsize;

return 0;
}


// DO NOT ADD ANY LOGIC TO THE MAIN FUNCTION.
// YOU MAY MODIFY FOR YOUR OWN TESTS ONLY BUT THE ORIGINAL MAIN
// FUNCTION SHOULD BE SUBMITTED AS IS
int main()
{
    int s1 = newstore(3); // create new empty data store of size 3
    int s2 = newstore(5); // create new empty data store of size 5
    
    if (s1 != -1)
    {
        add_element_to_store(s1, 13);       
        add_element_to_store(s1, 15);      
        add_element_to_store(s1, 21);    
        add_element_to_store(s1, 42); // this should return -1
        print_debug(); 
    }
    
    if (s2 != -1)
    {
        add_element_to_store(s2, 7, 2);
        add_element_to_store(s2, 15, 0);
        add_element_to_store(s2, 22, 1);
    }
    print_debug();
    
    delete_element_from_store_by_value(s1, 13);
    delete_element_from_store_by_value(s1, 71);
    delete_element_from_store_by_index(s2, 2);
    delete_element_from_store_by_index(s1, 5);
    
    
    which_stores_have_element(15);
    which_stores_have_element(29);
    
    delete_store(s1);
    print_debug();
    
    resize_store(s2, 20);
    int s3 = newstore(40);
    print_debug();

    s3 = newstore(30);
    add_element_to_store(s3, 7, 29);
    print_debug();
    
}