#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#include "Input.h"
#include "cassert"
#include <wrl.h>
#include <windows.h>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
using namespace Microsoft::WRL;

void Input::Initialize(HINSTANCE hInstance,HWND hwnd) {
	HRESULT result;

	ComPtr<IDirectInput8> directInput = nullptr;
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));
	ComPtr<IDirectInputDevice8> keyboard;
	result = directInput->CreateDevice(GUID_Syskeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	result = keyboard->SetDataFormat(&c_dfDIkeyboard);
	assert(SUCCEEDED(result));
	
	result = keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));

}

void Input::Update() {


}