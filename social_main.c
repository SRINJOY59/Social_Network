#include "social.h"

/**
 * Adds an individual to the linked list of individuals in the social network.
 * This function takes an Individual structure pointer as input and incorporates it into the individualList.
 * If the list is empty, a new IndividualList node is created, pointing to the given individual.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the individual.
 * individual: Pointer to the Individual structure to be added to the network.
 */

int individualCount = 0; // Global variable to count total number of individuals in this network
int businessCount = 0;   // Global variable to count total number of businesses in this network
int groupCount = 0;      // Global variable to count total number of groups in this network
int orgCount = 0;        // Global variable to count total number of organisations in this network
int id = 1;              ////Global variable to create id of each node

// Global pointers to linked lists for each type of node
IndividualList *individualList = NULL;
BusinessList *businessList = NULL;
GroupList *groupList = NULL;
OrgList *orgList = NULL;

void addToIndividualList(Individual *individual)
{
    // Checks if the individualList is currently empty
    if (individualList == NULL)
    {
        // If empty, creates a new IndividualList node
        individualList = (IndividualList *)malloc(sizeof(IndividualList));
        if (individualList == NULL)
        {
            // Handles memory allocation failure
            return;
        }
        // Sets the individual pointer of the new node to the provided individual
        individualList->individual = individual;
        individualList->next = NULL; // Sets next to NULL as it is the only node
    }
    else
    {
        // If the list is not empty, finds the last node
        IndividualList *current = individualList;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Creates a new IndividualList node at the end and set its individual pointer
        current->next = (IndividualList *)malloc(sizeof(IndividualList));
        if (current->next == NULL)
        {
            // Handles memory allocation failure
            return;
        }
        current->next->individual = individual;
        current->next->next = NULL; // Sets next to NULL as it is the last node
    }
}

/**
 * Adds a business node to the linked list of businesses in the social network.
 * This function takes a business structure pointer as input and incorporates it into the businessList.
 * If the list is empty, a new BusinessList node is created, pointing to the given business node.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the business node.
 * businessNode: Pointer to the business structure to be added to the network.
 */
void addToBusinessList(business *businessNode)
{
    // Checks if the businessList is currently empty
    if (businessList == NULL)
    {
        // If empty, creates a new BusinessList node
        businessList = (BusinessList *)malloc(sizeof(BusinessList));
        if (businessList == NULL)
        {
            // Handles memory allocation failure
            return;
        }
        // Sets the businessNode pointer of the new node to the provided business node
        businessList->businessNode = businessNode;
        businessList->next = NULL; // Sets next to NULL as it is the only node
    }
    else
    {
        // If the list is not empty, finds the last node
        BusinessList *current = businessList;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Creates a new BusinessList node at the end and set its businessNode pointer
        current->next = (BusinessList *)malloc(sizeof(BusinessList));
        if (current->next == NULL)
        {
            // Handles memory allocation failure
            return;
        }
        current->next->businessNode = businessNode;
        current->next->next = NULL; // Sets next to NULL as it is the last node
    }
}

/**
 * Adds a group node to the linked list of groups in the social network.
 * This function takes a groups structure pointer as input and incorporates it into the groupList.
 * If the list is empty, a new GroupList node is created, pointing to the given group node.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the group node.
 * @param group: Pointer to the groups structure to be added to the network.
 */
void addToGroupList(groups *group)
{
    // Check if the groupList is currently empty
    if (groupList == NULL)
    {
        // If empty, create a new GroupList node
        groupList = (GroupList *)malloc(sizeof(GroupList));
        if (groupList == NULL)
        {
            // Handle memory allocation failure
            return;
        }
        // Set the groupNode pointer of the new node to the provided group node
        groupList->grpNode = group;
        groupList->next = NULL; // Set next to NULL as it is the only node
    }
    else
    {
        // If the list is not empty, find the last node
        GroupList *current = groupList;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Create a new GroupList node at the end and set its groupNode pointer
        current->next = (GroupList *)malloc(sizeof(GroupList));
        if (current->next == NULL)
        {
            // Handle memory allocation failure
            return;
        }
        current->next->grpNode = group;
        current->next->next = NULL; // Set next to NULL as it is the last node
    }
}

/**
 * Adds an organization node to the linked list of organizations in the social network.
 * This function takes an organisations structure pointer as input and incorporates it into the orgList.
 * If the list is empty, a new OrgList node is created, pointing to the given organization node.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the organization node.
 * org: Pointer to the organisations structure to be added to the network.
 */
void addToOrgList(organisations *org)
{
    // Checks if the orgList is currently empty
    if (orgList == NULL)
    {
        // If empty, creates a new OrgList node
        orgList = (OrgList *)malloc(sizeof(OrgList));
        if (orgList == NULL)
        {
            // Handles memory allocation failure
            return;
        }
        // Sets the orgNode pointer of the new node to the provided organization node
        orgList->orgNode = org;
        orgList->next = NULL; // Sets next to NULL as it is the only node
    }
    else
    {
        // If the list is not empty, finds the last node
        OrgList *current = orgList;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Creates a new OrgList node at the end and set its orgNode pointer
        current->next = (OrgList *)malloc(sizeof(OrgList));
        if (current->next == NULL)
        {
            // Handles memory allocation failure
            return;
        }
        current->next->orgNode = org;
        current->next->next = NULL; // Sets next to NULL as it is the last node
    }
}

/**
 * Retrieves the current local time and formats it into a string.
 * The formatted time string is stored in the provided 'creationTime' buffer.
 * creationTime: A character array where the formatted time will be stored.
 */
void get_time(char *creationTime)
{
    time_t t;
    struct tm *timeinfo;

    // Gets current time
    time(&t);
    timeinfo = localtime(&t);

    // Formats the time and store it in 'creationTime'
    strftime(creationTime, 100, "%Y-%m-%d %H:%M:%S", timeinfo);
}

/**
 * Creates a new Name node and adds it to the end of the linked list.
 * The function takes the name, id, and the head of the Name list as parameters.
 * Returns the head of the updated Name list.
 * name: The name to be added to the list.
 * id: The identifier associated with the name.
 * nameNode: The head of the current Name list.
 * returns The updated head of the Name list.
 */
Name *create_Name_node(char *name, int id, Name *nameNode)
{
    Name *temp = nameNode;

    if (nameNode == NULL)
    {
        // If the list is empty, creates a new Name node
        nameNode = (Name *)malloc(sizeof(Name));
        strcpy(nameNode->name, name);
        nameNode->next = NULL;
    }
    else
    {
        // If the list is not empty, finds the last node
        while (nameNode->next != NULL)
        {
            nameNode = nameNode->next;
        }
        // Creates a new Name node at the end and set its properties
        Name *newNode = (Name *)malloc(sizeof(Name));
        strcpy(newNode->name, name); // Copies name into the new node
        newNode->next = NULL;
        newNode->id = id;
        nameNode->next = newNode;
    }

    return temp; // Returns the head of the updated Name list
}

/**
 * Deletes a Name node with the specified id from the linked list.
 * The function takes the id and the head of the Name list as parameters.
 * Returns the head of the updated Name list.
 * id: The identifier of the Name node to be deleted.
 * nameNode: The head of the current Name list.
 * returns The updated head of the Name list.
 */
