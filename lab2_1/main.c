#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXSTACKSIZE 10

// structure of a stack node
typedef struct Node {
    char par;
    struct Node* next;
} Node;

// a global node pointer variable, pointing to the top of the stack
Node *top = NULL;

// === functions === 
// --> conditions
static bool areBracketsBalanced(const char pars[]);
static bool isClosedBrackets();
// --> linked list
static void push(const char par);
static void pop();

// Driver code
int main()
{
	// prompts user for input parentheses array
	char pars[100] = {0};
	printf("Enter an parenthese string: ");
	scanf("%s", pars);

	// if input is larger than the stack, print Overflow, otherwise check if balanced
	if(strlen(pars) > MAXSTACKSIZE) {
		printf("Stack Overflow");
		return 0;
	}
	else
	{
		if (areBracketsBalanced(pars)) 
			printf("Balanced!");
		else
			printf("Not Balanced!");
	}

	return 0;
}

// adds element to top of stack, return bool true if the operation was successful
static void push(const char par) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->par = par; // save parenthesis to data slot
	if (top == NULL) // if no previous nodes exist
	{
		newNode->next = NULL; // make next node the null node
		top = newNode; // make the top node the new node
	}
	else // if previous nodes exist
	{ 
		newNode->next = top; // make new node, i.e. node_1 point to second node
		top = newNode; // make the top node the new node
		// top->(node1->next)->(node2->next) = NULL
	}
}

// remove the first element, return bool true if the operation was successful
static void pop() {
	if (top->next->next != NULL)
	{
		Node *third = top->next->next;
		free(top->next);
		free(top);
		top = third;
	}
	else
	{
		free(top->next);
		free(top);
		top = NULL;
	}
	
}

// checks if top two nodes in stack close, if so, return true
static bool isClosedBrackets() {
	if (top->par == ')' && top->next->par == '(') {
		return true;
	} else 
	if (top->par == ']' && top->next->par == '[') {
		return true;
	} else 
	if (top->par == '}' && top->next->par == '{') {
		return true;
	}
	return false; 
}

// inputs char array, checks if it is balanced, returns true if so
static bool areBracketsBalanced(const char pars[]) {

	unsigned short int i = 0;
	char currCh = pars[i];
	bool checkClosedBrackets;
	Node *ptr = NULL;
	
	while (currCh) {

		if (currCh == '{')
		{
			// if any other char than '{' is encountered previous to current char,
			// return false
			ptr = top;
			for(int j = 0; ptr != NULL; j++) {
				if(!(ptr->par == '{')) { 
					return false;
				}
				ptr = ptr->next;
			}
		}
		
		// if any other char than '{' && '[' is encountered previous to current char,
		// return false
		if (currCh == '[')
		{
			ptr = top;
			for(int j = 0; ptr != NULL; j++) {
				if(!(ptr->par == '{' || ptr->par == '[')) {
					return false;
				}
				ptr = ptr->next;
			}
		}

		// if any other char than '{', '[' and '(' is encountered previous to current char,
		// return false
		if (currCh == '(')
		{
			ptr = top;
			for(int j = 0; ptr != NULL; j++) {
				if(!(ptr->par == '{' || ptr->par == '[' || ptr->par == '(')) {
					return false;
				}
				ptr = ptr->next;
			}
		}
		
		// push current char to top of stack
		push(currCh);

		// if there is more than two nodes in a row, check whether you can pop them
		if (top != NULL && top->next != NULL) { 
			checkClosedBrackets = isClosedBrackets();
			if (checkClosedBrackets)
			{
				pop();
			}

			if(!checkClosedBrackets && !(currCh != '{' ||  currCh != '[' || currCh != '(')) {
				return false; // means brackets didn't pop and its not beginning bracket, must be false
			}
		}
				
		i++;
		currCh = pars[i];
	}

	// an expression is balanced when we have popped all characters, if some stay unpopped, return false 
	// say ((), has leftover '(' and thus top is not NULL
	if (!(top == NULL))
	{
		return false;
	}
	
	return true;
}