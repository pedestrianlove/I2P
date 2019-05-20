#include<stdio.h>
#include<stdlib.h>

// CONSTANT
#define MAX_NODE_DEGREE 18

// Structures
typedef struct LINK LINK;
typedef struct BUILDING BUILDING;
struct LINK {
	int LATENCY;
	int BANDWIDTH;
	BUILDING* SRC;
	BUILDING* DST;
};

struct BUILDING {
	int TRAVELED;
	int BUILDING_ID;
	int MAX_BANDWIDTH, MIN_LATENCY;
	LINK** LINK_OUT;	// A list of links
	int NUMBER_OF_LINKS;
};

// Global Variables
BUILDING** building_index; 

// Internal Function






// User Interface

LINK* INITIALIZE_LINK (int latency, int bandwidth)
{
	LINK* new_link 		= malloc (sizeof(LINK));
	
	// Initialize the basic info
	new_link -> SRC 	= NULL;
	new_link -> DST 	= NULL;
	new_link -> LATENCY 	= latency;
	new_link -> BANDWIDTH 	= bandwidth;

	return new_link;
}

BUILDING* INITIALIZE_BUILDING (int building_number)
{
	BUILDING* new_building 		= malloc (sizeof(BUILDING));
	
	// Get the link_out ready
	new_building -> LINK_OUT = malloc (sizeof(LINK*) * MAX_NODE_DEGREE);
	for (int i = 0 ; i < MAX_NODE_DEGREE ; i++){
		new_building -> LINK_OUT[i] = NULL;
	}

	// Initialize the basic info
	new_building -> TRAVELED	= 0;
	new_building -> NUMBER_OF_LINKS	= 0;
	new_building -> BUILDING_ID 	= building_number;
	new_building -> MIN_LATENCY	= 11; 	// 0 < LATENCY < 11
	new_building -> MAX_BANDWIDTH	= 0;	// 0 < BANDWIDTH < 31

	building_index[building_number]	= new_building;
	return new_building;
}

void ATTACH_LINK (BUILDING* SRC, BUILDING* DST, LINK* link)
{
	for (int i = 0 ; i < MAX_NODE_DEGREE; i++){
		if (SRC -> LINK_OUT[i] == NULL){
			SRC -> LINK_OUT[i] = link;
			break;
		}
	}
	link -> SRC = SRC;
	link -> DST = DST;
	SRC -> NUMBER_OF_LINKS ++;
}

void FIND_MIN_LATENCY (BUILDING* SRC, int latency, int bandwidth)
{
	// Write in traveled record
	SRC -> TRAVELED 	= 1;
	SRC -> MIN_LATENCY 	= latency;
	SRC -> MAX_BANDWIDTH 	= bandwidth;

	// Sort the minimum latency link
	int min_latency = 11;
	int min_index;
	for (int i= 0; i < SRC-> NUMBER_OF_LINKS; i++){
		if (SRC -> LINK_OUT[i] -> LATENCY < min_latency && 
				SRC -> LINK_OUT[i] -> DST -> TRAVELED == 0){
			min_latency = SRC -> LINK_OUT[i] -> LATENCY;
			min_index = i;
		}
	}
	
	// Go for the minimum latency link
	int LATENCY 	= latency + SRC->LINK_OUT[min_index]->LATENCY;
	int BANDWIDTH	= SRC -> LINK_OUT[i] -> BANDWIDTH; 	
	BANDWIDTH	= (bandwidth > BANDWIDTH)? bandwidth : BANDWIDTH;
	FIND_MIN_LATENCY (SRC -> LINK_OUT[min_index] -> DST, LATENCY, BANDWIDTH);

}

// TBD
void OUTPUT (BUILDING* SRC)
{
	if ()

}

// DEBUG
void PRINT_LINK (LINK* link)
{
	printf ("This link src from %d, dst at %d, latency is %d and bandwidth is %d\n", link -> SRC -> BUILDING_ID, 
											link -> DST -> BUILDING_ID, 
											link -> LATENCY, link -> BANDWIDTH);
}

void PRINT_BUILDING (BUILDING* building)
{
	printf("--------------------------------------------------------\n");
	printf ("Building no.%d, has following links to choose from:\n", building -> BUILDING_ID);
	for (int i = 0 ; building -> LINK_OUT[i] != NULL ; i++)
		if (building -> LINK_OUT[i] != NULL)
			PRINT_LINK (building -> LINK_OUT[i]);
	printf("\n");
}

// RELEASE THE MEMORY
void FREE_BUILDING (BUILDING* building)
{
	for (int i = 0; i< MAX_NODE_DEGREE ; i++)
		if (building -> LINK_OUT[i] != NULL){
			free(building -> LINK_OUT[i]);
		}
		else
			break;
}
void FREE (int length)
{
	for (int i = 0 ; i< length ; i++){
		FREE_BUILDING (building_index[i]);
	}
}

int main()
{
	// Prepare for the input
	int number_of_buildings;
	int number_of_candidate_connections;
	scanf ("%d%d", &number_of_buildings, &number_of_candidate_connections);

	// Make a list for buildings
	building_index = malloc (sizeof(BUILDING) * number_of_buildings);
	for (int i = 0; i< number_of_buildings; i++)
		building_index[i] = NULL;
	
	// Input
	LINK* link;
	BUILDING* SRC;
	BUILDING* DST;
	int src, dst, latency, bandwidth;
	
	for (int i = 0; i< number_of_candidate_connections; i++){
		scanf ("%d%d%d%d", &src, &dst, &latency, &bandwidth);
		printf ("Reading in data: src = %d, dst = %d, latency = %d, bandwidth = %d\n", src, dst, latency, bandwidth);
		// INITIALIZE THE BUILDINGS AND LINKS (First link and then building)
		link = INITIALIZE_LINK (latency, bandwidth);
		if (building_index[src] == NULL) 
			SRC = INITIALIZE_BUILDING (src);
		else
			SRC = building_index[src];
		
		if (building_index[dst] == NULL)
			DST = INITIALIZE_BUILDING (dst);
		else
			DST = building_index[dst];

		
		// ATTACH THE LINK AND THE BUILDING
		ATTACH_LINK (SRC, DST, link);
	}
	
	// Debugging Module
	/*
	for (int i = 0; i< number_of_buildings; i++)
		PRINT_BUILDING (building_index[i]);
	*/

	// Calculate the minimum spanning tree
	// 			BUILDING*		LATENCY		BANDWIDTH
	FIND_MIN_LATENCY (	building_index[0], 	0,		32);

	// Output the buildings' latency and bandwidth data
	for (int i = 0; i< number_of_buildings; i++){
		OUTPUT (building_index[i]);
	}



	// release the memory allocated
	FREE (number_of_buildings);
	return 0;
}
