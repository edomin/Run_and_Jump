#ifndef RNJ_INPUT_DUMMY_H
#define RNJ_INPUT_DUMMY_H

#include BOOLLIB
#include <stdint.h>

struct {
    bool currentKeystate[513]; /* ������� ��������� ���������� */
    bool previousKeystate[513];
    bool currentMouseLeft; /* ������� ��������� ����� ������� ���� */
    bool currentMouseMiddle; /* ������� ��������� ������� ������� ���� */
    bool currentMouseRight; /* ������� ��������� ������ ������� ���� */
    bool previousMouseLeft; /* ���������� ��������� ����� ������� ���� */
    bool previousMouseMiddle; /* ���������� ��������� ������� ������� ���� */
    bool previousMouseRight; /* ���������� ��������� ������ ������� ���� */
} Input;
//
void InputInit(void); /* ������������� ����� */
void InputQuit(void);
void InputKeystatesRefresh(void); /* ���������� ��������� ���������� */
bool InputKeyPress(signed int); /* �������� ������� ������� */
bool InputKeyRelease(signed int); /* �������� ���������� ������� */
bool InputKeyPressed(signed int); /* �������� ������� ������� */
void InputMouseRefresh(void); /* ���������� ��������� ���� */
void InputControllersRefresh(void); /* �������� ���������� � ��������� ������������ */
bool InputControllerButtonPress(int, uint8_t); /* �������� ������� ������ */
bool InputControllerButtonRelease(int, uint8_t); /* �������� ���������� ������ */
bool InputControllerButtonPressed(int, uint8_t); /* �������� ������� ������ */
int16_t InputControllerGetAxis(int, int); /* ��������� �������� ��� */
//
#endif
