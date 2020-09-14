#include <stdio.h>
#include <stdlib.h>
#include "link.h"

//假定存在头结点
void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
List MakeEmpty(List L)
{
	if (L != NULL)
		DeleteList(L);
	L = malloc(sizeof(Node));
	if (L)
		L->Next = NULL;
	//书中代码
	else 
		printf("out of memory");
	return L;
}
int IsEmpty(List L)
{
	//判断表L是否为空
	return L->Next == NULL;
}
int IsLast(Position P, List L)
{
	//判断元素P是否是表L最后一个元素
	return P->Next == NULL;
}
Position Find(ElementType X, List L)
{
	Position Tmp;
	Tmp = L->Next;
	while (Tmp != NULL && Tmp->Element != X)
	{
		Tmp = Tmp->Next;
	}
	return Tmp;
}
Position FindPrevious(ElementType X, List L)
{
	Position P = L;
	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	return P;	
}
void Delete(ElementType X, List L)
{
	//删除链表L中的元素X
	Position P, Tmp;
	P = FindPrevious(X, L);
	if (!IsLast(P, L))
		//如果表L本身为空呢？
	{
		Tmp = P->Next;
		P->Next = Tmp->Next;
		free(Tmp);
	}
}
void Insert(ElementType X, List L, Position P)
{
	if (!P)
	{
		printf("not legal\n");
		return;
	}
	Position Tmp;
	Tmp = malloc(sizeof(Node));
	if(Tmp)
	{
		Tmp->Element = X;
		Tmp->Next = P->Next;
		P->Next = Tmp;
	}
}
void InsertPrev(ElementType X, List L, Position P)
{
	if (!P)
	{
		printf("\nnot legal\n");
		return;
	}
	Position Prev = FindPrevious(P->Element, L);
	Position Tmp = malloc(sizeof(Node));
	if (Tmp)
	{
		Tmp->Element = X;
		Tmp->Next = P;
		Prev->Next = Tmp;
	}	
}
Position Header(List L)
{
	return L;
}
Position First(List L)
{
	return L->Next;
}
Position Advance(Position P)
{
	return P->Next;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}


void Travel(List L)
{
	printf("\nLet's travel\n-----------\n");
	Position p;
	p = L->Next;
	while (p)
	{
		printf("%d\t", Retrieve(p));
		p = p->Next;
	}
}

void PrintLots(List L, List P)
{
	printf("\nFind L in P\n-----------------\n");
	Position lPos, pPos;
	int counter = 1;
	lPos = First(L);
	pPos = First(P);
	while (lPos && pPos)
	{
		if (pPos->Element == counter++)
		{
			printf("%d\t", lPos->Element);
			pPos = pPos->Next;
		}
		lPos = lPos->Next;
	}
}

void SwapWithNext(List L, Position BeforeP)
{
	Position Tmp = BeforeP->Next;
	BeforeP->Next = BeforeP->Next->Next;

	Position Tmp2 = BeforeP->Next->Next;
	BeforeP->Next->Next = Tmp;
	BeforeP->Next->Next->Next = Tmp2;
}

List Intersect(List L1, List L2)
{
	List Result;
	Position L1pos, L2pos, ResultPos;
	Result = MakeEmpty(NULL);
	L1pos = First(L1);
	L2pos = First(L2);
	ResultPos = Header(Result);

	while (L1pos && L2pos)
	{
		if (L1pos->Element < L2pos->Element)
			L1pos = L1pos->Next;
		else if (L1pos->Element > L2pos->Element)
			L2pos = L2pos->Next;
		else
		{
			Insert(L1pos->Element, Result, ResultPos);
			L1pos = Advance(L1pos);
			L2pos = Advance(L2pos);
			ResultPos = Advance(ResultPos);
		}
	}
	return Result;
}