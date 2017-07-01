#include<iostream>
#include<assert.h>
#include<windows.h>
#include<math.h>
#define R 10
#define PI 3.14159265359
#define ox 410
#define oy 210
using namespace std;
int main()
{    cout<<"from ink_cherry"<<endl;
    int a[10]={77,83,80,65,73,78,84,13,13};
     keybd_event(91,0,0,0);
     keybd_event(82,0,0,0);
     Sleep(50);
     keybd_event(82,0,KEYEVENTF_KEYUP,0);
     keybd_event(91,0,KEYEVENTF_KEYUP,0);
     for(int i=0;i<9;i++)
     {
         Sleep(300);
         keybd_event(a[i],0,0,0);
         Sleep(50);
         keybd_event(a[i],0,KEYEVENTF_KEYUP,0);
     }

    HWND hwnd;
    POINT cursor;
    Sleep(3000);
//     SetCursorPos(10,171);
//    GetCursorPos(&cursor);
    cursor.x=ox;cursor.y=oy;
    hwnd=WindowFromPoint(cursor);
//      SendMessage(hwnd, WM_LBUTTONDOWN, NULL, MAKELPARAM(cursor.x, cursor.y));
    SendMessage(hwnd, WM_LBUTTONDOWN, NULL, MAKELPARAM(cursor.x-R*(16*sin(PI/2)*sin(PI/2)*sin(PI/2)), cursor.y-R*(-5*cos(PI)-cos(2*PI)))); //°´ÏÂ°´Å¥

    for(double i=PI/2;i<PI*5/2;i=i+0.01)
    {
    Sleep(5);

//  SendMessage(hwnd,WM_MOUSEMOVE,NULL,MAKELPARAM(i, point1.y));
//    SendMessage(hwnd,WM_MOUSEMOVE,NULL,MAKELPARAM((cursor.x)+i  ,cursor,y));
      SendMessage(hwnd,WM_MOUSEMOVE,NULL,MAKELPARAM(ox-R*(16*sin(i)*sin(i)*sin(i)),oy-R*(13*cos(i)-5*cos(2*i)-2*cos(3*i)-cos(4*i))));
//      cout<<ox+R*(cos(i))<<" "<<oy+R*(sin(i))<<endl;
    }
    SendMessage(hwnd,WM_LBUTTONUP,NULL,MAKELPARAM(cursor.x-R*(16*sin(PI/2)*sin(PI/2)*sin(PI/2)),oy-R*(-5*cos(PI)-cos(2*PI))));
    return 0;
}
