#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    char* name;
    struct TreeNode* children;
    int numChildren;
};

struct TreeNode* createTreeNode(char* name) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->name = name;
    node->children = NULL;
    node->numChildren = 0;
    return node;
}

void addChildNode(struct TreeNode* parent, struct TreeNode* child) {
    parent->numChildren++;
    parent->children = (struct TreeNode*)realloc(parent->children, parent->numChildren * sizeof(struct TreeNode));
    parent->children[parent->numChildren - 1] = *child;
}

int main() {
    char cityName[100];
    printf("Enter the city name: ");
    fgets(cityName, sizeof(cityName), stdin);
    cityName[strcspn(cityName, "\n")] = '\0';
    
    int numSuburbs;
    printf("Enter the number of suburbs: ");
    scanf("%d", &numSuburbs);
    getchar(); 
    
    struct TreeNode* cityNode = createTreeNode(cityName);
    
    for (int i = 0; i < numSuburbs; i++) {
        char suburbName[100];
        printf("Enter the name of suburb %d: ", i + 1);
        fgets(suburbName, sizeof(suburbName), stdin);
        suburbName[strcspn(suburbName, "\n")] = '\0'; 
        
        int numTowns;
        printf("Enter the number of towns in suburb %d: ", i + 1);
        scanf("%d", &numTowns);
        getchar(); 
        
        struct TreeNode* suburbNode = createTreeNode(suburbName);
        
        for (int j = 0; j < numTowns; j++) {
            char townName[100];
            printf("Enter the name of town %d in suburb %d: ", j + 1, i + 1);
            fgets(townName, sizeof(townName), stdin);
            townName[strcspn(townName, "\n")] = '\0'; 
            
            int numCorporations;
            printf("Enter the number of corporations in town %d, suburb %d: ", j + 1, i + 1);
            scanf("%d", &numCorporations);
            getchar(); 
            
            struct TreeNode* townNode = createTreeNode(townName);
            
            for (int k = 0; k < numCorporations; k++) {
                char corporationCode[100];
                printf("Enter the code for corporation %d in town %d, suburb %d: ", k + 1, j + 1, i + 1);
                fgets(corporationCode, sizeof(corporationCode), stdin);
                corporationCode[strcspn(corporationCode, "\n")] = '\0';  
                
                struct TreeNode* corporationNode = createTreeNode(corporationCode);
                addChildNode(townNode, corporationNode);
            }
            
            addChildNode(suburbNode, townNode);
        }
        
        addChildNode(cityNode, suburbNode);
    }
    
    int numCodes;
    printf("Enter the number of corporation codes: ");
    scanf("%d", &numCodes);
    getchar(); 
    
    char** corporationCodes = (char**)malloc(numCodes * sizeof(char*));
    for (int i = 0; i < numCodes; i++) {
        corporationCodes[i] = (char*)malloc(100 * sizeof(char));
        printf("Enter corporation code %d: ", i + 1);
        fgets(corporationCodes[i], 100, stdin);
        corporationCodes[i][strcspn(corporationCodes[i], "\n")] = '\0'; 
    }
    
    
    
    return 0;
}