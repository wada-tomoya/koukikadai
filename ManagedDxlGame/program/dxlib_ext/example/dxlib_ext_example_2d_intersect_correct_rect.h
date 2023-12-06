#pragma once


/*

//-----------------------------------------------------------------------------------------------------------
//
//
// 2D ��`���m�̏Փ˔���ƕ␳�T���v��
//
//
//-----------------------------------------------------------------------------------------------------------


#include <time.h>
#include <string>
#include <numbers>
#include <functional>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"

tnl::Vector3 posA = { 100, 100, 0 };
tnl::Vector2i sizeA = { 50, 50 };

tnl::Vector3 posB = { 400, 400, 0 };
tnl::Vector2i sizeB = { 200, 20 };

//------------------------------------------------------------------------------------------------------------
// �Q�[���N�����ɂP�x�������s����܂�
void gameStart() {
	srand(time(0));
	SetBackgroundColor(32, 32, 32);

}

//------------------------------------------------------------------------------------------------------------
// ���t���[�����s����܂�
void gameMain(float delta_time) {

	tnl::Vector3 before_A = posA;
	tnl::Vector3 before_B = posB;

	if (tnl::Input::IsKeyDown(eKeys::KB_A)) posA.x -= 6;
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) posA.x += 6;
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) posA.y -= 6;
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) posA.y += 6;

	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) posB.x -= 5;
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) posB.x += 5;
	if (tnl::Input::IsKeyDown(eKeys::KB_UP))	posB.y -= 5;
	if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) posB.y += 5;

	if (tnl::IsIntersectRect(posA, sizeA.x, sizeA.y, posB, sizeB.x, sizeB.y)) {

		// ��`���m�̍��W�␳
		// arg1.2. ��` A, B �̈ړ��O�̍��W
		// arg3.4. ��` A, B �̃T�C�Y
		// arg5.6. ��` A, B �̈ړ���̍��W ( ���̊֐��ɂ���ĕ␳��̍��W�ɍX�V )
		// arg7.8. ��, �c �����̕␳�^�C�v
		// ....... [ PWRFL_A : A �� ���� ] [ PWRFL_B : B �� ���� ] [ BOTH : A �� B �͉������� ]
		// arg9... �␳��� A �� B �̊Ԃɐ݂����� ( �f�t�H���g 1.0f )
		// ret.... ��` A �� B �ɑ΂��Ăǂ̕����֕␳���ꂽ��
		tnl::eCorrResRect n = tnl::CorrectPositionRect(
			before_A
			, before_B
			, sizeA
			, sizeB
			, posA
			, posB
			, tnl::eCorrTypeRect::PWRFL_A
			, tnl::eCorrTypeRect::PWRFL_A, 1.0f);

		std::string s[4] = { "��", "�E", "��", "��" };
		DrawStringEx(0, 0, -1, "%s", s[(int)n].c_str());
	}

	DrawBoxEx(posA, sizeA.x, sizeA.y, false, -1);
	DrawBoxEx(posB, sizeB.x, sizeB.y, false, -1);

	DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10, 0 }, delta_time);
}

//------------------------------------------------------------------------------------------------------------
// �Q�[���I�����ɂP�x�������s����܂�
void gameEnd() {

}



*/

