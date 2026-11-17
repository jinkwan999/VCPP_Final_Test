#pragma once
#include "framework.h"


class gameBoradPaint
{
private:
	/// 화면 좌상단 좌표 변수
	int screenX;		///< 좌상단 x
	int screenY;		///< 좌상단 y

	/// 점수 계산용 변수
	int score;

	/// 게임판 설정
	int boardX;			///< 좌상단 x좌표
	int boardY;			///< 좌상단 y 좌표
	int cellSize;		///< 1x1 사이즈 크기
	int boardSize;		///< 보드의 총 크기

	/// 임시 블록판 설정
	int tempX;			///< 좌상단 x
	int tempY;			///< 좌상단 y 좌표
	int tempWidth;		///< 우하단 x
	int tempHeight;		///< 우하단 y

public:
	
	/// 생성자
	gameBoradPaint();

	/// 게임판 생성 함수
	/// 전체 틀, 게임판, 임시블록판을 출력한다.
	void gameBoardPaint(HDC hdc);
};