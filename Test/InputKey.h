#pragma once

// �ŐV�̃L�[�{�[�h���p
static char keys[256];

// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
static char oldkeys[256];

// ����������
void KeyInit();

// �X�V����
void KeyUpdate();

// �O�t���[����������Ă��Ȃ���Ԃ��牟���ꂽ�ꍇTRUE
bool IsKeyInputNow(int key);

// ������Ă��ė����ꂽ�u��TRUE
bool IsKeyInputRelease(int key);