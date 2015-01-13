//Zachary Rump
//ZRRM74
//LAB 2
//LAB E
//Lab Code: "I'm not wearing hocky pads!"
#include <stdio.h>

#define MAX_ACCOUNTS 20

typedef struct {
	int accountId;
	float balance;
} Account; 

//prototypes
int load_accounts(Account accounts[], char* fileName);
void sort(Account accounts[], int length);
Account* find_account(Account accounts[], int low, int high, int id);
void run_transactions(Account accounts[], int length, char* fileName);
void print(Account accounts[], int length);
//bonus part sort using qsort() 
int cmpr(const void *,const void *); //compare function to pass to qsort
void sort_bonus(Account accounts[], int length);

int main(int argc, char **argv) {
	//check command line args for two input files
	if(argc<3) { printf("Incorrect number of arguments.\nUsage is ./a.out <account list> <transactions>\n"); return -1; }
	//declare struct array
	Account accnt[MAX_ACCOUNTS]; 
	//load accounts into array
	int len = load_accounts(accnt, argv[1]); //first arg is list of accounts
	//printf("account length: %d\n", len);
	//sort accounts array
	sort(accnt, len);
	//run transaction list
	run_transactions(accnt, len, argv[2]); //second arg is transaction list
	//print out final balances 
	printf("\nFinal Balance Sheet\n"); 
	print(accnt, len);
	//bonus
	printf("\n------ Bonus Part ------\n");
	//sort using qsort and cmpr()
	sort_bonus(accnt, len);
	printf("Final Balance Sheet\n");
	print(accnt, len);

	return 0; 
}

int load_accounts(Account accounts[], char *fileName) {
	//open file 
	FILE *file = fopen(fileName, "r");
	//check for bad filename arg
	if(file == NULL) { printf("Bad filename\n"); return -1; }
	//read accounts into array
	int len=0;
	while(1)
	{
		//unknown length so check for EOF or length > MAX_ACCOUNTS
		if(feof(file) || (len == MAX_ACCOUNTS)) { break; }
		fscanf(file, "%d %f", &accounts[len].accountId, &accounts[len].balance);
		len++; //iterate length counter 
	}
	fclose(file); 
	return len-1; //-1 because of the position of feof check in the loop, will iterate len count 1 extra
}

void sort(Account accounts[], int length) {
	//sort in ascending order based on account Id w/ bubble sort
	int pass=0;
	for(pass=1; pass<length; pass++)
	{
		int i=0;
		for(i=0; i<(length-1); i++)
		{
			if(accounts[i].accountId > accounts[i+1].accountId)
			{
				//swap account positions
				Account tmp = accounts[i];
				accounts[i] = accounts[i+1];
				accounts[i+1] = tmp;
			}
		}
	}
}

Account* find_account(Account accounts[], int low, int high, int id) {
	//binary search w/ accounts
	Account *accntPtr = NULL;
	if(low > high) { return accntPtr; } //key not found return ptr to NULL 
	//find midpoint
	int mid = (low+high)/2;
	if(accounts[mid].accountId == id) //key found
	{
		accntPtr = &accounts[mid]; //return ptr to struct w/ accountId id 
		return accntPtr;
	}
	else if(id > accounts[mid].accountId)
	{
		return find_account(accounts, mid+1, high, id);
	}
	else if(id < accounts[mid].accountId)
	{
		return find_account(accounts, low, mid-1, id);
	}
}

void run_transactions(Account accounts[], int length, char *fileName) {
	//open transactions file
	FILE *file = fopen(fileName, "r");
	if(file == NULL) { printf("Bad transaction filename arg\n"); }
	int accntid=0;
	float transc=0;
	while(1)
	{
		fscanf(file, "%d %f", &accntid, &transc);
		if(feof(file)) { break; } //check EOF after fscanf because fscanf will move to the next line
		Account *aPtr = find_account(accounts, 0, length, accntid); //get ptr to struct
		if(aPtr == NULL) //if ptr is null skip transaction
		{
			printf("Invalid transaction; account %d does not exist\n", accntid); 
		}
		else if((aPtr->balance + transc) < 0) //check if transaction will create negative balance
			{
				printf("Invalid transaction, withdrawing $%0.2f from account %d results in negative balance\n", transc, accntid);
			}
		else
		{
			aPtr->balance += transc; //add transc to account balance
		}
	}
	fclose(file);
}

void print(Account accounts[], int length) {
	int i=0;
	for(i=0; i<length; i++)
	{
		printf("%d %0.2f\n", accounts[i].accountId, accounts[i].balance);
	}
}


void sort_bonus(Account accounts[], int length) {
	//use qsort(array, len, sizeof(type), comparison_function())
	qsort(accounts, length, sizeof(Account), cmpr);
}

int cmpr(const void *a1, const void *a2) {
	//returns 1 if f1>f2
	//returns -1 if f1<f2
	//returns 0 if f1==f2
	//cast void pointers to struct ptrs
	Account aone = *(Account *)a1;
	Account atwo = *(Account *)a2;
	if(aone.balance > atwo.balance) 
		return 1; 
	else if (aone.balance < atwo.balance) 
		return -1; 
	else
		return 0;
}


		



