#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 3

typedef struct tnode {
    char* name;
    char* defn;
    struct tnode* next;
} TreeNode;

typedef TreeNode* TreePtr;
// FYI: Can also be written as:
// 'typedef struct tnode* TreePtr;'

static TreePtr hashtab[HASH_SIZE];  // hashtable
// FYI: Can also be written as:
// 'static struct tnode* hashtab[HASH_SIZE];'

void triverseTable() {
    struct tnode* np;
    int index = 0;

    for (np = hashtab[index]; np != NULL; np = np->next) {
        printf("%s -> %s\n", np->name, np->defn);
    }
}

TreePtr findDef(const char* name) {
    TreePtr np;
    for (int i = 0; i < HASH_SIZE && hashtab[i] != NULL; i++) {
        for (np = hashtab[i]; np != NULL; np = np->next) {
            if (strcmp(name, np->name) == 0) {
                return np;
            }
        }
    }
    return NULL;
}

void printTreeNode(void* data) {
    TreePtr np = (TreePtr)data;
    if (np->name == NULL || np->defn == NULL) {
        return;
    }
    printf("%s -> %s\n", np->name, np->defn);
}

int main(int argc, char* argv[]) {
    // Setting all pointers to equal NULL
    for (int i = 0; i < HASH_SIZE; i++) {
        hashtab[i] = NULL;
    }

    TreePtr h1 = malloc(sizeof(TreeNode));
    h1->name = "HASH_SIZE";
    h1->defn = "3";
    h1->next = NULL;
    hashtab[0] = h1;

    TreePtr h2 = malloc(sizeof(TreeNode));
    h1->next = h2;
    h2->name = "IN";
    h2->defn = "1";
    h2->next = NULL;

    TreePtr h3 = malloc(sizeof(TreeNode));
    h2->next = h3;
    h3->name = "OUT";
    h3->defn = "45";
    h3->next = NULL;

    triverseTable();  // prints out linked list of at the 0th index
    // printTreeNode(findDef("IN"));
    free(h1);
    free(h2);

    return 0;
}
