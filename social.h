// Function description is given above each function declaration

#ifndef SOCIAL_H
#define SOCIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 1000 // user is restricted to coonect with MAX_SIZE number of business, organisations and groups

// businesses are restricted to connect with MAX_SIZE number of groups

// Represents a linked list of post in the social network
typedef struct postList
{
    char post[500];        // Content of the post
    struct postList *next; // Pointer to the next post in the list
} postList;

// Represents an individual node in the social network
typedef struct Individual
{
    int id;                       // Unique identifier for the individual
    char name[100];               // Name of the individual
    char Creation_time[100];      // Creation timestamp
    char content[500];            // Content associated with the individual
    char birthday[100];           // Birthday of the individual (optional)
    postList *allPostsIndividual; // Linked list of all posts made by the individual

    // Arrays to store connections to businesses, groups, and organizations
    char businessConnections[MAX_SIZE][100];
    int ownerBusiness[MAX_SIZE];
    char groupConnections[MAX_SIZE][100];
    char orgConnections[MAX_SIZE][100];

    // Counts of connections to businesses, groups, and organizations
    int bCount;
    int gCount;
    int oCount;
} Individual;

// Represents a linked list node with a name and identifier
typedef struct Name
{
    char name[100];    // Name of the node
    int id;            // Identifier of the node
    struct Name *next; // Pointer to the next node in the list
} Name;

// Represents a business node in the social network
typedef struct business
{
    int id;                               // Unique identifier for the business
    char name[100];                       // Name of the business
    char Creation_time[100];              // Creation timestamp
    postList *allPostBusiness;            // Linked list of all posts made by the business
    Name *individualConnections;          // Linked list of individuals connected to the business
    char groupConnections[MAX_SIZE][100]; // Arrays to store connections to groups
    int gCount;                           // Count of connections to groups
    char location[100];                   // Location of the business (2D coordinates)
} business;

// Represents a group node in the social network
typedef struct groups
{
    int id;                      // Unique identifier for the group
    char name[100];              // Name of the group
    char Creation_time[100];     // Creation timestamp
    postList *allPostGroup;      // Linked list of all posts made by the group
    Name *individualConnections; // Linked list of individuals connected to the group
    Name *businessConnections;   // Linked list of businesses connected to the group
    char location[100];          // Location of the group (2D coordinates)
} groups;

// Represents an organization node in the social network
typedef struct organisations
{
    int id;                         // Unique identifier for the organization
    char name[100];                 // Name of the organization
    char Creation_time[100];        // Creation timestamp
    postList *allPostOrganisation;  // Linked list of all posts made by the organization
    char allContent[MAX_SIZE][100]; // Array to store content associated with the organization
    Name *individualConnections;    // Linked list of individuals connected to the organization
    char location[100];             // Location of the organization (2D coordinates)
} organisations;

// Represents a node in the social network (generic)
typedef struct Node
{
    int id;         // Unique identifier for the node
    char name[100]; // Name of the node
} Node;

// Represents a linked list node for Individual structures
typedef struct IndividualList
{
    Individual *individual;      // Pointer to an Individual structure
    struct IndividualList *next; // Pointer to the next node in the list
} IndividualList;

// Represents a linked list node for business structures
typedef struct BusinessList
{
    business *businessNode;    // Pointer to a business structure
    struct BusinessList *next; // Pointer to the next node in the list
} BusinessList;

// Represents a linked list node for groups structures
typedef struct GroupList
{
    groups *grpNode;        // Pointer to a groups structure
    struct GroupList *next; // Pointer to the next node in the list
} GroupList;

// Represents a linked list node for organizations structures
typedef struct OrgList
{
    organisations *orgNode; // Pointer to an organizations structure
    struct OrgList *next;   // Pointer to the next node in the list
} OrgList;

/**
 * Adds an individual to the linked list of individuals in the social network.
 * This function takes an Individual structure pointer as input and incorporates it into the individualList.
 * If the list is empty, a new IndividualList node is created, pointing to the given individual.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the individual.
 * individual: Pointer to the Individual structure to be added to the network.
 */

void addToIndividualList(Individual *individual);

/**
 * Adds a business node to the linked list of businesses in the social network.
 * This function takes a business structure pointer as input and incorporates it into the businessList.
 * If the list is empty, a new BusinessList node is created, pointing to the given business node.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the business node.
 * businessNode: Pointer to the business structure to be added to the network.
 */

void addToBusinessList(business *businessNode);

/**
 * Adds a group node to the linked list of groups in the social network.
 * This function takes a groups structure pointer as input and incorporates it into the groupList.
 * If the list is empty, a new GroupList node is created, pointing to the given group node.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the group node.
 * @param group: Pointer to the groups structure to be added to the network.
 */

