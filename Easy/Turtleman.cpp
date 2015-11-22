//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main()
//{
//
//   int i, j, k, cnt, ans, t;
//   
//   int xpos = 0, ypos = 0;
//
//   char way[500];
//
//   int dir = 0;
//   int xmin, xmax;
//   int ymin, ymax;
//
//   scanf("%d", &t);
//
//   while (t--) {
//      ans = 0;
//      dir = 0;
//      xpos = 0;
//      ypos = 0;
//      xmin = 0;
//      xmax = 0;
//      ymin = 0;
//      ymax = 0;
//      memset(way, 0, sizeof(char) * 500);
//
//
//      scanf("%s", way);
//      
//      for (i = 0; i < strlen(way); i++) {
//
//         if (way[i] == 'F') {
//            if (dir == 0) {
//               ypos++;
//               if (ypos > ymax)
//                  ymax = ypos;
//            }
//            else if (dir == 1) {
//               xpos++;
//               if (xpos > xmax)
//                  xmax = xpos;
//            }
//            else if (dir == 2) {
//               ypos--;
//               if (ypos < ymin)
//                  ymin = ypos;
//            }
//            else if (dir == 3) {
//               xpos--;
//               if (xpos < xmin)
//                  xmin = xpos;
//            }
//         }
//         else if (way[i] == 'B') {
//            if (dir == 0) {
//               ypos--;
//               if (ypos < ymin)
//                  ymin = ypos;
//            }
//            else if (dir == 1) {
//               xpos--;
//               if (xpos < xmin)
//                  xmin = xpos;
//            }
//            else if (dir == 2) {
//               ypos++;
//               if (ypos > ymax)
//                  ymax = ypos;
//            }
//            else if (dir == 3) {
//               xpos++;
//               if (xpos > xmax)
//                  xmax = xpos;
//            }
//
//         }
//         else if (way[i] == 'L') {
//            dir = ((dir + 3) % 4);
//
//         }
//         else if (way[i] == 'R') {
//            dir = ((dir + 1) % 4);
//
//         }
//      }
//      printf("%d\n", (xmax - xmin) * (ymax - ymin));
//   }
//   return 0;
//}