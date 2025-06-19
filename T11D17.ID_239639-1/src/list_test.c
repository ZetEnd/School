#include "list.h"

#include <stdio.h>

int test_add_door() {
    struct door test_door1 = {1, 0};

    struct node* list = init(&test_door1);
    if (list == NULL) {
        printf("Error: init failed\n");
        return FAIL;
    }

    if (list->door_data.id != 1 || list->door_data.status != 0 || list->next != NULL) {
        printf("Error: init returned incorrect node\n");
        destroy(list);
        return FAIL;
    }

    struct door test_door2 = {2, 1};
    struct node* added_node = add_door(list, &test_door2);
    if (added_node == NULL) {
        printf("Error: add_door failed\n");
        destroy(list);
        return FAIL;
    }

    if (list->next != added_node || added_node->door_data.id != 2 || added_node->door_data.status != 1 ||
        added_node->next != NULL) {
        printf("Error: add_door incorrect insertion\n");
        destroy(list);
        return FAIL;
    }

    destroy(list);
    return SUCCESS;
}

int test_remove_door() {
    struct door test_door1 = {1, 0};
    struct door test_door2 = {2, 1};

    struct node* list = init(&test_door1);
    if (list == NULL) {
        printf("Error: init failed\n");
        return FAIL;
    }

    struct node* added_node = add_door(list, &test_door2);
    if (added_node == NULL) {
        printf("Error: add_door failed\n");
        destroy(list);
        return FAIL;
    }

    list = remove_door(added_node, list);
    if (list == NULL) {
        printf("Error: remove_door failed (list became NULL)\n");
        return FAIL;
    }

    if (list->next != NULL) {
        printf("Error: remove_door did not delete the node\n");
        destroy(list);
        return FAIL;
    }

    if (list->door_data.id != 1 || list->door_data.status != 0) {
        printf("Error: remove_door corrupted the list\n");
        destroy(list);
        return FAIL;
    }

    destroy(list);
    return SUCCESS;
}

int main() {
    printf("add_door %s\n", test_add_door() == SUCCESS ? "SUCCESS" : "FAIL");
    printf("remove_door %s\n", test_remove_door() == SUCCESS ? "SUCCESS" : "FAIL");
    return 0;
}