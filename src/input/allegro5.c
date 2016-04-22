#include "input/allegro5.h"



void InputInit(void)
{
    int i;
    int j;
    int k;
    //int nJoysticks;
    LogWrite("Initializing Input Subsystem", 0, MT_INFO, NULL);
    LogWrite("Installing keyboard driver", 1, MT_INFO, NULL);
    if (al_install_keyboard())
    {
    	LogWrite("Keyboard driver installed", 1, MT_INFO, NULL);
    }
    else
    {
    	ErrorGive("Can not install keyboard driver", 1);
    }

	LogWrite("Creating event queue for keyboard", 1, MT_INFO, NULL);
	Input.keyboardEQ = al_create_event_queue();
	if (Input.keyboardEQ != NULL)
	{
		LogWrite("Event queue for keyboard created", 1, MT_INFO, NULL);
	}
	else
	{
		ErrorGive("Can not create event queue for keyboard", 1);
	}
    al_register_event_source(Input.keyboardEQ, al_get_keyboard_event_source());
    LogWrite("Keyboard event source registered", 1, MT_INFO, NULL);
    for (i = 0; i < KEYS_COUNT; i++)
    {
        Input.currentKeystate[i] = false;
    }
    LogWrite("Keystates initialized", 1, MT_INFO, NULL);

    LogWrite("Installing mouse driver", 1, MT_INFO, NULL);
    if (al_install_mouse())
    {
    	LogWrite("Mouse driver installed", 1, MT_INFO, NULL);
    }
    else
    {
    	ErrorGive("Can not install mouse driver", 1);
    }
    Input.mouseEQ = al_create_event_queue();
    if (Input.mouseEQ != NULL)
	{
		LogWrite("Event queue for mouse created", 1, MT_INFO, NULL);
	}
	else
	{
		ErrorGive("Can not create event queue for mouse", 1);
	}
    al_register_event_source(Input.mouseEQ, al_get_mouse_event_source());
    LogWrite("Mouse event source registered", 1, MT_INFO, NULL);
    Input.currentMouseLeft = false;
    Input.currentMouseMiddle = false;
    Input.currentMouseRight = false;
    LogWrite("Mouse button states initialized", 1, MT_INFO, NULL);

	LogWrite("Reporting Mouse's secification", 1, MT_INFO, NULL);
	LogWrite2("Axes/wheels found:", 2, MT_INFO, al_get_mouse_num_axes());
	LogWrite2("Buttons found:", 2, MT_INFO, al_get_mouse_num_buttons());

	LogWrite("Installing joystick driver", 1, MT_INFO, NULL);
    if ( al_install_joystick())
    {
    	LogWrite("Joystick driver installed", 1, MT_INFO, NULL);
    }
    else
    {
    	ErrorGive("Can not install joystick driver", 1);
    }

	//al_reconfigure_joysticks();

	Input.controllersCount = al_get_num_joysticks();
	LogWrite2("Controllers found", 1, MT_INFO, Input.controllersCount);
	if (Input.controllersCount > 0)
	{
		LogWrite("Creating event queue for controllers", 1, MT_INFO, NULL);
		Input.controllerEQ = al_create_event_queue();
		if (Input.controllerEQ != NULL)
		{
			LogWrite("Event queue for controllers created", 1, MT_INFO, NULL);
		}
		else
		{
			ErrorGive("Can not create event queue for controllers", 1);
		}
		al_register_event_source(Input.controllerEQ, al_get_joystick_event_source());
		LogWrite("Controllers event source registered", 1, MT_INFO, NULL);

		Input.controller = malloc(sizeof(ALLEGRO_JOYSTICK *) * Input.controllersCount);
		if (Input.controller == NULL)
		{
			ErrorGive("Can not allocate memory for Controllers", 1);
		}
		Input.currentControllerState = malloc(sizeof(ControllerState) * Input.controllersCount);
		if (Input.currentControllerState == NULL)
		{
			ErrorGive("Can not allocate memory for current controller's buttons state", 1);
		}
		Input.previousControllerState = malloc(sizeof(ControllerState) * Input.controllersCount);
		if (Input.currentControllerState == NULL)
		{
			ErrorGive("Can not allocate memory for previous controller's buttons state", 1);
		}
		Input.controllerAxis = malloc(sizeof(ControllerAxes) * Input.controllersCount);
		if (Input.currentControllerState == NULL)
		{
			ErrorGive("Can not allocate memory for controller's axes", 1);
		}
		for (i = 0; i < Input.controllersCount; i++)
		{
			Input.controller[i] = al_get_joystick(i);
			if (Input.controller[i] != NULL)
			{
				LogWrite2("Controller device got", 1, MT_INFO, i);
			}
			else
			{
				LogWrite2("Can not get controller device", 1, MT_INFO, i);
			}
			for (j = 0; j < CONTROLLER_MAX_BUTTONS; j++)
			{
				Input.currentControllerState[i][j] = false;
			}
			for (j = 0; j < CONTROLLER_MAX_AXES; j++)
			{
				Input.controllerAxis[i][j] = 0;
			}

		}
		LogWrite("Reporting Controllers' secification", 1, MT_INFO, NULL);
		for (i = 0; i < Input.controllersCount; i++)
		{
			LogWrite2("No.", 2, MT_INFO, i);
			LogWrite("Controller name:", 3, MT_INFO, (char *)al_get_joystick_name(Input.controller[i]));
			LogWrite("Checking controller's sticks", 3, MT_INFO, NULL);
			if (al_get_joystick_num_sticks(Input.controller[i]) > 0)
			{
				LogWrite2("Sticks/D-Pads found:", 3, MT_INFO, al_get_joystick_num_sticks(Input.controller[i]));
				for (j = 0; j < al_get_joystick_num_sticks(Input.controller[i]); j++)
				{
					LogWrite2("No.", 4, MT_INFO, j);
					LogWrite("Stick/D-Pad name:", 5, MT_INFO, (char *)al_get_joystick_stick_name(Input.controller[i], j));
					LogWrite2("Axes found:", 5, MT_INFO, al_get_joystick_num_axes(Input.controller[i], j));
					for (k = 0; k < al_get_joystick_num_axes(Input.controller[i], j); k++)
					{
						LogWrite2("No.", 6, MT_INFO, k);
						LogWrite("Axis name:", 7, MT_INFO, (char *)al_get_joystick_axis_name(Input.controller[i], j, k));
					}
				}
			}
			LogWrite2("Buttons found:", 3, MT_INFO, al_get_joystick_num_buttons(Input.controller[i]));
			for (j = 0; j < al_get_joystick_num_buttons(Input.controller[i]); j++)
			{
				LogWrite2("No.", 4, MT_INFO, j);
				LogWrite("Button name:", 5, MT_INFO, (char *)al_get_joystick_button_name(Input.controller[i], j));
			}
		}
	}
	else
	{
		Input.controller = NULL;
	}


    LogWrite("Input subsystem initialized", 0, MT_INFO, NULL);
}