void addToGroupList(groups *group);

/**
 * Adds an organization node to the linked list of organizations in the social network.
 * This function takes an organisations structure pointer as input and incorporates it into the orgList.
 * If the list is empty, a new OrgList node is created, pointing to the given organization node.
 * If the list is not empty, the function navigates to the end of the list and appends a new node with the organization node.
 * org: Pointer to the organisations structure to be added to the network.
 */

void addToOrgList(organisations *org);
/**
 * Retrieves the current local time and formats it into a string.
 * The formatted time string is stored in the provided 'creationTime' buffer.
 * creationTime: A character array where the formatted time will be stored.
 */

void get_time(char *creationTime);

/**
 * Creates a new Name node and adds it to the end of the linked list.
 * The function takes the name, id, and the head of the Name list as parameters.
 * Returns the head of the updated Name list.
 * name: The name to be added to the list.
 * id: The identifier associated with the name.
 * nameNode: The head of the current Name list.
 * returns The updated head of the Name list.
 */

Name *create_Name_node(char *name, int id, Name *nameNode);

/**
 * Prints the contents of the Name list.
 * The function takes the head of the Name list as a parameter.
 * nameNode: The head of the Name list.
 */

void print_name_list(Name *nameNode);

/**
 * Deletes a Name node with the specified id from the linked list.
 * The function takes the id and the head of the Name list as parameters.
 * Returns the head of the updated Name list.
 * id: The identifier of the Name node to be deleted.
 * nameNode: The head of the current Name list.
 * returns The updated head of the Name list.
 */

Name *delete_Name_node(int id, Name *nameNode);

/**
 * Creates a new Node with a unique identifier and the provided name.
 * The function allocates memory for the new node and assigns an id.
 * Returns the created Node.
 * name: The name to be assigned to the Node.
 * returns The newly created Node.
 */

Node *create_node(char *name);

/**
 * Prints the business connections of an Individual.
 * The function displays the business names and their connection types (Owner/Member).
 * individual: The Individual whose business connections are to be printed.
 */

void print_business_connections(Individual *individual);

/**
 * Prints the group connections of an Individual.
 * The function displays the names of the groups the Individual is connected to.
 * individual: The Individual whose group connections are to be printed.
 */

void print_group_connections(Individual *individual);

/**
 * Prints the organization connections of an Individual.
 * The function displays the names of the organizations the Individual is connected to.
 * individual: The Individual whose organization connections are to be printed.
 */

void print_organisation_connections(Individual *individual);

/**
 * Prints the details of all Individuals in the social network.
 * The function displays individual information, business connections, group connections,
 * and organization connections for each Individual in the list.
 */

void printIndividualList();

/**
 * Prints the group connections associated with a business.
 * The function displays the names of groups connected to the business.
 * @param businessNode: The business node for which group connections are to be printed.
 */

void print_group_connections_business(business *businessNode);

/**
 * Prints the details of all businesses in the social network.
 * The function displays business information, associated individuals, and group connections for each business in the list.
 */

void printBusinessList();

/**
 * Prints the details of all groups in the social network.
 * The function displays group information, associated individuals, and associated businesses for each group in the list.
 */

void printGroupList();

/**
 * Prints the details of all organizations in the social network.
 * The function displays organization information and associated individuals for each organization in the list.
 */

void printOrgList();

/**
 * Deletes a business node from the business list based on the provided ID.
 * Frees the memory occupied by the business node.
 * id: The ID of the business node to be deleted.
 */

void deleteFromBusinessList(int id);

/**
 * Deletes an individual node from the individual list based on the provided ID.
 * Frees the memory occupied by the individual node.
 * id: The ID of the individual node to be deleted.
 */

void deleteFromIndividualList(int id);

/**
 * Deletes a group node from the group list based on the provided ID.
 * Frees the memory occupied by the group node.
 * id: The ID of the group node to be deleted.
 */

void deleteFromGroupList(int id);

/**
 * Deletes an organization node from the organization list based on the provided ID.
 * Frees the memory occupied by the organization node.
 * id: The ID of the organization node to be deleted.
 */

void deleteFromOrgList(int id);

/**
 * Creates an individual node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the individual.
 * @return Returns a pointer to the created individual node.
 */

Individual *create_individual(Node *node, char *creationTime);

/**
 * Creates a business node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the business.
 * @return Returns a pointer to the created business node.
 */

business *create_business(Node *node, char *creationTime);

/**
 * Creates a group node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the group.
 * @return Returns a pointer to the created group node.
 */

groups *create_group(Node *node, char *creationTime);

