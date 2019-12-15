/* Given the following directory structure, 
 * write a C++ program that populates a linked list, 
 * each node of which 
 * contains the name of the directory.
 */

//Note: using C++17
//Use: g++ -g -std=c++17 task2.cpp -o task2.exe
#include <iostream>
#include <filesystem>
#include <fstream>


using namespace std;
namespace fs = std::filesystem;

struct Node { 
   string data; 
   struct Node *next; 
};

struct Node* head = NULL; 

void insert(string new_data) { 
   struct Node* new_node = new Node; 
   struct Node* last = head;
   new_node->data = new_data; 
   new_node->next = NULL;

   if (head == NULL) {
     head = new_node;
     return;
   }

   while (last->next != NULL)
     last = last->next;

   last->next = new_node;
} 

void display() { 
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) { 
      cout << ptr->data << " -> "; 
      ptr = ptr->next;
   }
   cout << "NULL";
}

int main() {
  for(auto p : fs::recursive_directory_iterator("test")) {
    string pname = p.path().filename().string();
    insert(pname);
  }
  display();
}
