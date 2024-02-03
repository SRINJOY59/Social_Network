#include "social.h"
int main() {
//     int cnt = 0;
//         char *business[MAX_SIZE] = {
//         "Facebook",
//         "Linkedin",
//         "Instagram",
//         "Whatsapp",
//         "GlobalSolutions",
//         "CreativeMinds",
//         "SwiftEnterprises",
//         "PinnacleVentures",
//         "DynamicConcepts",
//         "PeakPerformance",
//         "InfiniteIdeas",
//         "MegaSystems",
//         "VibrantCreations",
//         "PrimeDevelopments",
//         "EliteServices",
//         "ProfoundInnovations",
//         "NexGenSolutions",
//         "StrategicInsights",
//         "PrecisionTechnologies",
//         "EmpireEnterprises"
//     };
//     char *org[MAX_SIZE] = {
//         "ABCCorporation",
//         "XYZCompany",
//         "TechInnovatorsLtd.",
//         "GlobalSolutionsInc.",
//         "FinancialServicesGroup",
//         "GreenEnergyCo.",
//         "InfiniteTechnologies",
//         "SmartSystemsLtd.",
//         "InnovateXSolutions",
//         "OptimalStrategiesInc.",
//         "BlueSkyEnterprises",
//         "DataDynamicsLtd.",
//         "PrecisionEngineeringGroup",
//         "QuantumInnovationsInc.",
//         "NexGenNetworks",
//         "SunrisePharmaceuticals",
//         "UnifiedVisionSystems",
//         "DigitalInsightsCorporation",
//         "StrategicPartnersLtd.",
//         "OmegaSolutionsInc."
//     };
//     char *grp[MAX_SIZE] = {
//     "TechInnovators",
//     "CreativeMinds",
//     "DataDynasty",
//     "CodeCrafters",
//     "InfiniteIdeas",
//     "DigitalDazzle",
//     "FutureFusion",
//     "AlphaAlliance",
//     "PinnaclePioneers",
//     "QuantumQuest",
//     "InnoNest",
//     "TechTitans",
//     "VisionVoyagers",
//     "SynergeticSprint",
//     "NeuralNexuses",
//     "BinaryBridges",
//     "EcoEnvoys",
//     "SynthWave",
//     "SparkSquad",
//     "CerebralCatalysts"
// };
// for (cnt = 0; cnt < 3; cnt++) {
//     printf("Creating node for business: %s\n", business[cnt]);
//     create_node_and_connect(business[cnt]);

//     printf("Creating node for org: %s\n", org[cnt]);
//     create_node_and_connect(org[cnt]);

//     printf("Creating node for grp: %s\n", grp[cnt]);
//     create_node_and_connect(grp[cnt]);
// }

    char ch = 'Y';
    printf("Create nodes in this social network \n");
    while(1){
        if(ch == 'N'){
            break;
        }
        char name[100];
        printf("Enter the username:  ");
        scanf("%s",name);
        create_node_and_connect(name);
        printf("Do you want to create more nodes:  (Y|N) ");
        scanf(" %c",&ch);
    }
    printf("\nDisplaying individual details...\n");
    display_individuals();

    printf("\nDisplaying business details...\n");
    display_businesses();

    printf("\nDisplaying Group details...\n");
    display_groups();

    printf("\nDisplaying Organisations details...\n");
    display_organizations();

    // printf("\nDisplaying groups details...\n");
    // display_groups();

    // printf("\nDisplaying organizations details...\n");
    // display_organizations();

    char birthday[100];
    printf("Enter birthday for searching:   ");
    scanf("%s",birthday);
    searchByBirthday(birthday);

    char name[100];
    printf("Enter name for searching: ");
    scanf("%s",name);
    searchByName(name);

    int type ;
    printf("Enter type for searching:  \n 1 for Individual \n 2 for Business \n 3 for Groups \n 4 for Organizations \n");
    scanf("%d",&type);

    searchByType(type);
    // printf("\nDisplaying Individuals associated with each business: \n");
    // cnt = 0;
    // for(cnt = 0; cnt < businessCount; cnt++){
    //     display_individuals_for_business(businessArray[cnt]);
    // }

    // printf("\nDisplaying Individuals associated with each Groups: \n");
    // cnt = 0;
    // for(cnt = 0; cnt < groupCount; cnt++){
    //     display_individuals_for_groups(groupArray[cnt]);
    // }

    // printf("\nDisplaying Individuals associated with each Organisations: \n");
    // cnt = 0;
    // for(cnt = 0; cnt < orgCount; cnt++){
    //     display_individuals_for_organizations(orgArray[cnt]);
    // }

    // printf("\nDisplaying businesses associated with each groups: \n");
    // cnt = 0;
    // for(cnt = 0; cnt < groupCount; cnt++){
    //     display_businesses_for_groups(groupArray[cnt]);
    // }
    create_post(123, 2);
    printf("Enter the content to search :   \n");
    char contentDetails[100];
    scanf("%s", contentDetails);
    searchContent(contentDetails);
    return 0;
}
