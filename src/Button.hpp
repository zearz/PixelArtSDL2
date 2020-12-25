#include <SDL.h>
class Button
{
private:
    /* data */
public:
    Button(int x,int y,int w,int h,Uint8 _r,Uint8 _g,Uint8 _b,Uint8 _a);
    Draw(SDL_Renderer *render);
    Collision(int MouseX,int MouseY);
    bool MouseHover = false;
    SDL_Rect _Rect;
    SDL_Color _Color;
    ~Button();
};

Button::Button(int x,int y,int w,int h,Uint8 _r,Uint8 _g,Uint8 _b,Uint8 _a)
{
    _Rect.x = x;
    _Rect.y = y;
    _Rect.w = w;
    _Rect.h = h;
    _Color.a = _a;
    _Color.r = _r;
    _Color.g = _g;
    _Color.b = _b;
}

Button::Collision(int MouseX,int MouseY)
{
    if(MouseX > _Rect.x && MouseX < _Rect.x + _Rect.w && MouseY> _Rect.y && MouseY< _Rect.y +_Rect.h)
    {
        MouseHover = true;
        return true;
    }
    else
    {
        MouseHover = false;
        return false;
    }
}

Button::Draw(SDL_Renderer *render)
{
    SDL_SetRenderDrawColor(render,_Color.r,_Color.g,_Color.b,255);
    SDL_RenderFillRect(render,&_Rect);
}

Button::~Button()
{
}
