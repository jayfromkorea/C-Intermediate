// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
int xPos = 0, yPos = 0, xOldPos = 0, yOldPos = 0;
BOOL bDrag = FALSE;
int nColor = 0;
int Width = 2;



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // 기본 메시지 루프입니다: WM_QUIT
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);

    
}

void draw_mouse_position(HWND hWnd) {

    // device context: 윈도우 내부영역
    HDC hdc = ::GetDC(hWnd);

    // 좌표 출력
    WCHAR lpszPos[100] = { 0 };
    ::wsprintf(lpszPos, L"_______________________________________", xPos, yPos);
    ::TextOutW(hdc, 10, 10, lpszPos, wcslen(lpszPos));
    ::wsprintf(lpszPos, L"X: %d, Y: %d", xPos, yPos);
    ::TextOutW(hdc, 10, 10, lpszPos, wcslen(lpszPos));

    ::ReleaseDC(hWnd, hdc);
}

void draw_mouse_position(HDC hdc, PAINTSTRUCT ps)
{
    // 좌표 출력
    WCHAR lpszPos[100] = { 0 };
    ::wsprintf(lpszPos, L"_______________________________________", xPos, yPos);
    ::TextOutW(hdc, 10, 10, lpszPos, wcslen(lpszPos));
    ::wsprintf(lpszPos, L"X: %d, Y: %d", xPos, yPos);
    ::TextOutW(hdc, 10, 10, lpszPos, wcslen(lpszPos));

}

void drawing(HDC hdc, PAINTSTRUCT ps)
{
    COLORREF color;
    switch (nColor)
    {
    case 0: color = RGB(0, 0, 0); break;
    case 1: color = RGB(255, 0, 0); break;
    case 2: color = RGB(0, 0, 255); break;
    }

    HPEN hPen;
    HPEN hOldPen;
    hPen = ::CreatePen(PS_SOLID, Width, color);

    hOldPen = (HPEN)::SelectObject(hdc, hPen);
    ::MoveToEx(hdc, xOldPos, yOldPos, NULL);
    ::LineTo(hdc, xPos, yPos);

    ::SelectObject(hdc, hOldPen);
    ::DeleteObject(hPen);

    xOldPos = xPos;
    yOldPos = yPos;
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        //  메뉴가 선택되었을 때 발생하는 메시지
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case ID_32771:
                nColor = 0;
                //::MessageBox(hWnd, L"검정색 선택됨", L"드로잉", MB_OK);
                break;
                
            case ID_32772:
                nColor = 1;
                //::MessageBox(hWnd, L"검정색 선택됨", L"드로잉", MB_OK);
                break;
            case ID_32773:
                nColor = 2;
                //::MessageBox(hWnd, L"검정색 선택됨", L"드로잉", MB_OK);
                break;
            case ID_32774:
                Width = 2;
                break;
            case ID_32775:
                Width = 10;
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);    // WM_SESTROY 메시지가 발생됨
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:  // 윈도우 내부 영역을 다시 그릴 필요가 있을 때 발생하는 메시지
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            draw_mouse_position(hdc, ps);

            if (bDrag)
            {
                drawing(hdc, ps);
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:    // x 창닫기를 눌렀을 때 발생하는 메시지
        PostQuitMessage(0); // WM_QUIT
        break;

    case WM_LBUTTONDOWN:
        {
            xOldPos = GET_X_LPARAM(lParam);
            yOldPos = GET_Y_LPARAM(lParam);
            bDrag = TRUE;
        }
        break;

    case WM_LBUTTONUP:
        bDrag = FALSE;
        break;

    case WM_MOUSEMOVE:
        {
            xPos = GET_X_LPARAM(lParam);
            yPos = GET_Y_LPARAM(lParam);

            // WM_PAINT 메시지를 강제로 발생시킴
            ::InvalidateRect(hWnd, NULL, FALSE);
            //draw_mouse_position(hWnd);
        }
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
