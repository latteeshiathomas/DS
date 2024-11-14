#include <stdio.h>
#include <stdlib.h>

struct node {
struct node *rep;
struct node *next; 
int data; 
};
struct node *heads[50], *tails[50]; 
static int countRoot = 0; 

void makeSet(int x) {

struct node *newNode = (struct node *)malloc(sizeof(struct node));
newNode->rep = newNode; 
newNode->next = NULL; 
newNode->data = x; 
heads[countRoot] = newNode; 
tails[countRoot++] = newNode; 
}

struct node* find(int a) {
for (int i = 0; i < countRoot; i++) { 
struct node *tmp = heads[i]; 
while (tmp) { 
if (tmp->data == a) 
return tmp->rep; 
tmp = tmp->next; 
}
}
return NULL; 
}

void unionSets(int a, int b) {
struct node *rep1 = find(a); // Find representative of the first set
struct node *rep2 = find(b); // Find representative of the second set
// If either element is not in the set, return
if (rep1 == NULL || rep2 == NULL) {
printf("\nElement not present in the DS\n");
return;
}
// If they are in different sets, merge them
if (rep1 != rep2) {
struct node *temp = rep2;
while (temp) {
temp->rep = rep1; // Update representative to rep1 for all nodes in set with rep2
temp = temp->next;
}
// Find the index of the set containing rep2
int index = -1;
for (int i = 0; i < countRoot; i++) {
if (heads[i] == rep2) { // Directly compare heads to find rep2
index = i;
break;
}
}
// If the set containing rep2 was found, merge it with the set of rep1
if (index != -1) {
for (int i = 0; i < countRoot; i++) {
if (heads[i] == rep1) { // Find the set containing rep1
tails[i]->next = rep2; // Link the second set (rep2) to the first set (rep1)
tails[i] = tails[index]; // Update the tail to the tail of the merged set
break;
}
}
// Remove the second set from the heads and tails arrays
for (int i = index; i < countRoot - 1; i++) {
heads[i] = heads[i + 1];
tails[i] = tails[i + 1];
}
countRoot--; // Decrease the set count after merging
}
} else {
printf("\nElements are already in the same set\n");
}
}
// Function to check if an element x exists in any set
int search(int x) {
for (int i = 0; i < countRoot; i++) { // Loop through all sets
struct node *tmp = heads[i];
while (tmp) { // Traverse the set
if (tmp->data == x) // If the element is found
return 1;
tmp = tmp->next; // Move to the next node
}
}
return 0; // Return 0 if not found
}
// Main function
int main() {
int choice, x, y;

printf("Disjoint Set Operations Using Linked Lists\n");
do {
// Display menu options
printf("\n.......MENU.......\n");
printf("1. Make Set\n");
printf("2. Display Set Representatives\n");
printf("3. Union\n");
printf("4. Find Set\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice); // Get user choice
switch (choice) {
case 1: // Make a new set
printf("\nEnter new element: ");
scanf("%d", &x); // Input new element
if (search(x))
printf("\nElement already present in the disjoint set DS\n");
else
makeSet(x); // Create new set
break;
case 2: // Display representatives
printf("\nRepresentatives of the sets: ");
for (int i = 0; i < countRoot; i++)
printf("%d ", heads[i]->data); // Print each representative
printf("\n");
break;
case 3: // Union of two sets
printf("\nEnter first element: ");
scanf("%d", &x);
printf("\nEnter second element: ");
scanf("%d", &y);
unionSets(x, y); // Perform union operation
break;
case 4: // Find representative of an element
printf("\nEnter the element: ");
scanf("%d", &x);
struct node *rep = find(x); // Find representative
if (rep == NULL)
printf("\nElement not present in the DS\n");
else
// Print representative
printf("\nThe representative of %d is %d\n", x, rep->data);
break;
case 5: // Exit
exit(0);
default:
printf("\nWrong choice\n");
break;
}
} while (1); // Keep looping until exit
}
