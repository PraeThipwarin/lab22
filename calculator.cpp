#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND , UINT ,WPARAM ,LPARAM);
char text1[20];
char text2[20];
HWND textfield,textbox1,textbox2,button;

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE:
			textfield = CreateWindow("STATIC","   Please input two numbers",WS_VISIBLE|WS_CHILD|WS_BORDER,20,20,200,20,hwnd,NULL,NULL,NULL);
			textbox1 = CreateWindow("EDIT","",WS_VISIBLE|WS_CHILD|WS_BORDER,50,50,140,20,hwnd,NULL,NULL,NULL);
			textbox2 = CreateWindow("EDIT","",WS_VISIBLE|WS_CHILD|WS_BORDER,50,80,140,20,hwnd,NULL,NULL,NULL);
			button = CreateWindow("BUTTON","+",WS_VISIBLE|WS_CHILD|WS_BORDER,50,120,30,20,hwnd,(HMENU) 1,NULL,NULL);
			button = CreateWindow("BUTTON","-",WS_VISIBLE|WS_CHILD|WS_BORDER,85,120,30,20,hwnd,(HMENU) 2,NULL,NULL);
			button = CreateWindow("BUTTON","*",WS_VISIBLE|WS_CHILD|WS_BORDER,125,120,30,20,hwnd,(HMENU) 3,NULL,NULL);
			button = CreateWindow("BUTTON","/",WS_VISIBLE|WS_CHILD|WS_BORDER,160,120,30,20,hwnd,(HMENU) 4,NULL,NULL);
			break;
		
		case WM_COMMAND: 
				if(LOWORD(wParam)!=0){
					int gwtstat1 = 0,gwtstat2 = 0;
					gwtstat1 = GetWindowText(textbox1,&text1[0],20);
					gwtstat2 = GetWindowText(textbox2,&text2[0],20);
				}
				if(LOWORD(wParam)==1){
					float re=atof(text1)+atof(text2);
					char t[100];
					sprintf(t, "%f", re);
					:: MessageBox(hwnd,t,"Result",MB_OK);
				}
				if(LOWORD(wParam)==2){
					float re=atof(text1)-atof(text2);
					char t[100];
					sprintf(t, "%f", re);
					:: MessageBox(hwnd,t,"Result",MB_OK);
				}
				if(LOWORD(wParam)==3){
					float re=atof(text1)*atof(text2);
					char t[100];
					sprintf(t, "%f", re);
					:: MessageBox(hwnd,t,"Result",MB_OK);
				}
				if(LOWORD(wParam)==4){
					float re=atof(text1)/atof(text2);
					char t[100];
					sprintf(t, "%f", re);
					:: MessageBox(hwnd,t,"Result",MB_OK);
				}
				break;			
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	HWND hwnd;
	MSG msg;

	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hCursor	= LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+9);
	wc.lpszClassName = "WindowClass";
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm	= LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL,"Window Registration Failed!","Error!", MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		250,
		200,
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL,"Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	while(GetMessage(&msg, NULL, 0, 0) > 0){ 
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}