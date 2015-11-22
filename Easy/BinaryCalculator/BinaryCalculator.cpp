//#include "stdafx.h"
//
//#define MAX_LENGTH		80
//
//static char arBinary[2][MAX_LENGTH + 1];
//static char result[MAX_LENGTH + 2] = {0, };
//
//void Algorithm();
//
//int main()
//{
//	int i = 0;
//	char szTmp[MAX_LENGTH + 1];
//
//	FILE *fp;
//	fp = fopen("test.txt", "r+");
//    
//	fscanf(fp, "%s %s", arBinary[0], arBinary[1]);
//
//	if( strlen(arBinary[0]) < strlen(arBinary[1]) )
//	{
//		strcpy(szTmp, arBinary[1]);
//		strcpy(arBinary[1], arBinary[0]);
//		strcpy(arBinary[0], szTmp);
//	}
//
//	Algorithm();
//
//	printf("%s", result);
//    
//	fclose(fp);
//
//	return 0;
//}
//
//void Algorithm()
//{
//	int i, cnt, tmp = 0;
//	int diff = 0;
//	int length[2];
//	
//	length[0] = strlen(arBinary[0]);
//	length[1] = strlen(arBinary[1]);
//
//	i = 0;
//	while( arBinary[0][i] )
//	{
//		arBinary[0][i++] -= '0';
//	}
//	arBinary[0][i] = -1;
//
//	i = 0;
//	while( arBinary[1][i] )
//	{
//		arBinary[1][i++] -= '0';
//	}
//	arBinary[1][i] = -1;
//
//	diff = length[0] - length[1];
//
//	for( i = length[0] - 1 ; i >= 0 ; i-- )
//	{
//		if( i - diff >= 0)
//			result[i] = arBinary[0][i] + arBinary[1][i - diff] + tmp;
//		else
//			result[i] = arBinary[0][i] + tmp;
//
//		switch( result[i] )
//		{
//		case 0:
//			tmp = 0;
//			result[i] = 0;
//			break;
//		case 1:
//			tmp = 0;
//			result[i] = 1;
//			break;
//		case 2 :
//			tmp = 1;
//			result[i] = 0;
//			break;
//		case 3 :
//			tmp = 1;
//			result[i] = 1;
//			break;
//		}
//	}
//	
//	for( i = length[0] - 1 ; i >= 0 ; i-- )
//	{
//		result[i] += '0';
//
//		if( tmp )
//			result[i + 1] = result[i];
//			
//	}
//
//	if( tmp )
//	{
//		result[0] = '1';
//		result[length[0] + 1] = NULL;
//	}
//	else
//		result[length[0]] = NULL;
//
//	cnt = 0;
//
//	for( i = 0 ; i < strlen(result) ; i++ )
//	{
//		if( result[i] == '0' )
//			cnt++;
//		else 
//			break;
//	}
//
//	for( i = 0 ; i < strlen(result) - cnt ; i++ )
//		result[i] = result[i + cnt];
//
//	result[i] = NULL;
//
//	if( !result[0] )
//	{
//		result[0] = '0';
//		result[1] = NULL;
//	}
//
//	return;
//}