Name *delete_Name_node(int id, Name *nameNode)
{
    Name *current = nameNode;
    Name *prev = NULL;

    if (current == NULL)
    {
        // If the list is empty, prints a message and return the same head
        printf("List is empty. Nothing to delete.\n");
        return nameNode;
    }

    while (current != NULL && current->id != id)
    {
        // Finds the node to be deleted
        prev = current;
        current = current->next;
    }

    // If the node with the specified id is found
    if (current != NULL)
    {
        // If the node to be deleted is the first node
        if (prev == NULL)
        {
            nameNode = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        free(current); // To free the memory occupied by the node
    }
    return nameNode; // Returns the head of the updated Name list
}

/**
 * Prints the contents of the Name list.
 * The function takes the head of the Name list as a parameter.
 * nameNode: The head of the Name list.
 */
void print_name_list(Name *nameNode)
{
    printf("\n");
    int cnt = 0;
    while (nameNode != NULL)
    {
        // Prints the id and name of each node
        if (cnt != 0)
        {
            printf("Id: %d   Name: %s\n", nameNode->id, nameNode->name);
        }
        cnt++;
        nameNode = nameNode->next;
    }
    printf("\n");
}

/**
 * Creates a new Node with a unique identifier and the provided name.
 * The function allocates memory for the new node and assigns an id.
 * Returns the created Node.
 * name: The name to be assigned to the Node.
 * returns The newly created Node.
 */
Node *create_node(char *name)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    id++;

    strncpy(node->name, name, sizeof(node->name) - 1);
    node->name[sizeof(node->name) - 1] = '\0';

    return node;
}

/**
 * Prints the business connections of an Individual.
 * The function displays the business names and their connection types (Owner/Member).
 * individual: The Individual whose business connections are to be printed.
 */
void print_business_connections(Individual *individual)
{
    printf("\n");
    printf("\nBusiness Connections for %s:\n", individual->name);
    for (int i = 0; i < individual->bCount; i++)
    {
        printf("Business Name: %s\n", individual->businessConnections[i]);
        printf("Connection Type: %s\n", (individual->ownerBusiness[i]) ? "Owner" : "Member");
    }
    printf("\n");
}

/**
 * Prints the group connections of an Individual.
 * The function displays the names of the groups the Individual is connected to.
 * individual: The Individual whose group connections are to be printed.
 */
void print_group_connections(Individual *individual)
{
    printf("\n");
    printf("\nGroup Connections for %s:\n", individual->name);
    for (int i = 0; i < individual->gCount; i++)
    {
        printf("Group Name: %s\n", individual->groupConnections[i]);
    }
    printf("\n");
}

/**
 * Prints the organization connections of an Individual.
 * The function displays the names of the organizations the Individual is connected to.
 * individual: The Individual whose organization connections are to be printed.
 */
void print_organisation_connections(Individual *individual)
{
    printf("\n");
    printf("\nOrganisation Connections for %s:\n", individual->name);
    for (int i = 0; i < individual->oCount; i++)
    {
        printf("Organisation Name: %s\n", individual->orgConnections[i]);
    }
    printf("\n");
}

/**
 * Prints the details of all Individuals in the social network.
 * The function displays individual information, business connections, group connections,
 * and organization connections for each Individual in the list.
 */
void printIndividualList()
{
    printf("Printing Individual List:\n");
    IndividualList *current = individualList;
    while (current != NULL)
    {
        printf("\n=========================\n");
        printf("\n");
        printf("Individual ID: %d, Name: %s, Creation Time: %s",
               current->individual->id,
               current->individual->name,
               current->individual->Creation_time);

        print_business_connections(current->individual);

        print_group_connections(current->individual);

        print_organisation_connections(current->individual);
        current = current->next;
        printf("\n=========================\n");
        printf("\n");
    }
}

/**
 * Prints the group connections associated with a business.
 * The function displays the names of groups connected to the business.
 * @param businessNode: The business node for which group connections are to be printed.
 */
void print_group_connections_business(business *businessNode)
{
    printf("\n");
    printf("\nGroup Connections for  %s:\n", businessNode->name);
    for (int i = 0; i < businessNode->gCount; i++)
    {
        printf("Group Name: %s\n", businessNode->groupConnections[i]);
    }
    printf("\n");
}

/**
 * Prints the details of all businesses in the social network.
 * The function displays business information, associated individuals, and group connections for each business in the list.
 */
void printBusinessList()
{
    printf("Printing Business List:\n");
    BusinessList *current = businessList;
    while (current != NULL)
    {
        printf("\n=========================\n");
        printf("\n");
        printf("Business ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
               current->businessNode->id,
               current->businessNode->name,
               current->businessNode->Creation_time,
               current->businessNode->location);

        printf("Persons associated with this business: \n");
        print_name_list(current->businessNode->individualConnections);

        print_group_connections_business(current->businessNode);
        current = current->next;
        printf("\n=========================\n");
        printf("\n");
    }
}

/**
 * Prints the details of all groups in the social network.
 * The function displays group information, associated individuals, and associated businesses for each group in the list.
 */
void printGroupList()
{
    printf("Printing Group List:\n");
    GroupList *current = groupList;
    while (current != NULL)
    {
        printf("\n=========================\n");
        printf("\n");
        printf("Group ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
               current->grpNode->id,
               current->grpNode->name,
               current->grpNode->Creation_time,
               current->grpNode->location);
        printf("Persons associated with this Group: \n");
        print_name_list(current->grpNode->individualConnections);

        printf("Businesses associated with this Group: \n");
        print_name_list(current->grpNode->businessConnections);
        current = current->next;
        printf("\n=========================\n");
        printf("\n");
    }
}

/**
 * Prints the details of all organizations in the social network.
 * The function displays organization information and associated individuals for each organization in the list.
 */
void printOrgList()
{
    printf("Printing Organisation List:\n");
    OrgList *current = orgList;
    while (current != NULL)
    {
        printf("\n=========================\n");
        printf("\n");
        printf("Organisation ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
               current->orgNode->id,
               current->orgNode->name,
               current->orgNode->Creation_time,
               current->orgNode->location);

        printf("Persons associated with this Organisation: \n");
        print_name_list(current->orgNode->individualConnections);
        current = current->next;
        printf("\n=========================\n");
        printf("\n");
    }
}

/**
 * Deletes a business node from the business list based on the provided ID.
 * Frees the memory occupied by the business node.
 * id: The ID of the business node to be deleted.
 */
void deleteFromBusinessList(int id)
{
    BusinessList *current = businessList;
    BusinessList *prev = NULL;

    while (current != NULL && current->businessNode->id != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        // If Node with the given ID not found
        return;
    }

    if (prev == NULL)
    {
        // The node to be deleted is the first node
        businessList = current->next;
    }
    else
    {
        // The node to be deleted is not the first node
        prev->next = current->next;
    }

    // To free memory occupied by the business node
    free(current->businessNode);
    free(current);
}

/**
 * Deletes an individual node from the individual list based on the provided ID.
 * Frees the memory occupied by the individual node.
 * id: The ID of the individual node to be deleted.
 */
void deleteFromIndividualList(int id)
{
    IndividualList *current = individualList;
    IndividualList *prev = NULL;

    while (current != NULL && current->individual->id != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        // Node with the given ID not found
        return;
    }

    if (prev == NULL)
    {
        // The node to be deleted is the first node
        individualList = current->next;
    }
    else
    {
        // The node to be deleted is not the first node
        prev->next = current->next;
    }

    // To Free memory occupied by the individual node
    free(current->individual);
    free(current);
}

