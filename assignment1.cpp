#include <iostream>
using namespace std;

#define ARRSIZE 50
int datastore[ARRSIZE] = {};

// Feel free to add any useful variables that you might need
int ID = -1;
int size=0;
//int stores[ARRSIZE] = {};
//int storesize[ARRSIZE] = {};
int address[ARRSIZE] = {};
int capacity[ARRSIZE] = {};

// Question 1
int newstore(int ssize)
{
    // provide your implementation
    ID++;
    /*
    for (int i=0; i<ssize; i++) {
        if(size+1>50) return -1;
        datastore[size+i] = 0;
    
    }
    */
    //stores[ID] = ssize + size;
    address[ID] = size;
    capacity[ID] = ssize;
    //cout << "this is store number "; cout << ID; cout << " and it contains "; cout << datastore[stores[ID-ssize]];
    size += ssize;

    return ID;

}

// Question 2
int add_element_to_store(int id, int val, int idx=-1)
{
    // provide your implementation
    if (idx != -1) {
        if (idx < capacity[id]) {
            datastore[address[id]+idx]=val;
            cout << datastore[address[id]+idx];
        }
        else {
            return -1;
        }
    }
    else {
        idx = 0;
        while (datastore[address[id]+idx] != 0) {
            idx++;
        }
        if (idx < capacity[id]) {
            datastore[address[id]+idx] = val;
        }
        else {
            return -1;
        }
    }
    return 0;
}

// Question 3
void print_debug()
{
    // provide your implementation
    cout << "available elements in datastore: "; cout << 50-size; cout << endl;
    cout << endl;
    cout << "datastore: "; 
    for(int i=0; i<50; i++){
        cout << datastore[i]; cout << " ";
    }
    cout << endl;
    cout << endl;
    
    
    int h=0;
    int i = address[h];
    if (ID!=-1){
        do {
            
            cout << "Store "; cout << h; cout << ": ";
            for(int j=0; j<capacity[h]; j++){
                cout << datastore[i+j]; cout << " ";
            }
            h++; 
            //cout << " H is : "; cout << h; 
            i = address[h];
            cout << endl;
            cout << endl;
        } while(i!=0);
    }
    
    cout << "###########################"; cout << endl;
    cout << endl;

    
}

// Question 4
void delete_element_from_store_by_value(int id, int val)
{
    for(int i=0; i<capacity[id]; i++) {
        if(datastore[address[id]+i] == val) {
            datastore[address[id]+i] = 0;
            break;
        }
        
    }

    // provide your implementation
}

void delete_element_from_store_by_index(int id, int idx)
{
    if (idx < capacity[id]) {
        datastore[address[id]+idx] = 0;
    }
    // provide your implementation
}

// Question 5
void which_stores_have_element(int val)
{
    // provide your implementation
    
    
    int id=0;
    int count=0;
    do {
        
        for(int i=0; i<capacity[id]; i++) {
            if(datastore[address[id]+i] == val) {
                if(count==0){
                    cout << "Element "; cout << val; cout << " is in store IDs: "; cout << id;                   
                    count++;
                }
                else {
                    cout << ", "; cout << id;
                }
                break;
            }
        }
        
        id++;
        
    } while (address[id]!=0);
    if(count==0) {
            cout << "Element "; cout << val; cout << " is not available in any store."; 
        }
    cout << endl;
    cout << endl;
}

// Question 6
void delete_store(int id)
{
    // provide your implementation
    size = size - capacity[id];
    int i=id;
    int j=id;
    int k=id;
    int h=0;
    while(address[id] + h + capacity[id]<50){
        datastore[address[id]+h] = datastore[address[id]+ h + capacity[id]];
        h++;
    }
    do {
        capacity[i] = capacity[i+1];
        i++;
    }while(capacity[i]!=0);
    
    do {
        j++;
        address[j] = address[j-1] + capacity[j-1];
        
    } while(address[j+1]!=0);
    
}

// Question 7
int resize_store(int id, int newsize)
{
    // provide your implementation
    int available = 50 - size;
 
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
    print_debug();
    
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