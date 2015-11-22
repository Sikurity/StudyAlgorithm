//#include <stdio.h>
//#include <string.h>
//#include <time.h>
//
//typedef enum BOOL{FALSE, TRUE} BOOL;
//
//typedef enum DIRECTION{NORTH, RIGHT, SOUTH, LEFT} DIRECTION;
//
//char strCmd[11] = {0, };
//char arsMaze[100][101] = {0, };
//
//char unRoadAlreadyBeen[100][100][10][4] = {0, };
//
//int nFreeTerrain;
//
//int nHeight;
//int nWidth;
//
//int nCmdLen;
//
//int nResult;
//
//void Init();
//void DoAllCase();
//BOOL check(int x, int y);
//char DoCmd(int x, int y, int cnt, DIRECTION dir);
//
//int main()
//{
//	int nCase;
//
//	int i;
//	BOOL bContinue;
//
//	FILE *in, *out;
//	clock_t start, end;
//
//	in = fopen("input.txt", "r+");
//	out = fopen("output.txt", "w");
//
//	nCase = 0;
//
//	do
//	{
//		Init();
//
//		if( fscanf(in, "%d %d", &nHeight, &nWidth) != 2 )
//			break;
//
//		for( i = 0 ; i < nHeight ; i++ )
//			fscanf(in, "%s", arsMaze[i]);
//
//		fscanf(in, "%d", &nCmdLen);
//		
//		bContinue = (BOOL)(fscanf(in, "%s", strCmd) != EOF);
//
//		start = clock();
//		DoAllCase();
//		end = clock();
//
//		if( nResult == nFreeTerrain )
//			fprintf(out, "OK\n");
//		else
//			fprintf(out, "%d\n", nResult);
//
//		memset(unRoadAlreadyBeen, 0, sizeof(unRoadAlreadyBeen));
//
//		printf("[%d] : %f\n", ++nCase, ((double)(end - start)) / CLOCKS_PER_SEC );
//	}
//	while( bContinue );
//
//	return 0;
//}
//
//
//void Init()
//{
//	nResult = 0;
//	nFreeTerrain = 0;
//}
//
//void DoAllCase()
//{
//	int i, j;
//
//	for( i = 0 ; i < nHeight ; i++ )
//		for( j = 0 ; j < nWidth ; j++ )
//		{
//			if( arsMaze[i][j] == 'X' )
//				continue;
//
//			nFreeTerrain++;
//
//			if( DoCmd(j, i, 0, NORTH) == 1 )
//				nResult++;
//		}
//}
//
//char DoCmd(int x, int y, int cnt, DIRECTION dir)
//{
//	int nX, nY, nCnt;
//	DIRECTION nDir;
//
//	if( arsMaze[y][x] == 'E' )
//		return 1;
//
//	if( unRoadAlreadyBeen[y][x][cnt][dir] )
//		return unRoadAlreadyBeen[y][x][cnt][dir];
//	else
//	{
//		nX = x;
//		nY = y;
//		nCnt = cnt;
//		nDir = dir;
//
//		unRoadAlreadyBeen[y][x][cnt][dir] = -1;
//
//		switch( strCmd[cnt] )
//		{
//		case 'S':
//			switch( dir )
//			{
//				case NORTH:
//					if( check(x, y - 1) )
//						nY -= 1;
//					break;
//				case RIGHT:
//					if( check(x + 1, y) )
//						nX += 1;
//					break;
//				case SOUTH:
//					if( check(x, y + 1) )
//						nY += 1;
//					break;
//				case LEFT:
//					if( check(x - 1, y) )
//						nX -= 1;
//					break;
//			}
//			break;
//		case 'L':
//			nDir = (DIRECTION)((dir + 3) % 4);
//			break;
//		case 'R':
//			nDir = (DIRECTION)((dir + 1) % 4);
//			break;
//		}
//		
//		nCnt = (cnt + 1) % nCmdLen;
//
//		unRoadAlreadyBeen[y][x][cnt][dir] = DoCmd(nX, nY, nCnt, nDir);
//	}
//}
//
//BOOL check(int x, int y)
//{
//	return (x < 0 || x >= nWidth || y < 0 || y >= nHeight || arsMaze[y][x] == 'X') ? FALSE : TRUE;
//}