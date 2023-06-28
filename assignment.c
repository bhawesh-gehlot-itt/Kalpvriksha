#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node {
    char name[50];
    struct Node* children;
    int num_children;
} Node;


Node* createNode(char* name, int num_children) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->num_children = num_children;
    newNode->children = NULL;
    if (num_children > 0) {
        newNode->children = (Node*)malloc(num_children * sizeof(Node));
    }
    return newNode;
}


Node* buildTree() {
    char city[50];
    printf("Enter the city: ");
    scanf("%s", city);
    
    int num_suburbs;
    printf("Enter the number of suburbs: ");
    scanf("%d", &num_suburbs);
    
    Node* cityNode = createNode(city, num_suburbs);
    for (int i = 0; i < num_suburbs; i++) {
        char suburb[50];
        printf("Enter the name of suburb %d: ", i + 1);
        scanf("%s", suburb);
        
        int num_towns;
        printf("Enter the number of towns in %s: ", suburb);
        scanf("%d", &num_towns);
        
        Node* suburbNode = createNode(suburb, num_towns);
        for (int j = 0; j < num_towns; j++) {
            char town[50];
            printf("Enter the name of town %d in %s: ", j + 1, suburb);
            scanf("%s", town);
            
            int num_corporations;
            printf("Enter the number of corporations in %s: ", town);
            scanf("%d", &num_corporations);
            
            Node* townNode = createNode(town, num_corporations);
            for (int k = 0; k < num_corporations; k++) {
                char corporation[50];
                printf("Enter the name of corporation %d in %s: ", k + 1, town);
                scanf("%s", corporation);
                
                Node* corporationNode = createNode(corporation, 0);
                townNode->children[k] = *corporationNode;
            }
            
            suburbNode->children[j] = *townNode;
        }
        
        cityNode->children[i] = *suburbNode;
    }
    
    return cityNode;
}

Node* findCommonParent(Node* root, char* corporation1, char* corporation2) {
    if (root == NULL || strcmp(root->name, corporation1) == 0 || strcmp(root->name, corporation2) == 0) {
        return root;
    }
    
    Node* commonParent = NULL;
    
    for (int i = 0; i < root->num_children; i++) {
        Node* child = &(root->children[i]);
        Node* found = findCommonParent(child, corporation1, corporation2);
        
        if (found != NULL) {
            if (commonParent == NULL) {
                commonParent = found;
            } else {
                return root;
            }
        }
    }
    
    return commonParent;
}

void printPath(Node* node) {
    if (node == NULL) {
        return;
    }
    
    printPath((node - 1)->children);
    printf("%s, ", node->name);
}

int main() {
    Node* cityNode = buildTree();
    
    char corporation1[50], corporation2[50];
    printf("Enter the first corporation: ");
    scanf("%s", corporation1);
    printf("Enter the second corporation: ");
    scanf("%s", corporation2);
    
    Node* commonParent = findCommonParent(cityNode, corporation1, corporation2);
    
    printf("Nearest common parent: ");
    printPath(commonParent);
    printf("\n");
    
    return 0;
}