/**
 * Deletes a group node from the group list based on the provided ID.
 * Frees the memory occupied by the group node.
 * id: The ID of the group node to be deleted.
 */
void deleteFromGroupList(int id)
{
    GroupList *current = groupList;
    GroupList *prev = NULL;

    while (current != NULL && current->grpNode->id != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        // Node with the given ID not found
        return;
    }

    if (prev == NULL)
    {
        // The node to be deleted is the first node
        groupList = current->next;
    }
    else
    {
        // The node to be deleted is not the first node
        prev->next = current->next;
    }

    // To free memory occupied by the group node
    free(current->grpNode);
    free(current);
}

/**
 * Deletes an organization node from the organization list based on the provided ID.
 * Frees the memory occupied by the organization node.
 * id: The ID of the organization node to be deleted.
 */
void deleteFromOrgList(int id)
{
    OrgList *current = orgList;
    OrgList *prev = NULL;

    while (current != NULL && current->orgNode->id != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        // Node with the given ID not found
        return;
    }

    if (prev == NULL)
    {
        // The node to be deleted is the first node
        orgList = current->next;
    }
    else
    {
        // The node to be deleted is not the first node
        prev->next = current->next;
    }

    // To free memory occupied by the organization node
    free(current->orgNode);
    free(current);
}

/**
 * Creates an individual node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the individual.
 * @return Returns a pointer to the created individual node.
 */
Individual *create_individual(Node *node, char *creationTime)
{
    Individual *individual = (Individual *)malloc(sizeof(Individual));
    int i = 0;
    for (i = 0; i < strlen(node->name); i++)
    {
        individual->name[i] = node->name[i];
    }
    individual->name[i] = '\0';
    individual->id = node->id;
    i = 0;
    for (i = 0; i < strlen(creationTime); i++)
    {
        individual->Creation_time[i] = creationTime[i];
    }
    individual->Creation_time[i] = '\0';
    individual->allPostsIndividual = NULL;

    // Initialize connection lists
    printf("Enter your birthday in DD/MM/YYYY:  ");
    scanf("%s", individual->birthday);
    char businessConnections[MAX_SIZE][100] = {'\0'};
    char groupConnections[MAX_SIZE][100] = {'\0'};
    char orgConnections[MAX_SIZE][100] = {'\0'};
    int ownerBusiness[MAX_SIZE] = {0};
    individual->bCount = 0;
    individual->gCount = 0;
    individual->oCount = 0;
    return individual;
}

/**
 * Creates a business node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the business.
 * @return Returns a pointer to the created business node.
 */
business *create_business(Node *node, char *creationTime)
{
    business *businessNode = (business *)malloc(sizeof(business));
    strcpy(businessNode->name, node->name);
    businessNode->id = node->id;
    strcpy(businessNode->Creation_time, creationTime);
    businessNode->allPostBusiness = NULL;
    int i = 0;
    businessNode->individualConnections = (Name *)malloc(sizeof(Name));
    for (i = 0; i < strlen(businessNode->name); i++)
    {
        businessNode->individualConnections->name[i] = businessNode->name[i];
    }
    businessNode->individualConnections->name[i] = '\0';
    businessNode->individualConnections->next = NULL;
    printf("Enter the location of the business: ");
    scanf("%s", businessNode->location);

    return businessNode;
}
/**
 * Creates a group node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the group.
 * @return Returns a pointer to the created group node.
 */
groups *create_group(Node *node, char *creationTime)
{
    groups *groupNode = (groups *)malloc(sizeof(groups));
    strcpy(groupNode->name, node->name);
    groupNode->id = node->id;
    strcpy(groupNode->Creation_time, creationTime);
    groupNode->allPostGroup = NULL;

    groupNode->individualConnections = (Name *)malloc(sizeof(Name));
    groupNode->businessConnections = (Name *)malloc(sizeof(Name));
    int i = 0;
    for (i = 0; i < strlen(groupNode->name); i++)
    {
        groupNode->individualConnections->name[i] = groupNode->name[i];
        groupNode->businessConnections->name[i] = groupNode->name[i];
    }

    groupNode->individualConnections->name[i] = '\0';
    groupNode->businessConnections->next = NULL;
    groupNode->individualConnections->next = NULL;
    printf("Enter the location of the group: ");
    scanf("%s", groupNode->location);

    return groupNode;
}

/**
 * Creates an organization node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the organization.
 * @return Returns a pointer to the created organization node.
 */
organisations *create_org(Node *node, char *creationTime)
{
    organisations *orgNode = (organisations *)malloc(sizeof(organisations));
    strcpy(orgNode->name, node->name);
    orgNode->id = node->id;
    strcpy(orgNode->Creation_time, creationTime);
    orgNode->allPostOrganisation = NULL;

    // Initialize connection list
    orgNode->individualConnections = (Name *)malloc(sizeof(Name));
    int i = 0;
    for (i = 0; i < strlen(orgNode->name); i++)
    {
        orgNode->individualConnections->name[i] = orgNode->name[i];
    }
    orgNode->individualConnections->name[i] = '\0';
    orgNode->individualConnections->next = NULL;

    printf("Enter the location of the organization: ");
    scanf("%s", orgNode->location);
    return orgNode;
}

/**
 * Connects businesses to an individual based on user input.
 *
 * This function allows an individual to connect with businesses. It prompts the user
 * to enter the businesses they want to be part of, along with their ownership status.
 * It updates the individual's business connections and counts, and also updates the
 * business's individual connections. The function interacts with the global list of
 * businesses to find matching names.
 *
 * @param individual: The individual to connect businesses to.
 */
