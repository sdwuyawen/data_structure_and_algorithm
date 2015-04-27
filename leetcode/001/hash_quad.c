/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/2015 08:55:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef int ElementType;

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, ElementType Value, HashTable H );

ElementType Retrieve( Position P, HashTable H );
HashTable Rehash( HashTable H );
/* Routines such as Delete are MakeEmpty are omitted */

#define MinTableSize (10)

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry
{
	ElementType Element;
	ElementType Value;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

/* Cell *TheCells will be an array of */
/* HashEntry cells, allocated later */
struct HashTbl
{
	int TableSize;
	Cell *TheCells;
};

/* Return next prime; assume N >= 10 */

static int NextPrime( int N )
{
	int i;

	if( N % 2 == 0 )
		N++;
	for( ; ; N += 2 )
	{
		for( i = 3; i * i <= N; i += 2 )
			if( N % i == 0 )
				goto ContOuter;  /* Sorry about this! */
		return N;
ContOuter: ;
	}
}

/* Hash function for ints */
Index Hash( ElementType Key, int TableSize )
{
	if(Key < 0)
	{
		Key = -Key;
	}
	return Key % TableSize;
}

HashTable InitializeTable( int TableSize )
{
	HashTable H;
	int i;

	if( TableSize < MinTableSize )
	{
		Error( "Table size too small" );
		return NULL;
	}

	/* Allocate table */
	H = malloc( sizeof( struct HashTbl ) );
	if( H == NULL )
		FatalError( "Out of space!!!" );

	H->TableSize = NextPrime( TableSize );

	/* Allocate array of Cells */
	H->TheCells = malloc( sizeof( Cell ) * H->TableSize );
	if( H->TheCells == NULL )
		FatalError( "Out of space!!!" );

	for( i = 0; i < H->TableSize; i++ )
		H->TheCells[ i ].Info = Empty;

	return H;
}

Position Find( ElementType Key, HashTable H )
{
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash( Key, H->TableSize );
	while( H->TheCells[ CurrentPos ].Info != Empty &&
			H->TheCells[ CurrentPos ].Element != Key )
		/* Probably need strcmp!! */
	{
		//对于平方数，F(i) = F(i - 1) + 2i - 1
		CurrentPos += 2 * ++CollisionNum - 1;
		if( CurrentPos >= H->TableSize )
			CurrentPos -= H->TableSize;
	}

	//若找到，则H->TheCells[ CurrentPos ].Info != Empty
	//若没有找到，则H->TheCells[ CurrentPos ].Info == Empty
	return CurrentPos;
}

void Insert( ElementType Key, ElementType Value, HashTable H )
{
	Position Pos;

	Pos = Find( Key, H );
	if( H->TheCells[ Pos ].Info != Legitimate )
	{
		/* OK to insert here */
		H->TheCells[ Pos ].Info = Legitimate;
		H->TheCells[ Pos ].Element = Key;
		H->TheCells[ Pos ].Value = Value;

		/* Probably need strcpy! */
	}
}

#if 0
HashTable Rehash( HashTable H )
{
	int i, OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize  = H->TableSize;

	/* Get a new, empty table */
	H = InitializeTable( 2 * OldSize );

	/* Scan through old table, reinserting into new */
	for( i = 0; i < OldSize; i++ )
		if( OldCells[ i ].Info == Legitimate )
			Insert( OldCells[ i ].Element, H );

	free( OldCells );

	return H;
}
#endif

ElementType Retrieve( Position P, HashTable H )
{
	return H->TheCells[ P ].Element;
}

void DestroyTable( HashTable H )
{
	free( H->TheCells );
	free( H );
}



int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;

    int *index;
	int *array;

	HashTable hash_table;
	Position pos;

	hash_table = InitializeTable(100000);

    index = malloc(sizeof(int) * 2);
	memset(index, 0, sizeof(int) * 2);

/*  for(i = 0; i < numsSize; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}
*/

	for(i = 0; i < numsSize; i++)
	{
		Insert(nums[i], i, hash_table);		
	}

	for(i = 0; i < numsSize; i++)
	{
		pos = Find(target - nums[i], hash_table);

		/*
		 * 找到的元素不能是本身
		 * 例如：[3,2,4] 6
		 * 应该找到2和4，而不应该找到3
		 * */
		if(hash_table->TheCells[pos].Info != Empty && hash_table->TheCells[pos].Value != i)
		{
			index[0] = i < hash_table->TheCells[pos].Value ? i + 1 :  hash_table->TheCells[pos].Value + 1;
			index[1] = i > hash_table->TheCells[pos].Value ? i + 1 :  hash_table->TheCells[pos].Value + 1;
			*returnSize = 2;

			return index;
		}
	}

    *returnSize = 0;

    return NULL;
}


//int num[] = {2, 11, 7, 15};
//int num[] = {0 , 4, 3 ,0};
int num[] = {-1,-2,-3,-4,-5};
int main(void)
{
	int returnsize;
	int i;
	int *pret_val;

	pret_val = twoSum(num, sizeof(num)/sizeof(num[0]), -8, &returnsize);

	for(i = 0; i < sizeof(num)/sizeof(num[0]); i++)
	{
		printf("num[%d] = %d\n", i, num[i]);
	}

	
	for(i = 0; i < returnsize; i ++)
	{
		printf("#%d = %d\n", i, pret_val[i]);
	}

	return 0;

}