/**
 * Creates an organization node using the provided information.
 * @param node: The node containing information like ID and name.
 * @param creationTime: The creation time of the organization.
 * @return Returns a pointer to the created organization node.
 */

organisations *create_org(Node *node, char *creationTime);

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

void connect_business_to_individual(Individual *individual);

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

void connect_group_to_individual(Individual *individual);

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

void connect_org_to_individual(Individual *individual);

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

void connect_business_to_group(business *businessNode);

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

void create_node_and_connect(char *name);

/**
 * Searches for individuals, businesses, groups, and organizations based on the birthday.
 *
 * This function searches for individuals in the social network whose birthday matches
 * the given input. If found, it prints the details of those individuals. If not found,
 * it prints a message indicating that no one was found.
 *
 * @param birthday: The birthday to search for in the social network.
 */

void searchByBirthday(char *birthday);

/**
 * Searches for individuals, businesses, groups, and organizations based on the name.
 *
 * This function searches for individuals, businesses, groups, and organizations in the
 * social network whose name matches the given input. If found, it prints the details of
 * those entities. If not found, it prints a message indicating that no one was found.
 *
 * @param name: The name to search for in the social network.
 */

void searchByName(char *name);

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

bool isPostPresent(postList *postHead, char *post);

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

void addPostIndividual(Individual *individual, char *post);

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

void addPostBusiness(business *businessNode, char *post);

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

void addPostGroups(groups *groupNode, char *post);

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

void addPostOrganisations(organisations *orgNode, char *post);

/**
 * Creates a post for an entity (Individual, Business, Group, or Organisation) based on the given ID and type.
 *
 * This function prompts the user to write a post for the entity with the specified ID and type. It then adds
 * the post to the respective entity's post list.
 *
 * @param id: The ID of the entity.
 * @param type: The type of the entity (1 for Individual, 2 for Business, 3 for Group, 4 for Organisation).
 */

void create_post(int id, int type);

/**
 * Prints all posts for a specific Individual.
 *
 * This function prints all the posts associated with a specific Individual, including the content
 * of each post.
 */

void printAllPostsIndividual();

/**
 * Prints all posts for a specific Business.
 *
 * This function prints all the posts associated with a specific Business, including the content
 * of each post.
 */

void printAllPostsBusiness();

/**
 * Prints all posts for a specific Organisation.
 *
 * This function prints all the posts associated with a specific Organisation, including the content
 * of each post.
 */

void printAllPostsOrganisation();

/**
 * Prints all posts for a specific Group.
 *
 * This function prints all the posts associated with a specific Group, including the content
 * of each post.
 */

void printAllPostsGroup();

/**
 * Searches and prints entities based on their type.
 *
 * @param type: The type of the entities to search (1 for Individual, 2 for Business, 3 for Group, 4 for Organisation).
 */

void searchByType(int type);

/**
 * Searches and prints content associated with entities.
 *
 * This function searches for the specified content within the posts of all entities (Individuals, Businesses,
 * Groups, and Organisations) and prints information about the entities and their posts containing the specified content.
 *
 * @param content: The content to search for within the posts.
 */

void searchContent(char *content);

/**
 * Prints all connections (business, group, organisation) associated with an entity identified by its ID.
 *
 * @param id: The ID of the entity for which connections are to be printed.
 */

void print_all_hop(int id);

/**
 * Checks if a given name is present in the individual connections of a group.
 *
 * @param id: The ID of the entity for which the check is performed.
 * @param name: The name to check in the group's individual connections.
 * @param grpNode: Pointer to the group node.
 * @return: Returns 1 if the name is present, 0 otherwise.
 */

int isPresentInGroup(int id, char *name, groups *grpNode);

/**
 * Prints all two-hop connections with a given ID and name in groups.
 *
 * @param id: The ID of the entity for which two-hop connections are to be printed.
 * @param name: The name of the entity for which two-hop connections are to be printed.
 */

void print_two_hop_groups(int id, char *name);

/**
 * Checks if a given name is present in the individual connections of an organisation.
 *
 * @param id: The ID of the entity for which the check is performed.
 * @param name: The name to check in the organisation's individual connections.
 * @param orgNode: Pointer to the organisation node.
 * @return: Returns 1 if the name is present, 0 otherwise.
 */

int isPresentInOrganisation(int id, char *name, organisations *orgNode);

/**
 * Prints all two-hop connections with a given ID and name in organisations.
 *
 * @param id: The ID of the entity for which two-hop connections are to be printed.
 * @param name: The name of the entity for which two-hop connections are to be printed.
 */

void print_two_hop_organisations(int id, char *name);

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

void deleteNode(int id, int type, char *name);

#endif