void connect_business_to_individual(Individual *individual)
{
    char ch;
    printf("Enter the businesses you want to be part of: \n");
    printf("Do you want to add? (Y|N): ");
    scanf(" %c", &ch);
    while (ch != 'N')
    {
        char businessName[100];
        printf("Enter the business name: ");
        scanf("%99s", businessName);

        int isOwner;
        printf("Are you the owner of the business? (1 for Yes, 0 for No): ");
        scanf("%d", &isOwner);
        int i = 0;
        int flag = 0;
        BusinessList *temp = businessList;
        while (temp != NULL)
        {
            if (strcmp(temp->businessNode->name, businessName) == 0)
            {
                strcpy(individual->businessConnections[individual->bCount], businessName);
                individual->ownerBusiness[individual->bCount] = isOwner;
                individual->bCount++;
                temp->businessNode->individualConnections = create_Name_node(individual->name, individual->id, temp->businessNode->individualConnections);
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (!flag)
        {
            printf("You can not add this business because this is not added to the social network\n");
        }

        printf("Do you want to add more business connections? (Y|N): ");
        scanf(" %c", &ch);
    }
}

/**
 * Connects groups to an individual based on user input.
 *
 * This function allows an individual to connect with groups. It prompts the user
 * to enter the groups they want to be part of. It updates the individual's group
 * connections and counts, and also updates the group's individual connections. The
 * function interacts with the global list of groups to find matching names.
 *
 * @param individual: The individual to connect groups to.
 */
void connect_group_to_individual(Individual *individual)
{
    char ch;
    printf("Enter the groups you want to be part of: \n");
    printf("Do you want to add? (Y|N): ");
    scanf(" %c", &ch);
    while (ch != 'N')
    {
        char groupName[100];
        printf("Enter the group name: ");
        scanf("%99s", groupName);
        int i = 0;
        int flag = 0;
        GroupList *temp = groupList;
        while (temp != NULL)
        {
            if (strcmp(temp->grpNode->name, groupName) == 0)
            {
                strcpy(individual->groupConnections[individual->gCount], groupName);
                individual->gCount++;
                temp->grpNode->individualConnections = create_Name_node(individual->name, individual->id, temp->grpNode->individualConnections);
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (!flag)
        {
            printf("You can not add this group because this is not added to the social network\n");
        }
        printf("Do you want to add more group connections? (Y|N): ");
        scanf(" %c", &ch);
    }
}

/**
 * Connects organizations to an individual based on user input.
 *
 * This function allows an individual to connect with organizations. It prompts the user
 * to enter the organizations they want to be part of. It updates the individual's
 * organization connections and counts, and also updates the organization's individual
 * connections. The function interacts with the global list of organizations to find
 * matching names.
 *
 * @param individual: The individual to connect organizations to.
 */
void connect_org_to_individual(Individual *individual)
{
    char ch;
    printf("Enter the organsiations you want to be part of: \n");
    printf("Do you want to add? (Y|N): ");
    scanf(" %c", &ch);
    while (ch != 'N')
    {
        char orgName[100];
        printf("Enter the organisation name: ");
        scanf("%99s", orgName);

        int i = 0;
        int flag = 0;
        OrgList *temp = orgList;
        while (temp != NULL)
        {
            if (strcmp(temp->orgNode->name, orgName) == 0)
            {
                strcpy(individual->orgConnections[individual->oCount], orgName);
                individual->oCount++;
                temp->orgNode->individualConnections = create_Name_node(individual->name, individual->id, temp->orgNode->individualConnections);
                flag = 1;
                break;
            }
            temp = temp->next;
        }

        if (!flag)
        {
            printf("You can not add this organsiation because this is not added to the social network\n");
        }
        printf("Do you want to add more organsiation connections? (Y|N): ");
        scanf(" %c", &ch);
    }
}

/**
 * Connects groups to a business based on user input.
 *
 * This function allows a business to connect with groups. It prompts the user
 * to enter the groups they want to be part of. It updates the business's group
 * connections and counts, and also updates the group's business connections. The
 * function interacts with the global list of groups to find matching names.
 *
 * @param businessNode: The business to connect groups to.
 */
void connect_business_to_group(business *businessNode)
{
    char ch;
    printf("Enter the groups you want to be part of: \n");
    printf("Do you want to add? (Y|N): ");
    scanf(" %c", &ch);
    while (ch != 'N')
    {
        char groupName[100];
        printf("Enter the group name: ");
        scanf("%99s", groupName);
        int i = 0;
        int flag = 0;
        GroupList *temp = groupList;
        while (temp != NULL)
        {
            if (strcmp(temp->grpNode->name, groupName) == 0)
            {
                strcpy(businessNode->groupConnections[businessNode->gCount], groupName);
                businessNode->gCount++;
                temp->grpNode->businessConnections = create_Name_node(businessNode->name, businessNode->id, temp->grpNode->businessConnections);
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (!flag)
        {
            printf("You can not add this group because this is not added to the social network\n");
        }
        printf("Do you want to add more group connections? (Y|N): ");
        scanf(" %c", &ch);
    }
}

/**
 * Creates a new node and connects it to the social network based on user input.
 *
 * This function prompts the user to provide a name and creates a new node. It then
 * asks the user for the type of account (individual, business, group, or organization),
 * and based on the choice, it creates the corresponding entity and connects it to the
 * social network. The created entities are added to their respective lists, and the
 * counts for individuals, businesses, groups, and organizations are updated.
 *
 * @param name: The name of the node to be created and connected.
 */
void create_node_and_connect(char *name)
{
    Node *node = create_node(name);
    char creationTime[100];
    get_time(creationTime);
    printf("What is the type of your account?\n 1. Individual \n 2. Business \n 3. Group \n 4. Organisation\n");
    int choice;
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;

    if (choice == 1)
    {
        Individual *individual = create_individual(node, creationTime);
        connect_business_to_individual(individual);
        connect_group_to_individual(individual);
        connect_org_to_individual(individual);
        addToIndividualList(individual);
        individualCount++;
    }
    else if (choice == 2)
    {
        business *businessNode = create_business(node, creationTime);
        connect_business_to_group(businessNode);
        addToBusinessList(businessNode);
        businessCount++;
    }
    else if (choice == 3)
    {
        groups *groupNode = create_group(node, creationTime);
        addToGroupList(groupNode);
        groupCount++;
    }
    else
    {
        organisations *orgNode = create_org(node, creationTime);
        orgCount++;
        addToOrgList(orgNode);
    }
    printf("\n");
    printf("%d nodes added in this social network\n\n", individualCount + businessCount + groupCount + orgCount);
}

/**
 * Searches for individuals, businesses, groups, and organizations based on the birthday.
 *
 * This function searches for individuals in the social network whose birthday matches
 * the given input. If found, it prints the details of those individuals. If not found,
 * it prints a message indicating that no one was found.
 *
 * @param birthday: The birthday to search for in the social network.
 */
void searchByBirthday(char *birthday)
{
    IndividualList *current = individualList;
    int count = 0;

    while (current != NULL)
    {
        if (strcmp(current->individual->birthday, birthday) == 0)
        {
            printf("ID: %d\nName: %s\n", current->individual->id, current->individual->name);
            count++;
        }
        current = current->next;
    }

    if (count == 0)
    {
        printf("No one found with the provided birthday!\n");
    }
}

/**
 * Searches for individuals, businesses, groups, and organizations based on the name.
 *
 * This function searches for individuals, businesses, groups, and organizations in the
 * social network whose name matches the given input. If found, it prints the details of
 * those entities. If not found, it prints a message indicating that no one was found.
 *
 * @param name: The name to search for in the social network.
 */
void searchByName(char *name)
{
    // Searching for individuals
    IndividualList *current = individualList;
    int count = 0;

    printf("Individuals with name %s\n", name);
    while (current != NULL)
    {
        if (strcmp(current->individual->name, name) == 0)
        {
            printf("Individual ID: %d, Name: %s, Creation Time: %s\n",
                   current->individual->id,
                   current->individual->name,
                   current->individual->Creation_time);

            print_business_connections(current->individual);
            print_group_connections(current->individual);
            print_organisation_connections(current->individual);

            count++;
        }
        current = current->next;
    }

    if (count == 0)
    {
        printf("Oops!!!! There is no individual with this name\n");
    }

    // Searching for businesses
    count = 0;
    printf("Businesses with name %s\n", name);
    BusinessList *temp1 = businessList;
    while (temp1 != NULL)
    {
        if (strcmp(temp1->businessNode->name, name) == 0)
        {
            printf("Business ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                   temp1->businessNode->id,
                   temp1->businessNode->name,
                   temp1->businessNode->Creation_time,
                   temp1->businessNode->location);

            printf("Persons associated with this business: \n");
            print_name_list(temp1->businessNode->individualConnections);

            print_group_connections_business(temp1->businessNode);
            count++;
        }
        temp1 = temp1->next;
    }

    if (count == 0)
    {
        printf("Oops!!!! There is no business with this name\n");
    }

    // Searching for groups
    count = 0;
    printf("Groups with name %s\n", name);
    GroupList *curr = groupList;
    while (curr != NULL)
    {
        if (strcmp(curr->grpNode->name, name) == 0)
        {
            printf("Group ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                   curr->grpNode->id,
                   curr->grpNode->name,
                   curr->grpNode->Creation_time,
                   curr->grpNode->location);

            printf("Persons associated with this Group: \n");
            print_name_list(curr->grpNode->individualConnections);

            printf("Businesses associated with this Group: \n");
            print_name_list(curr->grpNode->businessConnections);

            count++;
        }
        curr = curr->next;
    }

    if (count == 0)
    {
        printf("Oops!!!! There is no Group with this name\n");
    }

    // Searching for organizations
    count = 0;
    printf("Organisations with name %s\n", name);
    OrgList *temp2 = orgList;
    while (temp2 != NULL)
    {
        if (strcmp(temp2->orgNode->name, name) == 0)
        {
            printf("Organisation ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                   temp2->orgNode->id,
                   temp2->orgNode->name,
                   temp2->orgNode->Creation_time,
                   temp2->orgNode->location);

            printf("Persons associated with this Organisation: \n");
            print_name_list(temp2->orgNode->individualConnections);

            count++;
        }
        temp2 = temp2->next;
    }

    if (count == 0)
    {
        printf("Oops!!!! There is no Organisation with this name\n");
    }
}

/**
 * Checks if a post is present in the given post list.
 *
 * This function traverses the post list and checks if a post with the given content
 * already exists in the list.
 *
 * @param postHead: The head of the post list.
 * @param post: The content of the post to be checked.
 * @return true if the post is present, false otherwise.
 */
bool isPostPresent(postList *postHead, char *post)
{
    postList *current = postHead;
    while (current != NULL)
    {
        if (strcmp(current->post, post) == 0)
        {
            // Post is already present
            return true;
        }
        current = current->next;
    }
    // Post is not present
    return false;
}

/**
 * Adds a post to the individual's post list.
 *
 * This function checks if the post is not already present in the individual's post list.
 * If not present, it creates a new post node, populates it with the given content, and adds
 * it to the individual's post list.
 *
 * @param individual: The individual to whom the post is associated.
 * @param post: The content of the post to be added.
 */
void addPostIndividual(Individual *individual, char *post)
{
    // Checks if the post is not already present
    if (!isPostPresent(individual->allPostsIndividual, post))
    {
        postList *newPost = (postList *)malloc(sizeof(postList));
        if (newPost == NULL)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        strcpy(newPost->post, post);
        newPost->next = individual->allPostsIndividual;
        individual->allPostsIndividual = newPost;
    }
    else
    {
        printf("Post '%s' already present for this individual.\n", post);
    }
}

/**
 * Adds a post to the business's post list.
 *
 * This function checks if the post is not already present in the business's post list.
 * If not present, it creates a new post node, populates it with the given content, and adds
 * it to the business's post list.
 *
 * @param businessNode: The business to which the post is associated.
 * @param post: The content of the post to be added.
 */
void addPostBusiness(business *businessNode, char *post)
{
    // Checks if the post is not already present
    if (!isPostPresent(businessNode->allPostBusiness, post))
    {
        postList *newPost = (postList *)malloc(sizeof(postList));
        if (newPost == NULL)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        strcpy(newPost->post, post);
        newPost->next = businessNode->allPostBusiness;
        businessNode->allPostBusiness = newPost;
    }
    else
    {
        printf("Post '%s' already present for this business.\n", post);
    }
}

/**
 * Adds a post to the group's post list.
 *
 * This function checks if the post is not already present in the group's post list.
 * If not present, it creates a new post node, populates it with the given content, and adds
 * it to the group's post list.
 *
 * @param groupNode: The group to which the post is associated.
 * @param post: The content of the post to be added.
 */
void addPostGroups(groups *groupNode, char *post)
{
    // Checks if the post is not already present
    if (!isPostPresent(groupNode->allPostGroup, post))
    {
        postList *newPost = (postList *)malloc(sizeof(postList));
        if (newPost == NULL)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        strcpy(newPost->post, post);
        newPost->next = groupNode->allPostGroup;
        groupNode->allPostGroup = newPost;
    }
    else
    {
        printf("Post '%s' already present for this group.\n", post);
    }
}

/**
 * Adds a post to the organization's post list.
 *
 * This function checks if the post is not already present in the organization's post list.
 * If not present, it creates a new post node, populates it with the given content, and adds
 * it to the organization's post list.
 *
 * @param orgNode: The organization to which the post is associated.
 * @param post: The content of the post to be added.
 */
void addPostOrganisations(organisations *orgNode, char *post)
{
    // Checks if the post is not already present
    if (!isPostPresent(orgNode->allPostOrganisation, post))
    {
        postList *newPost = (postList *)malloc(sizeof(postList));
        if (newPost == NULL)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        strcpy(newPost->post, post);
        newPost->next = orgNode->allPostOrganisation;
        orgNode->allPostOrganisation = newPost;
    }
    else
    {
        printf("Post '%s' already present for this organization.\n", post);
    }
}

/**
 * Creates a post for an entity (Individual, Business, Group, or Organisation) based on the given ID and type.
 *
 * This function prompts the user to write a post for the entity with the specified ID and type. It then adds
 * the post to the respective entity's post list.
 *
 * @param id: The ID of the entity.
 * @param type: The type of the entity (1 for Individual, 2 for Business, 3 for Group, 4 for Organisation).
 */
void create_post(int id, int type)
{
    printf("================================================================\n");
    printf("\n");
    if (type == 1)
    {
        IndividualList *current = individualList;
        while (current != NULL)
        {
            if (current->individual->id == id)
            {
                printf("Start writing post for ID %d   and  Name %s\n", id, current->individual->name);
                char post[500];
                scanf(" %[^\n]", post);
                addPostIndividual(current->individual, post);
            }
            current = current->next;
        }
    }
    else if (type == 2)
    {
        BusinessList *current = businessList;
        while (current != NULL)
        {
            if (current->businessNode->id == id)
            {
                printf("Start writing post for ID %d   and  Name %s\n", id, current->businessNode->name);
                char post[500];
                scanf(" %[^\n]", post);
                addPostBusiness(current->businessNode, post);
            }
            current = current->next;
        }
    }
    else if (type == 3)
    {
        GroupList *current = groupList;
        while (current != NULL)
        {
            if (current->grpNode->id == id)
            {
                printf("Start writing post for ID %d   and  Name %s\n", id, current->grpNode->name);
                char post[500];
                scanf(" %[^\n]", post);
                addPostGroups(current->grpNode, post);
            }
            current = current->next;
        }
    }
    else
    {
        OrgList *current = orgList;
        while (current != NULL)
        {
            if (current->orgNode->id == id)
            {
                printf("Start writing post for ID %d   and  Name %s\n", id, current->orgNode->name);
                char post[500];
                scanf(" %[^\n]", post);
                addPostOrganisations(current->orgNode, post);
            }
            current = current->next;
        }
    }
    printf("Post created successfully!!!\n");

    printf("\n================================================================\n");
    printf("\n");
}

/**
 * Prints all posts for a specific Individual.
 *
 * This function prints all the posts associated with a specific Individual, including the content
 * of each post.
 */
void printAllPostsIndividual()
{
    printf("================================================================\n");
    printf("\n");
    IndividualList *current = individualList;
    while (current != NULL)
    {
        const postList *currentPost = current->individual->allPostsIndividual;

        printf("\nAll Posts for %s:\n", current->individual->name);

        while (currentPost != NULL)
        {
            printf("%s\n", currentPost->post);
            currentPost = currentPost->next;
            printf("\n");
        }
        current = current->next;
    }
    printf("================================================================\n");
    printf("\n");
}

/**
 * Prints all posts for a specific Business.
 *
 * This function prints all the posts associated with a specific Business, including the content
 * of each post.
 */
void printAllPostsBusiness()
{
    printf("================================================================\n");
    printf("\n");
    BusinessList *current = businessList;
    while (current != NULL)
    {
        const postList *currentPost = current->businessNode->allPostBusiness;

        printf("\nAll Posts for %s:\n", current->businessNode->name);

        while (currentPost != NULL)
        {
            printf("%s\n", currentPost->post);
            currentPost = currentPost->next;
            printf("\n");
        }
        current = current->next;
    }
    printf("================================================================\n");
    printf("\n");
}

/**
 * Prints all posts for a specific Organisation.
 *
 * This function prints all the posts associated with a specific Organisation, including the content
 * of each post.
 */
void printAllPostsOrganisation()
{
    printf("================================================================\n");
    printf("\n");
    OrgList *current = orgList;
    const postList *currentPost = current->orgNode->allPostOrganisation;

    printf("\nAll Posts for %s:\n", current->orgNode->name);

    while (currentPost != NULL)
    {
        printf("%s\n", currentPost->post);
        currentPost = currentPost->next;
        printf("\n");
    }
    printf("================================================================\n");
    printf("\n");
}

/**
 * Prints all posts for a specific Group.
 *
 * This function prints all the posts associated with a specific Group, including the content
 * of each post.
 */
void printAllPostsGroup()
{
    printf("================================================================\n");
    printf("\n");
    GroupList *current = groupList;
    const postList *currentPost = current->grpNode->allPostGroup;

    printf("\nAll Posts for %s:\n", current->grpNode->name);

    while (currentPost != NULL)
    {
        printf("%s\n", currentPost->post);
        currentPost = currentPost->next;
        printf("\n");
    }
    printf("\n");
    printf("================================================================\n");
    printf("\n");
}

/**
 * Searches and prints entities based on their type.
 *
 * @param type: The type of the entities to search (1 for Individual, 2 for Business, 3 for Group, 4 for Organisation).
 */
void searchByType(int type)
{
    if (type == 1)
    {
        printIndividualList();
    }
    else if (type == 2)
    {
        printBusinessList();
    }
    else if (type == 3)
    {
        printGroupList();
    }
    else
    {
        printOrgList();
    }
}

/**
 * Searches and prints content associated with entities.
 *
 * This function searches for the specified content within the posts of all entities (Individuals, Businesses,
 * Groups, and Organisations) and prints information about the entities and their posts containing the specified content.
 *
 * @param content: The content to search for within the posts.
 */
void searchContent(char *content)
{
    printf("\n================================================================\n");
    printf("\n");
    IndividualList *currentInd = individualList;
    while (currentInd != NULL)
    {
        postList *currentPost = currentInd->individual->allPostsIndividual;
        while (currentPost != NULL)
        {
            if (strstr(currentPost->post, content) != NULL)
            {
                printf("\nThis content is associated with Individual: \n");

                printf("Individual ID: %d, Name: %s, Creation Time: %s\n",
                       currentInd->individual->id,
                       currentInd->individual->name,
                       currentInd->individual->Creation_time);
                printf("Post:   %s\n", currentPost->post);
                break; // No need to continue searching for this entity
            }
            currentPost = currentPost->next;
        }
        currentInd = currentInd->next;
    }

    BusinessList *currentBus = businessList;
    while (currentBus != NULL)
    {
        postList *currentPost = currentBus->businessNode->allPostBusiness;
        while (currentPost != NULL)
        {
            if (strstr(currentPost->post, content) != NULL)
            {
                printf("\nThis content is associated with Business: \n");
                printf("Business ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                       currentBus->businessNode->id,
                       currentBus->businessNode->name,
                       currentBus->businessNode->Creation_time,
                       currentBus->businessNode->location);
                printf("Post:   %s\n", currentPost->post);
                break; // No need to continue searching for this entity
            }
            currentPost = currentPost->next;
        }
        currentBus = currentBus->next;
    }

    GroupList *currentGroup = groupList;
    while (currentGroup != NULL)
    {
        postList *currentPost = currentGroup->grpNode->allPostGroup;
        while (currentPost != NULL)
        {
            if (strstr(currentPost->post, content) != NULL)
            {
                printf("\nThis content is associated with Group: \n");
                printf("Group ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                       currentGroup->grpNode->id,
                       currentGroup->grpNode->name,
                       currentGroup->grpNode->Creation_time,
                       currentGroup->grpNode->location);

                printf("Post:   %s\n", currentPost->post);
                break; // No need to continue searching for this entity
            }
            currentPost = currentPost->next;
        }
        currentGroup = currentGroup->next;
    }

    OrgList *currentOrg = orgList;
    while (currentOrg != NULL)
    {
        postList *currentPost = currentOrg->orgNode->allPostOrganisation;
        while (currentPost != NULL)
        {
            if (strstr(currentPost->post, content) != NULL)
            {
                printf("\nThis content is associated with Organisation: \n");
                printf("Organisation ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                       currentOrg->orgNode->id,
                       currentOrg->orgNode->name,
                       currentOrg->orgNode->Creation_time,
                       currentOrg->orgNode->location);

                printf("Post:   %s\n", currentPost->post);
                break; // No need to continue searching for this entity
            }
            currentPost = currentPost->next;
        }
        currentOrg = currentOrg->next;
    }
    printf("\n");
    printf("\n================================================================\n");
    printf("\n");
}

/**
 * Prints all connections (business, group, organisation) associated with an entity identified by its ID.
 *
 * @param id: The ID of the entity for which connections are to be printed.
 */
void print_all_hop(int id)
{
    printf("================================================================\n");
    printf("\n");
    IndividualList *current = individualList;
    while (current != NULL)
    {
        if (current->individual->id == id)
        {
            printf("Individual ID: %d, Name: %s, Creation Time: %s\n",
                   current->individual->id,
                   current->individual->name,
                   current->individual->Creation_time);

            print_business_connections(current->individual);

            print_group_connections(current->individual);

            print_organisation_connections(current->individual);
        }
        current = current->next;
    }
    BusinessList *temp1 = businessList;
    while (temp1 != NULL)
    {
        if (temp1->businessNode->id == id)
        {
            printf("Business ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                   temp1->businessNode->id,
                   temp1->businessNode->name,
                   temp1->businessNode->Creation_time,
                   temp1->businessNode->location);

            printf("Persons associated with this business: \n");
            print_name_list(temp1->businessNode->individualConnections);

            print_group_connections_business(temp1->businessNode);
        }
        temp1 = temp1->next;
    }
    GroupList *curr = groupList;
    while (curr != NULL)
    {
        if (curr->grpNode->id == id)
        {
            printf("Group ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                   curr->grpNode->id,
                   curr->grpNode->name,
                   curr->grpNode->Creation_time,
                   curr->grpNode->location);

            printf("Persons associated with this Group: \n");
            print_name_list(curr->grpNode->individualConnections);

            printf("Businesses associated with this Group: \n");
            print_name_list(curr->grpNode->businessConnections);
        }
        curr = curr->next;
    }

    OrgList *temp2 = orgList;
    while (temp2 != NULL)
    {
        if (temp2->orgNode->id == id)
        {
            printf("Organisation ID: %d, Name: %s, Creation Time: %s, Location: %s\n",
                   temp2->orgNode->id,
                   temp2->orgNode->name,
                   temp2->orgNode->Creation_time,
                   temp2->orgNode->location);

            printf("Persons associated with this Organisation: \n");
            print_name_list(temp2->orgNode->individualConnections);
        }
        temp2 = temp2->next;
    }
    printf("================================================================\n");
    printf("\n");
}

/**
 * Checks if a given name is present in the individual connections of a group.
 *
 * @param id: The ID of the entity for which the check is performed.
 * @param name: The name to check in the group's individual connections.
 * @param grpNode: Pointer to the group node.
 * @return: Returns 1 if the name is present, 0 otherwise.
 */
int isPresentInGroup(int id, char *name, groups *grpNode)
{
    int flag = 0;
    Name *node = grpNode->individualConnections;
    while (node != NULL)
    {
        if (strcmp(node->name, name) == 0)
        {
            flag = 1;
            break;
        }
        node = node->next;
    }
    return flag;
}

/**
 * Prints all two-hop connections with a given ID and name in groups.
 *
 * @param id: The ID of the entity for which two-hop connections are to be printed.
 * @param name: The name of the entity for which two-hop connections are to be printed.
 */
void print_two_hop_groups(int id, char *name)
{
    printf("================================================================\n");
    printf("\n");
    printf("Printing all two hop connections with ID %d and name %s\n\n", id, name);
    GroupList *current = groupList;


    while (current != NULL)
    {
        Name *node = current->grpNode->individualConnections;
        printf("Contents for all two-hop connections with this Group: %s\n", current->grpNode->name);
        printf("\n");

        while (node != NULL)
        {
            if (strcmp(node->name, name) && isPresentInGroup(id, name, current->grpNode))
            {
                IndividualList *temp = individualList;
                while (temp != NULL && strcmp(temp->individual->name, node->name) != 0)
                {
                    temp = temp->next;
                }

                if (temp != NULL)
                {
                    const postList *currentPost = temp->individual->allPostsIndividual;

                    printf("\nAll Posts for %s:\n", temp->individual->name);

                    while (currentPost != NULL)
                    {
                        printf("%s\n", currentPost->post);
                        currentPost = currentPost->next;
                    }
                    printf("\n");
                }
            }
            node = node->next;
        }
        current = current->next;
    }
    printf("================================================================\n");
    printf("\n");
}

/**
 * Checks if a given name is present in the individual connections of an organisation.
 *
 * @param id: The ID of the entity for which the check is performed.
 * @param name: The name to check in the organisation's individual connections.
 * @param orgNode: Pointer to the organisation node.
 * @return: Returns 1 if the name is present, 0 otherwise.
 */
int isPresentInOrganisation(int id, char *name, organisations *orgNode)
{
    int flag = 0;
    Name *node = orgNode->individualConnections;
    while (node != NULL)
    {
        if (strcmp(node->name, name) == 0)
        {
            flag = 1;
            break;
        }
        node = node->next;
    }
    return flag;
}

/**
 * Prints all two-hop connections with a given ID and name in organisations.
 *
 * @param id: The ID of the entity for which two-hop connections are to be printed.
 * @param name: The name of the entity for which two-hop connections are to be printed.
 */
void print_two_hop_organisations(int id, char *name)
{
    printf("================================================================\n");
    printf("\n");
    printf("Printing all two hop connections with ID %d and name %s\n\n", id, name);
    OrgList *current = orgList;
    while (current != NULL)
    {
        Name *node = current->orgNode->individualConnections;
        printf("Contents for all two-hop connections with this Organisation: %s\n", current->orgNode->name);
        printf("\n");
        while (node != NULL)
        {
            if (strcmp(node->name, name) && isPresentInOrganisation(id, name, current->orgNode))
            {
                IndividualList *temp = individualList;
                while (temp != NULL && strcmp(temp->individual->name, node->name) != 0)
                {
                    temp = temp->next;
                }

                if (temp != NULL)
                {
                    const postList *currentPost = temp->individual->allPostsIndividual;

                    printf("\nAll Posts for %s:\n", temp->individual->name);

                    while (currentPost != NULL)
                    {
                        printf("%s\n", currentPost->post);
                        currentPost = currentPost->next;
                    }
                    printf("\n");
                }
            }
            node = node->next;
        }
        current = current->next;
    }
    printf("================================================================\n");
    printf("\n");
}

/**
 * Deletes a node with the given ID, type, and name from the social network.
 * The function handles deletion of individual, business, group, and organization nodes.
 * When deleting an individual, it also removes connections from associated business, group, and organization nodes.
 * When deleting a business, it removes connections from associated individuals and groups.
 * When deleting a group, it removes connections from associated individuals and businesses.
 * When deleting an organization, it removes connections from associated individuals.
 *
 * @param id: The ID of the node to be deleted.
 * @param type: The type of the node (1 for individual, 2 for business, 3 for group, 4 for organization).
 * @param name: The name associated with the node.
 */
void deleteNode(int id, int type, char *name)
{
    if (type == 1)
    {
        IndividualList *current = individualList;
        while (current != NULL)
        {
            if (current->individual->id == id)
            {
                // Deletes the individual node and its connections from other nodes
                deleteFromIndividualList(id);

                // Removes connections from associated business nodes
                BusinessList *temp1 = businessList;
                while (temp1 != NULL)
                {
                    temp1->businessNode->individualConnections = delete_Name_node(id, temp1->businessNode->individualConnections);
                    temp1 = temp1->next;
                }

                // Removes connections from associated group nodes
                GroupList *temp2 = groupList;
                while (temp2 != NULL)
                {
                    temp2->grpNode->individualConnections = delete_Name_node(id, temp2->grpNode->individualConnections);
                    temp2 = temp2->next;
                }

                // Removes connections from associated organization nodes
                OrgList *temp3 = orgList;
                while (temp3 != NULL)
                {
                    temp3->orgNode->individualConnections = delete_Name_node(id, temp3->orgNode->individualConnections);
                    temp3 = temp3->next;
                }
                break;
            }
            current = current->next;
        }
        individualCount--;
        printf("Node with id %d deleted.\n", id);
    }
    else if (type == 2)
    {
        BusinessList *current = businessList;
        while (current != NULL)
        {
            if (current->businessNode->id == id)
            {
                // Deletes the business node
                deleteFromBusinessList(id);

                // Removes connections from associated individual nodes
                IndividualList *temp1 = individualList;
                while (temp1 != NULL)
                {
                    for (int k = 0; k < temp1->individual->bCount; ++k)
                    {
                        if (strcmp(temp1->individual->businessConnections[k], name) == 0)
                        {
                            for (int l = k; l < temp1->individual->bCount - 1; ++l)
                            {
                                strcpy(temp1->individual->businessConnections[l], temp1->individual->businessConnections[l + 1]);
                            }
                            temp1->individual->bCount--;
                            break;
                        }
                    }
                    temp1 = temp1->next;
                }

                // Removes connections from associated group nodes
                GroupList *temp2 = groupList;
                while (temp2 != NULL)
                {
                    temp2->grpNode->businessConnections = delete_Name_node(id, temp2->grpNode->businessConnections);
                    temp2 = temp2->next;
                }
                break;
            }
            current = current->next;
        }
        businessCount--;
        printf("Node with id %d deleted.\n", id);
    }
    else if (type == 3)
    {
        GroupList *current = groupList;
        while (current != NULL)
        {
            if (current->grpNode->id == id)
            {
                // Deletes the group node
                deleteFromGroupList(id);

                // Removes connections from associated individual nodes
                IndividualList *temp1 = individualList;
                while (temp1 != NULL)
                {
                    for (int k = 0; k < temp1->individual->gCount; ++k)
                    {
                        if (strcmp(temp1->individual->groupConnections[k], name) == 0)
                        {
                            for (int l = k; l < temp1->individual->gCount - 1; ++l)
                            {
                                strcpy(temp1->individual->groupConnections[l], temp1->individual->groupConnections[l + 1]);
                            }
                            temp1->individual->gCount--;
                            break;
                        }
                    }
                    temp1 = temp1->next;
                }

                // Removes connections from associated business nodes
                BusinessList *temp2 = businessList;
                while (temp2 != NULL)
                {
                    for (int k = 0; k < temp2->businessNode->gCount; ++k)
                    {
                        if (strcmp(temp2->businessNode->groupConnections[k], name) == 0)
                        {
                            for (int l = k; l < temp2->businessNode->gCount - 1; ++l)
                            {
                                strcpy(temp2->businessNode->groupConnections[l], temp2->businessNode->groupConnections[l + 1]);
                            }
                            temp2->businessNode->gCount--;
                            break;
                        }
                    }
                    temp2 = temp2->next;
                }
                break;
            }
            current = current->next;
        }
        groupCount--;
        printf("Node with id %d deleted.\n", id);
    }
    else if (type == 4)
    {
        OrgList *current = orgList;
        while (current != NULL)
        {
            if (current->orgNode->id == id)
            {
                // Deletes the organization node
                deleteFromOrgList(id);

                // Removes connections from associated individual nodes
                IndividualList *temp1 = individualList;
                while (temp1 != NULL)
                {
                    for (int k = 0; k < temp1->individual->oCount; ++k)
                    {
                        if (strcmp(temp1->individual->orgConnections[k], name) == 0)
                        {
                            for (int l = k; l < temp1->individual->oCount - 1; ++l)
                            {
                                strcpy(temp1->individual->orgConnections[l], temp1->individual->orgConnections[l + 1]);
                            }
                            temp1->individual->oCount--;
                            break;
                        }
                    }
                    temp1 = temp1->next;
                }
                break;
            }
            current = current->next;
        }
        orgCount--;
        printf("Node with id %d deleted.\n", id);
    }
    else
    {
        printf("This type of account is not present in this social network!!!!\n");
    }
}

int main()
{
    printf("\nIn this social network, diverse nodes encompass individuals, groups, businesses, and organizations. Each node possesses a unique ID, name, creation date, and a network of links to other nodes. Content, represented as strings, can be uploaded or posted without duplication. Individuals may include birthdays, and businesses/organizations incorporate 2D coordinates for location. Groups and organizations connect with individuals as members, while businesses can have individuals as owners or customers. Additionally, businesses may be affiliated with groups. Notably, restrictions exist on linkages, for instance, a business cannot own another business, and a group cannot be a member of an organization.\n\n");
    int choice;
    do
    {
        printf("\n--- Social Network Menu ---\n");
        printf("1. Create Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Nodes\n");
        printf("4. Print 1-hop Linked Nodes\n");
        printf("5. Create and Post Content\n");
        printf("6. Search Content\n");
        printf("7. Display Linked Individuals' Content\n");
        printf("8. Display All Nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\n============================================================\n");
            printf("\n");
            char name[100];
            printf("Enter the username: ");
            scanf("%s", name);
            create_node_and_connect(name);
            printf("============================================================\n");
            break;
        }

        case 2:
        {
            printf("================================================================\n");
            int type, id;
            char name_delete[100];
            printf("Enter the node type for deletion: \n1 for Individual.\n2 for Business.\n3 for Group\n4 for Organisation\n");
            scanf("%d", &type);
            printf("Enter the node id: ");
            scanf("%d", &id);
            printf("Enter the user name: ");
            scanf("%s", name_delete);
            deleteNode(id, type, name_delete);
            printf("=================================================================\n");
            break;
        }

        case 3:
        {
            int check;
            printf("How do you want to search?\nPress 1 for search by birthday\nPress 2 for search by name\nPress 3 for search by type\n");
            scanf("%d", &check);
            if (check == 1)
            {
                char birthday[100];
                printf("Enter the Date of Birth in dd/mm/yyyy format: ");
                scanf("%s", birthday);
                searchByBirthday(birthday);
            }
            else if (check == 2)
            {
                char name_search[100];
                printf("\n================================================================\n");
                printf("Enter the name of the user: ");
                scanf("%s", name_search);
                searchByName(name_search);
                printf("==================================================================\n");
            }
            else if (check == 3)
            {
                int type_search;
                printf("Enter the type of the user to search: \n1 for Individual.\n2 for Business.\n3 for Group\n4 for Organisation\n");
                scanf("%d", &type_search);
                searchByType(type_search);
            }
            else
            {
                printf("Wrong choice entered!!!!\n");
            }
            break;
        }

        case 4:
        {
            int id_print;
            printf("Enter the id for printing all one-hop nodes: ");
            scanf("%d", &id_print);
            print_all_hop(id_print);
            break;
        }

        case 5:
        {
            int id_post, type_post;
            printf("Enter the id of the username to post content: ");
            scanf("%d", &id_post);
            printf("Enter the type of the user: \n1 for Individual.\n2 for Business.\n3 for Group\n4 for Organisation\n");
            scanf("%d", &type_post);
            create_post(id_post, type_post);
            break;
        }

        case 6:
        {
            char post[500];
            printf("Type here the post to search: ");
            scanf(" %[^\n]s", post);
            searchContent(post);
            break;
        }

        case 7:
        {
            int id_display;
            char name_display[100];
            printf("Enter the id to print posts of all the connected nodes with this node: ");
            scanf("%d", &id_display);
            printf("Enter the name of the user: ");
            scanf("%s", name_display);
            print_two_hop_groups(id_display, name_display);
            print_two_hop_organisations(id_display, name_display);

            printf("\n\nIf nothing is printed after for a group or organisation then the given user is not connected with that group or organisation or no other person is present in that group or organisation.\n\n");
            break;
        }

        case 8:
            printf("\n================================================================\n\n");
            printIndividualList();
            printf("\n================================================================\n\n");
            printBusinessList();
            printf("\n================================================================\n\n");
            printGroupList();
            printf("\n================================================================\n\n");
            printOrgList();
            printf("\n================================================================\n\n");
            break;

        case 0:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}