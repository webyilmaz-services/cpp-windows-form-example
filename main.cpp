#include <windows.h>
#include <stdio.h>

using namespace std;
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		case WM_CREATE:{
			MessageBox(NULL, "Window Created!","Window Created!",MB_ICONEXCLAMATION|MB_OK);
			
			CreateWindow(TEXT("STATIC"),TEXT("MyText"),
			WS_VISIBLE | WS_CHILD,
			10,10,100,25,
			hwnd, (HMENU)NULL,NULL,NULL);
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wnd;
	HWND hwnd; 
	MSG xmsg; 
	memset(&wnd,0,sizeof(wnd));
	wnd.cbSize		 = sizeof(WNDCLASSEX);
	wnd.lpfnWndProc	 = WndProc; 
	wnd.hInstance	 = hInstance;
	wnd.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wnd.lpszClassName = "WindowClass";
	if(!RegisterClassEx(&wnd)) {
		MessageBox(NULL, "Error!!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Window Example",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		800, 
		800,
		NULL,NULL,hInstance,NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	while(GetMessage(&xmsg, NULL, 0, 0) > 0) { 
		TranslateMessage(&xmsg); 
		DispatchMessage(&xmsg); 
	}
	return xmsg.wParam;
	
}