void InputQuit(void)
{
    LogWrite("Destroying input subsystem", 0, MT_INFO, NULL);
	al_uninstall_keyboard();
	LogWrite("Keyboard driver uninstalled", 1, MT_INFO, NULL);
	al_uninstall_mouse();
	LogWrite("Mouse driver uninstalled", 1, MT_INFO, NULL);
	al_uninstall_joystick();
	LogWrite("Joystick driver uninstalled", 1, MT_INFO, NULL);
    LogWrite("Input subsystem destroyed", 0, MT_INFO, NULL);
}

void InputKeystatesRefresh(void)
{
	int i;
    for (i = 0; i < KEYS_COUNT; i++)
    {
        Input.previousKeystate[i] = Input.currentKeystate[i];
    }

    while (!al_is_event_queue_empty(Input.keyboardEQ))
	{
		al_get_next_event(Input.keyboardEQ, &Input.keyboardEvent);
		if (Input.keyboardEvent.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			Input.currentKeystate[Input.keyboardEvent.keyboard.keycode] = true;
		}
		else if (Input.keyboardEvent.type == ALLEGRO_EVENT_KEY_UP)
		{
			Input.currentKeystate[Input.keyboardEvent.keyboard.keycode] = false;
		}
	}
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

void InputMouseRefresh(void)
{
    Input.previousMouseLeft = Input.currentMouseLeft;
    Input.previousMouseMiddle = Input.currentMouseMiddle;
    Input.previousMouseRight = Input.currentMouseRight;

    while (!al_is_event_queue_empty(Input.mouseEQ))
	{
		al_get_next_event(Input.mouseEQ, &Input.mouseEvent);
		if (Input.mouseEvent.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			App.mouseX = Input.mouseEvent.mouse.x;
			App.mouseY = Input.mouseEvent.mouse.y;
		}
		else if (Input.mouseEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			switch (Input.mouseEvent.mouse.button)
			{
				case 1:
				{
					Input.currentMouseLeft = true;
					break;
				}
				case 2:
				{
					Input.currentMouseMiddle = true;
					break;
				}
				case 3:
				{
					Input.currentMouseRight = true;
					break;
				}
			}
		}
		else if (Input.mouseEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			switch (Input.mouseEvent.mouse.button)
			{
				case 1:
				{
					Input.currentMouseLeft = false;
					break;
				}
				case 2:
				{
					Input.currentMouseMiddle = false;
					break;
				}
				case 3:
				{
					Input.currentMouseRight = false;
					break;
				}
			}
		}
	}
}

int InputJoyToID(ALLEGRO_JOYSTICK *joy)
{
	int i;
	for (i = 0; i < Input.controllersCount; i++)
	{
		if (Input.controller[i] == joy)
		{
			return i;
		}
	}
	return -1;
}

int InputStickAxisToAxisnum(int joyID, int stick, int axis)
{
	int i;
	int j;
	int axisNum = 0;
	for (i = 0; i < al_get_joystick_num_sticks(Input.controller[joyID]); i++)
	{
		for (j = 0; j < al_get_joystick_num_axes(Input.controller[joyID], i); j++)
		{
			if ((stick == i) && (axis == j))
			{
				return axisNum;
			}
			else
			{
				axisNum++;
			}
		}
	}
	return -1;
}

void InputControllersRefresh(void)
{
    int i;
    int j;
    int controllerNum;
    int axisNum;
    if (Input.controllersCount > 0)
    {
		for (i = 0; i < Input.controllersCount; i++)
		{
			for (j = 0; j < CONTROLLER_MAX_BUTTONS; j++)
			{
				Input.previousControllerState[i][j] = Input.currentControllerState[i][j];
			}
		}
		while (!al_is_event_queue_empty(Input.controllerEQ))
		{
			al_get_next_event(Input.controllerEQ, &Input.controllerEvent);
			if (Input.controllerEvent.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN)
			{
				Input.currentControllerState[InputJoyToID(Input.controllerEvent.joystick.id)][Input.controllerEvent.joystick.button] = true;
			}
			else if (Input.controllerEvent.type == ALLEGRO_EVENT_JOYSTICK_BUTTON_UP)
			{
				Input.currentControllerState[InputJoyToID(Input.controllerEvent.joystick.id)][Input.controllerEvent.joystick.button] = false;
			}
			else if (Input.controllerEvent.type == ALLEGRO_EVENT_JOYSTICK_AXIS)
			{
				controllerNum = InputJoyToID(Input.controllerEvent.joystick.id);
				axisNum = InputStickAxisToAxisnum(controllerNum, Input.controllerEvent.joystick.stick, Input.controllerEvent.joystick.axis);
				Input.controllerAxis[controllerNum][axisNum] = RnjuAxisFloatToInt(Input.controllerEvent.joystick.pos);
			}
		}
    }
}

bool InputControllerButtonPress(int controllerNum, uint8_t button)
{
    if (Input.controllersCount > controllerNum)
    {
        if ((Input.currentControllerState[controllerNum][button]) &&
            !(Input.previousControllerState[controllerNum][button]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool InputControllerButtonRelease(int controllerNum, uint8_t button)
{
    if (Input.controllersCount > controllerNum)
    {
        if (!(Input.currentControllerState[controllerNum][button]) &&
            (Input.previousControllerState[controllerNum][button]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool InputControllerButtonPressed(int controllerNum, uint8_t button)
{
    if (Input.controllersCount > controllerNum)
    {
        if (Input.currentControllerState[controllerNum][button])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int16_t InputControllerGetAxis(int controllerNum, int axis)
{
    if (Input.controllersCount > controllerNum)
    {
        return Input.controllerAxis[controllerNum][axis];
    }
    else
    {
        return 0;
    }
}
