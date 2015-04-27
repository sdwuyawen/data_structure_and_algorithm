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

/* Interface for separate chaining hash table */
typedef int ElementType;

typedef unsigned int Index;

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( ElementType Key, HashTable H );
void Insert( ElementType Key, ElementType Value, HashTable H );
ElementType Retrieve( Position P );
/* Routines such as Delete are MakeEmpty are omitted */

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

#define MinTableSize (10)

struct ListNode
{
	ElementType Element;
	ElementType Value;
	Position    Next;
};

typedef Position List;

/* List *TheList will be an array of lists, allocated later */
/* The lists use headers (for simplicity), */
/* though this wastes space */
struct HashTbl
{
	int TableSize;
	List *TheLists;
};

/* Return next prime; assume N >= 10 */
/* 找到下一个素数  */
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

	/* Allocate array of lists */
	H->TheLists = malloc( sizeof( List ) * H->TableSize );
	if( H->TheLists == NULL )
		FatalError( "Out of space!!!" );

	/* Allocate list headers */
	for( i = 0; i < H->TableSize; i++ )
	{
		H->TheLists[ i ] = malloc( sizeof( struct ListNode ) );
		if( H->TheLists[ i ] == NULL )
			FatalError( "Out of space!!!" );
		else
			H->TheLists[ i ]->Next = NULL;
	}

	return H;
}

Position Find( ElementType Key, HashTable H )
{
	Position P;
	List L;

	L = H->TheLists[ Hash( Key, H->TableSize ) ];
	P = L->Next;
	while( P != NULL && P->Element != Key )
		/* Probably need strcmp!! */
		P = P->Next;
	return P;
}
/* END */

/* START: fig5_10.txt */
/* 
 * Key是关键字
 * Value是数值
 * H是散列表
 */
void Insert( ElementType Key, ElementType Value, HashTable H )
{
	Position Pos, NewCell;
	List L;

	Pos = Find( Key, H );
	if( Pos == NULL )   /* Key is not found */
	{
		NewCell = malloc( sizeof( struct ListNode ) );
		if( NewCell == NULL )
			FatalError( "Out of space!!!" );
		else
		{
			L = H->TheLists[ Hash( Key, H->TableSize ) ];
			NewCell->Next = L->Next;
			NewCell->Element = Key;  /* Probably need strcpy! */
			NewCell->Value = Value;
			L->Next = NewCell;
		}
	}
}
/* END */

/* 检索 */
ElementType Retrieve( Position P )
{
	return P->Element;
}

void DestroyTable( HashTable H )
{
	int i;

	for( i = 0; i < H->TableSize; i++ )
	{
		Position P = H->TheLists[ i ];
		Position Tmp;

		while( P != NULL )
		{
			Tmp = P->Next;
			free( P );
			P = Tmp;
		}
	}

	free( H->TheLists );
	free( H );
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;

    int *index;
	int *array;

	HashTable hash_table;
	struct ListNode *node;

	hash_table = InitializeTable(10);

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
		node = Find(target - nums[i], hash_table);

		if(node != NULL)
		{
			index[0] = i < node->Value ? i + 1 : node->Value + 1;
			index[1] = i > node->Value ? i + 1 : node->Value + 1;
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
