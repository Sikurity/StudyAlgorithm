//#include <stdio.h>
//
//#define MAX_CASE_NUM		50
//#define MAX_STUDENTS_NUM	10
//#define MAX_FRIENDSSET_NUM	45
//
///** ��������
//*	
//*	����� �� �� ¦������ �� �� ģ�� ��� ����� ��������
//*	��� ¦���� �� �ִ� ����� ���� ���϶�
//*	
//*
//*	ù��° �� : Test CaseNumber[0, 50]
//*	case 1 �� : �л� �� n [2, 10]
//*	case 2 �� : ģ�� ���� �� m [0, Permutation(n, 2)]
//*/
//
//static char aChecked[10];
//static char aFriendSet[MAX_CASE_NUM][MAX_FRIENDSSET_NUM][2];
//static int nStudents[MAX_CASE_NUM];
//static int nFriendSet[MAX_CASE_NUM];
//static int results[MAX_CASE_NUM] = {0, };
//
//static int terminus;
//
//void Algorithm(int);
//void RecursiveCheck(int, int, int);
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int nCaseNum;
//	int i, j;
//
//	FILE *fp = NULL;
//
//	fopen_s(&fp, "input.txt", "r");
//
//	fscanf_s(fp, "%d", &nCaseNum);
//	for( i = 0 ; i < nCaseNum ; i++ )
//	{
//		fscanf_s(fp, "%d %d", &nStudents[i], &nFriendSet[i]);
//		for( j = 0 ; j < nFriendSet[i] ; j++ )
//			fscanf_s(fp, "%d %d ", &aFriendSet[i][j][0], &aFriendSet[i][j][1]);
//	}
//	
//	printf_s("%d\n", nCaseNum);
//	for( i = 0 ; i < nCaseNum ; i++ )
//	{
//		printf_s("%d %d\n", nStudents[i], nFriendSet[i]);
//		for( j = 0 ; j < nFriendSet[i] ; j++ )
//			printf_s("%d %d ", aFriendSet[i][j][0], aFriendSet[i][j][1]);
//
//		Algorithm(i);
//
//		printf_s("\n");
//	}
//
//	for( i = 0 ; i < nCaseNum ; i++ )
//		printf_s("%d : %d \n", i, results[i]);
//
//	fclose(fp);
//
//	return 0;
//}
//
//void Algorithm(int nCaseNum)
//{
//	int i;
//
//	terminus = nStudents[nCaseNum] / 2;
//
//	for( i = 0 ; i < nFriendSet[nCaseNum] ; i++ )
//		RecursiveCheck(nCaseNum, i, 0);
//}
//
//void RecursiveCheck(int nCaseNum, int nCurSlot, int nRepeatNum )
//{
//	int i;
//
//	if( aChecked[aFriendSet[nCaseNum][nCurSlot][0]] || aChecked[aFriendSet[nCaseNum][nCurSlot][1]] )
//		return;
//	
//	aChecked[aFriendSet[nCaseNum][nCurSlot][0]] = 1;
//	aChecked[aFriendSet[nCaseNum][nCurSlot][1]] = 1;
//
//	if( ++nRepeatNum == terminus )
//	{
//		for( i = 0 ; i < nStudents[nCaseNum] ; i++ )
//			if( !aChecked[aFriendSet[nCaseNum][nCurSlot][0]] )
//			{
//				aChecked[aFriendSet[nCaseNum][nCurSlot][0]] = 0;
//				aChecked[aFriendSet[nCaseNum][nCurSlot][1]] = 0;
//
//				return;
//			}
//		
//		results[nCaseNum]++;
//	}
//	else
//		for( i = nCurSlot + 1 ; i < nFriendSet[nCaseNum] ; i++ )
//			RecursiveCheck(nCaseNum, i, nRepeatNum);
//
//	aChecked[aFriendSet[nCaseNum][nCurSlot][0]] = 0;
//	aChecked[aFriendSet[nCaseNum][nCurSlot][1]] = 0;
//
//	return;
//}