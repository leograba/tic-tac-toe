#include "CEvent.h"

CEvent::CEvent()
{
}

CEvent::~CEvent()
{
    //Do nothing
}

void CEvent::OnEvent(SDL_Event *Event)
{
    switch (Event->type)
    {

        case SDL_WINDOWEVENT:
        {
            switch (Event->window.event)
            {
                case SDL_WINDOWEVENT_SHOWN:
                    //SDL_Log("Window %d shown", Event->window.windowID);
                    break;
                case SDL_WINDOWEVENT_HIDDEN:
                    //SDL_Log("Window %d hidden", Event->window.windowID);
                    break;
                case SDL_WINDOWEVENT_EXPOSED:
                    //SDL_Log("Window %d exposed", Event->window.windowID);
                    OnExpose();
                    break;
                case SDL_WINDOWEVENT_MOVED:
                    //SDL_Log("Window %d moved to %d,%d",
                    //        Event->window.windowID, Event->window.data1,
                    //        Event->window.data2);
                    break;
                case SDL_WINDOWEVENT_RESIZED:
                    //SDL_Log("Window %d resized to %dx%d",
                    //        Event->window.windowID, Event->window.data1,
                    //        Event->window.data2);
                    //OnResize(Event->window.data1, Event->window.data2);
                    break;
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    //SDL_Log("Window %d size changed to %dx%d",
                    //        Event->window.windowID, Event->window.data1,
                    //        Event->window.data2);
                    OnResize(Event->window.data1, Event->window.data2);
                    break;
                case SDL_WINDOWEVENT_MINIMIZED:
                    //SDL_Log("Window %d minimized", Event->window.windowID);
                    break;
                case SDL_WINDOWEVENT_MAXIMIZED:
                    //SDL_Log("Window %d maximized", Event->window.windowID);
                    break;
                case SDL_WINDOWEVENT_RESTORED:
                    //SDL_Log("Window %d restored", Event->window.windowID);
                    break;
                case SDL_WINDOWEVENT_ENTER:
                    //SDL_Log("Mouse entered window %d",
                    //        Event->window.windowID);
                    OnMouseFocus();
                    break;
                case SDL_WINDOWEVENT_LEAVE:
                    //SDL_Log("Mouse left window %d", Event->window.windowID);
                    OnMouseBlur();
                    break;
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                    //SDL_Log("Window %d gained keyboard focus",
                    //        Event->window.windowID);
                    OnInputFocus();
                    break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                    //SDL_Log("Window %d lost keyboard focus",
                    //        Event->window.windowID);
                    OnInputBlur();
                    break;
                case SDL_WINDOWEVENT_CLOSE:
                    //SDL_Log("Window %d closed", Event->window.windowID);
                    break;
                #if SDL_VERSION_ATLEAST(2, 0, 5)
                case SDL_WINDOWEVENT_TAKE_FOCUS:
                    //SDL_Log("Window %d is offered a focus", Event->window.windowID);
                    break;
                case SDL_WINDOWEVENT_HIT_TEST:
                    //SDL_Log("Window %d has a special hit test", Event->window.windowID);
                    break;
                #endif
                default:
                    SDL_Log("Window %d got unknown event %d",
                            Event->window.windowID, Event->window.event);
                    break;
            }
        }

        case SDL_KEYDOWN:
        {
            OnKeyDown(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.scancode);
            break;
        }

        case SDL_KEYUP:
        {
            OnKeyUp(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.scancode);
            break;
        }

        case SDL_MOUSEMOTION:
        {
            OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, (Event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, (Event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (Event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            switch (Event->button.button)
            {
                case SDL_BUTTON_LEFT:
                {
                    OnLButtonDown(Event->button.x, Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT:
                {
                    OnRButtonDown(Event->button.x, Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE:
                {
                    OnMButtonDown(Event->button.x, Event->button.y);
                    break;
                }
            }
            break;
        }

        case SDL_MOUSEBUTTONUP:
        {
            switch (Event->button.button)
            {
            case SDL_BUTTON_LEFT:
            {
                OnLButtonUp(Event->button.x, Event->button.y);
                break;
            }
            case SDL_BUTTON_RIGHT:
            {
                OnRButtonUp(Event->button.x, Event->button.y);
                break;
            }
            case SDL_BUTTON_MIDDLE:
            {
                OnMButtonUp(Event->button.x, Event->button.y);
                break;
            }
            }
            break;
        }

        case SDL_JOYAXISMOTION:
        {
            OnJoyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
            break;
        }

        case SDL_JOYBALLMOTION:
        {
            OnJoyBall(Event->jball.which, Event->jball.ball, Event->jball.xrel, Event->jball.yrel);
            break;
        }

        case SDL_JOYHATMOTION:
        {
            OnJoyHat(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN:
        {
            OnJoyButtonDown(Event->jbutton.which, Event->jbutton.button);
            break;
        }

        case SDL_JOYBUTTONUP:
        {
            OnJoyButtonUp(Event->jbutton.which, Event->jbutton.button);
            break;
        }

        case SDL_QUIT:
        {
            OnExit();
            break;
        }

        case SDL_SYSWMEVENT:
        {
            //Ignore
            break;
        }

        default:
        {
            OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
            break;
        }
    }
}

void CEvent::OnInputFocus()
{
    //Pure virtual, do nothing
}

void CEvent::OnInputBlur()
{
    //Pure virtual, do nothing
}

void CEvent::OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode)
{
    //Pure virtual, do nothing
}

void CEvent::OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode unicode)
{
    //Pure virtual, do nothing
}

void CEvent::OnMouseFocus()
{
    //Pure virtual, do nothing
}

void CEvent::OnMouseBlur()
{
    //Pure virtual, do nothing
}

void CEvent::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
{
    //Pure virtual, do nothing
}

void CEvent::OnMouseWheel(bool Up, bool Down)
{
    //Pure virtual, do nothing
}

void CEvent::OnLButtonDown(int mX, int mY)
{
    //Pure virtual, do nothing
}

void CEvent::OnLButtonUp(int mX, int mY)
{
    //Pure virtual, do nothing
}

void CEvent::OnRButtonDown(int mX, int mY)
{
    //Pure virtual, do nothing
}

void CEvent::OnRButtonUp(int mX, int mY)
{
    //Pure virtual, do nothing
}

void CEvent::OnMButtonDown(int mX, int mY)
{
    //Pure virtual, do nothing
}

void CEvent::OnMButtonUp(int mX, int mY)
{
    //Pure virtual, do nothing
}

void CEvent::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
    //Pure virtual, do nothing
}

void CEvent::OnJoyButtonDown(Uint8 which, Uint8 button)
{
    //Pure virtual, do nothing
}

void CEvent::OnJoyButtonUp(Uint8 which, Uint8 button)
{
    //Pure virtual, do nothing
}

void CEvent::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value)
{
    //Pure virtual, do nothing
}

void CEvent::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
{
    //Pure virtual, do nothing
}

void CEvent::OnMinimize()
{
    //Pure virtual, do nothing
}

void CEvent::OnRestore()
{
    //Pure virtual, do nothing
}

void CEvent::OnResize(int w, int h)
{
    //Pure virtual, do nothing
}

void CEvent::OnExpose()
{
    //Pure virtual, do nothing
}

void CEvent::OnExit()
{
    //Pure virtual, do nothing
}

void CEvent::OnUser(Uint8 type, int code, void *data1, void *data2)
{
    //Pure virtual, do nothing
}