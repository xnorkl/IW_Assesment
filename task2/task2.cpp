/* Given the following directory structure, 
 * write a C++ program that populates a linked list, 
 * each node of which 
 * contains the name of the directory.
 */

struct node {
	auto data;
	node *next;
};

class list {
Private:
	node *head, *tail;
	public:
	list() {
		head=NULL;
		tail=NULL;
	}
};


:
