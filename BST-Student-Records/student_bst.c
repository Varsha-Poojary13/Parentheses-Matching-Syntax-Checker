#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    float cgpa;
    struct Student *left;
    struct Student *right;
};

struct Student *root = NULL;

struct Student* createNode(int roll, char name[], float cgpa)
{
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));

    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->cgpa = cgpa;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Student* insert(struct Student *root, int roll, char name[], float cgpa)
{
    if(root == NULL)
        return createNode(roll, name, cgpa);

    if(roll < root->roll)
        root->left = insert(root->left, roll, name, cgpa);

    else if(roll > root->roll)
        root->right = insert(root->right, roll, name, cgpa);

    return root;
}

void search(struct Student *root, int roll)
{
    if(root == NULL)
    {
        printf("Student not found\n");
        return;
    }

    if(root->roll == roll)
    {
        printf("\nStudent Found\n");
        printf("Roll: %d\n", root->roll);
        printf("Name: %s\n", root->name);
        printf("CGPA: %.2f\n", root->cgpa);
    }
    else if(roll < root->roll)
        search(root->left, roll);
    else
        search(root->right, roll);
}

struct Student* findMin(struct Student *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}

struct Student* deleteNode(struct Student *root, int roll)
{
    if(root == NULL)
        return root;

    if(roll < root->roll)
        root->left = deleteNode(root->left, roll);

    else if(roll > root->roll)
        root->right = deleteNode(root->right, roll);

    else
    {
        if(root->left == NULL)
        {
            struct Student *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            struct Student *temp = root->left;
            free(root);
            return temp;
        }

        struct Student *temp = findMin(root->right);

        root->roll = temp->roll;
        strcpy(root->name, temp->name);
        root->cgpa = temp->cgpa;

        root->right = deleteNode(root->right, temp->roll);
    }

    return root;
}

void inorder(struct Student *root)
{
    if(root != NULL)
    {
        inorder(root->left);

        printf("Roll: %d  Name: %s  CGPA: %.2f\n",
               root->roll, root->name, root->cgpa);

        inorder(root->right);
    }
}

int main()
{
    int choice, roll;
    char name[50];
    float cgpa;

    while(1)
    {
        printf("\n--- Student Record Management (BST) ---\n");
        printf("1. Insert Student\n");
        printf("2. Search Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Records (Sorted)\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll);

                printf("Enter Name: ");
                scanf("%s", name);

                printf("Enter CGPA: ");
                scanf("%f", &cgpa);

                root = insert(root, roll, name, cgpa);
                break;

            case 2:
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll);
                search(root, roll);
                break;

            case 3:
                printf("Enter Roll Number to delete: ");
                scanf("%d", &roll);
                root = deleteNode(root, roll);
                break;

            case 4:
                printf("\nStudent Records (Ascending Order):\n");
                inorder(root);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
