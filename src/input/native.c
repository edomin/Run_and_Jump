#include "input/native.h"

void kolibrios_InputSetScancodeMode(void)
{
    __asm__ __volatile__(
    "int $0x40"
    :
    :"a"(66),"b"(1),"c"(1)
    :"memory");
}

Uint8 kolibrios_InputGetScancode(void)
{
    uint32_t eax;

    __asm__ __volatile__(
    "int $0x40"
    :"=a"(eax)
    :"a"(2)
    :"memory");

    if (eax != 1)
    {
        return (Uint8)(eax >> 8);
    }
    else
    {
        return 0;
    }
}

Uint8 *GetKeyboardState(void)
{
    Uint8 scancode;
    Uint8 scancode2;
    Uint8 scancode4;

    scancode = kolibrios_InputGetScancode();
    switch (scancode)
    {
        case 0x1E:
            Input.keyboardState[RNJ_KEY_A] = 1;
            break;
        case 0x30:
            Input.keyboardState[RNJ_KEY_B] = 1;
            break;
        case 0x2E:
            Input.keyboardState[RNJ_KEY_C] = 1;
            break;
        case 0x20:
            Input.keyboardState[RNJ_KEY_D] = 1;
            break;
        case 0x12:
            Input.keyboardState[RNJ_KEY_E] = 1;
            break;
        case 0x21:
            Input.keyboardState[RNJ_KEY_F] = 1;
            break;
        case 0x22:
            Input.keyboardState[RNJ_KEY_G] = 1;
            break;
        case 0x23:
            Input.keyboardState[RNJ_KEY_H] = 1;
            break;
        case 0x17:
            Input.keyboardState[RNJ_KEY_I] = 1;
            break;
        case 0x24:
            Input.keyboardState[RNJ_KEY_J] = 1;
            break;
        case 0x25:
            Input.keyboardState[RNJ_KEY_K] = 1;
            break;
        case 0x26:
            Input.keyboardState[RNJ_KEY_L] = 1;
            break;
        case 0x32:
            Input.keyboardState[RNJ_KEY_M] = 1;
            break;
        case 0x31:
            Input.keyboardState[RNJ_KEY_N] = 1;
            break;
        case 0x18:
            Input.keyboardState[RNJ_KEY_O] = 1;
            break;
        case 0x19:
            Input.keyboardState[RNJ_KEY_P] = 1;
            break;
        case 0x10:
            Input.keyboardState[RNJ_KEY_Q] = 1;
            break;
        case 0x13:
            Input.keyboardState[RNJ_KEY_R] = 1;
            break;
        case 0x1F:
            Input.keyboardState[RNJ_KEY_S] = 1;
            break;
        case 0x14:
            Input.keyboardState[RNJ_KEY_T] = 1;
            break;
        case 0x16:
            Input.keyboardState[RNJ_KEY_U] = 1;
            break;
        case 0x2F:
            Input.keyboardState[RNJ_KEY_V] = 1;
            break;
        case 0x11:
            Input.keyboardState[RNJ_KEY_W] = 1;
            break;
        case 0x2D:
            Input.keyboardState[RNJ_KEY_X] = 1;
            break;
        case 0x15:
            Input.keyboardState[RNJ_KEY_Y] = 1;
            break;
        case 0x2C:
            Input.keyboardState[RNJ_KEY_Z] = 1;
            break;
        case 0x0B:
            Input.keyboardState[RNJ_KEY_0] = 1;
            break;
        case 0x02:
            Input.keyboardState[RNJ_KEY_1] = 1;
            break;
        case 0x03:
            Input.keyboardState[RNJ_KEY_2] = 1;
            break;
        case 0x04:
            Input.keyboardState[RNJ_KEY_3] = 1;
            break;
        case 0x05:
            Input.keyboardState[RNJ_KEY_4] = 1;
            break;
        case 0x06:
            Input.keyboardState[RNJ_KEY_5] = 1;
            break;
        case 0x07:
            Input.keyboardState[RNJ_KEY_6] = 1;
            break;
        case 0x08:
            Input.keyboardState[RNJ_KEY_7] = 1;
            break;
        case 0x09:
            Input.keyboardState[RNJ_KEY_8] = 1;
            break;
        case 0x0A:
            Input.keyboardState[RNJ_KEY_9] = 1;
            break;
        case 0x29:
            Input.keyboardState[RNJ_KEY_TILDE] = 1;
            break;
        case 0x0C:
            Input.keyboardState[RNJ_KEY_MINUS] = 1;
            break;
        case 0x0D:
            Input.keyboardState[RNJ_KEY_EQUALS] = 1;
            break;
        case 0x2B:
            Input.keyboardState[RNJ_KEY_BACKSLASH] = 1;
            break;
        case 0x1A:
            Input.keyboardState[RNJ_KEY_LEFTBRACKET] = 1;
            break;
        case 0x1B:
            Input.keyboardState[RNJ_KEY_RIGHTBRACKET] = 1;
            break;
        case 0x27:
            Input.keyboardState[RNJ_KEY_SEMICOLON] = 1;
            break;
        case 0x28:
            Input.keyboardState[RNJ_KEY_APOSTROPHE] = 1;
            break;
        case 0x33:
            Input.keyboardState[RNJ_KEY_COMMA] = 1;
            break;
        case 0x34:
            Input.keyboardState[RNJ_KEY_PERIOD] = 1;
            break;
        case 0x35:
            Input.keyboardState[RNJ_KEY_SLASH] = 1;
            break;
        case 0x0E:
            Input.keyboardState[RNJ_KEY_BACKSPACE] = 1;
            break;
        case 0x39:
            Input.keyboardState[RNJ_KEY_SPACE] = 1;
            break;
        case 0x0F:
            Input.keyboardState[RNJ_KEY_TAB] = 1;
            break;
        case 0x3A:
            Input.keyboardState[RNJ_KEY_CAPSLOCK] = 1;
            break;
        case 0x2A:
            Input.keyboardState[RNJ_KEY_LSHIFT] = 1;
            break;
        case 0x1D:
            Input.keyboardState[RNJ_KEY_LCTRL] = 1;
            break;
        case 0x38:
            Input.keyboardState[RNJ_KEY_LALT] = 1;
            break;
        case 0x36:
            Input.keyboardState[RNJ_KEY_RSHIFT] = 1;
            break;
        case 0x1C:
            Input.keyboardState[RNJ_KEY_RETURN] = 1;
            break;
        case 0x01:
            Input.keyboardState[RNJ_KEY_ESCAPE] = 1;
            break;
        case 0x3B:
            Input.keyboardState[RNJ_KEY_F1] = 1;
            break;
        case 0x3C:
            Input.keyboardState[RNJ_KEY_F2] = 1;
            break;
        case 0x3D:
            Input.keyboardState[RNJ_KEY_F3] = 1;
            break;
        case 0x3E:
            Input.keyboardState[RNJ_KEY_F4] = 1;
            break;
        case 0x3F:
            Input.keyboardState[RNJ_KEY_F5] = 1;
            break;
        case 0x40:
            Input.keyboardState[RNJ_KEY_F6] = 1;
            break;
        case 0x41:
            Input.keyboardState[RNJ_KEY_F7] = 1;
            break;
        case 0x42:
            Input.keyboardState[RNJ_KEY_F8] = 1;
            break;
        case 0x43:
            Input.keyboardState[RNJ_KEY_F9] = 1;
            break;
        case 0x44:
            Input.keyboardState[RNJ_KEY_F10] = 1;
            break;
        case 0x57:
            Input.keyboardState[RNJ_KEY_F11] = 1;
            break;
        case 0x58:
            Input.keyboardState[RNJ_KEY_F12] = 1;
            break;
        case 0x46:
            Input.keyboardState[RNJ_KEY_SCROLLLOCK] = 1;
            break;
        case 0x45:
            Input.keyboardState[RNJ_KEY_NUMLOCK] = 1;
            break;
        case 0x37:
            Input.keyboardState[RNJ_KEY_KP_MULTIPLY] = 1;
            break;
        case 0x4A:
            Input.keyboardState[RNJ_KEY_KP_MINUS] = 1;
            break;
        case 0x4E:
            Input.keyboardState[RNJ_KEY_KP_PLUS] = 1;
            break;
        case 0x53:
            Input.keyboardState[RNJ_KEY_KP_PERIOD] = 1;
            break;
        case 0x52:
            Input.keyboardState[RNJ_KEY_KP_0] = 1;
            break;
        case 0x4F:
            Input.keyboardState[RNJ_KEY_KP_1] = 1;
            break;
        case 0x50:
            Input.keyboardState[RNJ_KEY_KP_2] = 1;
            break;
        case 0x51:
            Input.keyboardState[RNJ_KEY_KP_3] = 1;
            break;
        case 0x4B:
            Input.keyboardState[RNJ_KEY_KP_4] = 1;
            break;
        case 0x4C:
            Input.keyboardState[RNJ_KEY_KP_5] = 1;
            break;
        case 0x4D:
            Input.keyboardState[RNJ_KEY_KP_6] = 1;
            break;
        case 0x47:
            Input.keyboardState[RNJ_KEY_KP_7] = 1;
            break;
        case 0x48:
            Input.keyboardState[RNJ_KEY_KP_8] = 1;
            break;
        case 0x49:
            Input.keyboardState[RNJ_KEY_KP_9] = 1;
            break;

        case 0x9E:
            Input.keyboardState[RNJ_KEY_A] = 0;
            break;
        case 0xB0:
            Input.keyboardState[RNJ_KEY_B] = 0;
            break;
        case 0xAE:
            Input.keyboardState[RNJ_KEY_C] = 0;
            break;
        case 0xA0:
            Input.keyboardState[RNJ_KEY_D] = 0;
            break;
        case 0x92:
            Input.keyboardState[RNJ_KEY_E] = 0;
            break;
        case 0xA1:
            Input.keyboardState[RNJ_KEY_F] = 0;
            break;
        case 0xA2:
            Input.keyboardState[RNJ_KEY_G] = 0;
            break;
        case 0xA3:
            Input.keyboardState[RNJ_KEY_H] = 0;
            break;
        case 0x97:
            Input.keyboardState[RNJ_KEY_I] = 0;
            break;
        case 0xA4:
            Input.keyboardState[RNJ_KEY_J] = 0;
            break;
        case 0xA5:
            Input.keyboardState[RNJ_KEY_K] = 0;
            break;
        case 0xA6:
            Input.keyboardState[RNJ_KEY_L] = 0;
            break;
        case 0xB2:
            Input.keyboardState[RNJ_KEY_M] = 0;
            break;
        case 0xB1:
            Input.keyboardState[RNJ_KEY_N] = 0;
            break;
        case 0x98:
            Input.keyboardState[RNJ_KEY_O] = 0;
            break;
        case 0x99:
            Input.keyboardState[RNJ_KEY_P] = 0;
            break;
        case 0x90:
            Input.keyboardState[RNJ_KEY_Q] = 0;
            break;
        case 0x93:
            Input.keyboardState[RNJ_KEY_R] = 0;
            break;
        case 0x9F:
            Input.keyboardState[RNJ_KEY_S] = 0;
            break;
        case 0x94:
            Input.keyboardState[RNJ_KEY_T] = 0;
            break;
        case 0x96:
            Input.keyboardState[RNJ_KEY_U] = 0;
            break;
        case 0xAF:
            Input.keyboardState[RNJ_KEY_V] = 0;
            break;
        case 0x91:
            Input.keyboardState[RNJ_KEY_W] = 0;
            break;
        case 0xAD:
            Input.keyboardState[RNJ_KEY_X] = 0;
            break;
        case 0x95:
            Input.keyboardState[RNJ_KEY_Y] = 0;
            break;
        case 0xAC:
            Input.keyboardState[RNJ_KEY_Z] = 0;
            break;
        case 0x8B:
            Input.keyboardState[RNJ_KEY_0] = 0;
            break;
        case 0x82:
            Input.keyboardState[RNJ_KEY_1] = 0;
            break;
        case 0x83:
            Input.keyboardState[RNJ_KEY_2] = 0;
            break;
        case 0x84:
            Input.keyboardState[RNJ_KEY_3] = 0;
            break;
        case 0x85:
            Input.keyboardState[RNJ_KEY_4] = 0;
            break;
        case 0x86:
            Input.keyboardState[RNJ_KEY_5] = 0;
            break;
        case 0x87:
            Input.keyboardState[RNJ_KEY_6] = 0;
            break;
        case 0x88:
            Input.keyboardState[RNJ_KEY_7] = 0;
            break;
        case 0x89:
            Input.keyboardState[RNJ_KEY_8] = 0;
            break;
        case 0x8A:
            Input.keyboardState[RNJ_KEY_9] = 0;
            break;
        case 0xA9:
            Input.keyboardState[RNJ_KEY_TILDE] = 0;
            break;
        case 0x8C:
            Input.keyboardState[RNJ_KEY_MINUS] = 0;
            break;
        case 0x8D:
            Input.keyboardState[RNJ_KEY_EQUALS] = 0;
            break;
        case 0xAB:
            Input.keyboardState[RNJ_KEY_BACKSLASH] = 0;
            break;
        case 0x9A:
            Input.keyboardState[RNJ_KEY_LEFTBRACKET] = 0;
            break;
        case 0x9B:
            Input.keyboardState[RNJ_KEY_RIGHTBRACKET] = 0;
            break;
        case 0xA7:
            Input.keyboardState[RNJ_KEY_SEMICOLON] = 0;
            break;
        case 0xA8:
            Input.keyboardState[RNJ_KEY_APOSTROPHE] = 0;
            break;
        case 0xB3:
            Input.keyboardState[RNJ_KEY_COMMA] = 0;
            break;
        case 0xB4:
            Input.keyboardState[RNJ_KEY_PERIOD] = 0;
            break;
        case 0xB5:
            Input.keyboardState[RNJ_KEY_SLASH] = 0;
            break;
        case 0x8E:
            Input.keyboardState[RNJ_KEY_BACKSPACE] = 0;
            break;
        case 0xB9:
            Input.keyboardState[RNJ_KEY_SPACE] = 0;
            break;
        case 0x8F:
            Input.keyboardState[RNJ_KEY_TAB] = 0;
            break;
        case 0xBA:
            Input.keyboardState[RNJ_KEY_CAPSLOCK] = 0;
            break;
        case 0xAA:
            Input.keyboardState[RNJ_KEY_LSHIFT] = 0;
            break;
        case 0x9D:
            Input.keyboardState[RNJ_KEY_LCTRL] = 0;
            break;
        case 0xB8:
            Input.keyboardState[RNJ_KEY_LALT] = 0;
            break;
        case 0xB6:
            Input.keyboardState[RNJ_KEY_RSHIFT] = 0;
            break;
        case 0x9C:
            Input.keyboardState[RNJ_KEY_RETURN] = 0;
            break;
        case 0x81:
            Input.keyboardState[RNJ_KEY_ESCAPE] = 0;
            break;
        case 0xBB:
            Input.keyboardState[RNJ_KEY_F1] = 0;
            break;
        case 0xBC:
            Input.keyboardState[RNJ_KEY_F2] = 0;
            break;
        case 0xBD:
            Input.keyboardState[RNJ_KEY_F3] = 0;
            break;
        case 0xBE:
            Input.keyboardState[RNJ_KEY_F4] = 0;
            break;
        case 0xBF:
            Input.keyboardState[RNJ_KEY_F5] = 0;
            break;
        case 0xC0:
            Input.keyboardState[RNJ_KEY_F6] = 0;
            break;
        case 0xC1:
            Input.keyboardState[RNJ_KEY_F7] = 0;
            break;
        case 0xC2:
            Input.keyboardState[RNJ_KEY_F8] = 0;
            break;
        case 0xC3:
            Input.keyboardState[RNJ_KEY_F9] = 0;
            break;
        case 0xC4:
            Input.keyboardState[RNJ_KEY_F10] = 0;
            break;
        case 0xD7:
            Input.keyboardState[RNJ_KEY_F11] = 0;
            break;
        case 0xD8:
            Input.keyboardState[RNJ_KEY_F12] = 0;
            break;
        case 0xC6:
            Input.keyboardState[RNJ_KEY_SCROLLLOCK] = 0;
            break;
        case 0xC5:
            Input.keyboardState[RNJ_KEY_NUMLOCK] = 0;
            break;
        case 0xB7:
            Input.keyboardState[RNJ_KEY_KP_MULTIPLY] = 0;
            break;
        case 0xCA:
            Input.keyboardState[RNJ_KEY_KP_MINUS] = 0;
            break;
        case 0xCE:
            Input.keyboardState[RNJ_KEY_KP_PLUS] = 0;
            break;
        case 0xD3:
            Input.keyboardState[RNJ_KEY_KP_PERIOD] = 0;
            break;
        case 0xD2:
            Input.keyboardState[RNJ_KEY_KP_0] = 0;
            break;
        case 0xCF:
            Input.keyboardState[RNJ_KEY_KP_1] = 0;
            break;
        case 0xD0:
            Input.keyboardState[RNJ_KEY_KP_2] = 0;
            break;
        case 0xD1:
            Input.keyboardState[RNJ_KEY_KP_3] = 0;
            break;
        case 0xCB:
            Input.keyboardState[RNJ_KEY_KP_4] = 0;
            break;
        case 0xCC:
            Input.keyboardState[RNJ_KEY_KP_5] = 0;
            break;
        case 0xCD:
            Input.keyboardState[RNJ_KEY_KP_6] = 0;
            break;
        case 0xC7:
            Input.keyboardState[RNJ_KEY_KP_7] = 0;
            break;
        case 0xC8:
            Input.keyboardState[RNJ_KEY_KP_8] = 0;
            break;
        case 0xC9:
            Input.keyboardState[RNJ_KEY_KP_9] = 0;
            break;

        case 0xE0:
            scancode2 = kolibrios_InputGetScancode();
            switch (scancode2)
            {
                case 0x5B:
                    Input.keyboardState[RNJ_KEY_LGUI] = 1;
                    break;
                case 0x1D:
                    Input.keyboardState[RNJ_KEY_RCTRL] = 1;
                    break;
                case 0x38:
                    Input.keyboardState[RNJ_KEY_RALT] = 1;
                    break;
                case 0x5C:
                    Input.keyboardState[RNJ_KEY_RGUI] = 1;
                    break;
                case 0x5D:
                    Input.keyboardState[RNJ_KEY_APPLICATION] = 1;
                    break;
                case 0x52:
                    Input.keyboardState[RNJ_KEY_INSERT] = 1;
                    break;
                case 0x47:
                    Input.keyboardState[RNJ_KEY_HOME] = 1;
                    break;
                case 0x4F:
                    Input.keyboardState[RNJ_KEY_END] = 1;
                    break;
                case 0x49:
                    Input.keyboardState[RNJ_KEY_PAGEUP] = 1;
                    break;
                case 0x51:
                    Input.keyboardState[RNJ_KEY_PAGEDOWN] = 1;
                    break;
                case 0x53:
                    Input.keyboardState[RNJ_KEY_DELETE] = 1;
                    break;
                case 0x48:
                    Input.keyboardState[RNJ_KEY_UP] = 1;
                    break;
                case 0x4B:
                    Input.keyboardState[RNJ_KEY_LEFT] = 1;
                    break;
                case 0x50:
                    Input.keyboardState[RNJ_KEY_DOWN] = 1;
                    break;
                case 0x4D:
                    Input.keyboardState[RNJ_KEY_RIGHT] = 1;
                    break;
                case 0x35:
                    Input.keyboardState[RNJ_KEY_KP_DIVIDE] = 1;
                    break;
                case 0x1C:
                    Input.keyboardState[RNJ_KEY_KP_ENTER] = 1;
                    break;
                case 0x2A:
                    kolibrios_InputGetScancode();
                    scancode4 = kolibrios_InputGetScancode();
                    switch (scancode4)
                    {
                        case 0x48:
                            Input.keyboardState[RNJ_KEY_UP] = 1;
                            break;
                        case 0x4B:
                            Input.keyboardState[RNJ_KEY_LEFT] = 1;
                            break;
                        case 0x50:
                            Input.keyboardState[RNJ_KEY_DOWN] = 1;
                            break;
                        case 0x4D:
                            Input.keyboardState[RNJ_KEY_RIGHT] = 1;
                            break;
                        case 0x37:
                            Input.keyboardState[RNJ_KEY_PRINTSCREEN] = 1;
                            break;
                        default:
                            break;
                    }
                    break;

                case 0xDB:
                    Input.keyboardState[RNJ_KEY_LGUI] = 0;
                    break;
                case 0x9D:
                    Input.keyboardState[RNJ_KEY_RCTRL] = 0;
                    break;
                case 0xB8:
                    Input.keyboardState[RNJ_KEY_RALT] = 0;
                    break;
                case 0xDC:
                    Input.keyboardState[RNJ_KEY_RGUI] = 0;
                    break;
                case 0xDD:
                    Input.keyboardState[RNJ_KEY_APPLICATION] = 0;
                    break;
                case 0xD2:
                    Input.keyboardState[RNJ_KEY_INSERT] = 0;
                    break;
                case 0xC7:
                    Input.keyboardState[RNJ_KEY_HOME] = 0;
                    break;
                case 0xCF:
                    Input.keyboardState[RNJ_KEY_END] = 0;
                    break;
                case 0xC9:
                    Input.keyboardState[RNJ_KEY_PAGEUP] = 0;
                    break;
                case 0xD1:
                    Input.keyboardState[RNJ_KEY_PAGEDOWN] = 0;
                    break;
                case 0xD3:
                    Input.keyboardState[RNJ_KEY_DELETE] = 0;
                    break;
                case 0xC8:
                    Input.keyboardState[RNJ_KEY_UP] = 0;
                    break;
                case 0xCB:
                    Input.keyboardState[RNJ_KEY_LEFT] = 0;
                    break;
                case 0xD0:
                    Input.keyboardState[RNJ_KEY_DOWN] = 0;
                    break;
                case 0xCD:
                    Input.keyboardState[RNJ_KEY_RIGHT] = 0;
                    break;
                case 0xB5:
                    Input.keyboardState[RNJ_KEY_KP_DIVIDE] = 0;
                    break;
                case 0x9C:
                    Input.keyboardState[RNJ_KEY_KP_ENTER] = 0;
                    break;
                case 0xB7:
                    kolibrios_InputGetScancode();
                    scancode4 = kolibrios_InputGetScancode();
                    switch (scancode4)
                    {
                        case 0xC8:
                            Input.keyboardState[RNJ_KEY_UP] = 1;
                            break;
                        case 0xCB:
                            Input.keyboardState[RNJ_KEY_LEFT] = 1;
                            break;
                        case 0xD0:
                            Input.keyboardState[RNJ_KEY_DOWN] = 1;
                            break;
                        case 0xCD:
                            Input.keyboardState[RNJ_KEY_RIGHT] = 1;
                            break;
                        case 0xAA:
                            Input.keyboardState[RNJ_KEY_PRINTSCREEN] = 1;
                            break;
                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
            break;
        case 0xE1:
            kolibrios_InputGetScancode();
            kolibrios_InputGetScancode();
            kolibrios_InputGetScancode();
            kolibrios_InputGetScancode();
            kolibrios_InputGetScancode();
            /* pause_key */
            break;
        default:
            break;
    }
    return Input.keyboardState;
}

void InputInit(void)
{
//    int nJoysticks;
    int i;
//    int j;
    LogWrite("Initializing Input Subsystem", 0, MT_INFO, NULL);

    LogWrite("Setting KolibriOS scancode input mode", 1, MT_INFO, NULL);
    kolibrios_InputSetScancodeMode();
    LogWrite("KolibriOS scancode input mode set", 1, MT_INFO, NULL);
    Input.keyboardState = malloc(sizeof(Uint8) * 513);
    if (Input.keyboardState != NULL)
        LogWrite("Keyboard state array initialized", 1, MT_INFO, NULL);
    else
        ErrorGive("Can not allocate memory for keyboard state array", 1);
    for (i = 0; i < 513; i++)
    {
        Input.keyboardState[i] = 0;
    }

    LogWrite("Initializing Keyboard State", 1, MT_INFO, NULL);
    Input.currentKeystate = GetKeyboardState();
    if (Input.currentKeystate != NULL)
    {
    	LogWrite("Keyboard State initialized", 1, MT_INFO, NULL);
    }
    else
    {
    	ErrorGive("Can not initialize Keyboard State", 1);
    }
//    LogWrite("Initializing Controller's support", 1, MT_INFO, NULL);
//    if(SDL_InitSubSystem(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER) == 0)
//    {
//    	LogWrite("Controller's support initialized", 1, MT_INFO, NULL);
//    }
//    else
//    {
//    	ErrorGive("Can not initialize Controller's support", 1);
//    }

//    if (SDL_GameControllerAddMappingsFromFile("gamecontrollerdb.txt") != -1)
//        LogWrite("Controller mappings added", 1, MT_INFO, NULL);
//    else
//        LogWrite("Can not add controller mappings", 1, MT_WARNING, NULL);
//
//    nJoysticks = SDL_NumJoysticks();
//    if(nJoysticks < 1)
//        LogWrite("Connected controllers not found", 1, MT_INFO, NULL);
//    Input.controllersCount = 0;
//
//    for (i = 0; i < nJoysticks; i++)
//    {
//        if (SDL_IsGameController(i))
//        {
//            Input.controllersCount++;
//            LogWrite("Controller found:", 1, MT_INFO, (char *)SDL_GameControllerNameForIndex(i));
//        }
//    }
//    if (Input.controllersCount > 0)
//    {
//        Input.controller = malloc(sizeof(SDL_GameController *) * Input.controllersCount);
//    }
//    for(i = 0; i < Input.controllersCount; i++)
//    {
//        Input.controller[i] = SDL_GameControllerOpen(i);
//        if(Input.controller[i] == NULL)
//            LogWrite("Can not open controller for use", 1, MT_WARNING, NULL);
//    }
//    if (Input.controllersCount > 0)
//    {
//        Input.currentControllerState = malloc(sizeof(ControllerState) * Input.controllersCount);
//        Input.previousControllerState = malloc(sizeof(ControllerState) * Input.controllersCount);
//        Input.controllerAxis = malloc(sizeof(ControllerAxes) * Input.controllersCount);
//    }
//
//    for (j = 0; j < Input.controllersCount; j++)
//    {
//        for (i = 0; i < 16; i++)
//        {
//            Input.currentControllerState[j][i] = 0;
//            Input.previousControllerState[j][i] = 0;
//        }
//    }

//    Input.currentMouseLeft = false;
//    Input.currentMouseMiddle = false;
//    Input.currentMouseRight = false;

    LogWrite("Input subsystem initialized", 0, MT_INFO, NULL);
}

void InputQuit(void)
{
//    int i;
//    for (i = 0; i < Input.controllersCount; i++)
//    {
//         SDL_GameControllerClose(Input.controller[i]);
//         Input.controller[i] = NULL;
//    }
//    if (Input.controllersCount > 0)
//    {
//        free(Input.controller);
//        free(Input.currentControllerState);
//        free(Input.previousControllerState);
//        free(Input.controllerAxis);
//    }
    free(Input.keyboardState);
    LogWrite("Input subsystem destroyed", 0, MT_INFO, NULL);
}

bool InputKeyPress(signed int key)
{
    if ((Input.currentKeystate[key]) &&
        !(Input.previousKeystate[key]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool InputKeyRelease(signed int key)
{
    if (!(Input.currentKeystate[key]) &&
        (Input.previousKeystate[key]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool InputKeyPressed(signed int key)
{
    if (Input.currentKeystate [key])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InputKeystatesRefresh(void)
{
    int i;
    for (i = 0; i < RNJ_KEYS_COUNT; i++)
    {
        Input.previousKeystate[i] = (Uint8)Input.currentKeystate[i];
    }
    Input.currentKeystate = GetKeyboardState();
}

void InputMouseRefresh(void)
{
//    Uint32 mouseState;
//    Input.previousMouseLeft = Input.currentMouseLeft;
//    Input.previousMouseMiddle = Input.currentMouseMiddle;
//    Input.previousMouseRight = Input.currentMouseRight;
//
//    mouseState = SDL_GetMouseState(&App.mouseX, &App.mouseY);
//    if ((mouseState & 1) > 0)
//    {
//        Input.currentMouseLeft = true;
//    }
//    else
//    {
//        Input.currentMouseLeft = false;
//    }
//    if ((mouseState & 2) > 0)
//    {
//        Input.currentMouseMiddle = true;
//    }
//    else
//    {
//        Input.currentMouseMiddle = false;
//    }
//    if ((mouseState & 4) > 0)
//    {
//        Input.currentMouseRight = true;
//    }
//    else
//    {
//        Input.currentMouseRight = false;
//    }
}

void InputControllersRefresh(void)
{
//    int i;
//    int j;
//    for (j = 0; j < Input.controllersCount; j++)
//    {
//        for (i = 0; i < 16; i++)
//        {
//            Input.previousControllerState[j][i] = Input.currentControllerState[j][i];
//        }
//    }
//
//    SDL_GameControllerUpdate();
//    for (j = 0; j < Input.controllersCount; j++)
//    {
//        for (i = 0; i < 16; i++)
//        {
//            if (SDL_GameControllerGetButton(Input.controller[j], i) == 1)
//            {
//                Input.currentControllerState[j][i] = 1;
//            }
//            else
//            {
//                Input.currentControllerState[j][i] = 0;
//            }
//        }
//        for (i = 0; i < 7; i++)
//        {
//            Input.controllerAxis[j][i] = SDL_GameControllerGetAxis(Input.controller[j], i);
//        }
//    }
}

bool InputControllerButtonPress(int controllerNum, Uint8 button)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        if ((Input.currentControllerState[controllerNum][button]) &&
//            !(Input.previousControllerState[controllerNum][button]))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
        return false;
//    }
}

bool InputControllerButtonRelease(int controllerNum, Uint8 button)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        if (!(Input.currentControllerState[controllerNum][button]) &&
//            (Input.previousControllerState[controllerNum][button]))
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
        return false;
//    }
}

bool InputControllerButtonPressed(int controllerNum, Uint8 button)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        if (Input.currentControllerState[controllerNum][button])
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    else
//    {
        return false;
//    }
}

Sint16 InputControllerGetAxis(int controllerNum, int axis)
{
//    if (Input.controllersCount > controllerNum)
//    {
//        return Input.controllerAxis[controllerNum][axis];
//    }
//    else
//    {
        return 0;
//    }
}

