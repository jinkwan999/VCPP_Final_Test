#include "GameBoardPaint.h"

/// 게임판 
gameBoradPaint::gameBoradPaint()
{
    /// 화면 좌상단 좌표 변수
    screenX = 10;
    screenY = 10;

    /// 점수 계산용 변수
    score = 0;

    /// 게임판 설정
    boardX = screenX + 135;
    boardY = screenY + 50;
    cellSize = 39;                      
    boardSize = cellSize * 10;          

    /// 임시 블록판 설정
    tempX = screenX + 10;
    tempY = screenY + 460;
    tempWidth = 630;
    tempHeight = 240;
}

void gameBoradPaint::gameBoardPaint(HDC hdc)
{
    /// 선 두께 변경
    HPEN myPen, osPen;
    myPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    osPen = (HPEN)SelectObject(hdc, myPen);

    /// 게임 전체 화면 출력
    Rectangle(hdc, screenX, screenY, screenX + 650, screenY + 710);

    /// 브러시 색상 변경
    HBRUSH myBrush, osBrush;
    myBrush = CreateSolidBrush(RGB(232, 232, 232));
    osBrush = (HBRUSH)SelectObject(hdc, myBrush);

    /// 게임판 출력
    Rectangle(hdc, boardX - 2, boardY - 2, boardX + boardSize + 2, boardY + boardSize + 2);

    /// 임시 블록판 출력
    Rectangle(hdc, tempX - 2, tempY - 2, tempX + tempWidth + 2, tempY + tempHeight + 2);

    /// 브러시 해제
    SelectObject(hdc, osBrush);
    DeleteObject(myBrush);

    /// 게임판 사이 구분선 색 변경
    myPen = CreatePen(PS_SOLID, 2, RGB(60, 60, 60));
    osPen = (HPEN)SelectObject(hdc, myPen);

    /// 게임판 사이 구분선 출력 위 > 아래
    for (int i = 1; i <= 9; i++)
    {
        MoveToEx(hdc, boardX + (cellSize * i), boardY, NULL);

        LineTo(hdc, boardX + (cellSize * i), boardY + boardSize);
    }
    /// 게임판 사이 구분선 출력 좌 > 우
    for (int i = 1; i <= 9; i++)
    {
        MoveToEx(hdc, boardX, boardY + (cellSize * i), NULL);

        LineTo(hdc, boardX + boardSize, boardY + (cellSize * i));
    }

    /// 펜 해제
    SelectObject(hdc, osPen);
    DeleteObject(myPen);

    /// 글씨 크기 증가 시키기 및 글꼴 변경
    HFONT hFont = CreateFont(30, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"맑은 고딕");

    // 기존 글꼴 저장 후 적용
    HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

    /// 점수 출력
    WCHAR buf[128] = { 0, };
    wsprintf(buf, L"점수 : %d", score);
    TextOut(hdc, 295, 20, buf, lstrlen(buf));

    // 기존 글꼴 복원 및 생성한 글꼴 제거
    SelectObject(hdc, oldFont);
    DeleteObject(hFont);
}